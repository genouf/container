#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include <iostream>

namespace ft
{
	template <class T>
	struct vector_iterator 
	{
			typedef	vector_iterator<T> self;

			/*		MEMBER TYPES		*/
			typedef typename std::random_access_iterator_tag iterator_category;
			typedef typename std::ptrdiff_t difference_type;
			typedef T 	value_type;
			typedef T*	pointer;
			typedef	T&	reference;

			/*	BASICS PROPERTIES	*/
			vector_iterator(void) : _it(NULL) { return ; }
			vector_iterator(pointer src) : _it(src) { return ; }
			self &operator=(self const &rhs)
			{ 
				this->_it = rhs;
				return (*this);
			}
			virtual ~vector_iterator() { return ; }

			/*	DEREFERENCE	*/
			reference operator*(void) const { return (*this->_it); }
			pointer operator->(void) const { return (*this->_it); }

			/*	PREFIX INCREMENT	*/
			reference operator++(void) { this->_it++; return (*this); }
			reference operator--(void) { this->_it--; return (*this); }

			/*	POSTFIX INCREMENT	*/
			self operator++(T) 
			{
				self	tmp = *this;

				++(*this);
				return (tmp);
			}
			self operator--(T) 
			{
				self	tmp = *this;

				--(*this);
				return (tmp);
			}

			/*	COMPARISON	*/
			bool operator==(self const &rhs) const { return (this->_it == rhs._it); }
			bool operator!=(self const &rhs) const { return (this->it != rhs._it); }
			bool operator>(self const &rhs) const { return (this->_it > rhs._it); }
			bool operator<(self const &rhs) const { return (this->_it < rhs._it); }
			bool operator>=(self const &rhs) const { return (this->_it >= rhs._it); }
			bool operator<=(self const &rhs) const { return (this->_it <= rhs._it); }

			/*	ADDITION AND SUBTRACTION*/
			self operator+=(int n)
			{
				this->_it += n;
				return (*this);
			}
			self operator-=(int n)
			{
				this->_it -= n;
				return (*this);
			}
			self operator+(int n) const
			{
				self	tmp(*this);

				return (tmp += n);
			}
			self operator-(int n) const
			{
				self tmp(*this);

				return (tmp -= n);
			}
			friend self operator+(int n, self it) { return (it += n); }
			friend self operator-(int n, self it) { return (it -= n); }

			/*	DEREFERENCE OPERATOR	*/
			reference operator[](unsigned int n) { return (this->_it[n]); }

		private:
			/*	MEMBER VAR	*/
			pointer _it;
	};
}

#endif