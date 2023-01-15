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

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <iostream>

Base	*generate(void)
{
	int	num = (std::rand() % 3);

	if (num == 0)
		return (new A());
	else if (num == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base *p)
{
	A	*a = dynamic_cast<A *>(p);
	if (a)
		std::cout << "A" << std::endl;

	B	*b = dynamic_cast<B *>(p);
	if (b)
		std::cout << "B" << std::endl;

	C	*c = dynamic_cast<C *>(p);
	if (c)
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A	&a = dynamic_cast<A &>(p);
		(void) a;
		std::cout << "A" << std::endl;
	}
	catch(std::exception &err)
	{
		(void) err;
	}

	try
	{
		B	&b = dynamic_cast<B &>(p);
		(void) b;
		std::cout << "B" << std::endl;
	}
	catch(std::exception &err)
	{
		(void) err;
	}

	try
	{
		C	&c = dynamic_cast<C &>(p);
		(void) c;
		std::cout << "C" << std::endl;
	}
	catch(std::exception &err)
	{
		(void) err;
	}
}

int	main(void)
{
	Base	*pointer;

	identify(new A());
	identify(new B());
	identify(new C());

	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
	{
		pointer = generate();
		identify(pointer);
	}

	std::cout << std::endl;

	identify(*(new A()));
	identify(*(new B()));
	identify(*(new C()));

	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
	{
		pointer = generate();
		identify(*pointer);
	}
}
