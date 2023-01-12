#include <iostream>
#include <map>

#include "../inc/rb_tree.hpp"

int	main(void)
{
	ft::RBTree<int, std::string>	tree;

	tree.insert(ft::make_pair<int, std::string>(24, "Marie"));
	// tree.insert(ft::make_pair<int, std::string>(12, "M"));
	tree.insert(ft::make_pair<int, std::string>(8, "M"));
	tree.insert(ft::make_pair<int, std::string>(14, "M"));
	tree.insert(ft::make_pair<int, std::string>(32, "M"));
	// tree.insert(ft::make_pair<int, std::string>(24, "M"));
	tree.insert(ft::make_pair<int, std::string>(11, "M"));
	tree.insert(ft::make_pair<int, std::string>(2, "M"));
	tree.insert(ft::make_pair<int, std::string>(9, "M"));
	tree.insert(ft::make_pair<int, std::string>(7, "M"));
	tree.insert(ft::make_pair<int, std::string>(10, "M"));

	ft::RBTree<int, std::string>::iterator	it1 = tree.begin();
	// std::cout << it1->pair.first << std::endl; 
	// ++it1;
	// std::cout << it1->pair.first << std::endl; 
	// ++it1;
	// std::cout << it1->pair.first << std::endl; 
	// ++it1;
	for (ft::RBTree<int, std::string>::iterator	it1 = tree.begin(); it1 != tree.end(); ++it1)
		std::cout << it1->pair.first << std::endl; 
	return (0);
}