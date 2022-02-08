#pragma once
#include <string>

class Card {
  private:
    int _number;
    std::string _family;

  public:
    Card(int number, std::string family) : _number(number), _family(family){};
    ~Card() = default;
    bool operator==(Card card)
    {
        return card.getNumber() == this->_number &&
               card.getFamily() == this->_family;
    };
    int getNumber()
    {
        return this->_number;
    }
    std::string &getFamily()
    {
        return this->_family;
    }
};
