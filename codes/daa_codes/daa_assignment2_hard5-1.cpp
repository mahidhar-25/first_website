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

void solve()
{
    string str;
    cin >> str;
    int n = str.length();
    int left, right, subStrLen;
    int L[n][n]; // Create a table to store results of subproblems

    // Strings of length 1 are palindrome of length 1
    for (left = 0; left < n; left++)
        L[left][left] = 1;

    for (subStrLen = 2; subStrLen <= n; subStrLen++)
    {
        for (left = 0; left < n - subStrLen + 1; left++)
        {
            right = left + subStrLen - 1;
            if (str[left] == str[right] && subStrLen == 2)
                L[left][right] = 2;
            else if (str[left] == str[right])
                L[left][right] = L[left + 1][right - 1] + 2;
            else
                L[left][right] = max(L[left][right - 1], L[left + 1][right]);
        }
    }

    cout << L[0][n - 1] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
    return (0);
}