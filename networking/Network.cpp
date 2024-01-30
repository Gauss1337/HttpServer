/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Network.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:20:33 by ahakam            #+#    #+#             */
/*   Updated: 2023/10/03 01:09:19 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Network.hpp"
#include "httpServer.hpp"

namespace Network
{
    int CreateSocket() {
       int sock_fd;
		sock_fd = socket(PF_INET, SOCK_STREAM, 0); 
		if (sock_fd < 0) {
			throw(ClientError("Error : socket not created!"));
		}
		return (sock_fd);
    }

void BindSocket(int sock_fd, short port, const std::string &address) {
    int bind_stat;
	struct sockaddr_in sock_addr;

	bzero(&sock_addr, sizeof(sock_addr));
	sock_addr.sin_family = AF_INET;
	sock_addr.sin_port = htons(port);
	if (inet_aton(address.c_str(), &sock_addr.sin_addr) == 0) { 
		throw(ClientError("Error: address invalid!"));
		close(sock_fd);
	}
	bind_stat = bind(sock_fd, (struct sockaddr *) &sock_addr, sizeof(sockaddr)); 
	if (bind_stat == -1) {
		close(sock_fd);
		throw(ClientError("Error: Failed to bind socket"));
	}
	int flags = fcntl(sock_fd, F_GETFL, 0);
    if (flags == -1)
        throw (ClientError("Error :Failed to get flags for server socket"));
    flags |= O_NONBLOCK;
    if (fcntl(sock_fd, F_SETFL, flags) == -1)
		throw (ClientError("Error :Failed to set server socket to non-blocking mode"));
}

void ListenOnSocket(int sock_fd) {
    int listen_stat;
	listen_stat = listen(sock_fd, SOMAXCONN);
	if (listen_stat == -1) {
	throw(ClientError("Error: failed to liten on socket"));
	}
}

Client acceptConnection(int sock_fd) {
    int connection_fd;

	Client new_client(sock_fd) ;
	connection_fd = accept(sock_fd, (struct sockaddr *) new_client.getClientAddress(), new_client.getAddressLen());
	fcntl(connection_fd, F_SETFL, O_NONBLOCK);
	if (connection_fd == -1) {
		close(sock_fd);
		throw(ClientError("Error: failed to liten on socket"));
	}
	new_client.setConnectionFd(connection_fd);
		return (new_client);
}

void closeConnection(int fd) {
    close(fd);
}
}


