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
        string input;
        cin >> input;
        int count = 0;
        vector<pair<int, int>> v;

        for (int i = 0; i < n - 1; i++)
        {
            if (input[i] == '0' && input[i + 1] == '1')
            {
                v.push_back({i + 1, n - i});
                v.push_back({i + 2, n - i - 1});

                count = count + 2;
                i++;
            }
            else
            {
                if (input[i] == '0' && input[i + 1] == '0')
                {
                    v.push_back({i + 1, n - i});
                    count++;

                    i++;
                }
            }
        }
        cout << count << endl;
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i].first << " " << v[i].second << endl;
        }
    }
}