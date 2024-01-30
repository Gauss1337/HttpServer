#include "response.hpp"
#include <map>


bool Response::check_permission() 
{
    struct stat fileInfo;

    // Utiliser stat pour obtenir les informations sur le fichier
    if (stat(client.getRequest().get_uri().c_str(), &fileInfo) != 0) {
        // Erreur lors de l'obtention des informations sur le fichier
       // std::cerr << "Erreur lors de la récupération des informations sur le fichier." << std::endl;
        return false;
    }

    // Vérifier si le fichier est régulier
    if (!S_ISREG(fileInfo.st_mode)) {
       // std::cerr << "Le chemin spécifié ne pointe pas vers un fichier régulier." << std::endl;
        return false;
    }

    // Vérifier les permissions de suppression (écriture)
    if (!(fileInfo.st_mode & S_IWUSR)) {
       // std::cerr << "Vous n'avez pas la permission de supprimer ce fichier." << std::endl;
        return false;
    }

    // Si toutes les vérifications réussissent, vous pouvez supprimer le fichier
    return true;
}


void Response::METHOD_DELETE()
{
    if (Check_method_config("DELETE") == 0)
    {
        Build_HTTP_Response(405); return;
    }

    if (Folder_OR_File() == "Resource Not Found")
    {
        Build_HTTP_Response(404); return;
    }

    if (Folder_OR_File() == "Folder")
    {
        Build_HTTP_Response(403); return;
    }

    if (Folder_OR_File() == "File")
    {
        if (check_permission())
        {
            if (std::remove(client.getRequest().get_uri().c_str()) == 0) 
            {
                client.setHEADER(Build_HTTP_Response_Header(204, "text/html", "0.0"));
                return ;
            } 
            else 
            {
                Build_HTTP_Response(403); return;
            }
        }
    }
    Build_HTTP_Response(403); return;
}