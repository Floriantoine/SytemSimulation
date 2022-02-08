#pragma once

#include "Deck.hpp"

class Dealer {
  private:
    Deck _deck;

  public:
    Dealer() : _deck(true){};
    Dealer(bool makeRemise) : _deck(makeRemise){};
    ~Dealer() = default;
    int getDeckSize()
    {
        return _deck.getSize();
    }
    void resetDeck()
    {
        _deck.resetDeck();
    }
    Card getCard()
    {
        return _deck.getCard();
    }
};
