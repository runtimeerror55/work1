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
        unordered_map<int, int> um;
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (um.find(x) != um.end())
            {
                flag = true;
            }
            else
            {
                um[x]++;
            }
        }
        if (flag)
        {
            cout << "no" << endl;
        }
        else
        {
            cout << "yes" << endl;
        }
    }
}