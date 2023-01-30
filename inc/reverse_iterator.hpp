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
		typedef typename iterator_traits<Iterator>::value_type value_type;
		typedef typename iterator_traits<Iterator>::difference_type difference_type;
		typedef typename iterator_traits<Iterator>::pointer pointer;
		typedef typename iterator_traits<Iterator>::reference reference;
		typedef typename iterator_traits<Iterator>::iterator_category iterator_category;

		/*	CONSTRUCTORS	*/
		// default constructor
		reverse_iterator(void) : _base_it(NULL) { return ; }

		// initialization constructor
		explicit reverse_iterator(iterator_type it) : _base_it(it.base()) { return ; }

		// copy constructor
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter>& rev_it) : _base_it(rev_it.base()) { return ; }

		virtual ~reverse_iterator() { return ; }
		
		/*	OPERATORS	*/
		// derefence
		reference operator*() const
		{
			iterator_type	tmp (this->_base_it);

			return (*(--tmp)); 
		}

		// addition
		reverse_iterator operator+(difference_type n) const { return (reverse_iterator(this->_base_it - n)); }

		// pre_increment
		reverse_iterator & operator++() 
		{ 
			this->_base_it--;
			return (*this);
		}

		// post_increment
		reverse_iterator operator++(int)
		{
			reverse_iterator tmp(*this);

			++(*this);
			return (tmp);
		}

		// advance
		reverse_iterator & operator+=(difference_type n)
		{
			this->_base_it -= n;
			return (*this);
		}

		// substraction
		reverse_iterator operator-(difference_type n) const { return (reverse_iterator(this->_base_it + n)); }

		// pre_decrease
		reverse_iterator & operator--() 
		{ 
			this->_base_it++;
			return (*this);
		}

		// post_decrease
		reverse_iterator operator--(int)
		{
			reverse_iterator tmp(*this);

			--(*this);
			return (tmp);
		}

		// retrocede
		reverse_iterator & operator-=(difference_type n)
		{
			this->_base_it += n;
			return (*this);
		}

		// dereference
		pointer operator->() const { return (&(*(this->_base_it - 1))); }

		// dereference with offset
		reference operator[] (difference_type n) const { return (this->_base_it[-n-1]); }

		/*	FUNCTIONS	*/
		iterator_type base() const { return (this->_base_it); }

		private: 
			/*	MEMBER VAR	*/
			iterator_type _base_it;
	};

	/*	RELATIONAL OPERATORS	*/
	template<class Iterator, class Iterator2>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() == rhs.base()); }

	template<class Iterator, class Iterator2>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() != rhs.base()); }

	template<class Iterator, class Iterator2>
	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() > rhs.base()); }

	template<class Iterator, class Iterator2>
	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() >= rhs.base()); }

	template<class Iterator, class Iterator2>
	bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() < rhs.base()); }

	template<class Iterator, class Iterator2>
	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() <= rhs.base()); }

	/*	ADDITION	*/
	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{
		return (reverse_iterator<Iterator>(rev_it.base() - n));
	}

	// template< class Iterator1, class Iterator2 >
	// typename reverse_iterator<Iterator1>::difference_type operator+( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	// {
	// 	return (lhs.base() + rhs.base());
	// }

	// /*	SUBSTRACTION*/
	// template <class Iterator>
	// reverse_iterator<Iterator> operator-(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	// {
	// 	return (reverse_iterator<Iterator>(rev_it.base() + n));
	// }

	template< class Iterator1, class Iterator2 >
	typename reverse_iterator<Iterator1>::difference_type operator-( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return (rhs.base() - lhs.base());
	}
}

#endif