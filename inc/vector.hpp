#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>

namespace ft
{
	template<class T, class Allocator = std::allocator<T>>
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

		value_type			iterator;
		const value_type	const_iterator;
		

		/*		CONSTRUCTORS		*/
		explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), v_pointer(NULL), alloc(al) {};
		
		explicit vector(size_type)

		private:
			value_type		_size;
			value_type		_capacity;
			value_type 		*_c_ptr;
			allocator_type	alloc;
	};
}

#endif