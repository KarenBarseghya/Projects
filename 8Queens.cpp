#include <iostream>
#include <vector>

const int Size = 4;

std::vector<std::vector<int>>vec(Size, {0});
 

bool is_safe(std::vector<std::vector<int>>& vec, int row, int col)
{ 
    for(int i = 0; i < Size; ++i)
    {
        if(vec[row][i])
        {
            return false;
        }
    }

    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if(vec[i][j])
        {
            return false;
        }
    }

    for(int i = row, j = col; i < vec.size() && j >= 0; ++i, --j)
    {
        if(vec[i][j])
        {
            return false;
        }
    }
    return true;
}

bool setQ(std::vector<std::vector<int>>& vec, int col)
{
    if(col >= Size)
    {
        return true;
    }
    for(int i = 0; i < Size; ++i)
    {
        if(is_safe(vec, i, col))
        {
            vec[i][col] = 1;
            if(setQ(vec, col + 1))
            {
                return true;
            }
            vec[i][col] = 0;
        }
    }
    return false;
}

bool solve()
{
    if(setQ(vec, 0) == false)
    {
        return false;
    }
    
    for(int i = 0; i < Size; ++i)
    {
        for(int j = 0; j < Size; ++j)
        {
            std::cout << vec[i][j];
        }
        std::cout << std::endl;
    }
    return true;
}

int main()
{
    solve();
}
