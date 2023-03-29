#pragma once

#include <array>

class Plugboard
{
private:
    std::array<std::pair<char, char>, 10> _pairs; // pairs of letter to swap
public:
    Plugboard(); // Constructor to set the pairs
    char Swap(char letter); // Function to swap the input letter with its corresponding pair
};

Plugboard::Plugboard()
{
    // Initializing the pairs of letter to swap
    _pairs = { {
        { 'A', 'J' },
        { 'B', 'D' },
        { 'C', 'F' },
        { 'E', 'I' },
        { 'G', 'K' },
        { 'H', 'M' },
        { 'L', 'N' },
        { 'O', 'P' },
        { 'Q', 'S' },
        { 'T', 'U' }
    } };
}

char Plugboard::Swap(char letter)
{
    // Find the matching pair for the input and return the other number in the pair
    auto it = std::find_if(_pairs.begin(), _pairs.end(),
        [letter](const std::pair<int, int>& pair) {
            return pair.first == letter || pair.second == letter;
        });

    // If the letter doesn't have a pair return the letter
    if (it == _pairs.end())
        return letter;
    // Return the other letter in the pair
    if (it->first == letter)
        return it->second;
    else
        return it->first;
}
