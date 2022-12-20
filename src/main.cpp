#include <iostream>
#include <vector>

// #include "../inc/vector.hpp"

int	main(void)
{
	std::vector<int> v;
	std::vector<int>::iterator it1;
	std::vector<int>::iterator it2;

	v.push_back(2);
	v.push_back(7);
	v.push_back(12);
	v.push_back(23);

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it;
	std::cout << std::endl;
	std::cout << "====== SUITE ======" << std::endl;
	it1 = v.begin();
	it2 = it1 + 2;
	std::cout << "it1 = " << *it1 << std::endl;
	std::cout << "it2 = " << *it2 << std::endl;
	std::cout << std::endl << std::endl;
	std::vector<int> v2(it1, it2);
	for (std::vector<int>::iterator i = v2.begin(); i != v2.end(); i++)
		std::cout << *i << std::endl;
	return (0);
}