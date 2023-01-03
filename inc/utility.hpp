#ifndef UTILITY_HPP
# define UTILITY_HPP

#include <limits>

namespace ft
{
	// ENABLE_IF
	template <bool Condition, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	// IS_INTEGRAL
	template <class T, T v>
	struct integral_constant
	{
		static const T value = v;
		typedef T value_type;
		typedef integral_constant<T, v> type;
		operator T() const { return v; }
	};
	
	template <class T>
	struct is_integral: integral_constant<bool, std::numeric_limits<T>::is_integer> {};

	// EQUAL

	// equality version
	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	// predicate version
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!(pred(*first1, *first2)))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	// LEXICOGRAPHICAL_COMPARE

	// default version
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2 )
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	// custom version
	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return (false);
			else if (comp(*first1, *first2))
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	// PAIR
	template <class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		// CONSTRUCTORS
		// default
		pair() : first(0), second(0) { return ; }

		// copy
		template <class U, class V>
		pair(const pair<U, V> & pr) : first(pr.first), second(pr.second) { return ; }

		// initialization
		pair (const first_type& a, const second_type& b) : first(a), second(b) { return ; }

		// assignation
		pair& operator= (const pair& pr)
		{
			if (this != &pr)
			{
				this->first = pr.first;
				this->second = pr.second;
			}
			return (*this);
		}

		first_type	first;
		second_type	second;
	};

	// Relational operators
	template <class T1, class T2>
	bool operator== (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) { return (lhs.first == rhs.first && lhs.second == rhs.second); }

	template <class T1, class T2>
	bool operator!= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) { return (!(lhs == rhs)); }

	template <class T1, class T2>
	bool operator< (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) { return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second)); }

	template <class T1, class T2>
	bool operator<= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) { return !(rhs < lhs); }

	template <class T1, class T2>
	bool operator> (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) { return (rhs < lhs); }

	template <class T1, class T2>
	bool operator>= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) { return !(lhs < rhs); }

	// MAKE PAIR
	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y) { return (pair<T1, T2>(x, y)); }
}

#endif