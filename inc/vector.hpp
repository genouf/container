/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:05:25 by genouf            #+#    #+#             */
/*   Updated: 2023/02/02 10:05:26 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "utility.hpp"

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
		typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
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
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename enable_if<!is_integral<InputIterator>::value>::type* = 0) : _size(0), _capacity(0), _container(0), _al(alloc)
		{
			size_type	size = std::distance(first, last);

			this->_size = size;
			this->_capacity = this->_size;
			this->_container = this->_al.allocate(this->_capacity);
			for (size_type i = 0; i < this->_size; i++)
			{
				this->_al.construct(this->_container + i, *first);
				first++;
			}
			return ;
		}

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

		const_reference operator[] (size_type n) const { return (this->_container[n]); }
		
		/*	FUNCTIONS	*/

		/*	ITERATORS :	*/
		iterator 		begin() { return (this->_container); }
		const_iterator	begin() const { return (this->_container); }

		iterator		end() { return (this->_container + this->_size); }
		const_iterator	end() const { return (this->_container + this->_size); }

		reverse_iterator rbegin() { return (reverse_iterator(this->end())); }
		const_reverse_iterator rbegin() const { return (reverse_iterator(this->end())); }

		reverse_iterator rend() { return (reverse_iterator(this->begin())); }
		const_reverse_iterator rend() const { return (reverse_iterator(this->begin())); }

		/*	CAPACITY :	*/
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

		/*	ELEMENT ACCESS :	*/
		reference at(size_type n)
		{
			if (n > this->_size - 1)
				throw std::out_of_range("vector out of range");
			return (*(this->_container + n));
		}

		const_reference at(size_type n) const
		{
			if (n > this->_size - 1)
				throw std::out_of_range("vector out of range");
			return (*(this->_container + n));
		}

		reference front() { return (*this->begin()); }
		const_reference front() const { return (*this->begin()); }

		reference back() { return (*(this->end() - 1)); }
		const_reference back() const { return (*(this->end() - 1)); }

		/*	MODIFIERS	*/

		// range version
		template <class InputIterator>
		void	assign(InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0)
		{
			size_type	range = std::distance(first, last);
			size_type		i = 0;

			this->clear();
			if (range > this->_capacity)
				reserve(range);
			for (InputIterator tmp = first; tmp != last; tmp++)
			{
				this->_al.construct(this->_container + i, *tmp);
				i++;
			}
			this->_size = range;
			return ;
		}

		// fill version
		void	assign(size_type n, const value_type& val)
		{
			this->clear();
			if (n > this->_capacity)
				reserve(n);
			for (size_type i = 0; i < n; i++)
				this->_al.construct(this->_container + i, val);
			this->_size = n;
			return ;
		}

		void	push_back(const value_type& val)
		{
			if (this->_size == this->_capacity)
			{
				if (this->_capacity == 0)
					reserve(1);
				else
					reserve(this->_capacity * 2);
			}
			this->_al.construct(this->_container + this->_size, val);
			this->_size++;
			return ;
		}

		void	pop_back()
		{
			this->_al.destroy(this->_container + this->_size - 1);
			this->_size--;
		}

		// single element version
		iterator	insert(iterator position, const value_type& val)
		{
			size_type	index = position - this->begin();

			if (this->_size == this->_capacity)
			{
				if (this->_capacity == 0)
					reserve(1);
				else
					reserve(this->_capacity * 2);
			}
			this->_size++;
			for (size_type i = this->_size - 1; i != index; i--)
			{
				if (i != this->_size - 1)
					this->_al.destroy(this->_container + i);
				this->_al.construct(this->_container + i, this->_container[i - 1]);
			}
			this->_al.destroy(this->_container + index);
			this->_al.construct(this->_container + index, val);
			return (iterator(this->_container + index));
		}

		// fill version
		void	insert(iterator position, size_type n, const value_type& val)
		{
			size_type	index = position - this->begin();
			size_type tmp = this->_capacity;

			if (this->_size + n > this->_capacity)
			{
				if (tmp == 0)
					tmp = 1;
				while (this->_size + n > tmp)
					tmp *= 2;
				reserve(tmp);
			}
 			this->_size += n;
			for (size_type i = this->_size - 1; i != index + n - 1; i--)
			{
				if (!(i > index) && !(i < index + n - 1))
					this->_al.destroy(this->_container + i);
				this->_al.construct(this->_container + i, this->_container[i - n]);
			}
			for (size_type i = index + n - 1; i != (index + n - 1) - n; i--)
			{
				this->_al.destroy(this->_container + i);
				this->_al.construct(this->_container + i, val);
			}
			return ;
		}

		// range version
		template <class InputIterator>
		void	insert(iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0)
		{
			size_type	size = std::distance(first, last);
			size_type	index = position - this->begin();
			size_type	tmp = this->_capacity;

			if (this->_size + size > this->_capacity)
			{
				if (tmp == 0)
					tmp = 1;
				while (this->_size + size > tmp)
					tmp *= 2;
				reserve(tmp);
			}
			this->_size += size;
			for (size_type i = this->_size - 1; i != index + size - 1; i--)
			{
				if (!(i > index) && !(i < index + size - 1))
					this->_al.destroy(this->_container + i);
				this->_al.construct(this->_container + i, this->_container[i - size]);
			}
			last--;
			for (size_type i = index + size - 1; i != (index + size - 1) - size; i--)
			{
				this->_al.destroy(this->_container + i);
				this->_al.construct(this->_container + i, *last);
				last--;
			}
			return ;
		}

		// single element version
		iterator erase(iterator position)
		{
			size_type	index = position - this->begin();

			// std::cout << "index is " << index << std::endl;
			if (this->_size == 0)
				return (position);
			for (size_type i = index; i < this->_size - 1; ++i)
			{
				this->_al.destroy(this->_container + i);
				this->_al.construct(this->_container + i, this->_container[i + 1]);
			}
			this->_al.destroy(this->_container + this->_size - 1);
			this->_size--;
			return (iterator(this->_container + index));
		}

		// range version
		iterator	erase(iterator first, iterator last)
		{
			size_type	index = first - this->begin();
			size_type	size = last - first;
			size_type	i = index;
			
			if (this->_size == 0)
				return (first);
			if (last < first || first == last || (first < this->begin() || last > this->end()))
				return (first);
			for ( ; i < index + size; i++)
				this->_al.destroy(this->_container + i);
			i = index;
			for (size_type j = index + size; j < this->_size; j++)
			{
				this->_al.construct(this->_container + i, this->_container[j]);
				this->_al.destroy(this->_container + j);
				i++;
			}
			this->_size -= size;
			return (iterator(this->_container + index));
		}

		void	swap(vector& x)
		{
			vector<T> tmp;

			if (*this != x)
			{
				tmp._al = this->_al;
				tmp._capacity = this->_capacity;
				tmp._size = this->_size;
				tmp._container = this->_container;
				this->_al = x._al;
				this->_capacity = x._capacity;
				this->_size = x._size;
				this->_container = x._container;
				x._al = tmp._al;
				x._capacity = tmp._capacity;
				x._size = tmp._size;
				x._container = tmp._container;
				tmp._container = NULL;
			}
			return ;
		}

		void	clear()
		{
			for (size_type i = 0; i < this->_size; i++)
				this->_al.destroy(this->_container + i);
			this->_size = 0;
			return ;
		}

		/*	ALLOCATOR	*/
		allocator_type	get_allocator() const { return (this->_al); }

		private:
			/*	MEMBER VAR	*/
			size_type		_size;
			size_type		_capacity;
			value_type 		*_container;
			allocator_type	_al;

	};

	/*	RELATIONAL OPERATORS	*/
	template <class T, class Alloc>
	bool	operator== (const vector<T, Alloc> &lhs, const vector<T, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool	operator!= (const vector<T, Alloc> &lhs, const vector<T, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool	operator< (const vector<T, Alloc> &lhs, const vector<T, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool	operator<= (const vector<T, Alloc> &lhs, const vector<T, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool	operator> (const vector<T, Alloc> &lhs, const vector<T, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool	operator>= (const vector<T, Alloc> &lhs, const vector<T, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	/*	SWAP	*/
	template <class T, class Alloc>
	void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
	{
		x.swap(y);
		return ;
	}
}

#endif