/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:07:16 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/28 18:58:07 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <deque>
#include <stack>
#include <iterator>

template <typename T, class Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack() : std::stack<T>() {}
		~MutantStack() {}
		MutantStack(const MutantStack& other) : std::stack<T>(other) {}
		MutantStack& operator=(const MutantStack& other)
		{
			std::stack<T>::operator=(other);
			return *this;
		}

		// Type aliases for convenience
		using iterator = typename Container::iterator;
		using const_iterator = typename Container::const_iterator;

		// Iterator functions
		iterator begin()
		{
			return this->c.begin();
		}

		iterator end()
		{
			return this->c.end();
		}

		const_iterator begin() const
		{
			return this->c.begin();
		}

		const_iterator end() const
		{
			return this->c.end();
		}

		const_iterator cbegin() const
		{
			return this->c.cbegin();
		}

		const_iterator cend() const
		{
			return this->c.cend();
		}
};
