#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

//Iterative bottom up with memoization

int main()
{
    cout << "\n\t\t\t\tProblem 2c: Compartmentalization" << endl;
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

    int new_size = size + 1;
    int i = 0,ans;
    int *dp = new int[new_size];

    dp[0] = 0;
    i++;

    do
    {
        ans = INT_MIN;
        int j = 0;

        do
        {
            ans = max(ans, prices[j] + dp[i - j - 1]);
            j++;

        } while (j < i);

        dp[i] = ans;
        i++;

    } while (i <= size);

    cout << "\nMaximum profit for size " << size * 100 << " is: " << dp[size] << endl;

    return 0;
}
