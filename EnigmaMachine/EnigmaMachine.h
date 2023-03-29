#pragma once

#include "Rotor.h"
#include "Plugboard.h"
#include "Reflector.h"

class EnigmaMachine
{
private:
	// Shared pointers to the three rotors
	std::shared_ptr<Rotor> _rotor1;
	std::shared_ptr<Rotor> _rotor2;
	std::shared_ptr<Rotor> _rotor3;
	// Plugboard and Reflector objects
	Plugboard _plugboard;
	Reflector _reflector;
public:
	EnigmaMachine(const Rotor& rotor1, const Rotor& rotor2, const Rotor& rotor3); // Constructor that takes three rotors as input and sets up the machine
	char Encrypt(char letter); // Function to encrypt a single letter
};

// Use shared pointers to initialize the rotor objects nad initialize plugboard and reflector objects
EnigmaMachine::EnigmaMachine(const Rotor& rotor1, const Rotor& rotor2, const Rotor& rotor3): _rotor1(std::make_shared<Rotor>(rotor1)),
	_rotor2(std::make_shared<Rotor>(rotor2)), _rotor3(std::make_shared<Rotor>(rotor3)), _plugboard(), _reflector()
{
	// Set up the rotors connection
	_rotor1->SetNextRotor(_rotor2);
	_rotor2->SetNextRotor(_rotor3);
	_rotor3->SetNextRotor(nullptr); // The last rotor has no next rotor
}

char EnigmaMachine::Encrypt(char letter)
{
	// Swap the input letter with its corresponding plugboard letter
	letter = _plugboard.Swap(letter);

	// Encrypt the letter with each of the three rotors in sequence
	letter = _rotor1->Encrypt(letter);
	letter = _rotor2->Encrypt(letter);
	letter = _rotor3->Encrypt(letter);

	// Reflect the letter with the reflector
	letter = _reflector.Reflect(letter);

	// Encrypt the letter again with each rotor in reverse order
	letter = _rotor3->Encrypt(letter);
	letter = _rotor2->Encrypt(letter);
	letter = _rotor1->Encrypt(letter);

	// Swap the final output letter with its corresponding plugboard letter
	return _plugboard.Swap(letter);
}