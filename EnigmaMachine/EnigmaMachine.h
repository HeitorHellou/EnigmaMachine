#pragma once

#include "Rotor.h"
#include "Plugboard.h"
#include "Reflector.h"

class EnigmaMachine
{
private:
	std::shared_ptr<Rotor> _rotor1;
	std::shared_ptr<Rotor> _rotor2;
	std::shared_ptr<Rotor> _rotor3;
	Plugboard _plugboard;
	Reflector _reflector;
public:
	EnigmaMachine(const Rotor& rotor1, const Rotor& rotor2, const Rotor& rotor3);
	char Encrypt(char letter);
};

EnigmaMachine::EnigmaMachine(const Rotor& rotor1, const Rotor& rotor2, const Rotor& rotor3): _rotor1(std::make_shared<Rotor>(rotor1)),
	_rotor2(std::make_shared<Rotor>(rotor2)), _rotor3(std::make_shared<Rotor>(rotor3)), _plugboard(), _reflector()
{
	_rotor1->SetNextRotor(_rotor2);
	_rotor2->SetNextRotor(_rotor3);
	_rotor3->SetNextRotor(nullptr);
}

char EnigmaMachine::Encrypt(char letter)
{
	letter = _plugboard.Swap(letter);

	letter = _rotor1->Encrypt(letter);
	letter = _rotor2->Encrypt(letter);
	letter = _rotor3->Encrypt(letter);

	letter = _reflector.Reflect(letter);

	letter = _rotor3->Encrypt(letter);
	letter = _rotor2->Encrypt(letter);
	letter = _rotor1->Encrypt(letter);

	return _plugboard.Swap(letter);
}