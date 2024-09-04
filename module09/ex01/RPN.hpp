/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 03:23:23 by vshchuki          #+#    #+#             */
/*   Updated: 2024/09/04 14:44:26 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>

// Text color macros
#define			TEXT_GREEN "\033[32m"
#define			TEXT_BLUE "\033[34m"
#define			TEXT_WHITE "\033[37m"

// Background color macros
#define			BG_RED "\033[41m"

// Reset macros
#define			RESET "\033[0m"

#define			EXIT_SUCCESS 0
#define			EXIT_FAILURE 1

enum LogType
{
	DEFAULT,
	ERROR,
	INFO,
	SUCCESS
};

class RPN
{
	private:
		static const std::string	allowedOperands;
		static const std::string	allowedOperators;

		std::string					expression;
		std::stack<float>			currNumbers;

	public:
		RPN();
		RPN(const char* expression);
		RPN(const RPN&);
		RPN& operator=(const RPN&);
		~RPN();

		class Error : public std::exception
		{
			private:
				std::string message;

			public:
				Error();
				Error(const std::string& message);
				Error(const Error& other);
				Error& operator=(const Error& other);
				~Error();

				std::string getMessage() const;
		};

		bool						checkOperand(std::string token);
		bool						checkOperator(std::string token);
		void						checkToken(std::string token);
		bool						checkIsStackReady(std::string token);
		void						applyOperator(float operand1, float operand2, std::string operandToken);
		void						calculate(std::string operandToken);
		void						execute(std::string delimiter);

		std::string					trimTrailingZeros(std::string floatStr);
		static void					log(std::string message, LogType type = DEFAULT);
};