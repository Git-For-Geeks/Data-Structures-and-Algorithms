#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    int arr[amount + 1];
    arr[0] = 0;
    for (int i = 1; i <= amount; ++i)
        arr[i] = INT_MAX;

    int len = coins.size();

    for (int i = 1; i <= amount; ++i)
    {
        for (int j = 0; j < len; ++j)
        {
            if (coins[j] <= i)
            {
                int rest = arr[i - coins[j]];
                if (rest != INT_MAX && rest + 1 < arr[i])
                {
                    arr[i] = rest + 1;
                }
            }
        }
    }
    return arr[amount] == INT_MAX ? -1 : arr[amount];
}

int main()
{
    int amount;
    int n;
    int coin, result;
    vector<int> coins;
    cout << "Enter Number of Coins: ";
    cin >> n;
    cout << "Enter the Amount: ";
    cin >> amount;
    cout << "Enter the space separated array of coins: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coin;
        coins.push_back(coin);
    }
    result = coinChange(coins, amount);
    cout << "Number of Coins Required to Make the Sum: " << result;
    return 0;
}