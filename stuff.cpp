#include <iostream>
#include <typeinfo>

int main()
{
	int a = 20; // = 0x14 = 0b10100 = 024;

	std::cout << typeid(a).name() << '\n';
	std::cout << typeid(5.0).name() << '\n';
	std::cout << typeid(5.0f).name() << '\n';

	return 0;
}