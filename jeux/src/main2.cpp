#include "Dealer.hpp"

int main()
{
    Dealer dealer;
    int money = 0;
    int haveWin = 0;
    int i = 0;

    while (i < 1000000) {
        money -= 1;
        Card card1 = dealer.getCard();
        dealer.resetDeck();
        Card card2 = dealer.getCard();
        if (card1.getNumber() == card2.getNumber() &&
            card1.getFamily() == card2.getFamily()) {
            money += 50;
            haveWin += 1;
        }
        dealer.resetDeck();
        ++i;
    }
    std::cout << "Balance: " << money
              << " - Win ratio: " << haveWin / 1000000.0f * 100.0f << "%"
              << std::endl;

    return 0;
}