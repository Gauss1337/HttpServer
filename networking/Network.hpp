/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Network.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:59:21 by ahakam            #+#    #+#             */
/*   Updated: 2023/10/01 23:24:48 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include <netinet/ip.h>
#include <fcntl.h>
#include <strings.h>
#include "Client.hpp"

namespace Network
{
    int CreateSocket();
    void BindSocket(int sock_fd, short port, const std::string &address);
    void ListenOnSocket(int sock_fd);
    Client acceptConnection(int sock_fd);
    void closeConnection(int fd);
    int getSocketBufferSize(int socket_fd, int io_type);
}

#endif
