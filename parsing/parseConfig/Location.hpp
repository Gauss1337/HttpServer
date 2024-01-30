#ifndef LOCATION_HPP
#define LOCATION_HPP
#include <iostream>
#include <vector>
#include "../webserv.hpp"

class Location
{
	
	std::string path;
	size_t bodySize;
	std::string root;
	std::vector<std::string> index;
	std::string try_file;
	std::string redirection;
	std::string autoindex;
	int redirect;
	std::vector<std::string> methods;
	std::string fastcgi_pass;
	std::vector<std::pair<std::vector<std::string>, std::string> > errorPage;
	std::string upload;
	public:
	Location();
	Location(const Location&);
	Location& operator=(const Location&);
	~Location();

	/*setters*/
	void set_autoindex(std::string&);
	void set_errorPage(std::string&);
	void set_index(std::string&);
	void set_methods(std::string&);
	void set_redirection(std::string&);
	void set_root(std::string&);
	void set_path(std::string&);
	void set_upload(std::string&);
	void set_bodySize(std::string&);

	/*getters*/
	std::string& get_autoindex();
	std::vector<std::string>& get_index();
	std::vector<std::string>& get_methods();
	std::string& get_redirection();
	std::string& get_root();
	std::vector<std::pair<std::vector<std::string>, std::string> >& get_errorPage();
	std::string& get_path();
	std::string& get_upload();
	int& get_redirect();
	size_t& get_bodySize();
};

#endif
