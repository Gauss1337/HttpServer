/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:18:15 by ahakam            #+#    #+#             */
/*   Updated: 2023/10/24 01:03:08 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP 

#include <netinet/in.h> 
#include <time.h>
#include <stdlib.h>
#include "../parsing/webserv.hpp"
#ifndef BUFFER_SIZE 
# define BUFFER_SIZE  1024
#endif 

class HttpRequest;
class Server;
class Location;

class Client {

	private:
		int 				serverFd;			 	
		int 				fdConnection; 		
		socklen_t 			addressLenght;
		struct sockaddr_in  ClientAdd;
		Server				Cserver;
		std::string 		Cresponse;
		size_t				Cresponse_size;
		HttpRequest			CRequest;
		bool				CRequestReady;
		std::string			HEADER;
		std::string			BODY;
		std::string			RESPONSE;
		bool				HEADER_SENT;
		bool				FILE_OPENED;

		public:
		void				setFILE_OPENED(bool);
		bool				getFILE_OPENED();
		bool				getHEADER_SENT();
		void				setHEADER_SENT(bool);
		std::string			getRESPONSE();
		void				setRESPONSE(std::string);
		std::string			getBODY();
		void				setBODY(std::string);
		void				setHEADER(std::string);
		std::string			getHEADER();
		int 				bytes_sent;
		int					bytes_read;
		std::ifstream 		file;
		char _buffer[BUFFER_SIZE];
		Client();
		~Client();
		Client(int connection_fd);
		Client(const Client &client);
		Client &operator=(const Client &client);

	public:
		struct sockaddr_in*		getClientAddress() ;
		socklen_t*				getAddressLen() ;
		void 					setConnectionFd(int fd);
		int						getServerFd() const;
		int						getConnectionFd() const ;
		time_t					getClientRequestTimeout() const;
		short					getRequestStatus() const;
	    Server&					getServer() ;
		void 					saveRequestData(size_t nb_bytes);
		void					setRequestStatus(short error_num);
		void					setServer(const Server &server);
		std::string					getResponse();
		 HttpRequest&			getRequest() ;
		size_t					getResponseSize() const ;
		void					setResponse(char *response, size_t size);
		bool					ResponseReady() const;

		void setResponseee(std::string str)
		{
			Cresponse = str;
		}

};


#endif
