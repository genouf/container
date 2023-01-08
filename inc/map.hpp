#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include "utility.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		/*	MEMBER TYPES	*/
		typedef	Key												key_type;
		typedef T												mapped_type;
		typedef pair<const key_type, mapped_type> 				value_type;
		typedef Compare											key_compare;
		// typename typedef ft::map::value_comp					value_compare;
		typedef Allocator										allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename ft::random_access_iterator<T> 			iterator;
		typedef typename ft::random_access_iterator<const T> 	const_iterator;
		typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef std::ptrdiff_t 									difference_type;
		typedef std::size_t 									size_type;

		/*	CONSTRUCTORS	*/
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{

		}


		private:
			// variable de l'arbre rouge et noir
			key_compare	m_key_comp;
	};
}

#endif