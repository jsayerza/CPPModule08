/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/11/13 10:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <algorithm>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _container;
		Span();

	public:
		Span(unsigned int maxSize);
		Span(const Span& other);
		~Span();

		Span& operator=(const Span& other);

		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;

		void printSpan() const;

		class FullContainerException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Container already full");
				}
		};

		class NotEnoughElementsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Not enough elements to calculate shortest span.");
				};
		};

		template <typename Iterator>
		void addRange(Iterator begin, Iterator end)
		{
			while (begin != end)
			{
				if (_container.size() >= _maxSize)
					throw std::runtime_error("Container is full");
				_container.push_back(*begin);
				++begin;
			}
		};
};

#endif