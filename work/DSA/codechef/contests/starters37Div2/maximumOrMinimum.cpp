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
        int n;
        cin >> n;
        int input[n];
        int ones = 0;
        int zeros = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> input[i];
            if (input[i] == 0)
            {
                zeros++;
            }
            else
            {
                ones++;
            }
        }

        if (zeros > ones)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
}