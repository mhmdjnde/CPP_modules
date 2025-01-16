#include <iostream>

int main()
{
	std::string s = "HI THIS IS BRAIN";
	std::string *ptr = &s;
	std::string &ref = s;
	std::cout << "Address of s: " << &s << std::endl;
	std::cout << "Address of ptr: " << ptr << std::endl;
	std::cout << "Address of ref: " << &ref << std::endl;
	std::cout << "Value of s: " << s << std::endl;
	std::cout << "Value of ptr: " << *ptr << std::endl;
	std::cout << "Value of ref: " << ref << std::endl;
	return 0;
}
