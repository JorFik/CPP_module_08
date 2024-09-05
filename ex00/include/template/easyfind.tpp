/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:27:11 by JFikents          #+#    #+#             */
/*   Updated: 2024/09/05 13:31:45 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include <iostream>
# include <algorithm>
# include <exception>

template <typename Container>
typename Container::iterator	easyfind(Container &container, int value)
{
	typename Container::iterator first_occurrence;

	first_occurrence = std::find(container.begin(), container.end(), value);
	if (first_occurrence == container.end())
		throw std::runtime_error("Value not found in container");
	std::cout << "Value " << value << " found in container at index: ";
	std::cout << std::distance(container.begin(), first_occurrence) << std::endl;
	return (first_occurrence);
}

#endif