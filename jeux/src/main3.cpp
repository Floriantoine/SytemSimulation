#include "Dealer.hpp"

int main()
{
    Dealer dealer(false);
    int money = 0;
    int haveWin = 0;
    int i = 0;
    while (i < 1000000) {
        money -= 1;
        int number = dealer.getCard().getNumber();
        int number2 = dealer.getCard().getNumber();
        if (number < number2) {
            money += 2;
            haveWin += 1;
        }
        ++i;
    }
    std::cout << "Balance: " << money
              << " - Win ratio: " << haveWin / 1000000.0f * 100.0f << "%"
              << std::endl;

    return 0;
}