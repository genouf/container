#include <iostream>
#include <map>

#include "../inc/utility.hpp"
#include "../inc/map.hpp"

int	main(void)
{
	{
		std::cout << "============ STD ============" << std::endl;
		std::map<int, std::string> mp;

		std::cout << "IS EMPTY ? : " << mp.empty() << std::endl;
		std::cout << "MAX_SIZE ? : " << mp.max_size() << std::endl;
		mp.insert(std::make_pair<int, std::string>(2, "xd"));
		mp.insert(std::make_pair<int, std::string>(6, "lol"));
		mp.insert(std::make_pair<int, std::string>(32, "mdr"));
		for (std::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << "IS EMPTY ? : " << mp.empty() << std::endl; 
		std::cout << "MAX_SIZE ? : " << mp.max_size() << std::endl;
		std::cout << "SIZE ? : " << mp.size() << std::endl;
		std::cout << "====== OPERATOR [] ======" << std::endl;
		std::cout << mp[2] << std::endl;
		std::cout << mp[12] << std::endl;

		std::cout << std::endl << "====== CONSTRUCTOR RANGE =======" << std::endl;
		std::map<int, std::string> mp_range(mp.begin(), mp.end());
		std::cout << "====== NEW MAP_RANGE IS ======" << std::endl;
		for (std::map<int, std::string>::iterator it = mp_range.begin(); it != mp_range.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		mp_range.insert(std::make_pair<int, std::string>(1, "allez"));
		std::cout << "====== NEW KEY INSERTED TO NEW MAP_RANGE ======" << std::endl;
		std::map<int, std::string> mp_cp(mp_range);
		std::cout << "====== NEW MAP_CP FROM MAP_RANGE IS ======" << std::endl;
		for (std::map<int, std::string>::iterator it = mp_cp.begin(); it != mp_cp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << std::endl << "====== COPY CONSTRUCTOR =======" << std::endl;
		mp_cp.erase(6);
		std::cout << std::endl << "====== ASSIGNATION MP = MP_CP =======" << std::endl;
		mp = mp_cp;
		std::cout << "====== MAP IS ======" << std::endl;
		for (std::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << "====== MAP_RANGE IS ======" << std::endl;
		for (std::map<int, std::string>::iterator it = mp_range.begin(); it != mp_range.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << "====== MAP_CP IS ======" << std::endl;
		for (std::map<int, std::string>::iterator it = mp_cp.begin(); it != mp_cp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;

		std::cout << std::endl << "====== ERASE ======" << std::endl;
		std::cout << mp.erase(2) << std::endl;
		std::cout << mp.erase(3) << std::endl;
	}
	{
		std::cout << "============ FT ============" << std::endl;
		ft::map<int, std::string> mp;

		std::cout << "IS EMPTY ? : " << mp.empty() << std::endl;
		std::cout << "MAX_SIZE ? : " << mp.max_size() << std::endl;
		mp.insert(ft::make_pair<int, std::string>(2, "xd"));
		mp.insert(ft::make_pair<int, std::string>(6, "lol"));
		mp.insert(ft::make_pair<int, std::string>(32, "mdr"));
		for (ft::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << "IS EMPTY ? : " << mp.empty() << std::endl; 
		std::cout << "MAX_SIZE ? : " << mp.max_size() << std::endl;
		std::cout << "SIZE ? : " << mp.size() << std::endl;
		std::cout << "====== OPERATOR [] ======" << std::endl;
		std::cout << mp[2] << std::endl;
		std::cout << mp[12] << std::endl;

		std::cout << std::endl << "====== CONSTRUCTOR RANGE =======" << std::endl;
		ft::map<int, std::string> mp_range(mp.begin(), mp.end());
		std::cout << "====== NEW MAP_RANGE IS ======" << std::endl;
		for (ft::map<int, std::string>::iterator it = mp_range.begin(); it != mp_range.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		mp_range.insert(ft::make_pair<int, std::string>(1, "allez"));
		std::cout << "====== NEW KEY INSERTED TO NEW MAP_RANGE ======" << std::endl;
		ft::map<int, std::string> mp_cp(mp_range);
		std::cout << "====== NEW MAP_CP FROM MAP_RANGE IS ======" << std::endl;
		for (ft::map<int, std::string>::iterator it = mp_cp.begin(); it != mp_cp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << std::endl << "====== COPY CONSTRUCTOR =======" << std::endl;
		mp_cp.erase(6);
		std::cout << std::endl << "====== ASSIGNATION MP = MP_CP =======" << std::endl;
		mp = mp_cp;
		std::cout << "====== MAP IS ======" << std::endl;
		for (ft::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << "====== MAP_RANGE IS ======" << std::endl;
		for (ft::map<int, std::string>::iterator it = mp_range.begin(); it != mp_range.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << "====== MAP_CP IS ======" << std::endl;
		for (ft::map<int, std::string>::iterator it = mp_cp.begin(); it != mp_cp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
	}
	

	
	// {
	// 	/*	STD	*/
	// 	std::map<int, std::string> mp;
	// 	std::pair<std::map<int, std::string>::iterator, bool>	pair_return;

	// 	pair_return = mp.insert(std::make_pair<int, std::string>(2, "mdr"));
	// 	std::cout << "====== PAIR VALUE ====== " << std::endl << "FIRST " << pair_return.first->first << "  SECOND " << pair_return.second << std::endl;
	// 	pair_return = mp.insert(std::make_pair<int, std::string>(2, "lol"));
	// 	std::cout << "====== PAIR VALUE ====== " << std::endl << "FIRST " << pair_return.first->second << "  SECOND " << pair_return.second << std::endl;
	// }
	// {
	// 	/*	FT	*/
	// 	ft::map<int, std::string> mp;
	// 	ft::pair<ft::map<int, std::string>::iterator, bool>	pair_return;

	// 	pair_return = mp.insert(ft::make_pair<int, std::string>(2, "mdr"));
	// 	std::cout << "====== PAIR VALUE ====== " << std::endl << "FIRST " << pair_return.first->first << "  SECOND " << pair_return.second << std::endl;
	// 	pair_return = mp.insert(ft::make_pair<int, std::string>(2, "lol"));
	// 	std::cout << "====== PAIR VALUE ====== " << std::endl << "FIRST " << pair_return.first->second << "  SECOND " << pair_return.second << std::endl;
	// }
	return (0);
}