/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:50:51 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/05 17:41:03 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int capacity) : _capacity(capacity) {}

Span::Span(Span const &other) : Span(other._capacity)
{
	for (int number : other._numbers)
		_numbers.insert(number);
}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		_capacity = other._capacity;
		_numbers.clear();
		for (int number : other._numbers)
			_numbers.insert(number);
	}
	return (*this);
}

void Span::addNumber(int number)
{
	if (_numbers.size() < _capacity)
		_numbers.insert(number);
	else
		throw std::out_of_range("Span is full");
}

std::set<int> Span::_getSpans(std::set<int> &spans)
{
	std::transform(_numbers.begin(), --_numbers.end(), ++_numbers.begin(),
		std::inserter(spans, spans.begin()),
		[](int a, int b) { return (b - a); });
	return (spans);
}

int Span::shortestSpan(void)
{
	if (_numbers.size() < 2)
		throw std::out_of_range("Span contains less than 2 numbers");
	std::set<int> spans;

	spans = _getSpans(spans);
	return (*spans.begin());
}

int Span::longestSpan(void)
{
	if (_numbers.size() < 2)
		throw std::out_of_range("Span contains less than 2 numbers");

	return (*_numbers.rbegin() - *_numbers.begin());
}
