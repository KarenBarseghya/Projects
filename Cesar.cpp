#include <iostream>

std::string Hidder(std::string message);
std::string Decoder(std::string message);

class cesar
{
    std::string hidden_message;
public :
    void set_hidden_word(std::string message);
};
int main()
{
    int choose = 0;
    std::string message{};
    std::cout << "Please enter your word : ";
    std::cin >> message;
    do
    {
        std::cout << "If you want hide the hidden work please enter 1 , else please enter 2 : ";
        std::cin >> choose;
    }while(choose != 1 && choose != 2);

    if(choose == 1)
    {
         Hidder(message);
    }
    else
    {
        Decoder(message);
    }

}

std::string Hidder(std::string message)
{
    int formation{};
    std::cout << "Please enter your formation count : ";
    std::cin >> formation;
    for(int i = 0; i < message.size(); ++i)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            if(message[i] - formation < 'a')
            {
                int count = message[i] - 'a' - 1;
                message[i] = 'z' - (formation + count);
                std::cout << message[i] << "    ";
            }
            else
            {
                message[i] -= formation;
                std::cout << message[i] << "    ";
            }
        }
        if(message[i] >= 'A' && message[i] <= 'Z')
        {
            if(message[i] - formation <'A')
            {
                int count = message[i] - 'A' - 1;
                message[i] = 'Z' - (formation + count);
            }
            else
            {
                message[i] -= formation;
            }
        }
    }
    return message;
}

std::string Decoder(std::string message)
{
    int formation{};
    std::cout << "Please enter the formation : ";
    std::cin >> formation; 
    for(int i = 0; i < message.size(); ++i)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            if(message[i] + formation >= 'z')
            {
                int count = 'z' - message[i] + 1;
                message[i] = 'a' + (formation - count);
                std::cout << message[i];
            }
            else
            {
                message[i] += formation;
                std::cout << message[i];
            }
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            if(message[i] + formation >= 'Z')
            {
                int count = 'Z' - message[i] + 1;
                message[i] = 'A' + (formation - count);
                std::cout << message[i];
            }
            else
            {
                message[i] += formation;
                std::cout << message[i];
            }
        }
    }

    return message;
}

