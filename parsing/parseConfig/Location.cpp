#include "../webserv.hpp" 

Location::Location()
{
	this->path = "";
	this->root = "";
	this->try_file = "";
	this->redirection = "";
	this->redirect = 0;
	this->fastcgi_pass = "";
	this->autoindex = "OFF";
	this->bodySize = 0;
}

Location::Location(const Location& location)
{
	this->path = location.path;
	this->root = location.root;
	this->index = location.index;
	this->bodySize = location.bodySize;
	this->redirection = location.redirection;
	this->autoindex = location.autoindex;
	this->redirect = location.redirect;
	this->methods = location.methods;
	this->fastcgi_pass = location.fastcgi_pass;
	this->errorPage = location.errorPage;
	this->upload = location.upload;
}

Location& Location::operator=(const Location& location)
{
	if(this != &location)
	{
		this->path = location.path;
		this->root = location.root;
		this->index = location.index;
		this->bodySize = location.bodySize;
		this->redirection = location.redirection;
		this->autoindex = location.autoindex;
		this->redirect = location.redirect;
		this->methods = location.methods;
		this->fastcgi_pass = location.fastcgi_pass;
		this->errorPage = location.errorPage;
		this->upload = location.upload;
	}
	return (*this);
}

Location::~Location()
{
}

void Location::set_path(std::string& path)
{
	this->path = path;
}

void Location::set_root(std::string& root)
{
	this->root = root;
}

void Location::set_index(std::string& index)
{
	size_t pos = 0;
	size_t i = 0;

	while (pos < index.size())
	{
		while (pos < index.size() && index[pos] != ' ' && index[pos] != '\t')
			pos++;
		std::string tmp = index.substr(i, pos - i);
		this->index.push_back(tmp);
		while (pos < index.size() && (index[pos] == ' ' || index[pos] == '\t'))
			pos++;
		i = pos;
	}
}

void Location::set_bodySize(std::string& bodySize)
{
	size_t pos;

	pos = bodySize.find("M");
	if (pos == std::string::npos)
		pos = bodySize.find("m");
	if (pos != std::string::npos)
	{
		if (pos + 1 < bodySize.size())
		{
			std::string tmp = bodySize.substr(pos + 1);
			std::string::iterator it;
			for (it = tmp.begin(); it != tmp.end(); ++it)
			{
				if (!std::isspace(*it))
					throw ConfigFileExecption("Error: Wrong max_body_size!");
			}
		}
		bodySize = bodySize.erase(pos, 1);
		
	}
if (bodySize.empty() || !isNumber(bodySize))
			throw ConfigFileExecption("Error: Wrong max_body_size!");
	std::istringstream iss(bodySize);
	iss >> this->bodySize;
}

void Location::set_errorPage(std::string& error)
{
	size_t pos = 0;
	size_t i = 0;
	std::vector<std::string> statusCode;
	std::string errorPage;
	std::pair<std::vector<std::string>, std::string> errors;

	while (pos < error.size())
	{
		while (pos < error.size() && error[pos] != ' ' && error[pos] != '\t')
			pos++;
		std::string tmp = error.substr(i, pos - i);
		if (isNumber(tmp))
			statusCode.push_back(tmp.c_str());
		else
			errorPage = tmp;
		while (pos < error.size() && (error[pos] == ' ' || error[pos] == '\t'))
			pos++;
		i = pos;
	}
	errors.first = statusCode;
	errors.second = errorPage;
	this->errorPage.push_back(errors);
}

void Location::set_redirection(std::string& redir)
{
	size_t pos = 0;

	while (pos < redir.size() && redir[pos] != ' ' && redir[pos] != '\t')
		pos++;
	if (pos < redir.size())
	{
		this->redirect = atoi(redir.substr(0, pos).c_str());
		this->redirection = redir.substr(pos + 1);
		str_trim(this->redirection);
	}
}

void Location::set_methods(std::string& methods)
{
	size_t pos = 0;
	size_t i = 0;

	while (pos < methods.size())
	{
		while (pos < methods.size() && methods[pos] != ' ' && methods[pos] != '\t')
			pos++;
		std::string tmp = methods.substr(i, pos - i);
		this->methods.push_back(tmp);
		while (pos < methods.size() && (methods[pos] == ' ' || methods[pos] == '\t'))
			pos++;
		i = pos;
	}
}

void Location::set_autoindex(std::string& autoindex)
{
	if (autoindex != "ON" && autoindex != "OFF")
		throw ConfigFileExecption("Wrong autoindex!: " + autoindex);
	this->autoindex = autoindex;
}

void Location::set_upload(std::string& upload)
{
	this->upload = upload;
}

std::vector<std::string>& Location::get_methods()
{
	return (this->methods);
}

std::string& Location::get_root()
{
	return (this->root);
}

std::vector<std::string>& Location::get_index()
{
	return (this->index);
}

std::vector<std::pair<std::vector<std::string>, std::string> >& Location::get_errorPage()
{
	return (this->errorPage);
}

std::string& Location::get_redirection()
{
	return (this->redirection);
}

int& Location::get_redirect()
{
	return (this->redirect);
}

std::string& Location::get_path()
{
	return (this->path);
}

std::string& Location::get_upload()
{
	return (this->upload);
}

std::string& Location::get_autoindex()
{
	return (this->autoindex);
}

size_t& Location::get_bodySize()
{
	return (this->bodySize);
}
