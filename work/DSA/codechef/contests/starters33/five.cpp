#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string temp, string a)
{
    if (temp.length() == 0 && a.length() != 0)
    {
        return false;
    }
    else if (temp.length() == 0 && a.length() == 0)
    {
        return true;
    }
    else if (a.length() == 0)
    {
        return true;
    }

    int index = -1;
    for (int i = 0; i < temp.length(); i++)
    {
        if (a[0] == temp[i])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        return false;
    }
    bool subAnswer = isSubsequence(temp.substr(index + 1), a.substr(1));
    if (subAnswer)
    {
        return subAnswer;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        string a;
        cin >> a;
        string temp;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '?')
            {
                temp.push_back(s[i]);
            }
        }

        bool ans = isSubsequence(temp, a);
        if (ans)
        {
            cout << -1 << endl;
        }
        else
        {
            int j = 0;
            string temp = "";

            for (int i = 0; i < n; i++)
            {
                if (s[i] == a[j])
                {
                    temp.push_back(s[i]);
                }
                else
                {
                    if (a[j] == 'e')
                    {
                        temp.push_back('e' - 1);
                    }
                    else
                    {
                        temp.push_back(a[j] + 1);
                    }
                }
                j++;
                if (j >= m)
                {
                    j = 0;
                }
            }
            cout << temp << endl;
        }
    }
}