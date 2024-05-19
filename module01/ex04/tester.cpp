/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:12:47 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/19 18:11:57 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(void)
{
	/* Create a test file */
	std::ofstream testFile("test.txt");

	if (!testFile.is_open()) {
		std::cout << "Error: Unable to create the test file!" << std::endl;
		return (1);
	}

	testFile << "Help me to put this to the output :)" << std::endl;
	testFile << "One more line" << std::endl << std::endl;
	testFile << "Maybe another line" << std::endl << std::endl;
	testFile << "So good that I have this file for a test" << std::endl;

	testFile.close();

	/* Create a test script */
	std::ofstream scriptFile("tests.sh");

	if (!scriptFile.is_open()) {
		std::cout << "Error: Unable to create the script file!" << std::endl;
		return (1);
	}

	scriptFile << "#!/bin/bash" << std::endl << std::endl;
	scriptFile << "echo 'Running tests.sh'" << std::endl;
	scriptFile << "echo 'Generated: test.txt:'" << std::endl;
	scriptFile << "echo '--------------------------------------------'" << std::endl;
	scriptFile << "cat test.txt" << std::endl;
	scriptFile << "echo '--------------------------------------------'" << std::endl;

	scriptFile << "echo 'Running ./losersed test.txt h '#''" << std::endl;
	scriptFile << "./losersed test.txt h '#'" << std::endl;
	scriptFile << "echo 'Output: test.txt.replace:'" << std::endl;
	scriptFile << "echo '--------------------------------------------'" << std::endl;
	scriptFile << "cat test.txt.replace" << std::endl;
	scriptFile << "echo '--------------------------------------------'" << std::endl;

	scriptFile << "echo '\n'" << std::endl;

	scriptFile << "echo 'Running diff test.txt test.txt.replace'" << std::endl;
	scriptFile << "echo '--------------------------------------------'" << std::endl;
	scriptFile << "diff test.txt test.txt.replace" << std::endl;
	scriptFile << "echo '--------------------------------------------'" << std::endl;

	scriptFile.close();

	// Make the shell script file executable
	system("chmod +x tests.sh");

	// Execute the shell script
	system("./tests.sh");

	return (0);
}
