#include "Dealer.hpp"
#include <algorithm>

bool isConsecutive(int a, int b, int c)
{
    int min = std::min(a, std::min(b, c));
    int max = std::max(a, std::max(b, c));
    return max - min == 2 && a != b && a != c && b != c;
}

int main()
{
    Dealer dealer(false);
    int money = 0;
    int haveWin = 0;
    int i = 0;
    while (i < 1000000) {
        if (dealer.getDeckSize() >= 5) {
            money -= 1;
            int number1 = dealer.getCard().getNumber();
            int number2 = dealer.getCard().getNumber();
            int number3 = dealer.getCard().getNumber();
            int number4 = dealer.getCard().getNumber();
            int number5 = dealer.getCard().getNumber();

            if (isConsecutive(number1, number2, number3) ||
                isConsecutive(number1, number2, number4) ||
                isConsecutive(number1, number2, number5) ||
                isConsecutive(number1, number3, number4) ||
                isConsecutive(number1, number3, number5) ||
                isConsecutive(number1, number4, number5) ||
                isConsecutive(number2, number3, number4) ||
                isConsecutive(number2, number3, number5) ||
                isConsecutive(number3, number4, number5)) {
                money += 5;
                haveWin += 1;
            }
            ++i;
        } else {
            dealer.resetDeck();
        }
    }
    std::cout << "money End: " << money
              << " - Ratio win: " << haveWin / 1000000.0f * 100.0f << "%"
              << std::endl;
    return 0;
}
