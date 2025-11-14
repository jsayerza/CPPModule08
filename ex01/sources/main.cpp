/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/11/13 10:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include "../includes/Span.hpp"

int randNumber()
{
	return (std::rand());
}

int main(void)
{
	{	
		std::cout << "--- Test subject" << std::endl;
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.printSpan();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;	
	}

	{	
		std::cout << "\n--- Test container full" << std::endl;
		Span sp = Span(5);

		try {
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			sp.printSpan();
			sp.addNumber(666);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	{	
		std::cout << "\n--- Test addRange with array small size" << std::endl;
		Span sp = Span(10);

		int array[] = {1,2,3,4,5,6,7,8,9,10};
		int size = sizeof(array) / sizeof(array[0]);
		sp.addRange(array, array + size);
		sp.printSpan();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;	
	}

	{	
		int maxNumbers = 100000;
		std::cout << "\n--- Test addRange with array big size (" << maxNumbers << ")" << std::endl;
		Span sp = Span(maxNumbers);

		std::vector<int> numbers(maxNumbers);
		std::generate(numbers.begin(), numbers.end(), randNumber);
		sp.addRange(numbers.begin(), numbers.end());
		// sp.printSpan();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;	
	}

	return (0);
}