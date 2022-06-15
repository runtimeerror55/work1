#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x;
        cin >> n, m, x;
        if (m == x)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << n - 1 << endl;
        }
    }
}