#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>

using namespace std;

int isValidNumber(const std::string& num) {
	if (num.find(',') != std::string::npos) {
		return 0;
	}

	try {
		size_t a = 0;
		std::stod(num, &a);
		if (a == num.length()) {
			return 1;
		}
	}
	catch (...) {
		return 0;
	}
	return 0;
}

int isValidInteger(const std::string& num) {
	if (num.empty()) {
		return 0;
	}

	if (num.find('.') != std::string::npos || num.find(',') != std::string::npos) {
		return 0;
	}

	try {
		size_t a = 0;
		std::stoi(num, &a);
		if (a == num.length()) {
			return 1;
		}
	}
	catch (...) {
		return 0;
	}

	return 0;
}

void displayMenu() {
	std::cout << "---------main-menu---------" << endl;
	std::cout << "1 - start algorithm(keyboard input)" << endl;
	std::cout << "2 - start algorithm(file input)" << endl;
	std::cout << "3 - exit" << endl;
	std::cout << "4 - menu" << endl;
	std::cout << "5 - help" << endl;
	std::cout << "---------------------------" << endl;
	std::cout << std::endl;
}

void displayHelp()
{
	std::cout << "==============================================================" << std::endl;
	std::cout << "                         USER GUIDE                           " << std::endl;
	std::cout << "==============================================================" << std::endl;
	std::cout << "1. PROGRAM PURPOSE:" << std::endl;
	std::cout << "   Calculates values of a mathematical function " << std::endl;
	std::cout << "   (y of function) for x in range [a, b] with step 'step'" << std::endl;
	std::cout << "   and a user-defined parameter 'n'." << std::endl;
	std::cout << std::endl;
	std::cout << "2. MAIN MENU OPTIONS:" << std::endl;
	std::cout << "   1 - Start algorithm (keyboard input)." << std::endl;
	std::cout << "   2 - Start algorithm (file input)." << std::endl;
	std::cout << "   3 - Exit program." << std::endl;
	std::cout << "   4 - Display main menu." << std::endl;
	std::cout << "   5 - Help / User guide." << std::endl;
	std::cout << std::endl;
	std::cout << "3. INPUT PROCEDURE (Option 1):" << std::endl;
	std::cout << "   - Enter parameter 'n'." << std::endl;
	std::cout << "   - Enter left range limit 'a'." << std::endl;
	std::cout << "   - Enter right range limit 'b' (must satisfy: a <= b)." << std::endl;
	std::cout << "   - Enter step size 'step' (if 0, 'a' must equal 'b' for 1-point calculation)." << std::endl;
	std::cout << std::endl;
	std::cout << "4. ALGORITHM BRANCHING & CONSTRAINTS:" << std::endl;
	std::cout << "   - Branch 1 (x < 3)" << std::endl;
	std::cout << "   - Branch 2 (x >= 3)" << std::endl;
	std::cout << "   - So, n >=7 and n < 100." << std::endl;
	std::cout << std::endl;
	std::cout << "5. ERRORS & VALIDATION:" << std::endl;
	std::cout << std::endl;
	std::cout << "   - parameter n must be integer and real number." << std::endl;
	std::cout << "   - parameters a,b,step must be real numbers, use a dot for decimals." << std::endl;
	std::cout << "   - parameter step cannot be less than 0, use a dot for decimal." << std::endl;
	std::cout << "   - Invalid choice: Entered menu option is not between 1 and 5." << std::endl;
	std::cout << "   - b < a: Right border is less than left border." << std::endl;
	std::cout << "   - step < 0: Step cannot be negative." << std::endl;
	std::cout << "   - step == 0 & a != b: Step cannot be 0 when borders are different." << std::endl;
	std::cout << "==============================================================" << std::endl;
	std::cout << std::endl;
}

double n, a, b, step;
string n1, a1, b1, step1;

int main()
{
	displayHelp();
	displayMenu();
	while (true)
	{
		int choice = 0;
		std::string choiceInput;

		std::cout << "Enter your choice: ";
		std::cin >> choiceInput;

		if (!isValidInteger(choiceInput)) {
			std::cout << "---------------------------" << endl;
			std::cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
			std::cout << "---------------------------" << endl;
			continue;
		}

		choice = std::stoi(choiceInput);

		if (choice < 1 || choice > 5)
		{
			std::cout << "---------------------------" << endl;
			std::cout << "Invalid choice." << endl;
			std::cout << "---------------------------" << endl;
			continue;
		}

		if (choice == 5)
		{
			displayHelp();
			displayMenu();
			continue;
		}
		if (choice == 4)
		{
			displayMenu();
			continue;
		}
		if (choice == 3) // exit
		{
			std::cout << "Exit" << endl;
			break;
		}
		if (choice == 1 || choice == 2) // keyboard/file input
		{
			if (choice == 1)
			{
				cout << "Input from file:" << endl;
				while (true) {
					std::cout << "Enter n(7<=n<100): ";
					std::cin >> n1;
					if (isValidInteger(n1)) {
						if (std::stoi(n1) < 7) {
							std::cout << "parameter n must be at least 7." << endl;
							continue;
						}
						if (std::stoi(n1) >= 100) {
							std::cout << "parameter n must be less than 100." << endl;
							continue;
						}
						n = std::stoi(n1);
						break;
					}
					std::cout << "parameter n must be integer and less than 100." << endl;
				}

				while (true) {
					std::cout << "Enter left border: ";
					std::cin >> a1;
					if (isValidNumber(a1)) {
						a = std::stod(a1);
						break;
					}
					std::cout << "parameters must be real numbers, use a dot for decimals." << endl;
				}

				while (true) {
					std::cout << "Enter right border: ";
					std::cin >> b1;
					if (isValidNumber(b1)) {
						b = std::stod(b1);
						break;
					}
					std::cout << "parameters must be real numbers, use a dot for decimals." << endl;
				}

				while (true) {
					std::cout << "Enter step (if 0, only 1 point will be calculated): ";
					std::cin >> step1;
					if (isValidNumber(step1)) {
						step = std::stod(step1);
						if (step < 0) {
							std::cout << "Error: step cannot be negative." << endl;
							continue;
						}
						break;
					}
					std::cout << "parameters must be real numbers, use a dot for decimals." << endl;
				}
			}
			else
			{
				std::cout << "---------------------------" << endl;
				std::cout << "Starting algorithm with file input..." << endl;
				std::cout << endl;

				std::ifstream fin("data.txt");
				if (!fin.is_open()) {
					std::cout << "Error: Could not open the file 'data.txt'" << std::endl;
					continue;
				}

				if (!(fin >> n1 >> a1 >> b1 >> step1)) {
					std::cout << "Error: File format is incorrect or missing data." << std::endl;
					fin.close();
					continue;
				}
				fin.close();

				if (!isValidInteger(n1) || !isValidNumber(a1) || !isValidNumber(b1) || !isValidNumber(step1)) {
					cout << "input from file: " << endl;
					cout << "n = " << n1 << endl;
					cout << "a = " << a1 << endl;
					cout << "b = " << b1 << endl;
					cout << "step = " << step1 << endl;
					std::cout << "Error: File contains invalid data types." << std::endl;
					continue;
				}

				cout << "input from file: " << endl;
				cout << "n = " << n1 << endl;
				cout << "a = " << a1 << endl;
				cout << "b = " << b1 << endl;
				cout << "step = " << step1 << endl;

				n = std::stoi(n1);
				a = std::stod(a1);
				b = std::stod(b1);
				step = std::stod(step1);
			}

			std::cout << "---------------------------" << endl;

			// Input validation
			if (a > b)
			{
				std::cout << "Error: right border is less than left border" << endl;
				std::cout << "Returning to the main menu..." << endl;
				std::cout << "---------------------------" << endl;
				std::cout << endl;
				displayMenu();
				continue;
			}

			if (step < 0)
			{
				std::cout << "Error: step must be greater than -1" << endl;
				std::cout << "Returning to choise of command..." << endl;
				std::cout << "---------------------------" << endl;
				std::cout << endl;
				displayMenu();
				continue;
			}

			if (step == 0 && a != b)
			{
				std::cout << "Error: step cannot be 0 when left border != right border" << endl;
				std::cout << "Returning to choise of command..." << endl;
				std::cout << "---------------------------" << endl;
				std::cout << endl;
				displayMenu();
				continue;
			}


			// Algorithm
			bool skip1 = false;
			bool skip2 = false;
			for (double x = a; x <= b; x += step)
			{
				double Ts = 0;
				if (x < 3)
				{
					if (n < 7)
					{
						if (skip1 == false)
						{
							std::cout << "Skipped for all x < 3 " << std::endl;
							skip1 = true;
						}
						else
						{
							continue;
						}
					}
					else
					{
						for (int i = 2; i <= (n - 5); i++)
						{
							double sum = 0;
							for (int j = 0; j <= n; j++)
							{
								sum = sum + 2 * i + (double)(x * x) / (j + 2) - j;
							}
							Ts = Ts + sum;
						}
						Ts = 5 * x - 2 - Ts;
						std::cout << "x = " << x << ", y = " << Ts << std::endl;
					}
				}
				else
				{
					if (n < -4)
					{
						if (skip2 == false)
						{
							std::cout << "Skipped for all x >= 3 " << std::endl;
							skip2 = true;
						}
						else
						{
							continue;
						}
					}
					else
					{
						double mlt = 1;
						for (int j = 0; j <= (n + 4); j++)
						{
							mlt = mlt * (4 * x - j);
						}

						double sum = 0;
						for (int j = -4; j <= n + 2; j++)
						{
							sum = sum + (1.0 / x) - 2 * j;
						}

						Ts = mlt + x * sum;
						std::cout << "x = " << x << ", y = " << Ts << endl;
					}
				}

				if (step == 0)
				{
					std::cout << endl;
					break;
				}

			}
			std::cout << "Stop" << endl;
			std::cout << "---------------------------" << endl;
			std::cout << endl;
			displayMenu();
		}
	}
	return 0;

	//hello world
}