#include <iostream>
#include <vector>
std::vector<int>vp{10,20,50,100,200,500};

int coinChange(std::vector<int>& coins, int amount) 
{
        std::sort(coins.begin() , coins.end());
        if(!amount)
        {
            return 0;
        }
        else if(coins.size() == 1 && coins[0] != amount)
        {
            return -1;
        }
        int count = 0;
        for(int i = coins.size() - 1 ; i >= 0 ; --i)
        {
            int div = amount / coins[i];
            count += div;
            if(!div)
            {
                continue;
            }
            amount -= (div * coins[i]);
            if(!amount)
            {
                return count;
            }
        }
        return -1;
    }

    int main()
    {
        std::cout << coinChange(vp , 1365);
    }