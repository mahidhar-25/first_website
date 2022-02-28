
//logic : 
// here we using the recursion and memorization
// top down dynamic approach
// it is very similar to 0-01 knapsack here the extra case we add we check if we can include half of the weight or not
// if we cant include half of the weight and full weight then we wont consider it 
// if we include half weight , we will check recusively for remaining weight and we store 

// time complexity : 
//                 O(n*w)
//                        n = no of items , w = max weight 
// space complexity : 
//                      O(n2)


// the recursion call is we check max of includeing with its weight , or not including with its weight

// Here is the top-down approach of
// dynamic programming
#include <bits/stdc++.h>
using namespace std;

// Returns the value of maximum profit
double knapSackRecursion(int W,vector<double>wt, vector<double>val, int i, vector<vector<double>>dp)
{
    // base condition
    if (i < 0) return 0;

    if (dp[i][W] != -1)
        return dp[i][W];

    if (wt[i] > W)// checking if weight is greater than required weight
    {
        if (wt[i] / 2 > W)   //checking the condition if half of the weight is greater than required weight then we wont consider it
        {
            dp[i][W] = knapSackRecursion(W, wt, val, i - 1, dp);
        }
        else
        {
            dp[i][W] = max(val[i] / 2 + knapSackRecursion(W - wt[i] / 2, wt, val, i - 1, dp), knapSackRecursion(W, wt, val, i - 1, dp));
        }
        return dp[i][W];
    }
    else
    {
        // Store value in a table before return
        // finding max btw half anf full values of objects.
        dp[i][W] = max(val[i] / 2 + knapSackRecursion(W - wt[i] / 2, wt, val, i - 1, dp), max(val[i] + knapSackRecursion(W - wt[i],  wt, val, i - 1, dp), knapSackRecursion(W, wt, val,  i - 1, dp)));

        // Return value of table after storing
        return dp[i][W];
    }
}

double knapSack(int W,vector<double>wt, vector<double>val, int n)
{
    //declaring a 2d dynamical array with each colum size maxweigh+1 
    // initilazing with -1
    // table dynamically
    vector<vector<double>> dp(n , vector<double>(W+1 , -1));
    return knapSackRecursion(W, wt, val, n - 1, dp);
}

int main()
{
    int W,n;
    cout << "Enter The Number OF Weights :"; cin >> n;
    vector<double> weight(n), values(n);
    cout << "Enter The Weights and Profits:";
    for (int i = 0; i < n; i++)
        cin >> weight[i] >> values[i];

    cout << "Enter Total Weight OF Knapsack in <int>:"; cin >> W;
    cout <<" max possible profit : " <<knapSack(W, weight, values, n);
    return 0;
}

