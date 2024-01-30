#include "response.hpp"

void Response::Fill_Map_Mime_Type()
{
    extensionToContentType["html"] = "text/html";
    extensionToContentType["htm"] = "text/html";
    extensionToContentType["shtml"] = "text/html";
    extensionToContentType["css"] = "text/css";
    extensionToContentType["xml"] = "text/xml";
    extensionToContentType["gif"] = "image/gif";
    extensionToContentType["jpeg"] = "image/jpeg";
    extensionToContentType["jpg"] = "image/jpeg";
    extensionToContentType["js"] = "application/javascript";
    extensionToContentType["atom"] = "application/atom+xml";
    extensionToContentType["rss"] = "application/rss+xml";
    extensionToContentType["mml"] = "text/mathml";
    extensionToContentType["txt"] = "text/plain";
    extensionToContentType["jad"] = "text/vnd.sun.j2me.app-descriptor";
    extensionToContentType["wml"] = "text/vnd.wap.wml";
    extensionToContentType["htc"] = "text/x-component";
    extensionToContentType["avif"] = "image/avif";
    extensionToContentType["png"] = "image/png";
    extensionToContentType["svg"] = "image/svg+xml";
    extensionToContentType["svgz"] = "image/svg+xml";
    extensionToContentType["tif"] = "image/tiff";
    extensionToContentType["tiff"] = "image/tiff";
    extensionToContentType["wbmp"] = "image/vnd.wap.wbmp";
    extensionToContentType["webp"] = "image/webp";
    extensionToContentType["ico"] = "image/x-icon";
    extensionToContentType["jng"] = "image/x-jng";
    extensionToContentType["bmp"] = "image/x-ms-bmp";
    extensionToContentType["woff"] = "font/woff";
    extensionToContentType["woff2"] = "font/woff2";
    extensionToContentType["jar"] = "application/java-archive";
    extensionToContentType["war"] = "application/java-archive";
    extensionToContentType["ear"] = "application/java-archive";
    extensionToContentType["json"] = "application/json";
    extensionToContentType["hqx"] = "application/mac-binhex40";
    extensionToContentType["doc"] = "application/msword";
    extensionToContentType["pdf"] = "application/pdf";
    extensionToContentType["ps"] = "application/postscript";
    extensionToContentType["eps"] = "application/postscript";
    extensionToContentType["ai"] = "application/postscript";
    extensionToContentType["rtf"] = "application/rtf";
    extensionToContentType["m3u8"] = "application/vnd.apple.mpegurl";
    extensionToContentType["kml"] = "application/vnd.google-earth.kml+xml";
    extensionToContentType["kmz"] = "application/vnd.google-earth.kmz";
    extensionToContentType["xls"] = "application/vnd.ms-excel";
    extensionToContentType["eot"] = "application/vnd.ms-fontobject";
    extensionToContentType["ppt"] = "application/vnd.ms-powerpoint";
    extensionToContentType["odg"] = "application/vnd.oasis.opendocument.graphics";
    extensionToContentType["odp"] = "application/vnd.oasis.opendocument.presentation";
    extensionToContentType["ods"] = "application/vnd.oasis.opendocument.spreadsheet";
    extensionToContentType["odt"] = "application/vnd.oasis.opendocument.text";
    extensionToContentType["pptx"] = "application/vnd.openxmlformats-officedocument.presentationml.presentation";
    extensionToContentType["xlsx"] = "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";
    extensionToContentType["docx"] = "application/vnd.openxmlformats-officedocument.wordprocessingml.document";
    extensionToContentType["wmlc"] = "application/vnd.wap.wmlc";
    extensionToContentType["wasm"] = "application/wasm";
    extensionToContentType["7z"] = "application/x-7z-compressed";
    extensionToContentType["cco"] = "application/x-cocoa";
    extensionToContentType["jardiff"] = "application/x-java-archive-diff";
    extensionToContentType["jnlp"] = "application/x-java-jnlp-file";
    extensionToContentType["run"] = "application/x-makeself";
    extensionToContentType["pl"] = "application/x-perl";
    extensionToContentType["pm"] = "application/x-perl";
    extensionToContentType["prc"] = "application/x-pilot";
    extensionToContentType["pdb"] = "application/x-pilot";
    extensionToContentType["rar"] = "application/x-rar-compressed";
    extensionToContentType["rpm"] = "application/x-redhat-package-manager";
    extensionToContentType["sea"] = "application/x-sea";
    extensionToContentType["swf"] = "application/x-shockwave-flash";
    extensionToContentType["sit"] = "application/x-stuffit";
    extensionToContentType["tcl"] = "application/x-tcl";
    extensionToContentType["tk"] = "application/x-tcl";
    extensionToContentType["der"] = "application/x-x509-ca-cert";
    extensionToContentType["pem"] = "application/x-x509-ca-cert";
    extensionToContentType["crt"] = "application/x-x509-ca-cert";
    extensionToContentType["xpi"] = "application/x-xpinstall";
    extensionToContentType["xhtml"] = "application/xhtml+xml";
    extensionToContentType["xspf"] = "application/xspf+xml";
    extensionToContentType["zip"] = "application/zip";
    extensionToContentType["bin"] = "application/octet-stream";
    extensionToContentType["exe"] = "application/octet-stream";
    extensionToContentType["dll"] = "application/octet-stream";
    extensionToContentType["deb"] = "application/octet-stream";
    extensionToContentType["dmg"] = "application/octet-stream";
    extensionToContentType["iso"] = "application/octet-stream";
    extensionToContentType["img"] = "application/octet-stream";
    extensionToContentType["msi"] = "application/octet-stream";
    extensionToContentType["msp"] = "application/octet-stream";
    extensionToContentType["msm"] = "application/octet-stream";
    extensionToContentType["mid"] = "audio/midi";
    extensionToContentType["midi"] = "audio/midi";
    extensionToContentType["kar"] = "audio/midi";
    extensionToContentType["mp3"] = "audio/mpeg";
    extensionToContentType["ogg"] = "audio/ogg";
    extensionToContentType["m4a"] = "audio/x-m4a";
    extensionToContentType["ra"] = "audio/x-realaudio";
    extensionToContentType["3gpp"] = "video/3gpp";
    extensionToContentType["3gp"] = "video/3gpp";
    extensionToContentType["ts"] = "video/mp2t";
    extensionToContentType["mp4"] = "video/mp4";
    extensionToContentType["mpeg"] = "video/mpeg";
    extensionToContentType["mpg"] = "video/mpeg";
    extensionToContentType["mov"] = "video/quicktime";
    extensionToContentType["webm"] = "video/webm";
    extensionToContentType["flv"] = "video/x-flv";
    extensionToContentType["m4v"] = "video/x-m4v";
    extensionToContentType["mng"] = "video/x-mng";
    extensionToContentType["asx"] = "video/x-ms-asf";
    extensionToContentType["asf"] = "video/x-ms-asf";
    extensionToContentType["wmv"] = "video/x-ms-wmv";
    extensionToContentType["avi"] = "video/x-msvideo";
}

Response::Response(Client &client) : client(client), cookies("")
{
    Fill_Map_Mime_Type();
}

std::string Response::decodeURI()
{
    std::string decodedURI;
    char hex[3] = {0};

    for (size_t i = 0; i < client.getRequest().get_uri().length(); ++i)
    {
        if (client.getRequest().get_uri()[i] == '%' && i + 2 < client.getRequest().get_uri().length())
        {
            hex[0] = client.getRequest().get_uri()[i + 1];
            hex[1] = client.getRequest().get_uri()[i + 2];
            decodedURI += static_cast<char>(strtol(hex, NULL, 16));
            i += 2;
        }
        else
        {
            decodedURI += client.getRequest().get_uri()[i];
        }
    }
    return decodedURI;
}

void Response::_Response()
{
    if (Check_location().empty())
    {
        Build_HTTP_Response(404);
        return;
    }

    if (client.getRequest().get_bodysize() > client.getServer().get_bodySize())
    {
        Build_HTTP_Response(413);
        return;
    }

    if (!client.getServer().get_location()[X].get_redirection().empty())
    {
        client.setHEADER(Build_HTTP_Response_Header(301, "text/html", ""));
        return;
    }

    if (client.getRequest().get_httpMethod() == "GET")
    {
        METHOD_GET();
        return;
    }
    else if (client.getRequest().get_httpMethod() == "DELETE")
    {
        METHOD_DELETE();
        return;
    }

    else if (client.getRequest().get_httpMethod() == "POST")
    {
        METHOD_POST();
        return;
    }

    Build_HTTP_Response(405);
    return;
}

bool Response::is_Character_Allowed(char c)
{
    const std::string allowedCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-._~:/?#[]@!$&'()*+,;=%";

    // Recherchez le caractère dans la chaîne des caractères autorisés
    return allowedCharacters.find(c) != std::string::npos;
}

bool Response::is_URI_Valid()
{
    std::string tab = client.getRequest().get_uri();
    // Parcourez chaque caractère de l'uri
    for (unsigned long i = 0; i < tab.length(); ++i)
    {
        if (!is_Character_Allowed(tab[i]))
        {
            return false; // Caractère non autorisé trouvé
        }
    }
    return true; // Tous les caractères sont autorisés
}

std::string Response::Header_status_code(int code)
{
    if (code == 404)
        return "HTTP/1.1 404 Not Found\r\n";
    else if (code == 200)
        return "HTTP/1.1 200 OK\r\n";
    else if (code == 201)
        return "HTTP/1.1 201 Created\r\n";
    else if (code == 204)
        return "HTTP/1.1 204 No Content\r\n";
    else if (code == 301)
        return "HTTP/1.1 301 Moved Permanently\r\n";
    else if (code == 400)
        return "HTTP/1.1 400 Bad Request\r\n";
    else if (code == 403)
        return "HTTP/1.1 403 Forbidden\r\n";
    else if (code == 405)
        return "HTTP/1.1 405 Method Not Allowed\r\n";
    else if (code == 409)
        return "HTTP/1.1 409 Conflict\r\n";
    else if (code == 413)
        return "HTTP/1.1 413 Payload Too Large\r\n";
    else if (code == 501)
        return "HTTP/1.1 501 Not Implemented\r\n";
    else if (code == 504)
        return "HTTP/1.1 504 Gateway Timeout\r\n";
    else if (code == 500)
        return "HTTP/1.1 500 Internal Server Error server\r\n";
    return ("");
}

bool isDirectory(std::string path)
{
    struct stat path_stat;
    stat(path.c_str(), &path_stat);
    return (S_ISDIR(path_stat.st_mode));
}

std::string Response::Folder_OR_File()
{
    struct stat st;
    if (lstat(client.getRequest().get_uri().c_str(), &st) != 0)
        return "File";
    else if (S_ISDIR(st.st_mode))
        return "Folder";
    else if (S_ISREG(st.st_mode))
        return "File";
    else
        return "UNKNOWN";
}

std::string Response::Generate_date()
{
    time_t t = time(0);
    struct tm *current_time = localtime(&t);
    char date_buffer[80];
    strftime(date_buffer, sizeof(date_buffer), "%a, %d %b %Y %H:%M:%S GMT", current_time);
    return (std::string(date_buffer));
}

std::string Response::Build_HTTP_Response_Header(int status_code, std::string content_type, std::string content_lenght)
{
    std::string HEADER_RESPONSE;

    HEADER_RESPONSE = Header_status_code(status_code);
    if (!this->cookies.empty())
        HEADER_RESPONSE += this->cookies + "\r\n";

    HEADER_RESPONSE += "Content-Type: " + content_type + "\r\n";
    HEADER_RESPONSE += "Content-Lenght: " + content_lenght + "\r\n";
    if (X != -42)
    {
        if (!client.getServer().get_location()[X].get_redirection().empty())
        {

            HEADER_RESPONSE += "Location: " + client.getServer().get_location()[X].get_redirection() + "\r\n";
        }
        else if (code_301 == 301)
        {
            HEADER_RESPONSE += "Location: " + client.getRequest().get_uri().substr(client.getServer().get_location()[X].get_root().size()) + "/" + "\r\n";
        }
    }
    HEADER_RESPONSE += "Server: webserv\r\n";
    HEADER_RESPONSE += "Cache-Control: public, max-age=14400\r\n";
        HEADER_RESPONSE += "Date: " + Generate_date() + "\r\n\r\n";

    return (HEADER_RESPONSE);
}

void Response::Build_HTTP_Response(int statusCode)
{
    std::ostringstream oss;
    oss << statusCode;
    std::string statusCodeStr = oss.str();
    std::string File_Name = Get_File_Name_From_URI();

    std::string File_Extension = Get_File_Extension(File_Name);
    std::string errorPagePath = Find_Error_Page(statusCodeStr);
    std::string contentLength;
    struct stat fileStat;
    if (stat(errorPagePath.c_str(), &fileStat) == 0) 
    {
        std::ostringstream oss;
        oss << fileStat.st_size;
        contentLength = oss.str();
    }
    client.setHEADER(Build_HTTP_Response_Header(statusCode, "text/html", contentLength));
    client.setBODY(errorPagePath);
}

int Response::Check_method_config(std::string m)
{
    Location &current_location = client.getServer().get_location()[X];

    if (current_location.get_methods().empty())
    {
        return 0;
    }

    for (size_t i = 0; i < current_location.get_methods().size(); i++)
    {
        if (current_location.get_methods()[i] == m)
        {
            return 1;
        }
    }

    return 0;
}

std::string Response::Find_Error_Page(std::string Error_code)
{
    if (X == -42)
        return ("");
    std::string path;

    for (size_t i = 0; i < client.getServer().get_location()[X].get_errorPage().size(); ++i)
    {
        for (size_t j = 0; j < client.getServer().get_location()[X].get_errorPage()[i].first.size(); j++)
        {
            if (client.getServer().get_location()[X].get_errorPage()[i].first[j] == Error_code)
            {
                path = client.getServer().get_location()[X].get_root() + client.getServer().get_location()[X].get_errorPage()[i].second + "/" + Error_code + ".html";
                return Clean_URI(path);
            }
        }
    }
    return ("");
}

std::string Response::Clean_URI(std::string &uri)
{
    std::string cleanedURI;
    bool previousCharWasSlash = false;

    for (std::string::iterator it = uri.begin(); it != uri.end(); ++it)
    {
        char c = *it;
        if (c != '/')
        {
            cleanedURI.push_back(c);
            previousCharWasSlash = false;
        }
        else if (!previousCharWasSlash)
        {
            cleanedURI.push_back(c);
            previousCharWasSlash = true;
        }
    }
    return cleanedURI;
}

std::string Response::Check_location()
{
    X = -42;
    std::string location;

    for (size_t i = 0; i < client.getServer().get_location().size(); i++)
    {
        if (client.getRequest().get_uri().find(client.getServer().get_location()[i].get_path()) == 0)
        {
            if (client.getRequest().get_uri().size() > client.getServer().get_location()[i].get_path().size() && client.getServer().get_location()[i].get_path() != "/" && client.getRequest().get_uri()[client.getServer().get_location()[i].get_path().size()] != '/');
            else if (client.getServer().get_location()[i].get_path().size() > location.size())
            {
                location = client.getServer().get_location()[i].get_path();
                X = i;
            }
        }
    }
    if (X == -42 || client.getServer().get_location()[X].get_root().empty())
        client.getRequest().get_uri() = "";
    else if (client.getRequest().get_uri().find(client.getServer().get_location()[X].get_root()) != std::string::npos)
        client.getRequest().get_uri() = client.getRequest().get_uri();
    else
        client.getRequest().get_uri() = client.getServer().get_location()[X].get_root() + "/" + client.getRequest().get_uri().substr(location.size());
    client.getRequest().get_uri() = Clean_URI(client.getRequest().get_uri());
    return client.getRequest().get_uri();
}

