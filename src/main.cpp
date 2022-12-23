#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#include "../inc/vector.hpp"

int	main(void)
{
	std::cout << "====== LE VECTEUR ======" << std::endl;
	std::vector<int> v(3, 100);
	std::vector<int>::iterator it1;
	std::vector<int>::iterator it2;

	std::cout << "SIZE IS " << v.size() << std::endl;
	std::cout << "CAPACITY IS " << v.capacity() << std::endl;
	v.push_back(7);
	std::cout << "SIZE IS " << v.size() << std::endl;
	std::cout << "CAPACITY IS " << v.capacity() << std::endl;
	v.push_back(12);
	std::cout << "SIZE IS " << v.size() << std::endl;
	std::cout << "CAPACITY IS " << v.capacity() << std::endl;
	v.push_back(23);
	std::cout << "SIZE IS " << v.size() << std::endl;
	std::cout << "CAPACITY IS " << v.capacity() << std::endl;
	v.push_back(32);
	std::cout << "SIZE IS " << v.size() << std::endl;
	std::cout << "CAPACITY IS " << v.capacity() << std::endl;

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << std::endl;
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
	std::cout << "SIZE IS " << v.size() << std::endl;
	std::cout << "MAX_SIZE IS " << v.max_size() << std::endl;
	ft::vector<int> my_v;
	std::cout << "MY MAX_SIZE IS " << my_v.max_size() << std::endl;


	std::cout << "====== MON VECTEUR PERSO ======" << std::endl;
	return (0);
}