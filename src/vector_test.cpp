#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#include "../inc/vector.hpp"
#include "../inc/utility.hpp"

template <class T>
void	print_vector(std::vector<T> & v)
{
	for (typename std::vector<T>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << std::endl;
}


template <class T>
void	print_mvector(ft::vector<T> & v)
{
	for (typename ft::vector<T>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << std::endl;
}

int	main(void)
{
	{
		/*	MANDATORY TESTS	*/
		// std::cout << "====== VECTEUR ======" << std::endl;
		// std::string string1("Gabriel");
		// std::vector<std::string> v(2, string1);
		// for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
		// 	std::cout << *it << std::endl;
		// std::cout << "====== MON VECTEUR ======" << std::endl;
		// ft::vector<std::string> my_v(2, string1);
		// print_vector(my_v);
		// std::cout << "====== MON VECTEUR COPIE ======" << std::endl;
		// ft::vector<std::string> my_v2(my_v);
		// print_vector(my_v2);
		// std::cout << "====== MON VECTEUR ASSIGNATION ======" << std::endl;
		// std::string string2("Mathilde");
		// ft::vector<std::string> my_v3(2, string2);
		// print_vector(my_v3);
		// my_v2 = my_v3;
		// print_vector(my_v2);
		// std::cout << "====== ACCESS OPERATOR ======" << std::endl;
		// std::cout << my_v2[0] << std::endl;
	}

	{
		// /*	CAPACITY TESTS	*/
		// std::cout << "BEFORE RESIZE" << std::endl;
		// ft::vector<std::string> my_v(2, "Allez");
		// print_vector(my_v);
		// my_v.resize(6, "Kiks");
		// std::cout << "AFTER RESIZE" << std::endl;
		// print_vector(my_v);
		// std::cout << "CAPACITY : " << my_v.capacity() << std::endl;
		// std::cout << "EMPTY ? : " << my_v.empty() << std::endl;
		// ft::vector<std::string> empty_v;
		// std::cout << "EMPTY V : " << empty_v.empty() << std::endl;
		// my_v.reserve(12);
		// std::cout << "CAPACITY AFTER RESERVE : " << my_v.capacity() << std::endl;
	}

	{
		/*	MODIFIERS TESTS	*/
		// ft::vector<std::string>	v_string;
		// v_string.push_back("Gabriel");
		// v_string.push_back("Mathilde");
		// v_string.push_back("Allez");
		// v_string.push_back("les");
		// v_string.push_back("bleus");
		// std::cout << v_string.capacity() << std::endl;
		// print_vector(v_string);
		// std::cout << std::endl << "ASSIGN TEST" << std::endl;
		// ft::vector<std::string> n_v(12, "bleus");
		// n_v.assign(v_string.begin(), v_string.begin() + 3);
		// print_vector(n_v);
		// n_v.assign(10, "allez");
		// print_vector(n_v);
		// std::cout << "CAPACITY : " << n_v.capacity() << std::endl;
		// std::cout << std::endl << std::endl;

		// std::vector<int> v6(4, 6);
		// // std::cout << *(v6.insert(v6.begin() + 2, 6, "l"));
		// v6.insert(v6.begin() + 2, 12, 1);
		// for (std::vector<int>::iterator it = v6.begin(); it != v6.end(); it++)
		// 	std::cout << *it << std::endl;
		// std::cout << "====== VS ======" << std::endl;
		// std::vector<int> v6(4, 6);
		// ft::vector<int>	my_v6(4, 6);
		// std::vector<int> v12(4, 12);
		// ft::vector<int>	my_v12(4, 12);
		// my_v6.insert(my_v6.end(), my_v12.begin(), my_v12.end());
		// v6.insert(v6.end(), v12.begin(), v12.end());
		// print_vector(my_v6);
		// for (std::vector<int>::iterator it = v6.begin(); it != v6.end(); it++)
			// std::cout << *it << std::endl;
		// std::cout << std::endl << std::endl;
		// std::vector<std::string> coucou(1, "coucou");
		// coucou.push_back("test");
		// coucou.insert(coucou.begin(), coucou.begin(), coucou.end() + 2);
		// std::cout << "coucou begin " << *(coucou.begin()) << std::endl;
		// std::cout << "coucou end " << *(coucou.end() + 2) << std::endl;
		// coucou.erase(coucou.begin());
		// print_vector(coucou);
		// std::cout << "CAPACITY " << my_v6.capacity() << std::endl;
		// my_v6.erase(my_v6.begin());
		// v6.erase(v6.end());
		// print_vector(my_v6);
		// for (std::vector<int>::iterator it = v6.begin(); it != v6.end(); it++)
			// std::cout << *it << std::endl;
		// std::cout << std::endl << std::endl;
		// my_v6.erase(my_v6.begin(), my_v6.end());
		// v6.erase(v6.begin(), v6.end());
		// print_vector(my_v6);
		// for (std::vector<int>::iterator it = v6.begin(); it != v6.end(); it++)
			// std::cout << *it << std::endl;
		// std::cout << "before " << *(my_v6.begin() + 4)-- << std::endl;
		// std::cout << "before " << *(v6.begin() + 4)-- << std::endl;
		// std::cout << "before " << *(v6.begin() + 4) << std::endl;

		// ft::vector<std::string> v1 (4, "allez");
		// ft::vector<std::string> v2 (v1.begin(), v1.end());
		// print_vector(v2);
		// v2.erase(v2.end());
		// std::cout << std::endl;

		// ft::vector<std::string> v1;
		// v1.push_back(" lol");
		// v1.push_back("mdr");
		// v1.push_back("xd");
		// v1.push_back("mdr");
		
		
		ft::vector<int> mv1;
		std::cout << "MAX_SIZE IS " << mv1.max_size() << std::endl;
		mv1.push_back(0);
		mv1.push_back(1);
		mv1.push_back(2);
		mv1.push_back(3);
		mv1.push_back(4);
		mv1.push_back(5);
		mv1.push_back(6);
		// print_mvector(mv1);
		// mv1.erase(mv1.begin(), mv1.end());
		// print_mvector(mv1);
		std::cout << "FRONT ELEMENT IS " << mv1.front() << std::endl;
		std::cout << "BACK ELEMENT IS " << mv1.back() << std::endl;
		

		std::vector<int> v1;
		std::cout << "MAX_SIZE IS " << v1.max_size() << std::endl;
		v1.push_back(0);
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(6);
		// print_vector(v1);
		// v1.erase(v1.begin(), v1.end() + 2);
		// std::cout << std::endl;
		// print_vector(v1);
		std::cout << "FRONT ELEMENT IS " << v1.front() << std::endl;
		std::cout << "BACK ELEMENT IS " << v1.back() << std::endl;
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