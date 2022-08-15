#include <iostream>
#include "main.hpp"

int main()
{
    std::string figure;
    std::string next_place;
    std::cout << "When you want restart game enter 0";    
    board_symbols();
    while(true)
    {
        std::cin >> figure;
        if(figure == 0)
        {
            return 0;
        }
        std::cin >> next_place;
        checker(figure , next_place);
        board_printer();
    }
}


