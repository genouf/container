#ifndef SET_HPP
# define SET_HPP

#include <iostream>
#include "utility.hpp"
#include "rb_tree_set.hpp"

namespace ft
{
	template < class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
	class set
	{
		public:
			/*	MEMBER TYPES	*/
			typedef T																						key_type;
			typedef T																						value_type;
			typedef	Compare																					key_compare;
			typedef Compare																					value_compare;
			typedef typename Allocator::template rebind< value_type >::other								allocator_type;
			typedef typename allocator_type::reference														reference;
			typedef typename allocator_type::const_reference												const_reference;
			typedef typename allocator_type::pointer														pointer;
			typedef typename allocator_type::const_pointer													const_pointer;
			typedef typename ft::RBTreeSet<value_type, key_compare, allocator_type>::iterator					iterator;
			typedef typename ft::RBTreeSet<value_type, key_compare, allocator_type>::const_iterator 			const_iterator;
			typedef typename ft::reverse_iterator<iterator>													reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>											const_reverse_iterator;
			typedef std::ptrdiff_t 																			difference_type;
			typedef std::size_t 																			size_type;

			/*	CONSTRUCTORS	*/
			explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _compare(comp), _al(alloc), _tree() { return ; }

			template <class InputIterator>
			set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _compare(comp), _al(alloc), _tree()
			{
				for ( ; first != last; ++first)
					this->_tree.insert(*first);
				return ;
			}

			set (const set& x) : _compare(x._compare), _al(x._al), _tree()
			{
				this->insert(x.begin(), x.end());
				return ;
			}

			/*	DESTRUCTOR	*/
			virtual ~set()	{ return; }

			/*	OPERATORS	*/
			set& operator= (const set& x)
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
			reverse_iterator rbegin() const { return (reverse_iterator(this->_tree.end())); }

			reverse_iterator rend() { return (reverse_iterator(this->_tree.begin())); }
			reverse_iterator rend() const { return (reverse_iterator(this->_tree.begin())); }

			/*	CAPACITY	*/
			bool	empty() const { return (this->_tree.empty()); }

			size_type	size() const { return (this->_tree.size()); }

			size_type	max_size() const { return (this->_al.max_size()); }

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
				this->_tree.pop(*position);
				return ;
			}

			size_type	erase(const key_type& k) { return (this->_tree.pop(k)); }

			void	erase(iterator first, iterator last)
			{
				while (first != last)
					this->_tree.pop((*(first++)));
				return ;
			}

			void	swap(set &x)
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

			value_compare value_comp() const { return (this->_compare); }

			/*	OPERATIONS	*/
			iterator	find(const key_type& k) { return (this->_tree.find(k)); }

			const_iterator	find(const key_type& k) const { return (this->_tree.find(k)); }

			size_type	count(const key_type& k) const { return (this->_tree.count(k)); }

			iterator	lower_bound(const key_type& k)
			{
				iterator last = this->end();

				for (iterator first = this->begin(); first != last; ++first)
				{
					 if (!this->_compare(*first, k))
					 	return (first);
				}
				return (last);
			}

			const_iterator	lower_bound(const key_type& k) const
			{
				const_iterator last = this->end();

				for (const_iterator first = this->begin(); first != last; ++first)
				{
					 if (!this->_compare(*first, k))
					 	return (first);
				}
				return (last);
			}

			iterator	upper_bound(const key_type& k)
			{
				iterator last = this->end();

				for (iterator first = begin(); first != last; ++first)
				{
					if (this->_compare(k, *first))
						return (first);
				}
				return (last);
			}

			const_iterator	upper_bound(const key_type& k) const
			{
				const_iterator last = this->end();

				for (const_iterator first = begin(); first != last; ++first)
				{
					if (this->_compare(k, *first))
						return (first);
				}
				return (last);
			}

			pair<iterator, iterator> equal_range(const key_type& k) { return (ft::make_pair(lower_bound(k), upper_bound(k))); }

			pair<const_iterator, const_iterator> equal_range(const key_type& k) const { return (ft::make_pair(this->lower_bound(k), this->upper_bound(k))); }

			/*	ALLOCATOR	*/
			allocator_type	get_allocator() const { return (this->_al); }

		private:
			key_compare											_compare;
			allocator_type										_al;
			RBTreeSet<value_type, key_compare, allocator_type>	_tree;

	};

	/*	RELATIONAL OPERATORS	*/
	template <class T, class Compare, class Alloc>
	bool operator== (const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Compare, class Alloc>
	bool operator!= (const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Compare, class Alloc>
	bool operator< (const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Compare, class Alloc>
	bool operator<= (const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Compare, class Alloc>
	bool operator> (const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Compare, class Alloc>
	bool operator>= (const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	/*	SWAP	*/
	template <class T, class Compare, class Alloc>
	void	swap(set<T, Compare, Alloc>& x, set<T, Compare, Alloc>& y)
	{
		x.swap(y);
		return ;
	}
}

#endif