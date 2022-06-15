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
        string s;
        cin >> s;
        int zeros = 0;
        int ones = 1;
        bool found = false;

        if (n % 2 != 0)
        {
            cout << "no" << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '0')
                {
                    zeros++;
                }
                else
                {
                    ones++;
                }
            }

            if (zeros == ones)
            {
                cout << "yes" << endl;
            }
            else
            {
                int size = 0;
                if (zeros > ones)
                {
                    size = zeros - ones;
                    size = size / 2;
                    for (int i = 0; i < n; i++)
                    {
                        if (s[i] == '0')
                        {
                            int j = i;
                            while (s[i] == s[j] && j < n)
                            {
                                j++;
                            }
                            if (j >= size)
                            {
                                found = true;
                                break;
                            }
                        }
                    }
                }
                else
                {
                    size = ones - zeros;
                    size = size / 2;
                    for (int i = 0; i < n; i++)
                    {
                        if (s[i] == '1')
                        {
                            int j = i;
                            while (s[i] == s[j] && j < n)
                            {
                                j++;
                            }
                            if (j >= size)
                            {
                                found = true;
                                break;
                            }
                        }
                    }
                }
                if (found)
                {
                    cout << "yes" << endl;
                }
                else
                {
                    cout << "no" << endl;
                }
            }
        }
    }
}