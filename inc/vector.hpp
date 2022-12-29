#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "random_access_iterator.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public: 

		/*		MEMBER TYPES		*/
		typedef T 												value_type;
		typedef Allocator 										allocator_type;
		typedef typename allocator_type::reference 				reference;
		typedef typename allocator_type::const_reference 		const_reference;
		typedef typename allocator_type::pointer 				pointer;
		typedef typename allocator_type::const_pointer 			const_pointer;
		typedef typename ft::random_access_iterator<T> 			iterator;
		typedef typename ft::random_access_iterator<const T> 	const_iterator;
		typedef std::ptrdiff_t 									difference_type;
		typedef std::size_t 									size_type;

		/*		CONSTRUCTORS		*/
		/*	Empty container constructor	*/
		explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _container(0), _al(alloc) { return ; };
		
		/*	Fill constructor	*/
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _al(alloc)
		{
			this->_container = this->_al.allocate(_capacity);
			for (size_type i = 0; i < this->_size; i++)
				this->_al.construct(this->_container + i, val);
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
			this->_container = this->_al.allocate(_capacity);
			for (size_type i = 0; i < this->_size; i++)
				this->_al.construct(this->_container + i, x._container[i]);
		}

		/*	DESTRUCTOR	*/
		virtual ~vector()
		{
			for (size_type i = 0; i < this->_size; i--)
				this->_al.destroy(this->_container + i);
			if (this->_container)
				this->_al.deallocate(this->_container, this->_capacity);
			return ;
		}

		/*	OPERATORS	*/
		vector& operator=(const vector& x)
		{
			if (this != &x)
			{
				for (size_type i = 0; i < this->_size; i--)
					this->_al.destroy(this->_container + i);
				if (this->_capacity < x._capacity)
				{
					if (this->_container)
						this->_al.deallocate(this->_container, this->_capacity);
					this->_capacity = x._capacity;
					this->_container = this->_al.allocate(this->_capacity);
				}
				this->_size = x._size;
				for (size_type i = 0; i < this->_size; i++)
					this->_al.construct(this->_container + i, x._container[i]);
			}
			return (*this);
		}

		reference operator[] (size_type n) { return (this->_container[n]); }

		/*	FUNCTIONS	*/

		/*	Iterators :	*/
		iterator 		begin() { return (iterator(this->_container)); }
		const_iterator	begin() const { return (iterator(this->_container)); }

		iterator		end() { return (iterator(this->_container + this->_size)); }
		const_iterator	end() const { return (iterator(this->_container + this->_size)); }

		/*	Capacity :	*/
		size_type	size() const { return (this->_size); }

		size_type	max_size() const { return (this->_al.max_size()); }

		void	resize(size_type n, value_type val = value_type())
		{
			if (n < this->_size)
			{
				for (size_type i = this->_size - 1; i < n; i++)
					this->_al.destroy(this->_container + i);
				this->_size = n;
			}
			if (n > this->_size)
			{
				reserve(n);
				for (size_type i = this->_size; i < n; i++)
					this->_al.construct(this->_container + i, val);
				this->_size = n;
			}
			return ;
		}

		size_type	capacity() const { return (this->_capacity); }

		bool	empty() const { return ((this->_size) ? false : true); }

		void	reserve (size_type n)
		{
			value_type	*tmp;

			if (n > this->_capacity)
			{
				tmp = this->_al.allocate(n);
				for (size_type i = 0; i < this->_size; i++)
					this->_al.construct(tmp + i, this->_container[i]);
				for (size_type i = 0; i < this->_size; i++)
					this->_al.destroy(this->_container + i);
				if (this->_container)
					this->_al.deallocate(this->_container, this->_capacity);
				this->_container = tmp;
				this->_capacity = n;
			}
			return ;
		}

		void	shrink_to_fit()
		{
			value_type	*tmp;

			if (this->_capacity > this->_size)
			{
				tmp = this->_al.allocate(this->_size);
				for (size_type i = 0; i < this->_size; i++)
					this->_al.construct(tmp + i, this->_container[i]);
				for (size_type i = 0; i < this->_size; i++)
					this->_al.destroy(this->_container + i);
				if (this->_container)
					this->_al.deallocate(this->_container, this->_capacity);
				this->_container = tmp;
				this->_capacity = this->_size;
			}
			return ;
		}

		/*	Element access :	*/
		// reference at(size_type n)

		/*	Modifiers	*/


		private:
			/*	MEMBER VAR	*/
			size_type		_size;
			size_type		_capacity;
			value_type 		*_container;
			allocator_type	_al;
	};
}

#endif