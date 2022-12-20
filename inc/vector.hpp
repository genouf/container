#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include "vector_iterator.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T>>
	class vector
	{
		public: 


		/*		MEMBER TYPES		*/
		typedef T value_type;
		typedef Allocator allocator_type;

		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename ft::vector_iterator iterator<T>;
		typedef typename std::random_access_iterator_tag iterator_category;
		typedef typename std::ptrdiff_t difference_type;

		/*		CONSTRUCTORS		*/
		/*	Empty container constructor	*/
		explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _container(NULL), _al(alloc) { return ; };
		
		/*	Fill constructor	*/
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _al(alloc)
		{
			this->_container = al.allocate(_capacity);
			for (int i = 0; i < _size; i++)
				_container[i] = val;
			return ;
		}

		/*	Range constructor	*/
		// template <class InputIterator>
		// vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		// {

		// }

		/*	Copy constructor	*/
		vector (const vector& x) : _size(x._size), _capacity(x._capacity), _al(x._al)
		{
			this->_container = _al.allocate(_capacity);
			for (int i = 0; i < size; i++)
				_container[i] = x._container[i];
			return (*this);
		}

		/*	DESTRUCTOR	*/
		virtual ~vector()
		{
			_al.deallocate(_container, _capacity);
			return ;
		}

		/*	OPERATORS	*/
		vector& operator=(const vector& x)
		{
			if (*this != x)
			{
				this->_container = _al.allocate(_capacity);
				for (int i = 0; i < size; i++)
					_container[i] = x._container[i];
			}
			return (*this);
		}

		private:
			value_type		_size;
			value_type		_capacity;
			value_type 		*_container;
			allocator_type	_al;
	};
}

#endif