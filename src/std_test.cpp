/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:05:33 by genouf            #+#    #+#             */
/*   Updated: 2023/02/02 10:34:18 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <set>

template <class T>
void	print_vector(std::vector<T> & v)
{
	for (typename std::vector<T>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << std::endl;
}

template <typename T, typename Allocator>
static void display(std::vector<T, Allocator>& vect) {
    std::cout << "size: " << vect.size() << std::endl;
    std::cout << "max_size: " << vect.max_size() << std::endl;
    std::cout << "capacity: " << vect.capacity() << std::endl;
    std::cout << "empty: " << vect.empty() << std::endl;
	if (!vect.empty()){
		std::cout << "content: ";
		for (size_t i = 0; i < vect.size(); i++){
			std::cout << ' ' << vect[i];}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int	main(void)
{
	// VECTOR
	{
		std::cout << "\e[7m=============CONSTRUCTORS============\e[0m" << std::endl;
		{
			std::vector<int> first; 			
			std::vector<int> second;								// empty vector of ints
			std::vector<int> third (second.begin(), second.end());	// iterating through second
			std::vector<int> fourth (second);						// a copy of third
			int myints[] = {16,2,77,29};
			std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) ); // the iterator constructor can also be used to construct from arrays:
			std::vector<int> sixth = fifth; // operator =

			std::cout << "The contents of FIRST are:" << std::endl;
			display(first);

			std::cout << "The contents of SECOND are:" << std::endl;
			display(second);

			std::cout << "The contents of THIRD are:" << std::endl;
			display(third);

			std::cout << "The contents of FOURTH are:" << std::endl;
			display(fourth);

			std::cout << "The contents of FIFTH are:" << std::endl;
			display(fifth);

			std::cout << "The contents of SIXTH are:" << std::endl;
			display(sixth);
		}
		std::cout << std::endl;
		// ################################  ITERATORS   ################
		std::cout << "\e[7m===============ITERATORS=============\e[0m" << std::endl;
		{
			std::vector<int> myvector;
			for (int i=1; i<=5; i++) myvector.push_back(i);

			std::cout << "begin-end  myvector contains:" << std::endl;
			for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << std::endl;
			std::cout << std::endl;
		}{
			std::vector<int> myvector (5);  // 5 default-constructed ints
			int i=0;
			std::vector<int>::reverse_iterator rit = myvector.rbegin();
			for (; rit!= myvector.rend(); ++rit)
			*rit = ++i;

			std::cout << "rbegin-rend myvector contains:" << std::endl;
			display(myvector);
		}
		std::cout << std::endl;
		// ################################  CAPACITY  ###############
		std::cout << "\e[7m=============CAPACITY============\e[0m" << std::endl;
		std::cout << "\033[31m***Resize***\033[0m" << std::endl;
		{
			std::vector<int> myvector;
			for (int i=1;i<10;i++) myvector.push_back(i);
			std::cout << "myvector contains:" << std::endl;
			display(myvector);
			myvector.resize(5);
			std::cout << "resize(5)  myvector contains:" << std::endl;
			display(myvector);
			myvector.resize(8,100);
			std::cout << "resize(8,100)  myvector contains:" << std::endl;
			display(myvector);
			myvector.resize(12);
			std::cout << "resize(12)  myvector contains:" << std::endl;
			display(myvector);
		}
		std::cout << "\033[31m***Empty***\033[0m" << std::endl;
		{
			std::vector<int> myvector;
			int sum (0);

			for (int i=1;i<=10;i++) myvector.push_back(i);
			std::cout << "myvector contains:" << std::endl;
			display(myvector);
			while (!myvector.empty()) {
				sum += myvector.back();
				myvector.pop_back();
			}
			std::cout << "total: " << sum << std::endl;
			std::cout << "after emptying myvector contains:" << std::endl;
			display(myvector);
		}
		std::cout << "\033[31m***Reserve***\033[0m" << std::endl;
		{
			std::vector<int>::size_type sz;
			std::vector<int> foo;
			sz = foo.capacity();
			std::cout << "making foo grow:" << std::endl;
			for (int i=0; i<100; ++i) {
				foo.push_back(i);
				if (sz!=foo.capacity()) {
					sz = foo.capacity();
					std::cout << "capacity changed: " << sz << std::endl;
				}
			}
			std::vector<int> bar;
			sz = bar.capacity();
			bar.reserve(100);   // this is the only difference with foo above
			std::cout << "making bar grow:" << std::endl;
			for (int i=0; i<100; ++i) {
				bar.push_back(i);
				if (sz!=bar.capacity()) {
					sz = bar.capacity();
				std::cout << "capacity changed: " << sz << std::endl;
				}
			}
		}
		std::cout << std::endl;
		// ################################  ELEMENT ACCESS  ###############
		std::cout << "\e[7m=============ELEMENT ACCESS============\e[0m" << std::endl;
		std::cout << "\033[31m***Operator []***\033[0m" << std::endl;
		{
			std::vector<int> myvector (10);   // 10 zero-initialized elements
			std::vector<int>::size_type sz = myvector.size();

			for (unsigned i=0; i<sz; i++)
				myvector[i]=i; // assign some values:
			std::cout << "myvector contains:" << std::endl;
			display(myvector);
			for (unsigned i=0; i<sz/2; i++) { // reverse vector using operator[]:
				int temp;
				temp = myvector[sz-1-i];
				myvector[sz-1-i]=myvector[i];
				myvector[i]=temp;
			}
			std::cout << "myvector contains:" << std::endl;
			display(myvector);
		}
		std::cout << "\033[31m***At***\033[0m" << std::endl;
		{
			std::vector<int> myvector (10);   // 10 zero-initialized ints

			for (unsigned i=0; i<myvector.size(); i++)
				myvector.at(i)=i; // assign some values:
			std::cout << "myvector contains:" << std::endl;
			display(myvector);
		}
		std::cout << "\033[31m***Front***\033[0m" << std::endl;
		{
			std::vector<int> myvector;
			myvector.push_back(78);
			myvector.push_back(16); // now front equals 78, and back 16
			std::cout << "myvector contains:" << std::endl;
			display(myvector);
			myvector.front() -= myvector.back();
			std::cout << "myvector.front() -= myvector.back()  myvector contains:" << std::endl;
			display(myvector);
		}
		std::cout << "\033[31m***Back***\033[0m" << std::endl;
		{
			std::vector<int> myvector;
			myvector.push_back(10);
			while (myvector.back() != 0) {
				myvector.push_back ( myvector.back() -1 );
			}
			std::cout << "myvector contains:" << std::endl;
			display(myvector);
		}
		// ################################  MODIFIERS  ###############
		std::cout << "\e[7m=============MODIFIERS============\e[0m" << std::endl;
		std::cout << "\033[31m***Assign***\033[0m" << std::endl;
		{
			std::vector<int> first;
			std::vector<int> second;
			std::vector<int> third;
			
			first.assign (7,100);             // 7 ints with a value of 100
			second.assign (first.begin()+1, first.end()-1); // the 5 central values of first
			
			int myints[] = {1776,7,4};
			third.assign (myints,myints+3);   // assigning from array.
			std::cout << "First: " << std::endl;
			display(first);
			std::cout << "Second: " << std::endl;
			display(second);
			std::cout << "Third: " << std::endl;
			display(third);
		}
		std::cout << "\033[31m***Push back / Pop back***\033[0m" << std::endl;
		{
			std::vector<int> myvector;
			myvector.push_back (100);
			myvector.push_back (200);
			myvector.push_back (300);
			display(myvector);
			while (!myvector.empty()) {
				myvector.pop_back();
			}
			display(myvector);
		}
		std::cout << "\033[31m***Insert***\033[0m" << std::endl;
		{
			std::vector<int> myvector (3,100);
			std::vector<int>::iterator it = myvector.begin();
			it = myvector.insert ( it , 200 );
			std::cout << "myvector contains: " << std::endl;
			display(myvector);

			myvector.insert (it,2,300);
			std::cout << "myvector contains: " << std::endl;
			display(myvector);

			it = myvector.begin(); // "it" no longer valid, get a new one
			std::vector<int> anothervector (2,400);
			myvector.insert (it+2,anothervector.begin(),anothervector.end());
			std::cout << "myvector contains: " << std::endl;
			display(myvector);

			int myarray [] = { 501,502,503 };
			myvector.insert (myvector.begin(), myarray, myarray+3);
			std::cout << "myvector contains: " << std::endl;
			display(myvector);
		}
		std::cout << "\033[31m***Erase***\033[0m" << std::endl;
		{
			std::vector<int> myvector;
			for (int i=1; i<=10; i++)
				myvector.push_back(i);// set some values (from 1 to 10)
			std::cout << "myvector contains: " << std::endl;
			display(myvector);

			myvector.erase (myvector.begin()+5);// erase the 6th element
			std::cout << "myvector contains: " << std::endl;
			display(myvector);

			myvector.erase (myvector.begin(),myvector.begin()+3);// erase the first 3 elements:
			std::cout << "myvector contains: " << std::endl;
			display(myvector);
		}
		std::cout << "\033[31m***Swap***\033[0m" << std::endl;
		{
			std::vector<int> foo (3,100);   // three ints with a value of 100
			std::vector<int> bar (5,200);   // five ints with a value of 200

			foo.swap(bar);

			std::cout << "foo contains:";
			display(foo);
			std::cout << "bar contains:";
			display(bar);
		}
		std::cout << "\033[31m***Clear***\033[0m" << std::endl;
		{
			std::vector<int> myvector;
			myvector.push_back (100);
			myvector.push_back (200);
			myvector.push_back (300);

			std::cout << "myvector contains:";
			display(myvector);

			myvector.clear();
			std::cout << "myvector contains:";
			display(myvector);

			myvector.push_back (1101);
			myvector.push_back (2202);
			std::cout << "myvector contains: " << std::endl;
			display(myvector);
		}
		// ################################  ALLOCATOR  ###############
		std::cout << "\e[7m=============ALLOCATOR============\e[0m" << std::endl;
		{
			std::vector<int> myvector;
			int * p;
			unsigned int i;

			p = myvector.get_allocator().allocate(5); // allocate an array with space for 5 elements using vector's allocator
			for (i=0; i<5; i++)
				myvector.get_allocator().construct(&p[i],i); // construct values in-place on the array

			std::cout << "myvector contains: " << std::endl;
			display(myvector);

		// destroy and deallocate:
			for (i=0; i<5; i++)
				myvector.get_allocator().destroy(&p[i]);
			myvector.get_allocator().deallocate(p,5);
		}
		// ################################  RELATIONAL OPERATORS  ###############
		std::cout << "\e[7m=============RELATIONAL OPERATORS============\e[0m" << std::endl;
		{
			std::vector<int> foo (3,100);   // three ints with a value of 100
			std::vector<int> bar (2,200);   // two ints with a value of 200

			if (foo == bar) std::cout << "foo and bar are equal" << std::endl;;
			if (foo != bar) std::cout << "foo and bar are not equal" << std::endl;;
			if (foo < bar) std::cout << "foo is less than bar" << std::endl;;
			if (foo > bar) std::cout << "foo is greater than bar" << std::endl;;
			if (foo <= bar) std::cout << "foo is less than or equal to bar" << std::endl;;
			if (foo >= bar) std::cout << "foo is greater than or equal to bar" << std::endl;;
		}
			// ################################  RELATIONAL OPERATORS  ###############
		std::cout << "\e[7m=============SWAP Overload============\e[0m" << std::endl;
		{
			std::vector<int> foo (3,100);   // three ints with a value of 100
			std::vector<int> bar (5,200);   // five ints with a value of 200
			swap(foo, bar);

			std::cout << "foo contains:";
			display(foo);
			std::cout << "bar contains:";
			display(bar);
		}
	}
	// STACK
	{
		std::stack<std::string> s;

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
		std::stack<std::string> s2;
		s2.push("2");

		std::cout << "EQUALITY : " << (s == s2) << std::endl;
		s2.pop();
		std::cout << "INEQUALITY : " << (s != s2) << std::endl;
	}
	// MAP
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

		std::cout << std::endl << "====== INSERT ======" << std::endl;
		std::pair<std::map<int, std::string>::iterator, bool > pair_return;
		pair_return = mp.insert(std::make_pair(64, "allezkylian"));
		std::cout << "====== PAIR_RETURN IS ======" << std::endl;
		std::cout << pair_return.first->first << "/" << pair_return.first->second << " | " << pair_return.second << std::endl;
		pair_return = mp.insert(std::make_pair(2, "allezkylian"));
		std::cout << "====== PAIR_RETURN IS ======" << std::endl;
		std::cout << pair_return.first->first << "/" << pair_return.first->second << " | " << pair_return.second << std::endl;
		std::cout << "====== MAP IS ======" << std::endl;
		for (std::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << "====== RANGE INSERT ======" << std::endl;
		mp.insert(mp_cp.begin(), mp_cp.end());
		std::cout << "====== MAP IS ======" << std::endl;
		for (std::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;

		std::cout << std::endl << "====== ERASE BY ITERATOR ======" << std::endl;
		mp.erase(mp.begin());
		std::cout << "====== MAP IS ======" << std::endl;
		for (std::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << std::endl << "====== ERASE BY KEY ======" << std::endl;
		std::cout << mp.erase(12) << std::endl;
		std::cout << mp.erase(3) << std::endl;
		std::cout << "====== MAP IS ======" << std::endl;
		for (std::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << "SIZE ? : " << mp.size() << std::endl;
		std::cout << std::endl << "====== ERASE BY RANGE ======" << std::endl;
		mp.erase(mp.begin(), mp.end());
		std::cout << "====== MAP IS ======" << std::endl;
		for (std::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << "SIZE ? : " << mp.size() << std::endl;

		std::cout << std::endl << "====== CLEAR ======" << std::endl;
		mp.insert(std::make_pair<int, std::string>(1, "Ballet Girl"));
		mp.insert(std::make_pair<int, std::string>(2, "Merci les bleus"));
		mp.insert(std::make_pair<int, std::string>(4, "Bloody Mary"));
		std::cout << "====== MAP IS ======" << std::endl;
		for (std::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << "SIZE ? : " << mp.size() << std::endl;
		mp.clear();
		std::cout << "====== MAP IS ======" << std::endl;
		for (std::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << "SIZE ? : " << mp.size() << std::endl;

		std::cout << std::endl << "====== SWAP ======" << std::endl;
		std::cout << "====== MAP IS ======" << std::endl;
		for (std::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << "====== MAP_RANGE IS ======" << std::endl;
		for (std::map<int, std::string>::iterator it = mp_range.begin(); it != mp_range.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		mp.swap(mp_range);
		std::cout << "====== MAP IS ======" << std::endl;
		for (std::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;
		std::cout << "====== MAP_RANGE IS ======" << std::endl;
		for (std::map<int, std::string>::iterator it = mp_range.begin(); it != mp_range.end(); ++it)
			std::cout << it->first << " | " << it->second << std::endl;

		std::cout << std::endl << "====== FIND ======" << std::endl;
		std::cout << mp.find(2)->second << std::endl;
		std::cout << std::endl << "====== COUNT ======" << std::endl;
		std::cout << mp.count(2) << std::endl;
		std::cout << mp.count(100) << std::endl;

		std::cout << std::endl << "====== LOWER BOUND ======" << std::endl;
		std::cout << mp.lower_bound(6)->first << " | " << mp.lower_bound(6)->second << std::endl;
		std::cout << mp.upper_bound(12)->first << " | " << mp.lower_bound(6)->second << std::endl;
		// std::cout << mp.upper_bound(64)->first << " | " << mp.lower_bound(6)->second << std::endl;
		std::cout << mp.equal_range(6).first->first << " | " << mp.equal_range(6).second->first << std::endl;
	}
	// SET
	{
		std::cout << std::endl << std::endl << "============ STD ============" << std::endl;
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

		std::cout << std::endl << "====== CONSTRUCTOR RANGE =======" << std::endl;
		std::set<std::string> set_range(st.begin(), st.end());
		std::cout << "====== NEW SET_RANGE IS ======" << std::endl;
		for (std::set<std::string>::iterator it = set_range.begin(); it != set_range.end(); ++it)
			std::cout << *it << std::endl;
		set_range.insert("allez");
		std::cout << "====== NEW KEY INSERTED TO NEW SET_RANGE ======" << std::endl;
		std::set<std::string> set_cp(set_range);
		std::cout << "====== NEW SET_CP FROM SET_RANGE IS ======" << std::endl;
		for (std::set<std::string>::iterator it = set_cp.begin(); it != set_cp.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << std::endl << "====== COPY CONSTRUCTOR =======" << std::endl;
		set_cp.erase("allez");
		std::cout << std::endl << "====== ASSIGNATION st = set_cp =======" << std::endl;
		st = set_cp;
		std::cout << "====== SET IS ======" << std::endl;
		for (std::set<std::string>::iterator it = st.begin(); it != st.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << "====== SET_RANGE IS ======" << std::endl;
		for (std::set<std::string>::iterator it = set_range.begin(); it != set_range.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << "====== SET_CP IS ======" << std::endl;
		for (std::set<std::string>::iterator it = set_cp.begin(); it != set_cp.end(); ++it)
			std::cout << *it << std::endl;

		std::cout << std::endl << "====== INSERT ======" << std::endl;
		std::pair<std::set<std::string>::iterator, bool > pair_return;
		pair_return = st.insert("allezkylian");
		std::cout << "====== PAIR_RETURN IS ======" << std::endl;
		std::cout << *pair_return.first << "/" << *pair_return.first << " | " << pair_return.second << std::endl;
		pair_return = st.insert("allezkylian");
		std::cout << "====== PAIR_RETURN IS ======" << std::endl;
		std::cout << *pair_return.first << "/" << *pair_return.first << " | " << pair_return.second << std::endl;
		std::cout << "====== SET IS ======" << std::endl;
		for (std::set<std::string>::iterator it = st.begin(); it != st.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << "====== RANGE INSERT ======" << std::endl;
		st.insert(set_cp.begin(), set_cp.end());
		std::cout << "====== SET IS ======" << std::endl;
		for (std::set<std::string>::iterator it = st.begin(); it != st.end(); ++it)
			std::cout << *it << std::endl;

		std::cout << std::endl << "====== ERASE BY ITERATOR ======" << std::endl;
		st.erase(st.begin());
		std::cout << "====== SET IS ======" << std::endl;
		for (std::set<std::string>::iterator it = st.begin(); it != st.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << std::endl << "====== ERASE BY KEY ======" << std::endl;
		std::cout << st.erase("") << std::endl;
		std::cout << st.erase("lol") << std::endl;
		std::cout << "====== SET IS ======" << std::endl;
		for (std::set<std::string>::iterator it = st.begin(); it != st.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << "SIZE ? : " << st.size() << std::endl;
		std::cout << std::endl << "====== ERASE BY RANGE ======" << std::endl;
		st.erase(st.begin(), st.end());
		std::cout << "====== SET IS ======" << std::endl;
		for (std::set<std::string>::iterator it = st.begin(); it != st.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << "SIZE ? : " << st.size() << std::endl;

		std::cout << std::endl << "====== CLEAR ======" << std::endl;
		st.insert("Ballet Girl");
		st.insert("Merci les bleus");
		st.insert("Bloody Mary");
		std::cout << "====== SET IS ======" << std::endl;
		for (std::set<std::string>::iterator it = st.begin(); it != st.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << "SIZE ? : " << st.size() << std::endl;
		st.clear();
		std::cout << "====== SET IS ======" << std::endl;
		for (std::set<std::string>::iterator it = st.begin(); it != st.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << "SIZE ? : " << st.size() << std::endl;

		std::cout << std::endl << "====== SWAP ======" << std::endl;
		std::cout << "====== SET IS ======" << std::endl;
		for (std::set<std::string>::iterator it = st.begin(); it != st.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << "====== SET_RANGE IS ======" << std::endl;
		for (std::set<std::string>::iterator it = set_range.begin(); it != set_range.end(); ++it)
			std::cout << *it << std::endl;
		st.swap(set_range);
		std::cout << "====== SET IS ======" << std::endl;
		for (std::set<std::string>::iterator it = st.begin(); it != st.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << "====== SET_RANGE IS ======" << std::endl;
		for (std::set<std::string>::iterator it = set_range.begin(); it != set_range.end(); ++it)
			std::cout << *it << std::endl;

		std::cout << std::endl << "====== FIND ======" << std::endl;
		std::cout << *st.find("xd") << std::endl;
		std::cout << std::endl << "====== COUNT ======" << std::endl;
		std::cout << st.count("xd") << std::endl;
		std::cout << st.count("lolmdr") << std::endl;

		std::cout << std::endl << "====== LOWER BOUND ======" << std::endl;
		std::cout << *st.lower_bound("lol") << " | " << *st.lower_bound("lol") << std::endl;
		std::cout << *st.upper_bound("") << " | " << *st.lower_bound("lol") << std::endl;
		std::cout << *st.upper_bound("lolmdr") << " | " << *st.lower_bound("lol") << std::endl;
		std::cout << *st.equal_range("lol").first << " | " << *st.equal_range("lol").second << std::endl;
	}
	return (0);
}