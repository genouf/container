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

	/*	ITERATORS TESTS	*/
	ft::RBTree<int, std::string>::iterator	it = tree.begin();
	for (ft::RBTree<int, std::string>::iterator	it = tree.begin(); it != tree.end(); ++it)
		std::cout << it->pair.first << " AND " <<  it->pair.second << std::endl; 
	
	for (ft::RBTree<int, std::string>::iterator	it = tree.end(); it != tree.begin(); --it)
		std::cout << it->pair.first << " AND " <<  it->pair.second << std::endl;

	

	return (0);
}