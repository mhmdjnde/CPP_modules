#include <iostream>
#include <fstream>

class FileTools{
	public:
		std::string rfile;
		std::string wfile;
		std::string rcontent;
		std::string wcontent;
		void	open_and_read();
		void	open_and_write();
		void	edit_wcontent(std::string s1, std::string s2);
};

void	FileTools::open_and_read()
{
	std::string buffer;
	std::ifstream rf(rfile.c_str());
	if (!rf.is_open())
	{
		std::cout << "Error: Unable to open file for reading." << std::endl;
		return ;
	}
	while (getline(rf, buffer))
		rcontent += buffer + "\n";
	rf.close();
	wcontent = rcontent;
}

void	FileTools::edit_wcontent(std::string s1, std::string s2)
{
	std::string temp;
	size_t i = 0;
	while (i < wcontent.length())
	{
		if (wcontent.compare(i, s1.length(), s1) == 0)
		{
			temp += s2;
			i += s1.length();
		}
		else
		{
			temp += wcontent[i];
			i++;
		}
	}
	wcontent = temp;
}

void	FileTools::open_and_write()
{
	wfile = rfile + ".replace";
	std::ofstream wf(wfile.c_str(), std::ios::out | std::ios::trunc);
	if (!wf.is_open())
	{
		std::cout << "Error: Unable to open file for writing." << std::endl;
		return ;
	}
	wf << wcontent;
	wf.close();
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "usage: ./replace  <rfile> <s1> <s2>" << std::endl;
		return 1;
	}
	FileTools f;
	f.rfile = av[1];
	f.open_and_read();
	f.edit_wcontent(av[2], av[3]);
	f.open_and_write();
}
