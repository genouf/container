#include <iostream>
#include <vector>

// #include "../inc/vector.hpp"

int	main(void)
{
	std::vector<int> v;

	v.push_back(2);
	v.push_back(7);

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it;
	std::cout << std::endl;
	return (0);
}