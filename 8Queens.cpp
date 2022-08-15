#include <iostream>
#include <vector>



std::vector<std::vector<int>>vec(4 ,{0});
 

bool is_safe(std::vector<std::vector<int>>& vec , int row , int col)
{ 
    for(int i = 0 ; i < 4 ; ++i)
    {
        if(vec[row][i])
        {
            return false;
        }
    }

    for(int i = row , j = col ; i >= 0 && j >= 0 ; i-- , j-- )
    {
        if(vec[i][j])
        {
            return false;
        }
    }

    for(int i = row , j = col ; i < vec.size() && j >= 0 ; ++i, --j)
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
    if(col >= 4)
    {
        return true;
    }
    for(int i = 0 ; i < 4 ; ++i)
    {
        if(is_safe(vec , i, col))
        {
            vec[i][col] = 1;
            if(setQ(vec , col + 1))
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
    if(setQ(vec , 0) == false)
    {
        return false;
    }
    
    for(int i = 0 ; i < 4 ; ++i)
    {
        for(int j = 0 ; j < 4 ; ++j)
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