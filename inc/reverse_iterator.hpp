#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <class Iterator>
	struct reverse_iterator
	{
		/*	MEMBER TYPES	*/
		typedef Iterator iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename iterator_traits<Iterator>::value_type value_type;
		typedef typename iterator_traits<Iterator>::difference_type difference_type;
		typedef typename iterator_traits<Iterator>::pointer pointer;
		typedef typename iterator_traits<Iterator>::reference reference;

		/*	CONSTRUCTORS	*/
		reverse_iterator(void) : _base_it(NULL) { return ; }

		explicit reverse_iterator(iterator_type it) : _base_it(it - 1) { return ; }

		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter>& rev_it) : _base_it(rev_it._base_it) { return ; }

		/*	OPERATORS	*/


		/*	FUNCTIONS	*/
		iterator_type base() const { return (this->_base_it); }

		private: 
			/*	MEMBER VAR	*/
			iterator_type _base_it;
	};
}

#endif