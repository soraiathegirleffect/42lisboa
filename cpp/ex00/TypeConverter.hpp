/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeConverter.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:00:05 by efreire-          #+#    #+#             */
/*   Updated: 2022/12/17 22:44:38 by efreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_INPUT_H
# define TYPE_INPUT_H

#include <cmath>
#include <iostream>
#include <limits>
#include <string>

class TypeConverter
{
	public:
		TypeConverter(void);
		TypeConverter(const TypeConverter &src);
		~TypeConverter(void);

		TypeConverter	&operator=(const TypeConverter &rhs);

		char		*getInput(void);
		void		setInput(char *input);

		void		analyzeInput(void);
		void		printInput(void);

	private:
		char		*_input;
		int			_type;
		char		_char;
		int			_int;
		float		_float;
		double		_double;

		void		resetValues(void);

		void		convertToScalarTypes(void);
		void		analyseType(void);
		void		analysePseudoLiterals(void);
		void		analyseNumericalValues(void);

		void		printfChar(void);
		void		printfInt(void);
		void		printfFloat(void);
		void		printfDouble(void);

		static const int	noType = -1;
		static const int	charType = 0;
		static const int	intType = 1;
		static const int	floatType = 2;
		static const int	doubleType = 3;

	public:
		class EmptyInput : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Please enter an input to be analysed!";
				}
		};

		class InvalidInput : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Please enter a valid input!";
				}
		};
};

#endif
