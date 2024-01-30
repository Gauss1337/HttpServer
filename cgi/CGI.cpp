#include "CGI.hpp"

CGI::CGI(Client &client):client(client), status_code(200)
{
}

CGI::~CGI()
{
}

CGI::CGI(const CGI& cgi) : client(cgi.client), status_code(200)
{
	this->env = cgi.env;
}

CGI& CGI::operator=(const CGI& cgi)
{
	if (this != &cgi)
	{
		this->env = cgi.env;
		this->client = cgi.client;
		this->status_code = cgi.status_code;
	}
	return (*this);
}

void CGI::set_environmentVariables(std::string& file_name)
{
	std::vector<std::string> envs;
	std::map<std::string, std::string> &headers = this->client.getRequest().get_headers();
	HttpRequest &request = this->client.getRequest();

	envs.push_back("CONTENT_TYPE="+ headers["Content-Type"]);
	envs.push_back("REDIRECT_STATUS=200");
	envs.push_back("CONTENT_LENGTH=" + headers["Content-Length"]);
	envs.push_back("HTTP_COOKIE=" + headers["Cookie"]);
	envs.push_back("HTTP_USER_AGENT=" + headers["User-Agent"]);
	envs.push_back("PATH_INFO=");
	envs.push_back("QUERY_STRING=" + request.get_queryString());
	envs.push_back("REMOTE_ADDR=");
	envs.push_back("REMOTE_HOST=");
	envs.push_back("REQUEST_METHOD=" + request.get_httpMethod());
	envs.push_back("SCRIPT_NAME="+ file_name);
	envs.push_back("SERVER_NAME="+headers["Host"]);
	envs.push_back("SERVER_SOFTWARE=HTTP/1.1");
	envs.push_back("SCRIPT_FILENAME="+ request.get_uri());
	envs.push_back("REQUEST_URI="+ request.get_uri());

	this->env = new char*[envs.size() + 1];
	size_t i = 0;
	for (i = 0; i < envs.size(); i++)
	{
		this->env[i] = new char[envs[i].size() + 1];
		strcpy(this->env[i], envs[i].c_str());
	}
	this->env[i] = NULL;
}


char** CGI::get_CGIenvironmentVariables()
{
	return (this->env);
}

void CGI::run()
{
	pid_t pid;
	int fdIn = 0;
	int fdOut = 1;
	FILE* tmp = std::tmpfile();


	std::string path(this->client.getRequest().get_uri());
	char* tmp_arg = new char[path.size() + 1];
	strcpy(tmp_arg, path.c_str());

	char *args[] = {tmp_arg, NULL};
	if (this->client.getRequest().get_httpMethod() == "POST")
	{
		fdIn = open(this->client.getRequest().get_bodyFileName().c_str(), O_RDONLY);
		if (!fdIn)
		{
			this->status_code = 500;
			std::exit(EXIT_FAILURE);
		}
			
	}
		
	tmp = std::tmpfile();
	fdOut = fileno(tmp);
	pid = fork();
	if (pid == -1)
	{
		std::string errorContent = "Content-Type: text/html\r\n\r\n<html><body style='text-align:center;'><h1>500 Internal Error</h1></body></html>";
        write(STDOUT_FILENO, errorContent.c_str(), errorContent.size());
		std::exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (dup2(fdIn, 0) == -1 || dup2(fdOut,1) == -1)
		{
			std::string errorContent = "Content-Type: text/html\r\n\r\n<html><body style='text-align:center;'><h1>500 Internal Error</h1></body></html>";
       		write(STDOUT_FILENO, errorContent.c_str(), errorContent.size());
			std::exit(EXIT_FAILURE);
		}
			
		if (this->client.getRequest().get_httpMethod() == "POST")
			close(fdIn);
		close(fdOut);
		fclose(tmp);
		execve(args[0], args, this->env);
		std::string errorContent = "Content-Type: text/html\r\n\r\n<html><body style='text-align:center;'><h1>500 Internal Error</h1></body></html>";
        write(STDOUT_FILENO, errorContent.c_str(), errorContent.size());
		std::exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		int change_status = 200;
		time_t start_time = time(NULL);
		while (time(NULL) - start_time < 5)
		{
			if (waitpid(pid, NULL, WNOHANG) == pid)
			{
				change_status = -2;
				break;
			}
		}
		if (change_status != -2 && waitpid(pid, NULL, WNOHANG) != pid)
		{
			this->status_code = 504;
			kill(pid, SIGKILL);
		}

		delete[] tmp_arg;

		/*free array of cgi environment variables*/
		int i = 0;
		while(this->env[i])
		{
			delete[] this->env[i];
			i++;
		}
		delete[] this->env;

		/*read response*/
		char buffer[1024];
		ssize_t bytes;
		std::string response;

		lseek(fdOut, 0, SEEK_SET);
		while ((bytes = read(fdOut, buffer, 1023)) > 0)	
		{
			buffer[bytes] = '\0';
			response += buffer;
		}
		char *tmp_str = new char[response.size() + 1];
		strcpy(tmp_str, response.c_str());
		this->client.setResponse(tmp_str, response.size());
		delete[] tmp_str;
		if (this->client.getRequest().get_httpMethod() == "POST")
			close(fdIn);
		close(fdOut);
		fclose(tmp);
	}
}
