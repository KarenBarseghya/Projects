#include <iostream>
#include <list>

class Hashtable
{
private:
    std::list<int> *table;
    int m_size;
    int getHash(int key);
public:
    Hashtable(int elem_count);
    void insert(int key);
    void remove(int key);
    void print();
    ~Hashtable();
};

int main()
{
    
}

Hashtable::Hashtable(int elem_count)
{
    m_size = elem_count;
    table = new std::list<int>[m_size];
}

int Hashtable::getHash(int key)
{
    return key % m_size;
}

void Hashtable::insert(int key)
{
    table[getHash(key)].push_back(key);
}

void Hashtable::remove(int key)
{
    int x = getHash(key);
    auto it = table[x].begin();
    for(; it != table[x].end(); ++it)
    {
        if(*it == key)
        {
            break;
        }
    }

    table->erase(it);
}

void Hashtable::print()
{
    for(int i = 0; i < m_size; ++i)
    {
        for(int j : table[i])
        {
            std::cout << j;
        }
        std::cout << std::endl;
    }
}

Hashtable::~Hashtable()
{
    delete [] table;
}
