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
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            cin >> input[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (input[i] == 1)
            {
                if (input[i + 1] == 0)
                {
                    flag = false;
                }
            }
            else if (input[i] == 2)
            {
                if (input[i + 1] == 0 || input[i + 1] == 3)
                {
                    flag = false;
                }
            }
            else if (input[i] == 3)
            {
                if (input[i + 1] == 0)
                {
                    flag = false;
                }
            }
            else if (input[i] == 0)
            {
                if (input[i + 1] == 2 || input[i] == 3)
                {
                    flag = false;
                }
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}