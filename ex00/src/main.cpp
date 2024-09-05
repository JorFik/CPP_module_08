/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:31:48 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/05 14:17:21 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <exception>
#include <array>
#include <deque>

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> vector;
	std::list<char> c_list;
	std::list<int> list;
	std::array<int, 10> array;
	std::deque<int> deque;
	
	for (int i = 0; i < 10; i++)
	{
		vector.push_back(i - 1);
		c_list.push_back(i + 48);
		list.push_back(i);
		array[i] = i;
		deque.push_back(i);
	}
		std::cout << *(easyfind(vector, -1)) << std::endl;
		std::cout << *(easyfind(c_list, '4')) << std::endl;
		std::cout << *(easyfind(list, 5)) << std::endl;
		std::cout << *(easyfind(array, 5)) << std::endl;
		std::cout << *(easyfind(deque, 5)) << std::endl;
	try
	{
		std::cout << *(easyfind(vector, 10)) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << *(easyfind(list, 10)) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << *(easyfind(array, 10)) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << *(easyfind(deque, 10)) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
