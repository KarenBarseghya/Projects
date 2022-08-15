#include <iostream>
#include <initializer_list>

enum{m_size = 8 * sizeof(size_t)};

class Vector
{
public:
    Vector();
    Vector(const Vector&);
    Vector(Vector&&);
    Vector(std::initializer_list<bool>);
    Vector(size_t);
    Vector(size_t , bool);
    bool empty();
    void push_back(bool val);
    ~Vector();

class reference
{
public:
    reference(size_t* , size_t);
    reference(const reference&);
    reference(reference&&);
    reference& operator = (const reference&);
    reference& operator=(reference&&);
    reference& operator=(bool);
    operator bool();
    void flip();
private:
    size_t* m_buf;
    size_t m_index;
    bool m_val;
};
reference operator[](size_t pos);
private:
    size_t m_cap;
    size_t Size;
    size_t* m_buf;
};

int main()
{
    Vector a(10 , 1);
    std::cout << a[0];
    
}

Vector::reference::reference(size_t* ptr , size_t index) : m_buf{ptr} , m_index{index} , m_val{}
{
    m_val = ptr[index / m_size] | (1 << (index % m_size));
}

void Vector::reference::flip()
{
    if(m_val)
    {
        m_buf[m_index / m_size] ^= (1 << (m_index % m_size));
        m_val = !m_val;
    }
}

Vector::reference::reference(const reference& other) : m_buf{other.m_buf} , m_index{other.m_index} , m_val{other.m_val}
{}

Vector::reference::reference(reference&& other) :  m_buf{other.m_buf} , m_index{other.m_index} , m_val{other.m_val}
{}

Vector::reference& Vector::reference::operator=(const reference& other)
{
    if(m_val != other.m_val)
    {
        this -> flip();
    }
    return *this;
}

Vector::reference& Vector::reference::operator=(reference&& other)
{
    if(m_val != other.m_val)
    {
        this -> flip();
    }
    return *this;
}

Vector::reference& Vector::reference::operator=(bool val)
{
    if(m_val != val)
    {
        this -> flip();
    } 
    return *this;
}

Vector::reference::operator bool()
{
    return m_val;
}

Vector::Vector() : m_cap{1}, Size{} , m_buf {}
{}

Vector::Vector(const Vector& other):m_cap{other.m_cap} , Size{other.Size}
{
    m_buf = new size_t[m_cap / m_size];
    for(int i = 0 ; i < (m_cap / m_size) ; ++i)
    {
        m_buf[i] = other.m_buf[i];
    }
}

Vector::Vector(Vector&& other):m_cap{other.m_cap} , m_buf {other.m_buf} , Size{other.Size}
{
    other.m_cap = 0;
    other.Size = 0;
    other.m_buf = nullptr;
}

Vector::Vector(std::initializer_list<bool> init) : m_cap{} , Size{init.size()} , m_buf{}
{
  if(init.size())
  {
      while(m_cap < init.size())
      {
          m_cap += m_size;
      }
      m_buf = new size_t[m_cap / m_size];
      size_t bit = 1;
      int i = 0;
      for(auto it = init.begin() ; it != init.end() ; ++it , ++i)
      {
          if(*it)
          {
              m_buf[i / m_size] |= (1 << (i % m_size)); 
          }
          bit <<= 1;
      }
  }  
}

Vector::Vector(size_t count) : m_cap{} , Size{count} , m_buf{}
{
    if(count)
    {
        while (m_cap < count)
        {
            m_cap += m_size;
        }
        m_buf = new size_t[m_cap / m_size];
    }
}

Vector::Vector(size_t count , bool val) : m_cap{} , Size{count} , m_buf{}
{
    if(count)
    {
        while(m_cap < count)
        {
            m_cap += m_size;
        }
        m_buf = new size_t[m_cap / m_size];
        if(val)
        {
            size_t bit = 1;
            for(int i = 0 ; i < count ; ++i)
            {
                m_buf[i / m_size] |= bit;
                bit <<= 1; 
            }
        }
    }
}

bool Vector::empty()
{
    if(Size)
    {
        return true;
    }
    return false;
}

Vector::reference Vector::operator[](size_t pos)
{
    return Vector::reference(m_buf , pos);
}

void Vector::push_back(bool val)
{
    if(this -> empty())
    {
        m_cap = m_size;
        m_buf = new size_t[1];
        (*this)[Size++] = val;
        return;
    }
    if(m_size == m_cap)
    {
        m_cap += m_size;
        size_t* ptr = new size_t[m_cap / m_size];
        for(int i = 0 ; i < (Size / m_size) ; ++i)
        {
            ptr[i] = m_buf[i];
        }
        delete [] m_buf;
        m_buf = ptr;
        ptr = nullptr;
    }
    (*this)[Size++] = val;
}

Vector::~Vector()
{
    if(m_buf)
    {
        delete [] m_buf;
    }
}

