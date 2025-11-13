/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/11/11 18:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include "../includes/easyfind.hpp"

template <typename T>
void findOcurrences(T& container)
{
	try {
		easyfind(container, 3);
		easyfind(container, 1);
		easyfind(container, 5);
	} catch (const std::exception& e) {
		std::cout << "Catched exception: " << e.what() << std::endl;
	}

	try {
		easyfind(container, 33);
	} catch (const std::exception& e) {
		std::cout << "Catched exception: " << e.what() << std::endl;
	}

	try {
		easyfind(container, 2);
		easyfind(container, 4);
	} catch (const std::exception& e) {
		std::cout << "Catched exception: " << e.what() << std::endl;
	}
}

template <typename T>
void fillContainer(T* container)
{
	for (int i = 1; i <= 5; i++)
		container->push_back(i);
}

int main()
{
	{	
		std::cout << "--- Test with std::vector" << std::endl;
		std::vector<int> container;
		fillContainer(&container);
		findOcurrences(container);
	}

	{	
		std::cout << "\n--- Test with std::list" << std::endl;
		std::list<int> container;
		fillContainer(&container);
		findOcurrences(container);
	}

	{	
		std::cout << "\n--- Test with std::deque" << std::endl;
		std::deque<int> container;
		fillContainer(&container);
		findOcurrences(container);
	}

	{	
		std::cout << "\n--- Test with empty std::vector " << std::endl;
		std::vector<int> container;
		findOcurrences(container);
	}

	return (0);
}

//// std::deque (Double-Ended QUEue)