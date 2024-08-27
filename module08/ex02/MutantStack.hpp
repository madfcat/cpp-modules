/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:07:16 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/27 18:41:53 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <deque>
#include <stack>
#include <iterator>
#include <utility> // For std::forward

template <typename T, class Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
	public:
		using std::stack<T, Container>::stack; // Inherit constructors

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
