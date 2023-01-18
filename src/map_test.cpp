#include <iostream>
#include <map>

#include "../inc/utility.hpp"
#include "../inc/map.hpp"

int	main(void)
{
	{
		/*	STD	*/
		std::map<int, std::string> mp;
		std::pair<std::map<int, std::string>::iterator, bool>	pair_return;

		pair_return = mp.insert(std::make_pair<int, std::string>(2, "mdr"));
		std::cout << "====== PAIR VALUE ====== " << std::endl << "FIRST " << pair_return.first->first << "  SECOND " << pair_return.second << std::endl;
		pair_return = mp.insert(std::make_pair<int, std::string>(2, "lol"));
		std::cout << "====== PAIR VALUE ====== " << std::endl << "FIRST " << pair_return.first->second << "  SECOND " << pair_return.second << std::endl;
	}
	{
		/*	FT	*/
		ft::map<int, std::string> mp;
		ft::pair<ft::map<int, std::string>::iterator, bool>	pair_return;

		pair_return = mp.insert(ft::make_pair<int, std::string>(2, "mdr"));
		std::cout << "====== PAIR VALUE ====== " << std::endl << "FIRST " << pair_return.first->first << "  SECOND " << pair_return.second << std::endl;
		pair_return = mp.insert(ft::make_pair<int, std::string>(2, "lol"));
		std::cout << "====== PAIR VALUE ====== " << std::endl << "FIRST " << pair_return.first->second << "  SECOND " << pair_return.second << std::endl;
	}
	return (0);
}