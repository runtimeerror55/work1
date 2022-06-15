#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
        int t;
        cin >> t;
        while (t--)
        {
                int n, k;
                cin >> n >> k;
                int input[n];
                priority_queue<pair<int, int>> pq;
                priority_queue<pair<int, int>> pq1;

                for (int i = 0; i < n; i++)
                {
                        cin >> input[i];
                }
                int i = 0;
                int p = 1;
                while (i < n)
                {
                        int j = i;
                        while (j < n && input[i] == input[j])
                        {
                                j++;
                        }
                        pq.push({j - i, p});
                        pq1.push({j - i, p});
                        i = j - 1;
                        i++;
                        p++;
                }
                vector<int> v(n, 0);

                while (k > 0)
                {
                        pair<int, int> front1 = pq.top();
                        if (front1.first == 1)
                        {
                                break;
                        }
                        pq.pop();
                        if (pq.size() == 0)
                        {
                                front1.second = front1.second + k;
                                k = 0;
                        }
                        else
                        {
                                pair<int, int> front2 = pq.top();
                                if (front1.first % 2 == 0)
                                {
                                        int division = front1.first / 2;
                                        if (division == 1)
                                        {
                                                pq.push({1, front1.second});
                                                pq.push({1, front1.second});
                                                v[front1.second] = v[front1.second]++;
                                        }
                                        else if (division == 0)
                                        {
                                        }
                                        else
                                        {
                                                pq.push({division - 1, front1.second});
                                                pq.push({front1.first - division, front1.second});
                                                pq.push({1, front1.second});
                                                v[front1.second] = v[front1.second]++;
                                        }
                                }
                                else
                                {

                                        int division = ((front1.first) + 1) / 2;
                                        if (division == 1)
                                        {
                                        }
                                        else if (division == 0)
                                        {
                                        }
                                        else
                                        {
                                                pq.push({division - 1, front1.second});
                                                pq.push({division - 1, front1.second});
                                                pq.push({1, front1.second});
                                                v[front1.second] = v[front1.second]++;
                                        }
                                }
                        }
                }

                vector<int> v1;
                while (pq1.size() != 0)
                {
                        pair<int, int> front = pq1.top();
                        pq1.pop();
                        int value = front.first;
                        int k = v[front.second];
                        while (k > 0)
                        {
                                int division = value / (k + 1);
                                if (division == 2)
                                {
                                        if (value % 2 == 0)
                                        {
                                                v1.push_back((value / 2) - 1);
                                                v1.push_back(1);
                                                value = value / 2;
                                        }
                                        else
                                        {
                                                v1.push_back(((value + 1) / 2) - 1);
                                                v1.push_back(1);
                                                value = ((value + 1) / 2) - 1;
                                        }
                                }
                                else
                                {
                                        v1.push_back(division - 1);
                                        v1.push_back(1);
                                        value = value - division;
                                }
                                k--;
                        }
                }
                long long count = 0;

                for (int i = 0; i < v1.size(); i++)
                {
                        count = count + (v[i]) * (v[i] + 1) / 2;
                }
                cout << count << endl;
        }
}