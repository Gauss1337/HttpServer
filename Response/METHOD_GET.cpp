#include "response.hpp"
#include <iostream>
#include <cstdio> // Pour les fonctions C de gestion de fichiers temporaires
#include <sstream>
#include <cstring>

std::string Response::GetContentTypeFromExtension(const std::string &fileExtension)
{

    // Recherche du type de contenu correspondant à l'extension

    std::string lowerCaseExtension = fileExtension;
    for (size_t i = 0; i < lowerCaseExtension.length(); ++i)
    {
        lowerCaseExtension[i] = tolower(lowerCaseExtension[i]);
    }

    std::map<std::string, std::string>::iterator it = extensionToContentType.find(lowerCaseExtension);
    if (it != extensionToContentType.end())
    {
        return it->second; // Type de contenu trouvé eeeejj
    }
    else
    {
        return "text/html"; // Type de contenu par défaut pour les extensions inconnues eeejjj
    }
}

void Response::METHOD_GET()
{
    std::string GET_FILEE;
    std::string GET_FOLDERR;

    if (Check_method_config("GET") == 0)
    {
        Build_HTTP_Response(405); return;
        return;
    }

    std::string type_resource = Folder_OR_File();
    if (type_resource == "File")
    {
        GET_FILE();
        return;
    }

    else if (type_resource == "Folder")
    {
        GET_FOLDER();
        return;
    }

    Build_HTTP_Response(404);
    return;
}

std::string Response::GetLastDirectoryName()
{
    size_t lastSlashPos = client.getRequest().get_uri().find_last_of('/');

    // Si lastSlashPos n'est pas npos (c'est-à-dire si un '/' a été trouvé)
    if (lastSlashPos != std::string::npos)
    {
        // Trouver la position du précédent '/'
        size_t secondLastSlashPos = client.getRequest().get_uri().find_last_of('/', lastSlashPos - 1);

        // Si secondLastSlashPos n'est pas npos (c'est-à-dire si un '/' précédent a été trouvé)
        if (secondLastSlashPos != std::string::npos)
        {
            // Extraire la sous-chaîne entre le précédent '/' et le dernier '/'
            std::string lastDir = client.getRequest().get_uri().substr(secondLastSlashPos + 1, lastSlashPos - secondLastSlashPos - 1);

            // Si la sous-chaîne extraite n'est pas vide
            if (!lastDir.empty())
            {
                return lastDir;
            }
        }
    }
    // Si aucun '/' précédent n'a été trouvé ou si la sous-chaîne extraite est vide, retourner une chaîne vide
    return "";
}

void Response::Auto_index_of_Directory()
{
    const std::string &fullURI = client.getRequest().get_uri();
    // Extraire le nom du répertoire à partir de l'uri
    std::size_t lastSlashPos = fullURI.find_last_of('/');
    std::string directory = (lastSlashPos != std::string::npos) ? fullURI.substr(0, lastSlashPos + 1) : "";
    std::string lastDirectoryName = GetLastDirectoryName();
    // std::cout << lastDirectoryName << std::endl;
    std::ostringstream htmlfile;
    // htmlfile << "<!DOCTYPE html>\n<html lang=\"en\">\n\t<head>\n\t\t<title>Index of " << lastDirectoryName << "</title>\n";
    htmlfile << "<!DOCTYPE html>\n<html lang=\"en\">\n\t<head>\n";
    htmlfile << "\t\t<meta charset=\"UTF-8\">\n"; // Spécifiez l'encodage UTF-8
    htmlfile << "\t\t<title>Index of " << lastDirectoryName << "</title>\n";

    // Ajouter du style CSS pour décaler les puces vers la droite
    htmlfile << "\t\t<style>\n";
    htmlfile << "\t\t\t.list-item { margin-left: 20px; }\n"; // Réglez la valeur selon votre préférence
    htmlfile << "\t\t</style>\n";
    htmlfile << "\t</head>\n\t<body>\n";
    htmlfile << "\t\t<h1>Index of   /" << lastDirectoryName << "</h1>\n";
    // Ajouter une ligne horizontale
    htmlfile << "\t\t<hr>\n";
    // Ajouter un retour à la ligne
    htmlfile << "\t\t<br>\n";

    // Ajouter l'entrée "/." (répertoire courant)
    htmlfile << "\t\t<span class='list-item'>• <a href='./'>./</a></span><br /><br />\n";

    // Si le répertoire courant n'est pas la racine, ajouter l'entrée "/.." (répertoire parent)
    if (directory != "/")
    {
        htmlfile << "\t\t<span class='list-item'>• <a href='../'>../</a></span><br /><br />\n";
    }

    FILE *dirlist = popen(("ls -p " + directory).c_str(), "r");
    if (dirlist)
    {
        char file[1024];
        while (fgets(file, sizeof(file), dirlist))
        {
            file[strlen(file) - 1] = '\0'; // Remove newline character

            std::string fileName(file);
            if (fileName != "." && fileName != "..")
            {
                struct stat file_stat;
                if (lstat((directory + fileName).c_str(), &file_stat) == 0)
                {
                    if (S_ISDIR(file_stat.st_mode))
                        htmlfile << "\t\t<span class='list-item'>• <a href='" << fileName << "/'>" << fileName << "/</a></span><br /><br />\n";
                    else
                        htmlfile << "\t\t<span class='list-item'>• <a href='" << fileName << "'>" << fileName << "</a></span><br /><br />\n";
                }
            }
        }
        pclose(dirlist);
    }
    htmlfile << "\t</body>\n</html>";
    int content_length = htmlfile.str().size();
    std::ostringstream CL;
    CL << content_length;

    char tempDirTemplate[] = "/tmp/tempdirXXXXXX";
    char *tempDir = mkdtemp(tempDirTemplate);
    if (tempDir)
    {
        chmod(tempDir, S_IRWXU | S_IRWXG | S_IRWXO);
        // Créer le chemin complet du fichier HTML
        char tempFileName[1024];
        std::strcpy(tempFileName, tempDir);
        std::strcat(tempFileName, "/index.html");

        FILE *tempFile = std::fopen(tempFileName, "w");
        if (tempFile)
        {
            std::fputs(htmlfile.str().c_str(), tempFile);
            std::fclose(tempFile);
            client.setBODY(tempFileName); // Affecter le chemin du fichier temporaire à client.BODY
        }
        else
        {
            // Gérer l'erreur ici, par exemple :
            std::cerr << "Erreur lors de la création du fichier temporaire." << std::endl;
        }
    }
    else
    {
        // std::cerr << "Impossible de créer un répertoire temporaire." << std::endl;
    }

    client.setHEADER(Build_HTTP_Response_Header(200, "text/html", CL.str()));
}

std::string Response::Get_File_Name_From_URI()
{
    size_t lastSlashPos = client.getRequest().get_uri().find_last_of('/');

    if (lastSlashPos != std::string::npos)
    {
        return client.getRequest().get_uri().substr(lastSlashPos + 1);
    }

    const char *cstr = client.getRequest().get_uri().c_str();
    const char *fileName = std::strrchr(cstr, '/');

    if (fileName)
    {
        return fileName + 1;
    }

    return client.getRequest().get_uri();
}

std::string Response::Get_File_Extension(std::string File_Name)
{
    std::string::size_type pos_dot = File_Name.rfind('.');
    if (pos_dot != std::string::npos && pos_dot != File_Name.length() - 1)
    {
        return File_Name.substr(pos_dot + 1);
    }
    return ""; // Pas d'extension ou extension vide
}

std::string extractBody(std::string httpResponse)
{
    size_t bodyStart = httpResponse.find("\r\n\r\n");
    if (bodyStart == std::string::npos)
    {
        return "";
    }
    std::string body = httpResponse.substr(bodyStart + 4); // Skip the double newline
    return body;
}

std::string extractHeaders(std::string httpResponse)
{
    size_t end_headers = httpResponse.find("\r\n\r\n");
    if (end_headers == std::string::npos)
        return "";
    else
        return httpResponse.substr(0, end_headers);
}

std::string findContentType(std::string response)
{
    std::istringstream responseStream(response);
    std::string line;
    std::string contentType;

    while (std::getline(responseStream, line))
    {
        // Recherche du champ "Content-Type" (insensible à la casse)
        if (strncasecmp(line.c_str(), "Content-Type:", 12) == 0)
        {
            size_t pos = line.find(':');
            if (pos != std::string::npos)
            {
                contentType = line.substr(pos + 1);

                // Supprime les espaces autour de la valeur du champ
                size_t firstNonSpace = contentType.find_first_not_of(" \t");
                size_t lastNonSpace = contentType.find_last_not_of(" \t");
                if (firstNonSpace != std::string::npos && lastNonSpace != std::string::npos)
                {
                    contentType = contentType.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);

                    // Chercher la position du premier point-virgule
                    size_t semicolonPos = contentType.find(';');
                    if (semicolonPos != std::string::npos)
                    {
                        // Extraire la sous-chaîne avant le point-virgule
                        contentType = contentType.substr(0, semicolonPos);
                    }
                }
                break;
            }
        }
    }
    return contentType;
}

void Response::GET_FILE()
{  
    std::ifstream fileStream(client.getRequest().get_uri().c_str());
    std::string filePath = client.getRequest().get_uri();
    std::string File_Name = Get_File_Name_From_URI();
    std::string File_Extension = Get_File_Extension(File_Name);
    if (!fileStream.is_open())
    {
        Build_HTTP_Response(404);
        return;
    }
    if (File_Extension == "php" || File_Extension == "py")
    {
        size_t pos;
        CGI cgi(client);
            cgi.set_environmentVariables(File_Name);
            cgi.run();
            if (cgi.status_code != 200)
            {  
                //std::cout << cgi.status_code << std::endl;
                Build_HTTP_Response(cgi.status_code);
                return;
            }
        std::string cgi_headers = extractHeaders(client.getResponse());
        pos = cgi_headers.find("Set-Cookie");
        if (pos != std::string::npos)
        {
            cgi_headers = cgi_headers.substr(pos);
            pos = cgi_headers.find("\r\n");
            this->cookies = cgi_headers.substr(0, pos);
        }
        std::string response_cgi = client.getResponse();
        std::string c_t = findContentType(response_cgi);
        client.setBODY(extractBody(client.getResponse()));
        std::stringstream ss;
        ss << client.getBODY().length();
        std::string body_length = ss.str();
        client.setHEADER(Build_HTTP_Response_Header(200, c_t, body_length));
        return;
    }

  

    std::string contentLength;
    struct stat fileStat;
    if (stat(filePath.c_str(), &fileStat) == 0)
    {
        std::ostringstream oss;
        oss << fileStat.st_size;
        contentLength = oss.str();
        // std::cout << "Longueur du fichier : " << contentLength << " octets" << std::endl;
    }
    client.setHEADER(Build_HTTP_Response_Header(200, GetContentTypeFromExtension(File_Extension), contentLength));
    client.setBODY(client.getRequest().get_uri());
}

void Response::GET_FOLDER()
{
    if (client.getRequest().get_uri()[client.getRequest().get_uri().size() - 1] != '/')
    {
        client.getRequest().get_uri()[client.getRequest().get_uri().size() - 1] += '/';
        code_301 = 301;
        Build_HTTP_Response(301);
    }

    if (client.getServer().get_location()[X].get_index().size() != 0) // Vector index not empty
    {
        std::string New_URI;

        for (size_t i = 0; i < client.getServer().get_location()[X].get_index().size(); i++)
        {
            New_URI = client.getRequest().get_uri() + client.getServer().get_location()[X].get_index()[i];
            New_URI = Clean_URI(New_URI);

            std::ifstream file(New_URI.c_str());

            if (file.is_open())
            {
                code_301 = 200;
                client.getRequest().get_uri() = New_URI;
                file.close();
                GET_FILE();
                return;
            }
        }
    }

    else if (client.getServer().get_location()[X].get_autoindex() == "ON")
    {
        Auto_index_of_Directory();
        return;
    }

    else if (client.getServer().get_location()[X].get_autoindex() == "OFF")
    {
        Build_HTTP_Response(403);
        return;
    }

    Build_HTTP_Response(404);
    return;
}