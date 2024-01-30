/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httpServer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:31:11 by ahakam            #+#    #+#             */
/*   Updated: 2023/10/24 03:15:57 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTPSERVER_HPP
#define HTTPSERVER_HPP

#include "Client.hpp"
#include "Network.hpp"
#include <algorithm>
#include <sstream>
#include "../Response/response.hpp"
#include <signal.h>

class Client;
class ParseConf;

class HttpServer
{
    std::map<int, Client> Mclient;
    fd_set ReadSet;
    fd_set ServerSet;
    fd_set WriteSet;
    ParseConf Config;
    std::vector<Server> &Vserver;
    std::vector<int> 			_server_fds;
    int MaxFd;
    public :
    HttpServer(ParseConf &pars);
    typedef std::map<int, Client>::iterator iteratorCl ;
    ~HttpServer();
    void addSocketFd(int fd);
    void  RunServer();
    void CheckRequestStatus(Client &client);
    void  selectServer(fd_set &Readcpy,fd_set &Writecpy);
    void addClient_to_map(Client client);
  const Server &MatchServerbyFd(int fd);
    const Server &MatchServerbyName(std::string);
    void  sendResponse(Client &client);
    std::string buildResponse();
    void log(const std::string &message)
    {
      std::cout << message << std::endl;
    }
    Client &GetRightClient(int fd);
    void   readRequest(int fd);
    void CloseConnection(int fd);

};

class ClientError : public std::exception {
	private:
		const  char *_error;
	public:
		ClientError(const char * error) : _error(error) {
		}
		ClientError(const ClientError &error_log) : _error(error_log._error) { } const char *what() const throw() {
			return  this->_error;
		}
};
class RequestError {
	private:
		int _error_number;

	public:
		RequestError(int error_number) : _error_number(error_number) {
		}
		int getErrorNumber() const  {
			return (this->_error_number);
		}
};

#endif
