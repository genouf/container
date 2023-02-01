#include <iostream>
#include "../inc/vector.hpp"
#include "../inc/stack.hpp"
#include "../inc/map.hpp"

template <class T>
void	print_mvector(ft::vector<T> & v)
{
	for (typename ft::vector<T>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << std::endl;
}

int	main(void)
{
	// VECTOR
	{

	}
	// STACK
	{
		ft::stack<std::string> s;

		// empty
		std::cout << "EMPTY " << s.empty() << std::endl;

		// size
		std::cout << "SIZE " << s.size() << std::endl;

		// push 
		s.push("2"); 
		s.push("6");

		//top
		std::cout << "TOP " << s.top() << std::endl;

		//pop
		s.pop();
		std::cout << "TOP AFTER POP " << s.top() << std::endl;

		//operators
		ft::stack<std::string> s2;
		s2.push("2");

		std::cout << "EQUALITY : " << (s == s2) << std::endl;
		s2.pop();
		std::cout << "INEQUALITY : " << (s != s2) << std::endl;
	}
	// MAP
	{
		std::cout << std::endl << std::endl << "============ FT ============" << std::endl;
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

		std::cout << std::endl << "====== INSERT ======" << std::endl;
		ft::pair<ft::map<int, std::string>::iterator, bool > pair_return;
		pair_return = mp.insert(ft::make_pair(64, "allezkylian"));
		std::cout << "====== PAIR_RETURN IS ======" << std::endl;
		std::cout << pair_return.first->first << "/" << pair_return.first->second << " | " << pair_return.second << std::endl;
		pair_return = mp.insert(ft::make_pair(2, "allezkylian"));
		std::cout << "====== PAIR_RETURN IS ======" << std::endl;
		std::cout << pair_return.first->first << "/" << pair_return.first->second << " | " << pair_return.second << std::endl;
		std::cout << "====== MAP IS ======" << std::endl;
		for (ft::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << "====== RANGE INSERT ======" << std::endl;
		mp.insert(mp_cp.begin(), mp_cp.end());
		std::cout << "====== MAP IS ======" << std::endl;
		for (ft::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;

		std::cout << std::endl << "====== ERASE BY ITERATOR ======" << std::endl;
		mp.erase(mp.begin());
		std::cout << "====== MAP IS ======" << std::endl;
		for (ft::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << std::endl << "====== ERASE BY KEY ======" << std::endl;
		std::cout << mp.erase(12) << std::endl;
		std::cout << mp.erase(3) << std::endl;
		std::cout << "====== MAP IS ======" << std::endl;
		for (ft::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << "SIZE ? : " << mp.size() << std::endl;
		std::cout << std::endl << "====== ERASE BY RANGE ======" << std::endl;
		mp.erase(mp.begin(), mp.end());
		std::cout << "====== MAP IS ======" << std::endl;
		for (ft::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;;
		std::cout << "SIZE ? : " << mp.size() << std::endl;

		std::cout << std::endl << "====== CLEAR ======" << std::endl;
		mp.insert(ft::make_pair<int, std::string>(1, "Ballet Girl"));
		mp.insert(ft::make_pair<int, std::string>(2, "Merci les bleus"));
		mp.insert(ft::make_pair<int, std::string>(4, "Bloody Mary"));
		std::cout << "====== MAP IS ======" << std::endl;
		for (ft::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << "SIZE ? : " << mp.size() << std::endl;
		mp.clear();
		std::cout << "====== MAP IS ======" << std::endl;
		for (ft::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << "SIZE ? : " << mp.size() << std::endl;

		std::cout << std::endl << "====== SWAP ======" << std::endl;
		std::cout << "====== MAP IS ======" << std::endl;
		for (ft::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << "====== MAP_RANGE IS ======" << std::endl;
		for (ft::map<int, std::string>::iterator it = mp_range.begin(); it != mp_range.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		mp.swap(mp_range);
		std::cout << "====== MAP IS ======" << std::endl;
		for (ft::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << "====== MAP_RANGE IS ======" << std::endl;
		for (ft::map<int, std::string>::iterator it = mp_range.begin(); it != mp_range.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;

		std::cout << std::endl << "====== FIND ======" << std::endl;
		std::cout << mp.find(2)->second << std::endl;
		std::cout << std::endl << "====== COUNT ======" << std::endl;
		std::cout << mp.count(2) << std::endl;
		std::cout << mp.count(100) << std::endl;

		std::cout << std::endl << "====== LOWER BOUND ======" << std::endl;
		std::cout << mp.lower_bound(6)->first << " | " << mp.lower_bound(6)->second << std::endl;
		std::cout << mp.upper_bound(12)->first << " | " << mp.lower_bound(6)->second << std::endl;
		std::cout << mp.upper_bound(64)->first << " | " << mp.lower_bound(6)->second << std::endl;
		std::cout << mp.equal_range(6).first->first << " | " << mp.equal_range(6).second->first << std::endl;
	}
	return (0);
}