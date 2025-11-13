/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/11/11 18:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <sstream>

class NotFoundException : public std::exception
{
	private:
		std::string _msg;
	public:
		virtual ~NotFoundException() throw() {};

		NotFoundException(int value)
		{
			std::ostringstream oss;
			oss << "Value " << value << " not found.";	
			_msg = oss.str();
		}
		
		virtual const char* what() const throw()
		{
			return (_msg.c_str());
		}
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
	{
		std::cout << "Value " << value << " not found." << std::endl;
		throw NotFoundException(value);
	}
	std::cout << "Value " << value << " found." << std::endl;
	return (it);
};

#endif


//// Notes: El método what() de std::exception debe devolver const char* (no std::string)