#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     int n, k;
    //     cin >> n >> k;
    //     string s;
    //     cin >> s;
    //     int prefix[n];
    //     int suffix[n];
    //     int ones = 0;
    //     long long int count = 0;

    //     int zeros = 0;
    //     for (int i = 0; i < n; i++)
    //     {

    //         prefix[i] = ones;
    //         if (s[i] == '1')
    //         {
    //             ones++;
    //         }
    //     }

    //     for (int i = n - 1; i >= 0; i--)
    //     {
    //         suffix[i] = zeros;
    //         if (s[i] == '0')
    //         {
    //             zeros++;
    //         }
    //     }

    //     int start = 0;
    //     int end = n - 1;
    //     while (start < end && k > 0)
    //     {
    //         if (s[start] == '1' && s[end] == '0')
    //         {
    //             if (prefix[end] > suffix[start])
    //             {
    //                 s[end] = '1';
    //                 end--;
    //             }
    //             else
    //             {
    //                 s[start] = '0';
    //                 start++;
    //             }
    //             k--;
    //         }
    //         else
    //         {
    //             if (s[start] != '1')
    //             {
    //                 start++;
    //             }
    //             if (s[end] != '0')
    //             {
    //                 end--;
    //             }
    //         }
    //     }
    //     zeros = 0;
    //     for (int i = n - 1; i >= 0; i--)
    //     {
    //         if (s[i] == '0')
    //         {
    //             zeros++;
    //         }
    //         else
    //         {
    //             count += zeros;
    //         }
    //     }
    //     cout << count << endl;
    // }
    for (int i = 2; i < 100; i++)
    {
        cout << i << " " << i + 2 << " " << (i - 1) * (i + 2) << " " << i * (i + 1) << endl;
    }
}