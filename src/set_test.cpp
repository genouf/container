#include <iostream>
#include <set>

#include "../inc/utility.hpp"
#include "../inc/set.hpp"

int	main(void)
{
	{
		std::cout << "============ STD ============" << std::endl;
		std::set<std::string> st;

		std::cout << "IS EMPTY ? : " << st.empty() << std::endl;
		std::cout << "MAX_SIZE ? : " << st.max_size() << std::endl;
		st.insert("xd");
		st.insert("lol");
		st.insert("mdr");
		for (std::set<std::string>::iterator it = st.begin(); it != st.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << "IS EMPTY ? : " << st.empty() << std::endl; 
		std::cout << "MAX_SIZE ? : " << st.max_size() << std::endl;
		std::cout << "SIZE ? : " << st.size() << std::endl;
	}
	{
		std::cout << "============ FT ============" << std::endl;
		ft::set<std::string> st;

		std::cout << "IS EMPTY ? : " << st.empty() << std::endl;
		std::cout << "MAX_SIZE ? : " << st.max_size() << std::endl;
		st.insert("xd");
		st.insert("lol");
		st.insert("mdr");
		for (ft::set<std::string>::iterator it = st.begin(); it != st.end(); ++it)
			std::cout << it->first << std::endl;
		std::cout << "IS EMPTY ? : " << st.empty() << std::endl; 
		std::cout << "MAX_SIZE ? : " << st.max_size() << std::endl;
		std::cout << "SIZE ? : " << st.size() << std::endl;
	}

	return (0);
}