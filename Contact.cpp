#include <iostream>
#include <fstream>
#include <vector>

const int size = 6;
void interface();
void Add_contact_list();
void List_all_contacts();
void Search_for_contact();
void Edit_contact();
void Delete_contact();
void collector();
void put_on_txt();

struct Contact
{
    std::string Name{};
    std::string Surname{};
    std::string Date_of_birth{};
    std::string ID{};
    std::string PhoneNumber{};
    std::string Email{};
};

std::vector<Contact>Data;

int main()
{
    collector();
   interface();
   put_on_txt();
}

void interface()
{
    int choose = 0;
     do
    {
        std::cout << "           Main Menu        " << std::endl;        
        std::cout << "    =======================    " << std::endl;
        std::cout <<  "   [1] Add a new Contact" << std::endl;
        std::cout <<  "   [2] List all Contacts" << std::endl;
        std::cout <<  "   [3] Search for Contact" << std::endl;
        std::cout <<  "   [4]Edit a Contact" << std::endl;
        std::cout <<  "   [5] Delete a Contact" << std::endl;
        std::cout <<  "   [0] exit" << std::endl;
        std::cout << "Which function are you want , please input number of option : ";
     std::cin >> choose;
     switch(choose)
     {
         case 1 : 
            Add_contact_list(); 
            break;
         case 2 : 
            List_all_contacts(); 
            break;
         case 3 : 
            Search_for_contact(); 
            break;
         case 4 : 
            Edit_contact(); 
            break;
         case 5 : 
            Delete_contact();
            break;
     }
   }while(choose != 0);
}
void collector()
{
    std::ifstream fin;
    std::string str;
    fin.open("text.txt");
    Contact data;
    std::getline(fin , str);
    int count = 0;
    if(str.length() != 0)
    {
        count = stoi(str);
    }
    std::getline(fin , str);
    for(int k = 0 ; k < count ; ++k)
    {
    for(int i = 0 ; i < size ; ++i)
    {
        std::getline(fin , str);
        std::string str2;
        for(int h = 0 ; str[h] != ';' ; ++h)
        {
          str2 += str[h];
        }
        if(str2 == "-----contact-----")
        {
            break;
        }
        if(i == 0)
        {
            data.Name = str2;
        }
        else if(i == 1)
        {
            data.Surname = str2;
        }

        else if(i == 2)
        {
            data.Date_of_birth = str2;
        }

        else if(i == 3)
        {
            data.ID = str2;
        }

        else if(i == 4)
        {
            data.PhoneNumber = str2;
        }

        else if(i == 5)
        {
            data.Email = str2;
        }
    }
    std::getline(fin , str);
    Data.push_back(data);
    }
    fin.clear();
    fin.close();
}
void Add_contact_list()
{
    std::string name{};
    std::cout << "Please enter Name : ";
    std::cin >> name;
    std::string surname{};
    std::cout << "Please enter Surname : ";
    std::cin >> surname;
    std::string date_of_birth{};
    std::cout << "Please enter date of birth : ";
    std::cin >> date_of_birth;
    std::string id{};
    std::cout << "Please enter your passport id : ";
    std::cin >> id;
    std::string Phonenumber{};
    std::cout << "Please enter your phone number : ";
    std::cin >> Phonenumber;
    std::string email{};
    std::cout << "Please enter your email : ";
    std::cin >> email;

    Contact data;
    data.Name = name ;
    data.Surname = surname;
    data.Date_of_birth = date_of_birth;
    for(int i = 0 ; i < Data.size() ; ++i)
    {
        if(Data[i].ID == id)
        {
            do
            {
                std::cout << "Your id is repeated please enter new id : ";
                std::cin >> id;
            }   while (Data[i].ID == id);
        }
        data.ID = id;
    }
    for(int i = 0 ; i < Data.size() ; ++i)
    {
        if(Data[i].PhoneNumber == Phonenumber)
        {
            
            do
            {
                std::cout << "Your phonenumber is repeated please enter new phone number : ";
                std::cin >> Phonenumber;
            }   while (Data[i].PhoneNumber == Phonenumber);
        }
        data.PhoneNumber = Phonenumber;
    }

    for(int i = 0 ; i < Data.size() ; ++i)
    {
        if(data.Email == email)
        {
            do
            {
                std::cout << "Your email is repeated please enter new email : ";
                std::cin >> email;
            }   while (Data[i].Email == email);
            
        }
        data.Email = email;
    }

    Data.push_back(data);
}

void List_all_contacts()
{
    for(int i = 0 ; i < Data.size() ; ++i)
    {
        std::cout << "Name : " << Data[i].Name << "  ";
        std::cout << "Surname : " << Data[i].Surname << "  ";
        std::cout << "Date of birth : " << Data[i].Date_of_birth << "  ";
        std::cout << "Pasport Id : " << Data[i].ID << "  ";
        std::cout << "Phone Number : " << Data[i].PhoneNumber << "  ";
        std::cout << "Email : " << Data[i].Email << std::endl;
    }
}

void Search_for_contact()
{
    std::string word;
    std::cout << "Pease enter data for searching : ";
    std::cin >> word;
    for(int i = 0 ; i < Data.size() ; ++i)
    {
        if(word == Data[i].Name || word == Data[i].Surname || word == Data[i].Date_of_birth
          || word == Data[i].ID || word == Data[i].PhoneNumber || word == Data[i].Email)
        {
            for(int i = 0 ; i < Data.size() ; ++i)
            {
                std::cout << "Name : " << Data[i].Name << "  ";
                std::cout << "Surname : " << Data[i].Surname << "  ";
                std::cout << "Date of birth : " << Data[i].Date_of_birth << "  ";
                std::cout << "Pasport Id : " << Data[i].ID << "  ";
                std::cout << "Phone Number : " << Data[i].PhoneNumber << "  ";
                std::cout << "Email : " << Data[i].Email << std::endl;
            }
        }
    }
}

void Edit_contact()
{
    std::string word;
    int count = 0;
    do
    {
        std::cout << "Pease enter data for searching : ";    
        std::cin >> word;
        for(int i = 0 ; i < Data.size() ; ++i)
        {
            if(word == Data[i].Name || word == Data[i].Surname || word == Data[i].Date_of_birth
            || word == Data[i].ID || word == Data[i].PhoneNumber || word == Data[i].Email)
            {
                ++count;
            }
        }
    }while(count != 1);
    
     for(int i = 0 ; i < Data.size() ; ++i)
     {
        if(word == Data[i].Name || word == Data[i].Surname || word == Data[i].Date_of_birth
        || word == Data[i].ID || word == Data[i].PhoneNumber || word == Data[i].Email)
        {
            int choose_counter = 0;
            std::cout << "Please enter what you want to move :  1.Name ,  2.Surname , 3.Date of birh , 4.ID , 5.Phone number , 6.Email :  ";
            std::cin >> choose_counter;
            bool test = false;
            do
            {
                std::cout << "Please enter the word and then we move old word : ";
                std::cin >> word;
                test = false;
                if(word == Data[i].Name || word == Data[i].Surname || word == Data[i].Date_of_birth
                || word == Data[i].ID || word == Data[i].PhoneNumber || word == Data[i].Email)
                {
                    test = true;;
                }
            }while(test);

                switch (choose_counter)
                {
                    case 1: Data[i].Name = word; break;
                    case 2: Data[i].Name = word; break;
                    case 3: Data[i].Date_of_birth = word; break;
                    case 4: Data[i].ID = word; break;
                    case 5: Data[i].PhoneNumber = word; break;
                    case 6: Data[i].Email = word; break;
            
                default:
                    break;
                } 
        }

    }
}

void Delete_contact()
{
    std::string word;
    int count = 0;
    do
    {
        std::cout << "Pease enter data for searching : ";    
        std::cin >> word;
        for(int i = 0 ; i < Data.size() ; ++i)
        {
            if(word == Data[i].Name || word == Data[i].Surname || word == Data[i].Date_of_birth
            || word == Data[i].ID || word == Data[i].PhoneNumber || word == Data[i].Email)
            {
                ++count;
            }
        }
    }while(count != 1);
    
    for(int i = 0 ; i < Data.size() ; ++i)
     {
        if(word == Data[i].Name || word == Data[i].Surname || word == Data[i].Date_of_birth
        || word == Data[i].ID || word == Data[i].PhoneNumber || word == Data[i].Email)
        {
            Data.erase(Data.begin() + i);
        }
    }
}

void put_on_txt()
{
    std::ofstream fin;
    fin.open("text.txt");
   fin << Data.size() << std::endl;
   for(int i = 0 ; i < Data.size() ; ++i)
   {
       fin << "-----contact-----;" << std::endl;
       fin << Data[i].Name << ';' << "name;"  << std::endl;
       fin << Data[i].Surname << ';' << "surname;" << std::endl;
       fin << Data[i].Date_of_birth << ';' <<"dateofbirth;" <<  std::endl;
       fin << Data[i].ID << ';' <<"id;" << std::endl;
       fin << Data[i].PhoneNumber << ';' << "phonenumber;" << std::endl;
       fin << Data[i].Email << ';' <<"email;" <<  std::endl;
    }
    fin.close();
}