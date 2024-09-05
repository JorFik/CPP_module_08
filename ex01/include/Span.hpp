/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:35:48 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/05 17:02:39 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <set>
# include <cstddef>

typedef std::multiset<int>::iterator	ms_iterator;

class Span
{
	private:
		size_t				_capacity;
		std::multiset<int>	_numbers;

		std::set<int>		_getSpans(std::set<int> &spans);

	public:
		Span()	=	delete;
		~Span()	=	default;

		Span(unsigned int capacity);
		Span(Span const &other);
		Span &operator=(Span const &other);

		void	addNumber(int number);
		int		shortestSpan(void);
		int		longestSpan(void);
		template <typename InputIterator>
		void	addNumber(InputIterator begin, InputIterator end);
};

template <typename InputIterator>
void Span::addNumber(InputIterator begin, InputIterator end)
{
	if (_numbers.size() + std::distance(begin, end) > _capacity)
		throw std::out_of_range("Span is full");
	_numbers.insert(begin, end);
}
