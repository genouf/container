#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#include "../inc/vector.hpp"

template <class T>
void	print_vector(ft::vector<T> & v)
{
	for (typename ft::vector<T>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << std::endl;
}

int	main(void)
{
	{
		/*	MANDATORY TESTS	*/
		std::cout << "====== VECTEUR ======" << std::endl;
		std::string string1("Gabriel");
		std::vector<std::string> v(2, string1);
		for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		std::cout << "====== MON VECTEUR ======" << std::endl;
		ft::vector<std::string> my_v(2, string1);
		print_vector(my_v);
		std::cout << "====== MON VECTEUR COPIE ======" << std::endl;
		ft::vector<std::string> my_v2(my_v);
		print_vector(my_v2);
		std::cout << "====== MON VECTEUR ASSIGNATION ======" << std::endl;
		std::string string2("Mathilde");
		ft::vector<std::string> my_v3(2, string2);
		print_vector(my_v3);
		my_v2 = my_v3;
		print_vector(my_v2);
		std::cout << "====== ACCESS OPERATOR ======" << std::endl;
		std::cout << my_v2[0] << std::endl;
	}

	{
		/*	CAPACITY TESTS	*/
		std::cout << "BEFORE RESIZE" << std::endl;
		ft::vector<std::string> my_v(2, "Allez");
		print_vector(my_v);
		my_v.resize(6, "Kiks");
		std::cout << "AFTER RESIZE" << std::endl;
		print_vector(my_v);
		std::cout << "CAPACITY : " << my_v.capacity() << std::endl;
		std::cout << "EMPTY ? : " << my_v.empty() << std::endl;
		ft::vector<std::string> empty_v;
		std::cout << "EMPTY V : " << empty_v.empty() << std::endl;
		my_v.reserve(12);
		std::cout << "CAPACITY AFTER RESERVE : " << my_v.capacity() << std::endl;
	}

	{
		/*	MODIFIERS TESTS	*/
		ft::vector<std::string>	v_string;
		v_string.push_back("Gabriel");
		v_string.push_back("Mathilde");
		v_string.push_back("Allez");
		v_string.push_back("les");
		v_string.push_back("bleus");
		std::cout << v_string.capacity() << std::endl;
		print_vector(v_string);
		std::cout << std::endl << "ASSIGN TEST" << std::endl;
		ft::vector<std::string> n_v(12, "bleus");
		n_v.assign(v_string.begin(), v_string.begin() + 3);
		n_v.assign(10, "allez");
		std::cout << "CAPACITY : " << n_v.capacity() << std::endl;
		print_vector(n_v);
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