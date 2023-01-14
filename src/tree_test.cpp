#include <iostream>
#include <map>

#include "../inc/rb_tree.hpp"

int	main(void)
{
	ft::RBTree<ft::pair<int, std::string> >	tree;

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
	ft::RBTree<ft::pair<int, std::string> >::iterator	it = tree.begin();
	for (ft::RBTree<ft::pair<int, std::string> >::iterator	it = tree.begin(); it != tree.end(); ++it)
		std::cout << it->first << " AND " <<  it->second << std::endl; 
	
	// for (ft::RBTree<ft::pair<int, std::string> >::iterator	it = tree.end(); it != tree.begin(); --it)
	// 	std::cout << it->first << " AND " <<  it->second << std::endl;

	// /*	STD	*/
	// std::map<int, std::string> map1;

	// map1.insert(std::make_pair<int, std::string>(32, "M"));
	// map1.insert(std::make_pair<int, std::string>(5, "M"));
	// map1.insert(std::make_pair<int, std::string>(20, "M"));
	// map1.insert(std::make_pair<int, std::string>(64, "M"));
	// map1.insert(std::make_pair<int, std::string>(2, "M"));
	// for(std::map<int, std::string>::iterator it1 = map1.end(); it1 != map1.begin(); --it1)
	// 	std::cout << it1->first << std::endl;
	
	return (0);
}