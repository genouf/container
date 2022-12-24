#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include <iostream>

namespace ft
{
	template <class T>
	struct random_access_iterator 
	{
			typedef	random_access_iterator iterator;

			/*		MEMBER TYPES		*/
			typedef typename std::random_access_iterator_tag	iterator_category;
			typedef typename std::ptrdiff_t 					difference_type;
			typedef T 											value_type;
			typedef T*											pointer;
			typedef	T&											reference;

			/*	CONSTRUCTORS	*/
			random_access_iterator(void) : _it(NULL) { return ; }

			random_access_iterator(pointer src) : _it(src) { return ; }

			iterator &operator=(iterator const &rhs)
			{ 
				this->_it = rhs._it;
				return (*this);
			}

			/*	DESTRUCTOR	*/
			virtual ~random_access_iterator() { return ; }

			/*	DEREFERENCE	*/
			reference operator*(void) const { return (*this->_it); }
			pointer operator->(void) const { return (this->_it); }

			/*	PREFIX INCREMENT	*/
			reference operator++(void) { this->_it++; return (*this->_it); }
			reference operator--(void) { this->_it--; return (*this->_it); }

			/*	POSTFIX INCREMENT	*/
			iterator operator++(int) 
			{
				iterator	tmp = *this;

				++(*this);
				return (tmp);
			}
			iterator operator--(int) 
			{
				iterator	tmp = *this;

				--(*this);
				return (tmp);
			}

			/*	COMPARISON	*/
			bool operator==(iterator const &rhs) const { return (this->_it == rhs._it); }
			bool operator!=(iterator const &rhs) const { return (this->_it != rhs._it); }
			bool operator>(iterator const &rhs) const { return (this->_it > rhs._it); }
			bool operator<(iterator const &rhs) const { return (this->_it < rhs._it); }
			bool operator>=(iterator const &rhs) const { return (this->_it >= rhs._it); }
			bool operator<=(iterator const &rhs) const { return (this->_it <= rhs._it); }

			/*	ADDITION AND SUBTRACTION*/
			iterator operator+=(int n)
			{
				this->_it += n;
				return (*this);
			}
			iterator operator-=(int n)
			{
				this->_it -= n;
				return (*this);
			}
			iterator operator+(int n) const
			{
				iterator	tmp(*this);

				return (tmp += n);
			}
			iterator operator-(int n) const
			{
				iterator tmp(*this);

				return (tmp -= n);
			}
			friend iterator operator+(int n, iterator it) { return (it += n); }
			friend iterator operator-(int n, iterator it) { return (it -= n); }

			/*	DEREFERENCE OPERATOR	*/
			reference operator[](unsigned int n) { return (this->_it[n]); }

		private:
			/*	MEMBER VAR	*/
			pointer _it;
	};
}

#endif