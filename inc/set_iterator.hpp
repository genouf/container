#ifndef SET_ITERATOR_HPP
#define SET_ITERATOR_HPP

#include <iostream>
#include "iterator_traits.hpp"

namespace ft
{
	template < class T, class Value >
	struct set_iterator
	{
		typedef set_iterator	iterator;

		/*	MEMBER TYPES	*/
		typedef typename ft::iterator_traits<T*>::value_type		value_type;
		typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
		typedef typename ft::iterator_traits<T*>::pointer			pointer;
		typedef typename ft::iterator_traits<T*>::reference			reference;
		typedef typename std::bidirectional_iterator_tag			iterator_category;

		/*	CONSTRUCTORS	*/
		set_iterator() : _it(NULL) { return ; }

		set_iterator(pointer src) : _it(src) { return ; }

		set_iterator(iterator const & copy) : _it(copy._it) { return ; }

		iterator & operator=(iterator const &rhs)
		{
			if (this != &rhs)
				this->_it = rhs._it;
			return (*this);
		}

		/*	DESTRUCTOR	*/
		virtual ~set_iterator() { return ; }

		/*	COMPARISON	*/
		bool operator==(iterator const &rhs) const { return (this->_it == rhs._it); }
		bool operator!=(iterator const &rhs) const { return (this->_it != rhs._it); }

		/*	DEREFERENCE	*/
		Value & operator*() const {return (*this->_it->content->first); }
		Value *operator->() const { return (this->_it->content->first); }

		/*	PREFIX INCREMENT	*/
		iterator & operator++()
		{
			if (this->_it->right && this->_it->right->is_null == false)
				this->_it = tree_min(this->_it->right);
			else
			{
				pointer tmp = this->_it;
				while (tmp->parent->is_null != true && tmp != tmp->parent->left)
					tmp = tmp->parent;
				this->_it = tmp->parent;
			}
			return (*this);
		}

		iterator & operator--()
		{
			if (this->_it->left && this->_it->left->is_null == false)
				this->_it = tree_max(this->_it->left);
			else
			{
				pointer tmp = this->_it;
				while (tmp != tmp->parent->right)
					tmp = tmp->parent;
				this->_it = tmp->parent;
			}
			return (*this);
		}

		/*	POSTFIX INCREMENT	*/
		iterator operator++(int)
		{
			iterator	tmp(*this);

			++(*this);
			return (tmp);
		}

		iterator operator--(int)
		{
			iterator	tmp(*this);

			--(*this);
			return (tmp);
		}

		private:
			/*	MEMBER VAR	*/
			pointer _it;

			/*	FUNCTIONS	*/
			pointer	tree_min(pointer node) const
			{
				pointer tmp = node;
			
				while (tmp->left != NULL && tmp->left->is_null == false)
					tmp = tmp->left;
				return (tmp);
			}

			pointer	tree_max(pointer node) const
			{
				pointer tmp = node;
			
				while (tmp->right != NULL && tmp->right->is_null == false)
					tmp = tmp->right;
				return (tmp);
			}
	};
	
}

#endif