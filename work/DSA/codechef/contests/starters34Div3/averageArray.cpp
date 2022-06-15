#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        int finalSum = n * x;

        vector<int> v;
        if (n == 2)
        {
            v.push_back(x + 1);
            v.push_back(x - 1);
        }
        else
        {
            v.push_back(x);
            int s = 0;
            for (int i = 1; i <= n - 2; i++)
            {
                v.push_back(i + x);
                s = s + i;
            }

            v.push_back(x - s);
        }
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
}