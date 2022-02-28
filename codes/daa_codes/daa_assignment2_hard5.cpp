#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define ar array
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define all(x) x.begin(), x.end()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int max(int x, int y) { return (x > y) ? x : y; }

void solve1(string str)
{
    int n = str.length();
    int i, j, subStrLen;
    int L[n][n]; // Create a table to store results of subproblems

    int Way[n][n]; // Store how the palindrome come from.

    // Strings of length 1 are palindrome of lentgh 1
    for (i = 0; i < n; i++)
    {
        L[i][i] = 1;
        Way[i][i] = 0;
    }
    for (subStrLen = 2; subStrLen <= n; subStrLen++)
    {
        for (i = 0; i < n - subStrLen + 1; i++)
        {
            j = i + subStrLen - 1;
            if (str[i] == str[j] && subStrLen == 2)
            {
                L[i][j] = 2;
                Way[i][j] = 0;
            }
            else if (str[i] == str[j])
            {
                L[i][j] = L[i + 1][j - 1] + 2;
                Way[i][j] = 0;
            }
            else
            {
                if (L[i][j - 1] > L[i + 1][j])
                {
                    L[i][j] = L[i][j - 1];
                    Way[i][j] = 1;
                }
                else
                {
                    L[i][j] = L[i + 1][j];
                    Way[i][j] = 2;
                }
            }
        }
    }

    string result(L[0][n - 1] + 1, '\0');
    int index = 0;
    int left = 0, right = n - 1;

    while (left <= right)
    {
        if (Way[left][right] == 0)
        {
            result[index++] = str[left];
            left += 1;
            right -= 1;
        }
        else if (Way[left][right] == 1)
            right -= 1;
        else if (Way[left][right] == 2)
            left += 1;
    }

    int endIndex = (L[0][n - 1] % 2) ? index - 1 : index;

    for (int k = 0; k < endIndex; ++k)
        result[L[0][n - 1] - 1 - k] = result[k];

    result[index + endIndex] = '\0';

    cout << "result 1: " << result << endl;
}

void solve2(string str)
{
    string rev = str;
    reverse(rev.begin(), rev.end());
    int m = str.length();
    int n = rev.length();

    int L[m + 1][n + 1];
    // finding length of longest common subsequence(LCS) of str and rev of str.
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (str[i - 1] == rev[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    int index = L[m][n];
    string result(index + 1, '\0');

    // Start from the right-most-bottom-most
    // corner and one by one store characters
    // in result[]
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        // If current character in str[] and rev
        // are same, then current character
        // is part of LCS
        if (str[i - 1] == rev[j - 1])
        {
            // Put current character in result
            result[index - 1] = str[i - 1];
            i--;
            j--;

            // reduce values of i, j and index
            index--;
        }

        // If not same, then find the larger of
        // two and go in the direction of larger
        // value
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    cout << "result 2: " << result << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++)
    {
        string str;
        cin >> str;
        solve1(str);
        solve2(str);
    }
    return (0);
}