#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include "utility.hpp"
#include "rb_tree.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			/*	MEMBER TYPES	*/
			typedef	Key																						key_type;
			typedef T																						mapped_type;
			typedef pair<const key_type, mapped_type> 														value_type;
			typedef Compare																					key_compare;
			// typename typedef ft::map::value_comp															value_compare;
			typedef Allocator																				allocator_type;
			typedef typename allocator_type::reference														reference;
			typedef typename allocator_type::const_reference												const_reference;
			typedef typename allocator_type::pointer														pointer;
			typedef typename allocator_type::const_pointer													const_pointer;
			typedef typename ft::RBTree<value_type, key_compare, allocator_type>::iterator					iterator;
			typedef typename ft::RBTree<value_type, key_compare, allocator_type>::const_iterator 			const_iterator;
			typedef typename ft::reverse_iterator<iterator>													reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>											const_reverse_iterator;
			typedef std::ptrdiff_t 																			difference_type;
			typedef std::size_t 																			size_type;

			/*	CONSTRUCTORS	*/
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _compare(comp), _al(alloc), _tree() { return ; }

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _compare(comp), _al(alloc), _tree()
			{
				for ( ; first != last; ++first)
					this->_tree.insert(*first);
				return ;
			}

			map (const map& x) : _compare(x._compare), _al(x._al), _tree()
			{
				this->insert(x.begin(), x.end());
				return ;
			}

			/*	OPERATORS	*/
			map& operator= (const map& x)
			{
				if (this != &x)
				{
					this->_al = x._al;
					this->_compare = x._compare;
					this->erase(this->begin(), this->end());
					this->insert(x.begin(), x.end());
				}
				return (*this);
			}

			/*	FUNCTIONS	*/

			/*	ITERATORS	*/
			iterator 		begin() { return (this->_tree.begin()); }
			const_iterator	begin() const { return (this->_tree.begin()); }

			iterator		end() { return (this->_tree.end()); }
			const_iterator	end() const { return (this->_tree.end()); }

			reverse_iterator rbegin() { return (reverse_iterator(this->_tree.end())); }
			reverse_iterator rbegin() const { return (reverse_iterator(this->_tree.end())); }

			reverse_iterator rend() { return (reverse_iterator(this->_tree.begin())); }
			reverse_iterator rend() const { return (reverse_iterator(this->_tree.begin())); }

			/*	CAPACITY	*/
			bool	empty() const { return (this->_tree.empty()); }

			size_type	size() const { return (this->_tree.size()); }

			size_type	max_size() const { return (this->_al.max_size()); }

			/*	ELEMENT ACCESS	*/
			mapped_type& operator[] (const key_type& k) { return ((this->_tree.insert(ft::make_pair(k, mapped_type())).first)->second); }

			// mapped_type& at(const key_type& k) 
			// {
			// 	iterator	it(this->_tree.find(ft::make_pair(k, mapped_type())));

			// 	if (it == NULL)
			// 		throw std::out_of_range("map out of range");
			// 	return (it->second);
			// }

			/*	MODIFIERS	*/

			// single element
			ft::pair<iterator, bool> insert(const value_type& val) { return (this->_tree.insert(val)); }

			// hint
			iterator insert(iterator position, const value_type& val)
			{
				(void)position;
				return (this->_tree.insert(val).first);
			}

			// range
			template <class InputIterator>
			void	insert(InputIterator first, InputIterator last)
			{
				for ( ; first != last; ++first)
					this->_tree.insert(*first);
				return ;
			}

			void	erase(iterator position)
			{
				this->_tree.pop(ft::make_pair(position->first, mapped_type()));
				return ;
			}

			size_type	erase(const key_type& k) { return (this->_tree.pop(ft::make_pair(k, mapped_type()))); }

			void	erase(iterator first, iterator last)
			{
				for ( ; first != last; ++first)
					this->_tree.pop(ft::make_pair(first->first, mapped_type()));
				return ;
			}

		private:
			key_compare										_compare;
			allocator_type									_al;
			RBTree<value_type, key_compare, allocator_type>	_tree;

	};
}

#endif