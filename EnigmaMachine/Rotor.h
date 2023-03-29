#pragma once

#include "Alphabet.h"

#include <vector>
#include <algorithm>
#include <iostream>

class Rotor
{
private:
	const char _notch; // The letter that, when reached, will cause the next rotor to rotate
	int _position; // The current position of the rotor (0-25)
	std::vector<int> _wiring; // The mapping of input letters to output letters
	std::weak_ptr<Rotor> _nextRotor; // weak pointer to the next rotor in sequence
	void RotateArray(); // Helper fuction to rotate array
public:
	Rotor(const std::vector<int>& wiring, char initializer, char notch, int position); // Constructor that initializes the rotor's wiring, notch, and position
	void Rotate(); // Rotates the rotor by one position
	char Encrypt(char letter); // Encrypts a letter using the rotor's wiring
	void SetNextRotor(std::shared_ptr<Rotor> nextRotor); // Sets the next rotor in the sequence
};

Rotor::Rotor(const std::vector<int>& wiring, char initializer, char notch, int position): _notch(notch), _position(position)
{
	// Find the index of the initial position in the alphabet
	int index = std::find(alphabet.begin(), alphabet.end(), initializer) - alphabet.begin();

	// Populate the rotor's wiring using the provided wiring and initial position
	for (int i = 0; i < 26; i++) 
	{
		_wiring.push_back(wiring[index]);
		index = (index + 1) % 26;
	}
}

void Rotor::Rotate()
{
	// Increment the rotor's position by one
	_position++;

	// Wrap around to the beginning if the position reaches 26
	if (_position > 25) _position = 0;

	// Rotate wiring array
	RotateArray();

	// If the rotor has reached its notch, rotate the next rotor
	if (_notch == alphabet[_position] || _position == 25) 
	{
		if (auto nextRotor = _nextRotor.lock())
			nextRotor->Rotate();
	}
}

char Rotor::Encrypt(char letter)
{
	// Find the index of the input letter in the alphabet
	int index = letter - 'A';

	// Map the input letter to the output letter using the rotor's wiring
	char output = _wiring[index];

	// Rotate the rotor
	Rotate();

	return output;
}

void Rotor::RotateArray()
{
	char lastChar = _wiring.back(); // Store the last character

	// Rotate the array
	for (int i = _wiring.size() - 1; i > 0; i--)
		_wiring[i] = _wiring[i - 1];

	_wiring.front() = lastChar;
}

void Rotor::SetNextRotor(std::shared_ptr<Rotor> nextRotor)
{
	// Setting the next rotor
	_nextRotor = std::weak_ptr<Rotor>(nextRotor);
}