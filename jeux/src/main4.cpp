#include "Dealer.hpp"

int main()
{
    Dealer dealer(false);
    int money = 0;
    int haveWin = 0;
    int i = 0;
    while (i < 1000000) {
        if (dealer.getDeckSize() >= 3) {
            money -= 1;
            int numberHearts = 0;
            std::string family1 = dealer.getCard().getFamily();
            std::string family2 = dealer.getCard().getFamily();
            std::string family3 = dealer.getCard().getFamily();
            if (family1 == "Hearts") {
                numberHearts += 1;
            }
            if (family2 == "Hearts") {
                numberHearts += 1;
            }
            if (family3 == "Hearts") {
                numberHearts += 1;
            }
            if (numberHearts > 0) {
                money += numberHearts;
                haveWin += 1;
            }
            ++i;
        } else {
            dealer.resetDeck();
        }
    }
    std::cout << "Balance: " << money
              << " - Win ratio: " << haveWin / 1000000.0f * 100.0f << "%"
              << std::endl;
    return 0;
}
