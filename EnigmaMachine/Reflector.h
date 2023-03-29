#pragma once

#include <array>

class Reflector
{
private:
	std::array<int, 26> _wiring; // Array to represent the wiring of the reflector
public:
	Reflector(); // Class constructor to initialize the array
	char Reflect(char letter); // Function to reflect the input letter
};

Reflector::Reflector()
{
	// Set up the wiring of the reflector using an array of integers
	_wiring = { 24, 17, 20, 7, 16, 18, 11, 15, 23, 13, 25, 22, 6, 5, 26, 10, 3, 19, 12, 14, 21, 8, 4, 2, 1, 9 };
}

char Reflector::Reflect(char letter)
{
	// Find the index of the input letter in the alphabet
	int index = letter - 'A';

	// Map the input letter to the output letter using the reflector's wiring
	char output = _wiring[index] + 'A';

	return output;
}
