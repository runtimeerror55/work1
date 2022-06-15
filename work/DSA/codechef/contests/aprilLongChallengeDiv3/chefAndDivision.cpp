#include <bits/stdc++.h>
using namespace std;

int helper(int input[], int n, int sum, bool isEven, int i, int temp, int k)
{

    int ans1 = 0;
    int ans2 = 0;

    if (i == n)
    {

        if (temp == 0)
        {
            return 1;
        }
        if (isEven)
        {
            if (sum % 2 != 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if (sum % 2 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }

    ans1 = helper(input, n, sum + input[i], isEven, i + 1, temp, 1);
    if (temp == 0)
    {
        if (sum == 0)
        {
            if (k == 0)
            {
                if (input[i] % 2 == 0)
                {
                    ans2 = helper(input, n, sum, true, i + 1, 0, 0);
                }
                else
                {
                    ans2 = helper(input, n, sum, false, i + 1, 0, 0);
                }
            }
            else
            {
                if (isEven)
                {
                    if (input[i] % 2 != 0)
                    {
                        ans2 = helper(input, n, sum, false, i + 1, 0, 0);
                    }
                    else
                    {
                        ans2 = 0;
                    }
                }
                else
                {
                    if (input[i] % 2 == 0)
                    {
                        ans2 = ans2 = helper(input, n, sum, true, i + 1, 0, 0);
                    }
                    else
                    {
                        ans2 = 0;
                    }
                }
            }
        }
        else
        {
            if (sum % 2 == 0)
            {
                sum = input[i];

                ans2 = helper(input, n, sum, true, i + 1, 1, k);
            }
            else
            {
                sum = input[i];
                ans2 = helper(input, n, sum, false, i + 1, 1, k);
            }
        }
    }
    else
    {

        if (isEven)
        {
            if (sum % 2 != 0)
            {
                sum = input[i];
                ans2 = helper(input, n, sum, false, i + 1, temp, k);
            }
            else
            {
                ans2 = 0;
            }
        }
        else
        {
            if (sum % 2 == 0)
            {
                sum = input[i];
                ans2 = helper(input, n, sum, true, i + 1, temp, k);
            }
            else
            {
                ans2 = 0;
            }
        }
    }
    return ans1 + ans2;
}

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

        cout << helper(input, n, 0, false, 0, 0, 0) << endl;
    }
}