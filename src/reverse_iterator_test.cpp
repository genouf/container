#include <iostream>
#include <vector>


#include "../inc/vector.hpp"
#include "../inc/reverse_iterator.hpp"

int	main(void)
{
	std::vector<int> v;
	ft::vector<int> mv;

	typedef std::vector<int>::iterator iter_type;
	typedef ft::vector<int>::iterator miter_type;

	v.push_back(2);
	v.push_back(4);
	v.push_back(6);
	v.push_back(8);
	v.push_back(10);
	v.push_back(12);
	v.push_back(14);
	mv.push_back(2);
	mv.push_back(4);
	mv.push_back(6);
	mv.push_back(8);
	mv.push_back(10);
	mv.push_back(12);
	mv.push_back(14);

	// default constructor
	std::reverse_iterator<iter_type>	dr_it;
	ft::reverse_iterator<miter_type>	dmr_it;

	// inialization constructor
	std::reverse_iterator<iter_type>	ir_it(v.end() - 3);
	ft::reverse_iterator<miter_type>	imr_it(mv.end() - 3);

	std::cout << "DEREFERENCEMENT" << std::endl;
	std::cout << *ir_it << std::endl;
	std::cout << *imr_it << std::endl;
	std::cout << "BASE" << std::endl;
	std::cout << *ir_it.base() << std::endl;
	std::cout << *imr_it.base() << std::endl;
	std::cout << std::endl << std::endl;

	// // copy constructor
	std::reverse_iterator<iter_type>	r_it(ir_it);
	ft::reverse_iterator<miter_type>	mr_it(imr_it);

	std::cout << "DEREFERENCEMENT" << std::endl;
	std::cout << *r_it << std::endl;
	std::cout << *mr_it << std::endl;
	std::cout << "BASE" << std::endl;
	std::cout << *r_it.base() << std::endl;
	std::cout << *mr_it.base() << std::endl;
	std::cout << std::endl << std::endl;

	// addition
	std::cout << "DEREFERENCEMENT" << std::endl;
	std::cout << *(r_it + 2) << std::endl;
	std::cout << *(mr_it + 2) << std::endl;
	std::cout << "BASE" << std::endl;
	std::cout << *r_it.base() << std::endl;
	std::cout << *mr_it.base() << std::endl;
	std::cout << std::endl << std::endl;

	// increment
	std::cout << *(r_it++) << std::endl;
	std::cout << *(mr_it++) << std::endl;
	++r_it;
	++mr_it;
	std::cout << "DEREFERENCEMENT" << std::endl;
	std::cout << *r_it << std::endl;
	std::cout << *mr_it << std::endl;
	std::cout << "BASE" << std::endl;
	std::cout << *r_it.base() << std::endl;
	std::cout << *mr_it.base() << std::endl;
	std::cout << std::endl << std::endl;

	//advance
	r_it += 1;
	mr_it += 1;
	std::cout << "DEREFERENCEMENT" << std::endl;
	std::cout << *r_it << std::endl;
	std::cout << *mr_it << std::endl;
	std::cout << "BASE" << std::endl;
	std::cout << *r_it.base() << std::endl;
	std::cout << *mr_it.base() << std::endl;
	std::cout << std::endl << std::endl;

	// substraction
	std::cout << "DEREFERENCEMENT" << std::endl;
	std::cout << *(r_it - 1) << std::endl;
	std::cout << *(mr_it - 1) << std::endl;
	std::cout << "BASE" << std::endl;
	std::cout << *r_it.base() << std::endl;
	std::cout << *mr_it.base() << std::endl;
	std::cout << std::endl << std::endl;

	// decrease
	std::cout << *(r_it--) << std::endl;
	std::cout << *(mr_it--) << std::endl;
	--r_it;
	--mr_it;
	std::cout << "DEREFERENCEMENT" << std::endl;
	std::cout << *r_it << std::endl;
	std::cout << *mr_it << std::endl;
	std::cout << "BASE" << std::endl;
	std::cout << *r_it.base() << std::endl;
	std::cout << *mr_it.base() << std::endl;
	std::cout << std::endl << std::endl;

	// retrocede
	r_it -= 1;
	mr_it -= 1;
	std::cout << "DEREFERENCEMENT" << std::endl;
	std::cout << *r_it << std::endl;
	std::cout << *mr_it << std::endl;
	std::cout << "BASE" << std::endl;
	std::cout << *r_it.base() << std::endl;
	std::cout << *mr_it.base() << std::endl;
	std::cout << std::endl << std::endl;

	// dereference
	std::cout << r_it[2] << std::endl;
	std::cout << mr_it[2] << std::endl;

	return (0);
}