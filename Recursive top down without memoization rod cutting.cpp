#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

//RECURSIVE TOP DOWN WITHOUT MEMOIZATION
int top_down(vector<int>&prices,int size);

int main()
{
    cout<<"\n\t\t\t\tProblem 2a: Compartmentalization"<<endl;
    
    int L,B;
    vector<int> prices;
    //vector<int> prices {15000,75000,120000,135000,150000,255000};

    cout<<"\nPlease enter your land side in terms of length and breadth separated by space: ";
    cin>>L>>B;

    int size = L * B;

    if(size%100 != 0 && size <= 1000000)
    {
        cout<<"You have entered an invalid plot size... The area of the plot shall be in multiple of 100...";
        return 0;
    }

    size=size/100;

    srand((unsigned)time(NULL));

    cout<<"\n\tLand Size\tPrice"<<endl;
    cout<<"\t---------------------"<<endl;

    for (int i =0; i < size; i++)
    {
        int rnum = rand() % 500000 + 15000;
        prices.push_back(rnum);
        cout <<"\t"<<100*(i+1) << "\t\t" << prices[i] << endl;
    }

    cout<<"\nMaximum profit for size "<<size*100<<" is: "<<top_down(prices,size)<<endl;
    return 0;
}

int top_down(vector<int>&prices,int size)
{
    int ans = INT_MIN;    //Initialized to negative infinity

    if(size < 0 || size == 0)
    {
        return 0;
    }

    int i = 0;

    do
    {
         ans = max(ans, prices[i] + top_down(prices, size-i-1));
         i++;

    }while(i<size);

    return ans;
}

