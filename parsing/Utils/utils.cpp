#include "../webserv.hpp"

int check_file(std::ifstream &conffile, int argc, char **argv)
{
	std::string filename("parsing/configs/default.conf");
	
	if (argc == 2)
	{
		conffile.open(argv[1]);
		if (!conffile)
			throw ConfigFileExecption(filename + ": No such file or permission denied!");
		return 0;
	}
	conffile.open(filename.c_str());
	if (!conffile)
		throw ConfigFileExecption(filename + ": No such file or permission denied!");
	return 0;
}

void trim_front(std::string &str)
{
	std::size_t i = 0;
	while (i < str.size() && (str[i] == ' ' || str[i] == '\t'))
		i++;
	str = str.substr(i);
}

void trim_back(std::string &str)
{
	std::size_t pos;

	pos = str.size();
	while (pos > 0 && (str[pos - 1] == ' ' || str[pos - 1] == '\t'))
		pos--;
	if (pos == 0)
		return;
	// sus error
	str = str.substr(0, pos);
}

void str_trim(std::string &str)
{
	trim_front(str);
	trim_back(str);
}

std::vector<std::string> split(std::string &str, char delim)
{
	std::vector<std::string> split_str;
	std::string tmp;
	size_t pos;

	pos = str.find(delim);
	while (pos != std::string::npos)
	{
		tmp = str.substr(0, pos);
		str = str.substr(pos + 1);
		split_str.push_back(tmp);
		pos = str.find(delim);
	}
	split_str.push_back(str);
	return split_str;
}

bool isHexadecimal(std::string &str)
{

	if (str.empty())
		return false;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isxdigit(str[i]))
			return false;
	}
	return true;
}

bool isNumber(std::string &str)
{

	if (str.empty())
		return false;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

std::string Generate_Random_File_Name()
{
	const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	const int charsetSize = sizeof(charset) - 1;
	const int fileNameLength = 7;
	std::string randomFileName;

	std::srand(static_cast<unsigned int>(std::time(0)));

	for (int i = 0; i < fileNameLength; ++i)
	{
		int randomIndex = std::rand() % charsetSize;
		randomFileName += charset[randomIndex];
	}
	return randomFileName;
}
