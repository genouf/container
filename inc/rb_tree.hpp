#ifndef RB_TREE_HPP
# define RB_TREE_HPP

#include <iostream>
#include "utility.hpp"

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T>> >
class	RBTree
{
	public:

		/*	MEMBER TYPES	*/
		typedef Key			key_type;
		typedef	T			value_type;
		typedef Allocator	allocator_type;
		typedef Compare		key_compare;

		/*	CONSTRUCTORS	*/
		RBTree(const allocator_type& alloc = allocator_type()) : _al(alloc)
		{ 
			this->_root = this->_al.allocate(1);
			this->_al.construct(this->_root, Node());
			return ;
		}

		/*	DESTRUCTOR	*/
		virtual ~RBTree() { return ; }

		/*	FUNCTIONS	*/
		Node	*create_node(Node *parent)
		{
			Node	*new_node;

			new_node = this->_al.allocator(1);
			this->_al.construct(new_node, Node());
			new_node->parent = parent;
			return (new_node);
		}

		void	assign_node(Node *node, key_type key, value_type data)
		{
			node->key = key;
			node->data = data;
			node->left = create_node(node);
			node->right = create_node(node);
			node->color = 1;
			return ;
		}

		void	insert(key_type key, value_type data)
		{
			if (this->_root->left == NULL || this->_root->right)
			{
				this->_root->key = key;
				this->_root->data = data;
				this->_root->color = 0;
			}
			else
			{
				Node	*i = this->_root;
				while (i->left != NULL && i->right != NULL)
				{
					// si il est plus petit
					if (key_compare(key, i->key) == true)
					{
						
					}
					// si il est plus grand
					else if (key_compare(key, i->key) == false)
					{

					}
					// si il est egal
					else if (!key_compare(key, i->key) && !key_compare(i->key, key))
					{
						
					}
				}
			}
		}

	private:

		/*	MAIN STRUCT	*/

		template < class Key, class T>
		struct Node
		{
			Node() : key(0), data(0), parent(NULL), left(NULL), right(NULL), color(0) { return ; }
			virtual ~Node() { return ; }

			Key		key;
			T		data;
			Node	*parent;
			Node	*left;
			Node	*right;
			int		color;
		};

		/*	MEMBER VAR	*/
		Node			*_root;
		allocator_type	_al;
};

#endif
