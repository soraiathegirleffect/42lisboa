/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeConverter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:59:35 by efreire-          #+#    #+#             */
/*   Updated: 2022/12/17 22:44:31 by efreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeConverter.hpp"

bool		ft_is_digit(char c);
bool		canConvertToChar(double number);
bool		canConvertToInt(double num);
bool		canConvertToFloat(double num);
std::string	trailingZeros(double num);

TypeConverter::TypeConverter(void)
{
	resetValues();
	return ;
}

TypeConverter::TypeConverter(const TypeConverter &src)
{
	*this = src;
	return ;
}

TypeConverter::~TypeConverter(void)
{
	return ;
}

TypeConverter	&TypeConverter::operator=(const TypeConverter &rhs)
{
	this->_input = rhs._input;
	this->_type = rhs._type;
	this->_char = rhs._char;
	this->_int = rhs._int;
	this->_float = rhs._float;
	this->_double = rhs._double;
	return (*this);
}

char		*TypeConverter::getInput(void)
{
	return (this->_input);
}

void		TypeConverter::setInput(char *input)
{
	this->_input = input;
}

void		TypeConverter::analyzeInput(void)
{
	if ( !this->_input || !this->_input[0] )
		throw TypeConverter::InvalidInput();

	analyseType();
	convertToScalarTypes();
}

void		TypeConverter::printInput(void)
{
	printfChar();
	printfInt();
	printfFloat();
	printfDouble();
}

void		TypeConverter::resetValues(void)
{
	this->_input = NULL;
	this->_type = TypeConverter::noType;
	this->_char = 0;
	this->_int = 0;
	this->_float = 0;
	this->_double = 0;
}

void		TypeConverter::convertToScalarTypes(void)
{
	if (this->_type == TypeConverter::charType)
		this->_char = this->_input[0];
	else if (this->_type == TypeConverter::intType)
		this->_int = atoi(this->_input);
	else if (this->_type == TypeConverter::floatType)
		this->_float = atof(this->_input);
	else if (this->_type == TypeConverter::doubleType)
		this->_double = atof(this->_input);
}

void		TypeConverter::analyseType(void)
{
	this->_type = TypeConverter::noType;

	analysePseudoLiterals();
	if (this->_type != TypeConverter::noType)
		return ;

	analyseNumericalValues();
	if (this->_type != TypeConverter::noType)
		return ;

	if (this->_input[1])
		throw TypeConverter::InvalidInput();

	this->_type = TypeConverter::charType;
}

void		TypeConverter::analysePseudoLiterals(void)
{
	const std::string	float_literals[] = {
		"inff",
		"-inff",
		"+inff",
		"nanf"
	};
	const std::string	double_literals[] = {
		"inf",
		"-inf",
		"+inf",
		"nan"
	};

	for (int i = 0; i < 4; i++)
	{
		if (this->_input == float_literals[i])
			this->_type = TypeConverter::floatType;
		else if (this->_input == double_literals[i])
			this->_type = TypeConverter::doubleType;
	}
}

void		TypeConverter::analyseNumericalValues(void)
{
	char	*str = this->_input;
	int		dotCount = 0;
	int		i = 0;

	if ( !ft_is_digit(str[0]) && (str[0] != '-') && (str[0] != '.') )
		return ;

	if ((str[0] == '.') && ((str[1] == '0') || (str[1] == 'f')))
		return ;

	if ((str[0] == '-') && (str[1]))
		i++;

	while ((str[i] == '.') || ft_is_digit(str[i]))
		if (str[i++] == '.')
			dotCount++;
	if (dotCount > 1)
		return ;

	if ( !str[i] )
	{
		if (dotCount == 1)
			this->_type = TypeConverter::doubleType;
		else
			this->_type = TypeConverter::intType;
	}
	else if ((str[i] == 'f') && !str[i + 1] && (dotCount == 1))
		this->_type = TypeConverter::floatType;
}

void		TypeConverter::printfChar(void)
{
	std::cout << "char: ";

	if (this->_type == TypeConverter::charType)
		std::cout << this->_char;
	else if ((this->_type == TypeConverter::intType) && canConvertToChar(this->_int))
		std::cout << static_cast<char>(this->_int);
	else if ((this->_type == TypeConverter::floatType) && canConvertToChar(this->_float))
		std::cout << static_cast<char>(this->_float);
	else if ((this->_type == TypeConverter::doubleType) && canConvertToChar(this->_double))
		std::cout << static_cast<char>(this->_double);

	std::cout << std::endl;
}

void		TypeConverter::printfInt(void)
{
	std::cout << "int: ";

	if (this->_type == TypeConverter::charType)
		std::cout << static_cast<int>(this->_char);
	else if (this->_type == TypeConverter::intType)
		std::cout << this->_int;
	else if ((this->_type == TypeConverter::floatType) && canConvertToInt(this->_float))
		std::cout << static_cast<int>(this->_float);
	else if ((this->_type == TypeConverter::doubleType) && canConvertToInt(this->_double))
		std::cout << static_cast<int>(this->_double);

	std::cout << std::endl;
}

void		TypeConverter::printfFloat(void)
{
	std::cout << "float: ";

	if (this->_type == TypeConverter::charType)
		std::cout << static_cast<float>(this->_char) << ".0";
	else if (this->_type == TypeConverter::intType)
		std::cout << static_cast<float>(this->_int) << ".0";
	else if (this->_type == TypeConverter::floatType)
		std::cout << this->_float << trailingZeros(this->_float);
	else if ((this->_type == TypeConverter::doubleType) && canConvertToFloat(this->_double))
		std::cout
			<< static_cast<float>(this->_double)
			<< trailingZeros(static_cast<float>(this->_double));

	std::cout << "f" << std::endl;
}

void		TypeConverter::printfDouble(void)
{
	std::cout << "double: ";

	if (this->_type == TypeConverter::charType)
		std::cout << static_cast<double>(this->_char) << ".0";
	else if (this->_type == TypeConverter::intType)
		std::cout << static_cast<double>(this->_int) << ".0";
	else if (this->_type == TypeConverter::floatType)
		std::cout
			<< static_cast<double>(this->_float)
			<< trailingZeros(this->_float);
	else if (this->_type == TypeConverter::doubleType)
		std::cout
			<< this->_double
			<< trailingZeros(this->_double);

	std::cout << std::endl;
}

// Utils
bool		ft_is_digit(char c)
{
	return ((c >= '0') && (c <= '9'));
}

bool	canConvertToChar(double number)
{
	if (
		(number != static_cast<int>(number)) ||
		(number > 127) ||
		(number < 0)
	)
	{
		std::cout << "impossible";
		return (false);
	}
	else if (number <= 31 || number == 127)
	{
		std::cout << "Non displayable";
		return (false);
	}
	return (true);
}

bool	canConvertToInt(double num)
{
	if (
		(num <= std::numeric_limits<int>::max()) &&
		(num >= std::numeric_limits<int>::min()) &&
		(num != std::numeric_limits<double>::infinity()) &&
		(num != -std::numeric_limits<double>::infinity()) &&
		(num != std::numeric_limits<double>::quiet_NaN())
	)
		return (true);
	std::cout << "impossible";
	return (false);
}

bool	canConvertToFloat(double num)
{
	if (
		(
			(num <= std::numeric_limits<float>::max()) &&
			(num >= -std::numeric_limits<float>::max())
		) ||
		(num == std::numeric_limits<double>::infinity()) ||
		(num == -std::numeric_limits<double>::infinity()) ||
		std::isnan(num)
	)
		return (true);
	std::cout << "impossible";
	return (false);
}

std::string	trailingZeros(double num)
{
	return ((num == static_cast<int>(num)) ? ".0" : "");
}
