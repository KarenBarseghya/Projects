#include <iostream>
#include "main.hpp"

void Validation::set_string(std::string word)
{
    m_word = word;
}

std::string Validation::get_string()
{
    return m_word;
}

bool Validation::is_valid_mail(std::string mail)
{
    const int idCount = 7;
    std::string mailIds[idCount] = {"@mail.ru", "@gmail.com", "@bk.ru", 
                            "@internet.ru", "gmail.com" , 
                            "@list.ru" , "@yahoo.com" };
    std::string word{};
    for(int i = 0; i < mail.length(); ++i)
    {
        if(mail[i] == '@')
        {
            if(i < 7)
            {
                return false;
            }
            while(mail[i] != '\0')
            {
                word.push_back(mail[i]);
                ++i;
            }
        }
    }
    for(int i = 0; i < idCount; ++i)
    {
        if(word == mailIds[i])
        {
            return true;
        }
    }
    return false;
}

bool Validation::is_valid_reference(std::string reference)
{
    std::string word{};
    const int Protocolcount = 2;
    std::string Protocol[Protocolcount] = {"http://" , "https://"};
    for(int i = 0; i < Protocol[Protocolcount - 1].size(); ++i)
    {
        word.push_back(reference[i]);
        if(word == Protocol[Protocolcount - 2] || word == Protocol[Protocolcount-1])
        {
            return true;
        }
    }
    return false;
}

bool Validation::is_valid_month_day(std::string month_day)
{
    for(int i = 0; i < month_day.size(); ++i)
    {
        if(month_day[i] <= '0' && month_day[i] >= '9')
        {
            return false;
        }
    }
    int a = stoi(month_day);
    if(a >= 1 && a <= 31)
    {
        return true;
    }
    return false;
}

bool Validation::is_valid_phone_number(std::string phone_number)
{
    std::string word{};
    bool test = true;
    const int validPhonenumbercount = 8;
    std::string validPhonenumber[] = {"+37477" , "+37499" , "+37496" , "+37494" ,
                                     "+37433","+37493" , "+37443" , "+37444"};

    std::string validPhonenumberwithout374[] = {"077" , "099" , "096" , 
                                                "094" , "033" , "093"
                                                "043" , "044"};
    if(phone_number[0] == '+')
    {
        for(int i = 0; i < validPhonenumber[0].length(); ++i)
        {
            word.push_back(phone_number[i]);
        }

        for(int i = 0; i < validPhonenumbercount; ++i)
        {
            if(word == validPhonenumber[i])
            {
                test = false;
            }
        }

    }
    else if(phone_number[0] == '0')
    {
        for(int i = 0; i < validPhonenumberwithout374[0].length(); ++i)
        {
            word.push_back(phone_number[i]);
        }

        for(int i = 0; i < validPhonenumbercount; ++i)
        {
            if(word == validPhonenumber[i])
            {
                test = false;
            }
        }
       
    }

    if(phone_number.length() == 9 && phone_number[0] == '0')
    {
        return true;
    }

    if(phone_number.length() == 12 && phone_number[0] == '+')
    {
        return true;
    }

    return false;
}

bool Validation::is_valid_credit_card(std::string card_number)
{
    if(card_number.length() == 16 || card_number.length() == 13)
    {
        for(int i = 0; i < card_number.length(); ++i)
        {
            if(card_number[i] < '0' || card_number[i] > '9')
            {
                return false;
            }
        }
    }
}
