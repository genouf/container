#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template < class T, class Container = ft::vector<T> >
	class stack
	{
		public:

		/*	MEMBER TYPES	*/
		typedef T 					value_type;
		typedef Container			container_type;
		typedef std::size_t			size_type;

		/*	CONSTRUCTORS	*/
		explicit stack(const container_type& ctnr = container_type()) : _container(ctnr) { return ; }

		virtual ~stack() { return ; }

		/*	FUNCTIONS	*/
		bool empty() const { return (this->_container.empty()); }

		size_type size() const { return (this->_container.size()); }

		value_type& top() { return (this->_container.back()); }
		const value_type& top() const { return (this->_container.back()); }

		void push(const value_type& val)
		{
			this->_container.push_back(val);
			return ;
		}

		void pop()
		{
			this->_container.pop_back();
			return ;
		}

		private:
			container_type	_container;

		/*	RELATIONAL OPERATORS	*/
		template <class Ts, class Containers>
		friend bool operator==(const stack<Ts,Containers>& lhs, const stack<Ts, Containers>& rhs) { return (lhs._container == rhs._container); }

		template <class Ts, class Containers>
		friend bool operator!=(const stack<Ts,Containers>& lhs, const stack<Ts, Containers>& rhs) { return (lhs._container != rhs._container); }

		template <class Ts, class Containers>
		friend bool operator<(const stack<Ts,Containers>& lhs, const stack<Ts, Containers>& rhs) { return (lhs._container < rhs._container); }

		template <class Ts, class Containers>
		friend bool operator<=(const stack<Ts,Containers>& lhs, const stack<Ts, Containers>& rhs) { return (lhs._container <= rhs._container); }

		template <class Ts, class Containers>
		friend bool operator>(const stack<Ts,Containers>& lhs, const stack<Ts, Containers>& rhs) { return (lhs._container > rhs._container); }

		template <class Ts, class Containers>
		friend bool operator>=(const stack<Ts,Containers>& lhs, const stack<Ts, Containers>& rhs) { return (lhs._container >= rhs._container); }
	};
}

#endif