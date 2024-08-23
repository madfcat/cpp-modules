/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 03:23:26 by vshchuki          #+#    #+#             */
/*   Updated: 2024/08/23 12:00:20 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

const std::string RPN::allowedOperands = "1234567890";
const std::string RPN::allowedOperators = "-+/*";

RPN::RPN() : result(0.0), operandsCount(0), operatorsCount(0)
{
	log("RPN default constructor called", INFO);
}

RPN::RPN(const char* expression) : expression(expression), result(0.0),
									operandsCount(0), operatorsCount(0)
{
	log("RPN constructor called", INFO);
}

RPN::RPN(const RPN& other)
{
	log("RPN copy constructor called", INFO);
	this->expression = other.expression;
	this->currNumbers = other.currNumbers;
	this->result = other.result;
	this->operandsCount = other.operandsCount;
	this->operatorsCount = other.operandsCount;
}

RPN& RPN::operator=(const RPN& other)
{
	log("RPN assignment operator called", INFO);
	if (this != &other)
	{
		this->expression = other.expression;
		this->currNumbers = other.currNumbers;
		this->result = other.result;
		this->operandsCount = other.operandsCount;
		this->operatorsCount = other.operandsCount;
	}
	return *this;
}

RPN::~RPN()
{
	log("RPN destructor called", INFO);
}

/* Methods */

bool RPN::checkOperand(std::string token)
{
	return (this->allowedOperands.find(token) != std::string::npos && token.size() == 1);
}

bool RPN::checkOperator(std::string token)
{
	return (this->allowedOperators.find(token) != std::string::npos && token.size() == 1);
}

void RPN::checkToken(std::string token)
{
	if (!checkOperator(token) && !checkOperand(token))
		throw RPN::Error("Token is not allowed: " + token);
}

bool RPN::checkIsStackReady(std::string token)
{
	if (checkOperator(token))
	{
		// log(token, INFO);
		if (this->currNumbers.size() < 2)
			throw RPN::Error("Expression has wrong tokens order");
		else
			return true;
	}
	return false;
}

void RPN::applyOperator(float operand1, float operand2, std::string operandToken)
{
	if (operandToken == "+")
		this->currNumbers.push(operand1 + operand2);
	else if (operandToken == "-")
		this->currNumbers.push(operand1 - operand2);
	else if (operandToken == "/")
		this->currNumbers.push(operand1 / operand2);
	else if (operandToken == "*")
		this->currNumbers.push(operand1 * operand2);
}

void RPN::calculate(std::string operandToken)
{
	float operand2 = this->currNumbers.top();
	this->currNumbers.pop();
	float operand1 = this->currNumbers.top();
	this->currNumbers.pop();
	applyOperator(operand1, operand2, operandToken);
}

void RPN::execute(std::string delimiter)
{
	std::string str = this->expression;
	while (!str.empty())
	{
		std::string token;
		size_t delimiterPos = str.find(delimiter);

		if (delimiterPos == std::string::npos)
		{
			checkToken(str);
			token = str;
			str = "";
		}
		else if (delimiterPos == 0)
		{
			str = str.substr(delimiter.length());
			continue;
		}
		else if (delimiterPos == str.length() - 1)
		{
			str = str.substr(0, delimiterPos - 1);
			continue;
		}
		else
		{
			token = str.substr(0, delimiterPos);
			checkToken(token);
			
			str = str.substr(delimiterPos + delimiter.length());
		}

		if (checkIsStackReady(token))
			calculate(token);
		else
			this->currNumbers.push(std::stof(token));
	}
	if (this->currNumbers.size() != 1)
		throw RPN::Error("Expression has missing tokens");
	log(trimTrailingZeros(std::to_string(this->currNumbers.top())), SUCCESS);
}

std::string RPN::trimTrailingZeros(std::string floatStr)
{
	size_t dotPos = floatStr.find(".");
	if (dotPos == std::string::npos) {
		return floatStr;
	}

	size_t lastNonZeroPos = floatStr.find_last_not_of('0');
	if (lastNonZeroPos == std::string::npos || lastNonZeroPos < dotPos) {
		return floatStr.substr(0, dotPos);
	}

	if (lastNonZeroPos == dotPos) {
		lastNonZeroPos--;
	}

	return floatStr.substr(0, lastNonZeroPos + 1);
}

void RPN::log(std::string message, LogType type)
{
	switch (type)
	{
		case INFO:
			std::cout << "ℹ️ " << TEXT_BLUE ;
			break;
		case ERROR:
			std::cout << "🚫 " << BG_RED << TEXT_WHITE ;
			break;
		case SUCCESS:
			std::cout << "✅ " << TEXT_GREEN ;
			break;
		case DEFAULT:
			break;
	}
	std::cout << message << RESET << std::endl;
}

/* Error */

std::string RPN::Error::getMessage() const
{
	return this->message;
}

RPN::Error::Error(const std::string& message)
{
	this->message = message;
}