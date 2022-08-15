#include <iostream>
#include <map>

std::map<std::string , std::string> board;

void board_symbols()
{
    board["A1"] = "Wcastle1";
    board["B1"] = "Whorse1";
    board["C1"] = "Wbishop1";
    board["D1"] = "Wqueen";
    board["E1"] = "Wking";
    board["F1"] = "Wbishop2";
    board["G1"] = "Whorse2";
    board["H1"] = "Wcastle2";

    board["A2"] = "Wpawn1";
    board["B2"] = "Wpawn2";
    board["C2"] = "Wpawn3";
    board["D2"] = "Wpawn4";
    board["E2"] = "Wpawn5";
    board["F2"] = "Wpawn6";
    board["G2"] = "Wpawn7";
    board["H2"] = "Wpawn8";

    board["A3"] = "      ";
    board["B3"] = "      ";
    board["C3"] = "      ";
    board["D3"] = "      ";
    board["E3"] = "      ";
    board["F3"] = "      ";
    board["G3"] = "      ";
    board["H3"] = "      ";

    board["A4"] = "      ";
    board["B4"] = "      ";
    board["C4"] = "      ";
    board["D4"] = "      ";
    board["E4"] = "      ";
    board["F4"] = "      ";
    board["G4"] = "      ";
    board["H4"] = "      ";

    board["A5"] = "      ";
    board["B5"] = "      ";
    board["C5"] = "      ";
    board["D5"] = "      ";
    board["E5"] = "      ";
    board["F5"] = "      ";
    board["G5"] = "      ";
    board["H5"] = "      ";

    board["A6"] = "      ";
    board["B6"] = "      ";
    board["C6"] = "      ";
    board["D6"] = "      ";
    board["E6"] = "      ";
    board["F6"] = "      ";
    board["G6"] = "      ";
    board["H6"] = "      ";

    board["A7"] = "Bpawn1";
    board["B7"] = "Bpawn2";
    board["C7"] = "Bpawn3";
    board["D7"] = "Bpawn4";
    board["E7"] = "Bpawn5";
    board["F7"] = "Bpawn6";
    board["G7"] = "Bpawn7";
    board["H7"] = "Bpawn8";

    board["A8"] = "Bcastle1";
    board["B8"] = "Bhorse1";
    board["C8"] = "Bbishop1";
    board["D8"] = "Bking";
    board["E8"] = "Bqueen";
    board["F8"] = "Bbishop2";
    board["G8"] = "Bhorse2";
    board["H8"] = "Bcastle2";
}

void board_printer()
{ 
    std::cout << "   A    |   B    |   C    |   D    |   E    |   F    |   G    |   H    |" << std::endl;
    
    std::cout << "1" << board["A1"] <<"|" << board["B1"] << "|" << 
    board["C1"] << "|" << board["D1"] << "|" << board["E1"] << "|" << 
    board["F1"] << "|" << board["G1"] << "|" << board["H1"] << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;

    std::cout << "2" << board["A2"] << "  |" << board["B2"] << "|  " << 
    board["C2"] << "|" << board["D2"] << " |" << board["E2"] << "| " << 
    board["F2"] << "| " << board["G2"] << "| " << board["H2"] << std::endl;

    std::cout << "-----------------------------------------------------------------------" << std::endl;

    std::cout << "3" << board["A3"] << "  |" << board["B3"] << "|  " << 
    board["C3"] << "|" << board["D3"] << " |" << board["E3"] << "| " << 
    board["F3"] << "| " << board["G3"] << "| " << board["H3"] << std::endl;

    std::cout << "-----------------------------------------------------------------------" << std::endl;

    std::cout << "4" << board["A4"] << "  |" << board["B4"] << "|  " << 
    board["C4"] << "|" << board["D4"] << " |" << board["E4"] << "| " << 
    board["F4"] << "| " << board["G4"] << "| " << board["H4"] << std::endl;

    std::cout << "-----------------------------------------------------------------------" << std::endl;

    std::cout << "5" << board["A5"] << "  |" << board["B5"] << "|  " << 
    board["C5"] << "|" << board["D5"] << " |" << board["E5"] << "| " << 
    board["F5"] << "| " << board["G5"] << "| " << board["H5"] << std::endl;

    std::cout << "-----------------------------------------------------------------------" << std::endl;

    std::cout << "6" << board["A6"] << "  |" << board["B6"] << "|  " << 
    board["C6"] << "|" << board["D6"] << " |" << board["E6"] << "| " << 
    board["F6"] << "| " << board["G6"] << "| " << board["H6"] << std::endl;

    std::cout << "-----------------------------------------------------------------------" << std::endl;

    std::cout << "7" <<  board["A7"] << "  |" << board["B7"] << "|  " << 
    board["C7"] << "|" << board["D7"] << " |" << board["E7"] << "| " << 
    board["F7"] << "| " << board["G7"] << "| " << board["H7"] << std::endl;

    std::cout << "-----------------------------------------------------------------------" << std::endl;

    std::cout << "8" <<  board["A8"] << "  |" << board["B8"] << "|  " << 
    board["C8"] << "|" << board["D8"] << " |" << board["E8"] << "| " << 
    board["F8"] << "| " << board["G8"] << "| " << board["H8"] <<  std::endl;

    std::cout << "-----------------------------------------------------------------------" << std::endl;
}

void checker(std::string figure , std::string next_place)
{
    if(next_place[2] != '\0' || next_place[1] == '0' || next_place[1] == '9')
    {
        std::cout << "Try again !!!";
        return;
    }

    std::string word = board[figure].erase(5);

    if(word == "Wpawn" && figure[0] == next_place[0] || (figure[0] + 1 == next_place[0] + 0 && board[next_place][0] != ' '))
    {
        int first_tester = (int)figure[1] - 48;
        int second_tester = (int)next_place[1] - 48;
        if(first_tester + 1 == second_tester )
        {
            board[next_place] = board[figure];
            board[figure] = "      ";
        }
    }

    if(word == "Bpawn" && figure[0] == next_place[0])
    {
        int first_tester = (int)figure[1] - 48;
        int second_tester = (int)next_place[1] - 48;
        if(first_tester - second_tester == 1)
        {
            board[next_place] = board[figure];
            board[figure] = "      ";
        }
    }

    if (word == "Wcast" || word == "Bcast")
    {
        if(figure[0] == next_place[0] || figure[1] == next_place[1])
        {
            int tester = (int)figure[1] - 48;
            int second_tester = (int)next_place[1] - 48;
            if(word == "Wcast")
            {
                if(figure[0] == next_place[0])
                {
                    for(int i = tester + 1 ; i <= second_tester ; ++i)
                    {
                        std::string b = std::to_string(i);
                        if(board[figure[0] + b] != "      ")
                        {
                            if(i == second_tester  && board[figure[0] + b][0] == 'B')
                            {
                                board[next_place] = board[figure];
                                board[figure] = "      ";
                            }
                        return;
                        }
                        board[next_place] = board[figure];
                        board[figure] = "      ";

                    }
                }
                    if(figure[1] == next_place[1])
                    {
                        char sym = figure[0];
                        int i = 1;
                        for(char i = figure[0] ; i != next_place[0] + 1 ; ++i)
                        {
                            std::cout << board[figure];
                            if(board[figure] != "      " && figure[0] != sym)
                            {
                                return;
                            }
                        }
                        figure[0] = sym;
                        board[next_place] = board[figure];
                        board[figure] = "      ";
                    }
            }
            else if(word == "Bcast")
            {
                for(int i = tester - 1 ; i >= second_tester ; --i)
                {
                    std::string b = std::to_string(i);
                    if(i == second_tester  && board[figure[0] + b][0] == 'W')
                    {
                            board[next_place] = board[figure];
                            board[figure] = "      ";
                    }
                    else if(board[figure[0] + b] != "      ")
                    {
                        return;
                    }
                }
                board[next_place] = board[figure];
                board[figure] = "      ";
            }

        }
    }


    if(word == "Wbish" || word == "Bbish")
    {
        int tester = (int)figure[1] - 48;
        int second_tester = (int)next_place[1] - 48;
        if(figure[0] > next_place[0] && tester < second_tester)
        {
            if(figure[0] - next_place[0] == second_tester - tester)
            {
                board[next_place] = board[figure];
                board[figure] = "      ";
            }
        }
        else if(figure[0] < next_place[0] && tester < second_tester)
        {
            if(next_place[0] - figure[0] == second_tester - tester)
            {
                board[next_place] = board[figure];
                board[figure] = "      ";
            }
        }

        else if(figure[0] < next_place[0] && tester > second_tester)
        {
            if(next_place[0] - figure[0] == tester - second_tester)
            {
                board[next_place] = board[figure];
                board[figure] = "      ";
            }
        }

        else if(figure[0] > next_place[0] && tester > second_tester)
        {
            if(figure[0] - next_place[0] == tester - second_tester)
            {
                board[next_place] = board[figure];
                board[figure] = "      ";
            }
        }
    }

    if(word == "Whors" || word == "Bhors")
    {
        int tester = (int)figure[1] - 48;
        int second_tester = (int)next_place[1] - 48;
        if(figure[0] > next_place[0] && tester < second_tester)
        {
            if(figure[0] - next_place[0] == second_tester - tester - 1)
            {
                board[next_place] = board[figure];
                board[figure] = "      ";
            }
        }

        else if(figure[0] < next_place[0] && tester > second_tester)
        {
            if( next_place[0] - figure[0] == tester - second_tester +1)
            {
                board[next_place] = board[figure];
                board[figure] = "      ";
            }
        }

        else if(figure[0] > next_place[0] && tester > second_tester)
        {
            if(figure[0] - next_place[0] == tester - second_tester + 1)
            {
                board[next_place] = board[figure];
                board[figure] = "      ";
            }
        }

        else if(figure[0] < next_place[0] && tester < second_tester)
        {
            if(next_place[0] - figure[0] == second_tester - tester - 1) 
            {
                board[next_place] = board[figure];
                board[figure] = "      ";
            }
        }
    }

    if(word == "Wquee" || word == "Bquee")
    {
        if(figure[0] == next_place[0] || figure[1] == next_place[1])
        {
            int tester = (int)figure[1] - 48;
            int second_tester = (int)next_place[1] - 48;
            for(int i = tester + 1 ; i < second_tester ; ++i)
            {
                std::string b = std::to_string(i);
                if(board[figure[0] + b] != "      ")
                {
                    return;
                }
            }
            board[next_place] = board[figure];
            board[figure] = "      ";
        }

        int tester = (int)figure[1] - 48;
        int second_tester = (int)next_place[1] - 48;
        if(figure[0] > next_place[0] && tester < second_tester)
        {
            if(figure[0] - next_place[0] == second_tester - tester)
            {
                board[next_place] = board[figure];
                board[figure] = "      ";
            }
        }
        else if(figure[0] < next_place[0] && tester < second_tester)
        {
            if(next_place[0] - figure[0] == second_tester - tester)
            {
                board[next_place] = board[figure];
                board[figure] = "      ";
            }
        }

        else if(figure[0] < next_place[0] && tester > second_tester)
        {
            if(next_place[0] - figure[0] == tester - second_tester)
            {
                board[next_place] = board[figure];
                board[figure] = "      ";
            }
        }
    }
}

