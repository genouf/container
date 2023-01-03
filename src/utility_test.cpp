#include "../inc/utility.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
	
int main(void)	
{
	// UTILITY

	// is_integral
	std::cout << ft::is_integral<float>::value << std::endl;

	//equal
	std::vector<std::string> v1(3, "lol");
	std::vector<std::string> v2(4, "lol");
	std::vector<std::string> v3(12, "xd");
	
	std::cout << "====== V1 AND V2 ======" << std::endl;
	std::cout << ft::equal(v1.begin(), v1.end(), v2.begin()) << std::endl; 
	std::cout << std::equal(v1.begin(), v1.end(), v2.begin()) << std::endl; 
	std::cout << "====== V1 AND V3 ======" << std::endl;
	std::cout << ft::equal(v1.begin(), v1.end(), v3.begin()) << std::endl; 
	std::cout << std::equal(v1.begin(), v1.end(), v3.begin()) << std::endl; 

	// lexicographical_compare
	char	str1[] = "Scarlet";
	char	str2[] = "Mathilde";
	char	str3[] = "scarlet";

	std::cout << "====== STR1 AND STR2 ======" << std::endl;
	std::cout << ft::lexicographical_compare(str1, str1 + 6, str2, str2 + 6) << std::endl;
	std::cout << std::lexicographical_compare(str1, str1 + 6, str2, str2 + 6) << std::endl;
	std::cout << "====== STR1 AND STR3 ======" << std::endl;
	std::cout << ft::lexicographical_compare(str1, str1 + 6, str3, str3 + 6) << std::endl;
	std::cout << std::lexicographical_compare(str1, str1 + 6, str3, str3 + 6) << std::endl;

	return (0);
}