#include <iostream>

#include "EnigmaMachine.h"

int main()
{
	Rotor r1{ {'I', 'P', 'R', 'N', 'F', 'M', 'W', 'O', 'Z', 'J', 'Q', 'C', 'X', 'G', 'T', 'D', 'B', 'K', 'E', 'L', 'Y', 'V', 'A', 'H', 'S', 'U'}, 'H', 'J', 0};
	Rotor r2{ {'B', 'K', 'Q', 'S', 'L', 'P', 'M', 'D', 'C', 'A', 'N', 'Y', 'H', 'G', 'I', 'R', 'Z', 'V', 'J', 'F', 'T', 'U', 'X', 'E', 'O', 'W'}, 'I', 'C', 0};
	Rotor r3{ {'C', 'D', 'Z', 'R', 'M', 'G', 'H', 'X', 'A', 'W', 'Q', 'V', 'U', 'F', 'S', 'B', 'P', 'L', 'T', 'O', 'E', 'I', 'Y', 'N', 'K', 'J'}, 'Q', 'M', 0};

	EnigmaMachine enigma(r1, r2, r3);

	char letter{ 'A' };
	letter = enigma.Encrypt(letter);

	std::cout << letter << '\n';
}