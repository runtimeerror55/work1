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
        int a[n];
        int b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        map<pair<int, int>, int> um;

        for (int i = 0; i < n; i++)
        {
            um[{a[i] + b[i], abs(a[i] - b[i])}]++;
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (um[{a[i] + b[i], a[i] - b[i]}] > 1)
            {
                count += um[{a[i] + b[i], a[i] - b[i]}] - 1;
                um[{a[i] + b[i], a[i] - b[i]}]--;
            }
        }
        cout << count << endl;
    }
}