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
        unordered_map<int, int> um;
        for (int i = 0; i < n; i++)
        {
            cin >> input[i];
            um[input[i]]++;
        }
        sort(input, input + n);

        vector<int> temp;
        for (int i = 0; i < n; i++)
        {

            for (int j = n - 1; j >= 0; j--)
            {
                if (input[i] != input[j] && um[input[j]] > 0)
                {

                    temp.push_back(input[j]);
                    um[input[j]]--;
                    break;
                }
            }
        }

        if (temp.size() == n)
        {
            for (int i = 0; i < n; i++)
            {
                cout << input[i] << " ";
            }
            cout << endl;
            for (int i = 0; i < temp.size(); i++)
            {
                cout << temp[i] << " ";
            }

            cout << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
}