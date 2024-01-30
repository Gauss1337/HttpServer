#ifndef CGI_HPP
#define CGI_HPP
#include <sys/types.h>
#include <fcntl.h>
#include <cstring>
#include <sys/wait.h>
#include "../parsing/webserv.hpp"
#include "../networking/Client.hpp"
#include <unistd.h>
#include <signal.h>

class Client;
class HttpRequest;

class CGI
{
	char** env;
	Client &client;

	public:
	int status_code;
	CGI(Client&);
	CGI(const CGI&);
	CGI& operator=(const CGI&);
	~CGI();

	/*setters*/
	void set_environmentVariables(std::string&);

	/*getters*/
	char** get_CGIenvironmentVariables();

	void run();
};

#endif
