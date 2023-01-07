#include <iostream>
#include <vector>
#include <stack>

#include "../inc/stack.hpp"

int	main(void)
{
	std::stack<std::string, std::vector<std::string> > s;
	ft::stack<std::string> ms;

	// empty
	std::cout << "EMPTY " << s.empty() << std::endl;
	std::cout << "EMPTY " << ms.empty() << std::endl;

	// size
	std::cout << "SIZE " << s.size() << std::endl;
	std::cout << "SIZE " << ms.size() << std::endl;

	// push 
	s.push("2"); 
	s.push("6");
	ms.push("2"); 
	ms.push("6");

	//top
	std::cout << "TOP " << s.top() << std::endl;
	std::cout << "TOP " << ms.top() << std::endl;

	//pop
	s.pop();
	ms.pop();
	std::cout << "TOP AFTER POP " << s.top() << std::endl;
	std::cout << "TOP AFTER POP " << ms.top() << std::endl;

	//operators
	std::stack<std::string, std::vector<std::string> > s2;
	ft::stack<std::string> ms2;
	s2.push("2");
	ms2.push("2");

	std::cout << "EQUALITY : " << (s == s2) << std::endl;
	std::cout << "EQUALITY : " << (ms == ms2) << std::endl;
	s2.pop();
	ms2.pop();
	std::cout << "INEQUALITY : " << (s != s2) << std::endl;
	std::cout << "INEQUALITY : " << (ms != ms2) << std::endl;
	return (0);
}