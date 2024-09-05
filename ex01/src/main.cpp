/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:02:41 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/05 17:48:07 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

static void	subject_test(void)
{
	std::cout << "---------------- Subject Tests ----------------" << std::endl;
	Span	sp(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	if (sp.shortestSpan() != 2)
		std::cerr << "Shortest span should be 2" << std::endl;
	if (sp.longestSpan() != 14)
		std::cerr << "Longest span should be 14" << std::endl;
	if (sp.shortestSpan() == 2 && sp.longestSpan() == 14)
		std::cout << std::endl << "Test passed" << std::endl;
}

static void	error_handling_test(void)
{
	std::cout << "------------- Error Handling test -------------" << std::endl;
	Span	sp(1);
	bool	fail = false;

	try
	{
		sp.addNumber(5);
		sp.addNumber(3);
		std::cerr << "Should not be able to add more than 1 number" << std::endl;
		fail = true;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << "This is expected" << std::endl;
	}
	try
	{
		sp.shortestSpan();
		std::cerr << "Should not be able to get shortest span with less than 2 numbers" << std::endl;
		fail = true;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << "This is expected" << std::endl;
	}
	try
	{
		sp.longestSpan();
		std::cerr << "Should not be able to get longest span with less than 2 numbers" << std::endl;
		fail = true;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << "This is expected" << std::endl;
	}
	if (!fail)
		std::cout << std::endl << "Test passed" << std::endl;
}

static void	test_shortest_and_longest_span(void)
{
	std::cout << "-------- Test shortest and longest span --------" << std::endl;
	Span	sp(3);

	sp.addNumber(1);
	sp.addNumber(2);
	sp.addNumber(20);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	if (sp.shortestSpan() != 1)
		std::cerr << "Shortest span should be 1" << std::endl;
	if (sp.longestSpan() != 19)
		std::cerr << "Longest span should be 19" << std::endl;
	if (sp.shortestSpan() == 1 && sp.longestSpan() == 19)
		std::cout << std::endl << "Test passed" << std::endl;
}

static std::set<int>	get_spans(std::vector<int> &v)
{
	std::set<int>	spans;

	std::sort(v.begin(), v.end());
	for (size_t i = 1; i < v.size(); i++)
		spans.insert(v[i] - v[i - 1]);
	spans.insert(v[v.size() - 1] - v[0]);
	return (spans);
}

static void	test_more_than_10000_numbers(void)
{
	std::cout << "-------------- Test 15000 numbers --------------" << std::endl;
	std::set<int>		vector_spans;
	Span				sp(15000);
	std::vector<int>	v(15000);

	for (size_t i = 0; i < 15000; i++)
		v[i] = rand();
	sp.addNumber(v.begin(), v.end());
	vector_spans = get_spans(v);
	std::cout << "Shortest span:\t\t\t" << sp.shortestSpan() << std::endl;
	std::cout << "Longest span:\t\t\t" << sp.longestSpan() << std::endl;
	std::cout << "Shortest span in vector:\t" << *vector_spans.begin() << std::endl;
	std::cout << "Longest span in vector:\t\t" << *(--vector_spans.end()) << std::endl;
	if (sp.shortestSpan() == *vector_spans.begin() && sp.longestSpan() == *(--vector_spans.end()))
		std::cout << std::endl << "Test passed" << std::endl;
	else
		std::cerr << "Test failed" << std::endl;
}

int	main(void)
{
	srand(time(NULL));
	subject_test();
	std::cout << std::endl;
	error_handling_test();
	std::cout << std::endl;
	test_shortest_and_longest_span();
	std::cout << std::endl;
	test_more_than_10000_numbers();
	std::cout << std::endl;
	return (0);
}
