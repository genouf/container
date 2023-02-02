/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:05:20 by genouf            #+#    #+#             */
/*   Updated: 2023/02/02 10:05:21 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include <iostream>
#include "iterator_traits.hpp"

namespace ft
{
	template <class T, class Node>
	struct tree_iterator
	{
		typedef tree_iterator	iterator;

		/*	MEMBER TYPES	*/
		typedef typename ft::iterator_traits<T*>::value_type		value_type;
		typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
		typedef typename ft::iterator_traits<T*>::pointer			pointer;
		typedef typename ft::iterator_traits<T*>::reference			reference;
		typedef typename std::bidirectional_iterator_tag			iterator_category;
		typedef Node *												node_pointer;

		/*	CONSTRUCTORS	*/
		tree_iterator() : _it(NULL) { return ; }

		tree_iterator(node_pointer src) : _it(src) { return ; }

		tree_iterator(iterator const & copy) : _it(copy.base()) { return ; }

		reference operator=(iterator const &rhs)
		{
			if (this != &rhs)
				this->_it = rhs._it;
			return (*this->_it->content);
		}

		/*	DESTRUCTOR	*/
		virtual ~tree_iterator() { return ; }

		/*	COMPARISON	*/
		bool operator==(iterator const &rhs) const { return (this->_it == rhs._it); }
		bool operator!=(iterator const &rhs) const { return (this->_it != rhs._it); }

		operator tree_iterator<const T, const Node> () { return (tree_iterator<const T, const Node>(this->_it)); }

		/*	DEREFERENCE	*/
		reference 	operator*() const {return (*(this->_it->content)); }
		pointer		operator->() const { return (this->_it->content); }

		/*	PREFIX INCREMENT	*/
		tree_iterator & operator++()
		{
			if (this->_it->right && this->_it->right->is_null == false)
				this->_it = tree_min(this->_it->right);
			else
			{
				node_pointer tmp = this->_it;
				while (tmp->parent->is_null != true && tmp != tmp->parent->left)
					tmp = tmp->parent;
				this->_it = tmp->parent;
			}
			return (*this);
		}

		tree_iterator & operator--()
		{
			if (this->_it->left && this->_it->left->is_null == false)
				this->_it = tree_max(this->_it->left);
			else
			{
				node_pointer tmp = this->_it;
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

		node_pointer	base() const { return (this->_it); }

		private:
			/*	MEMBER VAR	*/
			node_pointer _it;

			/*	FUNCTIONS	*/
			node_pointer	tree_min(node_pointer node) const
			{
				node_pointer tmp = node;
			
				while (tmp->left != NULL && tmp->left->is_null == false)
					tmp = tmp->left;
				return (tmp);
			}

			node_pointer	tree_max(node_pointer node) const
			{
				node_pointer tmp = node;
			
				while (tmp->right != NULL && tmp->right->is_null == false)
					tmp = tmp->right;
				return (tmp);
			}
	};
	
}

#endif