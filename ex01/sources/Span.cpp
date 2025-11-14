/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/11/13 10:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span() : _maxSize(1)
{}

Span::Span(unsigned int maxSize) : _maxSize(maxSize)
{}

Span::Span(const Span& other) : _maxSize(other._maxSize)
{}

Span::~Span()
{}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
		_maxSize = other._maxSize;
	return (*this);
}

void Span::addNumber(int number)
{
	if (_container.size() < _maxSize)
		_container.push_back(number);
	else
	{
		std::cout << "_container.size(): " << _container.size() << " _maxSize: " << _maxSize << std::endl;
		throw FullContainerException();
	}
}


int Span::shortestSpan() const
{
	if (_container.size() < 2)
		throw NotEnoughElementsException();
	std::vector<int> auxContainer = _container;
	std::sort(auxContainer.begin(), auxContainer.end());
	int shortestSpanVal = auxContainer[1] - auxContainer[0];
	for (long unsigned int i = 1; i < auxContainer.size(); i++)
	{
		if (auxContainer[i] - auxContainer[i-1] < shortestSpanVal)
			shortestSpanVal = auxContainer[i] - auxContainer[i-1];
	}

	return (shortestSpanVal);
}

int Span::longestSpan() const
{
	if (_container.size() < 2)
		throw NotEnoughElementsException();
	std::vector<int> auxContainer = _container;
	std::sort(auxContainer.begin(), auxContainer.end());
	int longestSpanVal = auxContainer[auxContainer.size() -1] - auxContainer[0];
	std::cout	<< "Min.: " << auxContainer[0] 
				<< " Max.: " << auxContainer[auxContainer.size() -1] 
				<< std::endl;

	return (longestSpanVal);
}

void Span::printSpan() const
{
	for (unsigned int i = 0; i < _container.size(); i++)
		std::cout << _container[i] << " ";
	std::cout << std::endl;
}