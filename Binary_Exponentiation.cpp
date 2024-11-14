#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M = 998244353;
const int N = 2e5 + 5;

class BinaryExponentiation
{

    int M;


    public:

    BinaryExponentiation(int mod)
    {
        M = mod;
    };

    int P(int a, int b)
    {

        int res = 1;

        while (b)
        {

            if (b & 1)
            {
                res = res * a % M;
            }

            b = b >> 1;
            a = a * a % M;
        }

        return res;
    }

    int MI(int a)
    {

        return P(a, M - 2);
    }
};

int32_t main()
{

    BinaryExponentiation BE(M);

    cout << BE.P(2,5);
}