#ifndef WEBSERV_HPP
#define WEBSERV_HPP
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "parseConfig/Location.hpp"
#include "parseConfig/Server.hpp"
#include "parseRequest/Request.hpp"

class Location;
class Server;
class HttpRequest;

class HttpExceptions : public std::exception
{
	std::string message;

public:
	HttpExceptions(std::string msg) : message(msg){};
	const char *what() const throw()
	{
		return (this->message.c_str());
	}
	~HttpExceptions() throw(){};
};

class ConfigFileExecption : public HttpExceptions
{
public:
	ConfigFileExecption(std::string msg) : HttpExceptions(msg){};
};

class ParseConf
{
public:
	ParseConf()
	{
	}
	~ParseConf()
	{
	}
	std::vector<Server> servers;
	void parsing(int, char **);
	void read_file(std::ifstream &);
	std::vector<Server> &get_servers();
	typedef std::vector<Server>::iterator v_iterator;
	typedef std::vector<Server>::const_iterator cv_iterator;
};

int check_file(std::ifstream &, int argc, char **argv);
void trim_front(std::string &str);
void trim_back(std::string &str);
void str_trim(std::string &str);
Server parse_server(std::ifstream &);
Location parse_location(std::ifstream &, std::string &);
void set_key_value(std::string &, std::string &, std::string &);
std::vector<std::string> split(std::string &, char);
bool isHexadecimal(std::string &);
bool isNumber(std::string &);
std::string Generate_Random_File_Name();
std::string extractBody(std::string);
#endif
