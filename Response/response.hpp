#pragma once

#include <string>
#include <map>
#include <cstring>      // Pour C-style strings
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>     // Pour les opérations d'entrée/sortie
#include <sstream>      // Pour les opérations de flux
#include <string>       // Pour les opérations de chaînes de caractères
#include <dirent.h>		// Pour la gestion des répertoires (DIR, dirent, opendir, readdir, closedir)
#include <unistd.h>     // Ajout de cette inclusion pour les constantes de mode
#include "../parsing/parseConfig/Server.hpp"
#include "../networking/Client.hpp"
#include "../cgi/CGI.hpp"

class Client;

class Response
{
	private:

		Client& client;
		int code_301;
		int X;
		std::string boundary;
		std::string Body_boundary;
		std::map<std::string, std::string> extensionToContentType;
		std::map<std::string ,std::string> map_bdry_header;
		std::string cookies;
		

    public:

    
		void	_Response();	
		Response(Client &client);
		void Fill_Map_Mime_Type();
		std::string Check_location();
		std::string Clean_URI(std::string &uri);
		std::string Find_Error_Page(std::string error_code);
		void	Build_HTTP_Response(int statusCode);
		std::string Build_HTTP_Response_Header(int code, std::string content_type, std::string content_lenght);
		std::string Generate_date();
		std::string Header_status_code(int code);
		std::string Folder_OR_File();
		std::string Moved_Permanently();
		std::string decodeURI();
		std::string handle_uri();



		bool is_Character_Allowed(char c);
		bool is_URI_Valid();

		int Check_method_config(std::string m);


		// METHODE GET
		void METHOD_GET();
		std::string Get_File_Name_From_URI();
		std::string Get_File_Extension(std::string File_Name);
		std::string GetContentTypeFromExtension(const std::string& fileExtension);
		void Auto_index_of_Directory();
		std::string GetLastDirectoryName();
		void GET_FILE();
		void GET_FOLDER();

		//METHOD DELETE
		void	METHOD_DELETE();
		bool check_permission();



		// METHOD POST
		void	METHOD_POST();
		std::string Generate_Random_File_Name();
		void post_file();


void setServer(Server&);
void setRequest(HttpRequest&);
//void setClient(Client&);

};
std::string extractHeaders(std::string httpResponse);
std::string findContentType(std::string response);