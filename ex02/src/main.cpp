/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:17:57 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/05 18:53:21 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include "MutantStack.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <list>

static void	subject_tests(void)
{
	std::cout << "---------------- Subject tests ----------------" << std::endl;
	std::cout << "Testing MutantStack<int> with basic stack methods" << std::endl << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;

	std::cout << "Size before pop: " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "New size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << "Mutant Stack: " << *(it++) << std::flush;
	while (it != ite)
	{
		std::cout << ", " << *it << std::flush;
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);
}

static void	test_against_vector(void)
{
	std::cout << "------------- Test against vector -------------" << std::endl;
	std::cout << "Testing MutantStack<string> against vector<string>\n" << std::endl;
	srand(time(NULL));
	MutantStack<std::string> mstack;
	std::vector<std::string> v;

	for (int i = 0; i < 10000; i++)
	{
		int r = rand() % 255;
		mstack.push(std::string(1, r));
		v.push_back(std::string(1, r));
	}
	auto	ms_it = mstack.begin();
	auto	v_it = v.begin();
	auto	ms_end_it = mstack.end();
	while (ms_it != ms_end_it)
	{
		if (*ms_it != *v_it)
		{
			std::cout << "Error: " << *ms_it << " != " << *v_it << std::endl;
			return ;
		}
		++ms_it;
		++v_it;
	}
	std::cout << "All elements are equal" << std::endl;
}

static void	test_against_list(void)
{
	std::cout << "-------------- Test against list --------------" << std::endl;
	std::cout << "Testing MutantStack<vector> against list<vector>\n" << std::endl;
	MutantStack<std::vector<int>>	mstack;
	std::list<std::vector<int>>		l;

	for (int i = 0; i < 15000; i++)
	{
		std::vector<int> v;
		v.push_back(rand() % 255);
		mstack.push(v);
		l.push_back(v);
	}
	auto	ms_it = mstack.begin();
	auto	l_it = l.begin();
	auto	ms_end_it = mstack.end();
	while (ms_it != ms_end_it)
	{
		if (*ms_it != *l_it)
		{
			std::cout << "Error: the vectors are not equal" << std::endl;
			return ;
		}
		++ms_it;
		++l_it;
	}
	std::cout << "All elements are equal" << std::endl;
}

int	main(void)
{
	subject_tests();
	std::cout << std::endl;
	test_against_vector();
	std::cout << std::endl;
	test_against_list();
	std::cout << std::endl;
	return (0);
}
