/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_linux.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:02:15 by ahakam            #+#    #+#             */
/*   Updated: 2023/10/24 03:15:40 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "httpServer.hpp"

int main(int argc, char **argv)
{
    try
    {
        ParseConf pars;
        pars.parsing(argc,argv);
        HttpServer server(pars);
        server.RunServer();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }   
}