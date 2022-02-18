#include "Dealer.hpp"
#include <algorithm>
#include <array>

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
        money -= 1;
        int number1 = dealer.getCard().getNumber();
        int number2 = dealer.getCard().getNumber();
        int number3 = dealer.getCard().getNumber();
        int number4 = dealer.getCard().getNumber();
        int number5 = dealer.getCard().getNumber();
        std::array<int, 5> intArray = {
            number1, number2, number3, number4, number5};

        std::sort(intArray.begin(), intArray.end());
        if (isConsecutive(intArray[0], intArray[1], intArray[2]) ||
            isConsecutive(intArray[1], intArray[2], intArray[3]) ||
            isConsecutive(intArray[2], intArray[3], intArray[4])) {
            money += 5;
            haveWin += 1;
        }
        ++i;
        dealer.resetDeck();
    }
    std::cout << "Balance: " << money
              << " - Win Ratio: " << haveWin / 1000000.0f * 100.0f << "%"
              << std::endl;
    return 0;
}
