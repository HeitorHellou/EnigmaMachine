#pragma once

#include <array>

class Reflector
{
private:
	std::array<int, 26> _wiring;
public:
	Reflector();
	char Reflect(char letter);
};

Reflector::Reflector()
{
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
