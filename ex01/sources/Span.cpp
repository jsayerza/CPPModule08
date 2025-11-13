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

Span::Span() : _maxSize(10000)
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
	return (0);
}

int Span::longestSpan() const
{
	return (0);
}

void Span::printSpan() const
{
	for (unsigned int i = 0; i < _container.size(); i++)
		std::cout << _container[i] << " ";
	std::cout << std::endl;
}