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

			class value_compare : ft::binary_function<value_type, value_type, bool>
			{
				friend class map<key_type, mapped_type, key_compare, Allocator>;

				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}

				public:
					bool operator() (const value_type& x, const value_type& y) const { return (comp(x.first, y.first)); }
			};

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

			/*	DESTRUCTOR	*/
			virtual ~map()	{ return; }

			/*	OPERATORS	*/
			map& operator= (const map& x)
			{
				if (this != &x)
				{
					this->_al = x._al;
					this->_compare = x._compare;
					this->clear();
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
			const_reverse_iterator rbegin() const { return (const_reverse_iterator(this->_tree.end())); }

			reverse_iterator rend() { return (reverse_iterator(this->_tree.begin())); }
			const_reverse_iterator rend() const { return (const_reverse_iterator(this->_tree.begin())); }

			/*	CAPACITY	*/
			bool	empty() const { return (this->_tree.empty()); }

			size_type	size() const { return (this->_tree.size()); }

			size_type	max_size() const { return (this->_tree.max_size()); }

			/*	ELEMENT ACCESS	*/
			mapped_type& operator[] (const key_type& k) { return ((this->_tree.insert(ft::make_pair(k, mapped_type())).first)->second); }

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
				while (first != last)
					this->_tree.pop(ft::make_pair((first++)->first, mapped_type()));
				return ;
			}

			void	swap(map &x)
			{
				this->_tree.swap(x._tree);
				return ; 
			}

			void	clear()
			{
				this->erase(this->begin(), this->end());
				return ;
			}

			/*	OBSERVERS	*/
			key_compare key_comp() const { return (this->_compare); }

			value_compare value_comp() const { return (key_compare()); }

			/*	OPERATIONS	*/
			iterator	find(const key_type& k) { return (this->_tree.find(ft::make_pair(k, mapped_type()))); }

			const_iterator	find(const key_type& k) const { return (this->_tree.find(ft::make_pair(k, mapped_type()))); }

			size_type	count(const key_type& k) const { return (this->_tree.count(ft::make_pair(k, mapped_type()))); }

			iterator	lower_bound(const key_type& k)
			{
				iterator last = this->end();

				for (iterator first = this->begin(); first != last; ++first)
				{
					 if (!this->_compare(first->first, k))
					 	return (first);
				}
				return (last);
			}

			const_iterator	lower_bound(const key_type& k) const
			{
				const_iterator last = this->end();

				for (const_iterator first = this->begin(); first != last; ++first)
				{
					 if (!this->_compare(first->first, k))
					 	return (first);
				}
				return (last);
			}

			iterator	upper_bound(const key_type& k)
			{
				iterator last = this->end();

				for (iterator first = begin(); first != last; ++first)
				{
					if (this->_compare(k, first->first))
						return (first);
				}
				return (last);
			}

			const_iterator	upper_bound(const key_type& k) const
			{
				const_iterator last = this->end();

				for (const_iterator first = begin(); first != last; ++first)
				{
					if (this->_compare(k, first->first))
						return (first);
				}
				return (last);
			}

			pair<iterator, iterator> equal_range(const key_type& k) { return (ft::make_pair(lower_bound(k), upper_bound(k))); }

			pair<const_iterator, const_iterator> equal_range(const key_type& k) const { return (ft::make_pair(this->lower_bound(k), this->upper_bound(k))); }

			/*	ALLOCATOR	*/
			allocator_type	get_allocator() const { return (this->_al); }

		private:
			key_compare										_compare;
			allocator_type									_al;
			RBTree<value_type, key_compare, allocator_type>	_tree;

	};

	/*	RELATIONAL OPERATORS	*/
	template <class Key, class T, class Compare, class Alloc>
	bool operator== (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!= (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator< (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<= (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator> (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>= (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	/*	SWAP	*/
	template <class Key, class T, class Compare, class Alloc>
	void	swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y)
	{
		x.swap(y);
		return ;
	}
}

#endif