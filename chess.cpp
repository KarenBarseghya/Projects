#include <iostream>
#include "main.hpp"

int main()
{
    std::string figure;
    std::string next_place;
    board_symbols();
    while(true)
    {
        std::cin >> figure;
        std::cin >> next_place;
        checker(figure , next_place);
        board_printer();
    }
}


