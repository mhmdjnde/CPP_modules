#include <iostream>

class Contact{
	public:
		std::string fname;
		std::string lname;
		std::string nname;
		std::string pnum;
		std::string secret;
};

void	print_with_rules(std::string str, int f)
{
	if (str.length() > 10)
	{
		std::cout << str.substr(9);
		std::cout << "." << std::endl;
	}
	else
		std::cout << str;
	if (f == 0)
		std::cout << " | ";
}

class PhoneBook{
	public:
		Contact c[8];
	private:
		int i;
	public:
	void	ini_index()
	{
		i = 0;
	}
		void	add(Contact nc)
		{
			if (i == 8)
				i = 0;
			c[i] = nc;
			i++;
		}
		void	search(int	in)
		{
			if (in < 0 || in > 7)
			{
				std::cout << "Invalid index" << std::endl;
				return ;
			}
			if (!c[in].fname.empty())
			{
				std::cout << in << " | ";
				print_with_rules(c[in].fname, 0);
				print_with_rules(c[in].lname, 0);
				print_with_rules(c[in].nname, 1);
				std::cout << std::endl;
			}
			else
				std::cout << "Invalid index" << std::endl;
		}
};

void add_pb(PhoneBook *pb)
{
    Contact nc;
    
    std::cout << "Enter the first name of your contact: ";
    std::getline(std::cin, nc.fname);
    std::cout << "Enter the last name of your contact: ";
    std::getline(std::cin, nc.lname);
    std::cout << "Enter the nickname of your contact: ";
    std::getline(std::cin, nc.nname);
    std::cout << "Enter the phone number of your contact: ";
    std::getline(std::cin, nc.pnum);
    std::cout << "SHHH, enter your contact's secret: ";
    std::getline(std::cin, nc.secret);
    pb->add(nc);
}

void search_pb(PhoneBook *pb)
{
    int in;

    std::cout << "Enter the index you want to search for: ";
    if (!(std::cin >> in))
    {
        std::cout << "Invalid input. Please enter a number." << std::endl;
        std::cin.clear();
        return;
    }
    pb->search(in);
}

int main(){
	std::string str;
	PhoneBook pb;

	std::cout << "Welcome To The Best PhoneBook" << std::endl;
	pb.ini_index();
	do{
		std::cout << "enter your command (ADD, SEARCH, EXIT)> ";
		std::getline(std::cin, str);
		if (str == "ADD")
			add_pb(&pb);
		else if (str == "SEARCH")
			search_pb(&pb);
		else if (str == "EXIT")
			break ;
	}while (str != "EXIT");
	return 0;
}
