/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:12:47 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/17 16:08:28 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>

int	main(void)
{
    std::ofstream scriptFile("tests.sh");

    // Check if the file was opened successfully
    if (!scriptFile.is_open()) {
        std::cerr << "Error: Unable to create the script file!" << "\n";
        return 1;
    }

    // Write some shell script commands to the file
    scriptFile << "#!/bin/bash" << "\n";
    scriptFile << "echo 'Hello, this is a shell script!'" << "\n";
    // scriptFile << "ls -l" << "\n";

    // Close the file
    scriptFile.close();

    // Make the shell script file executable
    system("chmod +x tests.sh");

    // Execute the shell script
    system("./tests.sh");

	return (0);
}
