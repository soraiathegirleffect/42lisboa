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

#include "struct.hpp"

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main(void)
{
	Data		*data_1 = new Data;
	Data		*data_2;
	uintptr_t	raw;

	data_1->str = "Hello World";

	std::cout << "Original:   " << data_1->str << std::endl;

	raw = serialize(data_1);
	data_2 = deserialize(raw);

	std::cout << "Serialized: " << data_2->str << std::endl;
}
