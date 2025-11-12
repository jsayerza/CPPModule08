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
#include <iostream>
#include "../includes/easyfind.hpp"

int main()
{
	std::vector<int> container;
	container.push_back(1);
	container.push_back(2);
	container.push_back(3);
	container.push_back(4);
	container.push_back(5);
	try {
		easyfind(container, 3);
		easyfind(container, 1);
		easyfind(container, 5);
	} catch (const std::exception& e) {
		std::cout << "Excepció capturada: " << e.what() << std::endl;
	}

	try {
		easyfind(container, 33);
	} catch (const std::exception& e) {
		std::cout << "Excepció capturada: " << e.what() << std::endl;
	}

	try {
		easyfind(container, 2);
		easyfind(container, 4);
	} catch (const std::exception& e) {
		std::cout << "Excepció capturada: " << e.what() << std::endl;
	}

	return (0);
}