#include <bits/stdc++.h>
using namespace std;

bool check(string &str, int mid, char a)
{

    int n = str.size();

    int previous = -1, i;

    for (i = 0; i < n; ++i)
    {

        if (str[i] == a)
        {

            if (i - previous > mid)
            {
                return false;
            }
            previous = i;
        }
    }

    if (i - previous > mid)
        return false;
    else
        return true;
}

bool possible(string &str, int mid)
{

    for (int i = 0; i < 26; ++i)
    {

        if (check(str, mid, i + 'a'))
            return true;
    }

    return false;
}

int findMinLength(string &str)
{

    int low = 1, high = str.length();

    while (low <= high)
    {

        int mid = (low + high) / 2;

        if (possible(str, mid))
            high = mid - 1;
        else
            low = mid + 1;
    }

    return high + 1;
}

int main()
{

    string str;
    cin >> str;

   
        cout << findMinLength(str);
    return 0;
}