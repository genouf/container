#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#include "../inc/vector.hpp"

// class Test
// {
// 	public:
// 		Test() {};
// 		~Test() {};
// };

int	main(void)
{
	{
		std::cout << "====== VECTEUR ======" << std::endl;
		std::string string1("Gabriel");
		std::vector<std::string> v(2, string1);
		for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		std::cout << "====== MON VECTEUR ======" << std::endl;
		ft::vector<std::string> my_v(2, string1);
		for (ft::vector<std::string>::iterator it = my_v.begin(); it != my_v.end(); it++)
			std::cout << *it << std::endl;
		std::cout << "====== MON VECTEUR COPIE ======" << std::endl;
		ft::vector<std::string> my_v2(my_v);
		for (ft::vector<std::string>::iterator it = my_v2.begin(); it != my_v2.end(); it++)
			std::cout << *it << std::endl;
		std::cout << "====== MON VECTEUR ASSIGNATION ======" << std::endl;
		std::string string2("Mathilde");
		ft::vector<std::string> my_v3(2, string2);
		for (ft::vector<std::string>::iterator it = my_v3.begin(); it != my_v3.end(); it++)
			std::cout << *it << std::endl;
		my_v2 = my_v3;
		for (ft::vector<std::string>::iterator it = my_v2.begin(); it != my_v2.end(); it++)
			std::cout << *it << std::endl;
		std::cout << "====== ACCESS OPERATOR ======" << std::endl;
		std::cout << my_v2[0] << std::endl;
	}

	{
		std::cout << "BEFORE RESIZE" << std::endl;
		ft::vector<std::string> my_v(2, "Allez");
		for (ft::vector<std::string>::iterator it = my_v.begin(); it != my_v.end(); it++)
			std::cout << *it << std::endl;
		my_v.resize(6, "Kiks");
		std::cout << "AFTER RESIZE" << std::endl;
		for (ft::vector<std::string>::iterator it = my_v.begin(); it != my_v.end(); it++)
			std::cout << *it << std::endl;
		std::cout << "CAPACITY : " << my_v.capacity() << std::endl;
		std::cout << "EMPTY ? : " << my_v.empty() << std::endl;
		ft::vector<std::string> empty_v;
		std::cout << "EMPTY V : " << empty_v.empty() << std::endl;
		my_v.reserve(12);
		std::cout << "CAPACITY AFTER RESERVE : " << my_v.capacity() << std::endl;
		my_v.shrink_to_fit();
		std::cout << "CAPACITY AFTER SHRINK : " << my_v.capacity() << std::endl;
	}
	return (0);
}

	// v.push_back(6);
	// v.push_back(7);
	// v.push_back(12);
	// std::cout << "CAPACITY IS " << v.capacity() << std::endl;
	// std::cout << "SIZE IS " << v.capacity() << std::endl;
	// for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	// 	std::cout << *it << std::endl;
	// std::cout << std::endl;
	// std::cout << "====== SUITE ======" << std::endl;
	// it1 = v.begin();
	// it2 = it1 + 2;
	// std::cout << "it1 = " << *it1 << std::endl;
	// std::cout << "it2 = " << *it2 << std::endl;
	// std::cout << std::endl << std::endl;
	// std::vector<int> v2(it1, it2);
	// for (std::vector<int>::iterator i = v2.begin(); i != v2.end(); i++)
	// 	std::cout << *i << std::endl;
	// std::cout << "SIZE IS " << v.size() << std::endl;
	// std::cout << "MAX_SIZE IS " << v.max_size() << std::endl;