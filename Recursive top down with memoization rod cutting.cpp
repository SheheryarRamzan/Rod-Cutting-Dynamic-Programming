#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

//RECURSIVE TOP DOWN WITH MEMOIZATION
int top_down_memoized(vector<int>& prices, int size, int dp[]);
int recursive_top_down(vector<int>& prices, int size);

int main()
{
    cout << "\n\t\t\t\tProblem 2b: Compartmentalization" << endl;

    //vector<int> prices {15000,75000,120000,135000,150000,255000};
    vector<int> prices;
    int L, B;

    cout << "\nPlease enter your land side in terms of length and breadth separated by space: ";
    cin >> L >> B;

    int size = L * B;

    if (size % 100 != 0 && size <= 1000000)
    {
        cout << "You have entered an invalid plot size... The area of the plot shall be in multiple of 100...";
        return 0;
    }

    size = size / 100;

    srand((unsigned)time(NULL));

    cout << "\n\tLand Size\tPrice" << endl;
    cout << "\t---------------------" << endl;

    for (int i = 0; i < size; i++)
    {
        int rnum = rand() % 500000 + 15000;
        prices.push_back(rnum);
        cout << "\t" << 100 * (i + 1) << "\t\t" << prices[i] << endl;
    }

    cout << "\nMaximum profit for size " << size * 100 << " is: " << recursive_top_down(prices, size) << endl;
    return 0;
}

int top_down_memoized(vector<int>& prices, int size, int dp[])
{
    int ans;

    if (dp[size] > 0 || dp[size] == 0)
    {
        return dp[size];
    }

    if (size == 0)
    {
        ans = 0;
    }
    else
    {
        ans = INT_MIN;

        int i = 0;
        do
        {
            ans = max(ans, prices[i] + top_down_memoized(prices, size - i - 1, dp));
            i++;

        } while (i < size);

    }

    dp[size] = ans;
    return ans;
}

int recursive_top_down(vector<int>& prices, int size)
{
    int const new_size = size + 1;
    int *dp=new int[new_size];

    int i = 0;
    do
    {
        dp[i] = INT_MIN;
        i++;

    } while (i < new_size);

    return top_down_memoized(prices, size, dp);
}
