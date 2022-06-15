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
        int n, x;
        cin >> n >> x;
        int input[n];
        for (int i = 0; i < n; i++)
        {
            cin >> input[i];
        }
        sort(input, input + n);

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int quotient = input[i] / x;
            int remainder = input[i] % x;
            count += quotient;
            if (remainder > 0)
            {
                count++;
            }
        }
        cout << min(count, input[n - 1]) << endl;
    }
}