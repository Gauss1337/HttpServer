#include "../webserv.hpp"

Server parse_server(std::ifstream &conffile)
{
	std::string key, value, line;
	Server server;

	while (getline(conffile, line))
	{
		if (line.empty())
		continue;
		set_key_value(line, key, value);
		if (key == "}")
			break;
		if (key == "location")
		{
			if (conffile)
				server.set_location(conffile, value);
		}
		else if (key == "server_name")
			server.set_serverName(value);
		else if (key == "listen")
			server.set_host_port(value);
		else if (key == "client_max_body_size")
			server.set_bodySize(value);
		else if (key == "autoindex")
			server.set_autoindex(value);
		else if (key == "root")
			server.set_root(value);
		else if (key == "error_page")
			server.set_errorPage(value);
		else if (key.empty())
		continue;
		else
			break;
	}
	if (key != "}")
		throw ConfigFileExecption("Missing right curly brace '}'");
		
	return server;
}
