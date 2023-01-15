/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:29:17 by efreire-          #+#    #+#             */
/*   Updated: 2023/01/14 15:29:19 by efreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeConverter.hpp"

int	main(int argc, char **argv)
{
	TypeConverter	typeConverter;

	try
	{
		if (argc <= 1)
			throw TypeConverter::EmptyInput();
		else
		{
			typeConverter.setInput(argv[1]);
			typeConverter.analyzeInput();
			typeConverter.printInput();
			std::cout << std::endl;
		}
	}
	catch(std::exception &err)
	{
		std::cout << err.what() << std::endl << std::endl;
	}
}
