#pragma once

#include "Card.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

class Deck {
  private:
    bool _haveRemise = true;
    std::vector<Card> _cardDeath;

  public:
    Deck() = default;
    Deck(bool haveRemise) : _haveRemise(haveRemise)
    {
        std::srand(std::time(nullptr));
    };
    ~Deck() = default;
    int getSize()
    {
        return 13 - _cardDeath.size();
    }
    void resetDeck()
    {
        _cardDeath.clear();
    }
    Card getCard()
    {
        std::string families[4] = {"Diamond", "Clubs", "Hearts", "Spades"};
        bool isValidCard = false;
        int number = 0;
        std::string familyName = "";
        if (_cardDeath.size() == 52)
            _cardDeath.clear();

        while (isValidCard == false) {
            number = std::rand() % 13 + 1;
            int family = std::rand() % (4 - 0);
            familyName = families[family];
            Card card(number, familyName);

            if (_cardDeath.size() == 0 ||
                std::find(_cardDeath.begin(), _cardDeath.end(), card) ==
                    _cardDeath.end()) {
                isValidCard = true;
            }
        }

        if (!_haveRemise) {
            _cardDeath.push_back(Card(number, familyName));
        }
        return Card(number, familyName);
    }
};
