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
        for (int i = 0; i < n; i++)
        {
            cin >> input[i];
        }
        sort(input, input + n);
        vector<int> diff;
        int diff2[n];
        bool flag = true;
        for (int i = 1; i < n; i++)
        {
            diff.push_back(input[i] - input[i - 1]);
        }
        for (int i = 0; i < diff.size() - 1; i++)
        {

            if (diff[i] != 2 * diff[i + 1] && 2 * diff[i] != diff[i + 1])
            {
                flag = false;
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