/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awesome_phonebook.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:51:26 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/22 18:07:37 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWESOME_PHONEBOOK_H
# define AWESOME_PHONEBOOK_H
# include <iostream>
# include <string>
# include "PhoneBook.hpp"

// Define ANSI escape codes for colors
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"

// Define ANSI escape codes for text decoration
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define ITALIC  "\033[3m"
#define UNDERLINE "\033[4m"


typedef void (Contact::*MemberFunction)(std::string);

#endif