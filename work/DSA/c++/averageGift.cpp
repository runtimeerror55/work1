#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j < 50; j++)
        {

            int x = i | j;
            int y = i ^ j;
            cout << i << " " << j << " " << x << " " << y << endl;
        }
    }
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int input[n];
        for (int i = 0; i < n; i++)
        {
            cin >> input[i];
        }
        unordered_map<int, int> um;
        bool flag = false;
        um[input[0]]++;
        for (int i = 1; i < n; i++)
        {
            input[i] = input[i] + input[i - 1];
            um[input[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (input[i] == 5 * (i + 1))
            {
                flag = true;
                break;
            }
            else if (input[i] > x * (i + 1))
            {
                if (um[input[i] - (x * (i + 1))] > 0)
                {
                    flag = true;
                    break;
                }
            }
        }

        if (flag)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
}