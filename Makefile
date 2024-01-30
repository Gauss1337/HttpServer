# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: AAIT-MAS <AAIT-MAS@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 02:01:35 by ahakam            #+#    #+#              #
#    Updated: 2023/10/16 23:00:53 by AAIT-MAS         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = webserv

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3 $(shell pkill webserv)

SRC =  networking/Network.cpp networking/httpServer.cpp networking/server_linux.cpp networking/Client.cpp \
      ./parsing/parseConfig/config_parsing.cpp ./parsing/Utils/utils.cpp\
      ./parsing/parseConfig/Server.cpp ./parsing/parseConfig/parse_server.cpp\
      ./parsing/parseConfig/Location.cpp ./parsing/parseConfig/parse_location.cpp\
      ./parsing/parseRequest/Request.cpp ./Response/METHOD_GET.cpp ./Response/METHOD_POST.cpp\
      ./Response/METHODE_DELETE.cpp ./Response/response.cpp ./cgi/CGI.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
