#include <bits/stdc++.h>
using namespace std;

void searchBinary(long long int start, long long int end, long long int input[], long long int candies, long long int &index)
{

    if (start <= end)
    {
        int mid = (end + start) / 2;
        if ((candies / input[mid - 1]) < 0)
        {
            index = mid;
            searchBinary(mid - 1, end, input, candies, index);
        }
        else
        {
            searchBinary(mid + 1, end, input, candies, index);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        long long int n, m, l;
        cin >> n >> m >> l;
        long long int temp = l;
        long long int input[n];
        long long int lastBuckets = l + n - 1;
        for (int i = 0; i < n; i++)
        {
            input[i] = temp;
            temp++;
        }

        long long int index = -1;
        searchBinary(1, n, input, m, index);
        if (index = -1)
        {
            index = n - 1;
        }
        else
        {
            lastBuckets = l + index;
            index--;
        }

        for (long long int i = index; i >= 0; i--)
        {
            long long int ratio = (m / lastBuckets);
            if ((m / lastBuckets) > 0)
            {

                m = m - (lastBuckets * ratio);
            }
            lastBuckets--;
        }
        cout << m << endl;
    }
}