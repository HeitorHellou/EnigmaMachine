#pragma once

#include <array>

class Plugboard
{
private:
    std::array<std::pair<char, char>, 10> _pairs;
public:
    Plugboard();
    char Swap(char letter);
};

Plugboard::Plugboard()
{
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

    if (it == _pairs.end()) {
        return letter;
    }

    if (it->first == letter) {
        return it->second;
    }
    else {
        return it->first;
    }
}
