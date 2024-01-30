/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:18:13 by ahakam            #+#    #+#             */
/*   Updated: 2023/10/24 01:00:25 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"
#include <strings.h>

Client::Client() {
	
}

void Client::setFILE_OPENED(bool value) {
    this->FILE_OPENED = value;
}
bool Client::getFILE_OPENED() {
    return this->FILE_OPENED;
}
bool Client::getHEADER_SENT() {
    return this->HEADER_SENT;
}
void Client::setHEADER_SENT(bool value) {
    this->HEADER_SENT = value;
}
std::string Client::getRESPONSE() {
    return this->RESPONSE;
}
void Client::setRESPONSE(std::string response) {
    this->RESPONSE = response;
}
std::string Client::getBODY() {
    return this->BODY;
}
void Client::setBODY(std::string body) {
    this->BODY = body;
}
void Client::setHEADER(std::string header) {
    this->HEADER = header;
}

std::string Client::getHEADER() {
    return this->HEADER;
}


Client::Client(int connection_fd) : serverFd(connection_fd),
									addressLenght(0),
									Cresponse_size(0),
									HEADER_SENT(false),
									FILE_OPENED(false)
									 {

	bzero(&this->ClientAdd, sizeof(this->ClientAdd));
}


Client::Client(const Client &client)
									{
	*this = client;
}

Client::~Client()
{
    
}
Client &Client::operator=(const Client &client) {
	this->serverFd = client.serverFd;
	this->fdConnection = client.fdConnection;
	this->addressLenght = client.addressLenght;
	this->Cserver = client.Cserver;
	this->Cresponse_size = client.Cresponse_size;
	this->Cresponse = client.Cresponse;
	this->CRequest = client.CRequest;
	this->CRequestReady = client.CRequestReady;
	this->ClientAdd = client.ClientAdd;
	this->HEADER = client.HEADER;
	this->BODY = client.BODY;
	this->HEADER_SENT = client.HEADER_SENT;
	this->FILE_OPENED = client.FILE_OPENED;
	this->RESPONSE = client.RESPONSE;
	return (*this);
}

int Client::getServerFd() const {
	return (this->serverFd);
}

int Client::getConnectionFd() const {
	return (this->fdConnection);
}

struct sockaddr_in *Client::getClientAddress()  {
	return (&this->ClientAdd);
}

void Client::setConnectionFd(int fd) {
	this->fdConnection = fd;
}

socklen_t  *Client::getAddressLen()   {
	return (&this->addressLenght);
}

bool 	Client::ResponseReady() const {
	return (this->CRequestReady);
}

std::string Client::getResponse() {
	return (this->Cresponse);
}

size_t Client::getResponseSize() const {
	return (this->Cresponse_size);
}

void Client::setServer(const Server &server) {
	this->Cserver = server;
}

Server&	Client::getServer()  {
	return (this->Cserver);
}

HttpRequest&	Client::getRequest()  {
	return (this->CRequest);
}
void Client::setResponse(char *response, size_t size) {
	this->Cresponse = response;
	this->Cresponse_size = size;
}

