#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#define ll long long

using namespace std;

int n;
ll k;
vector<string> v1;
vector<int> v2;
vector<int> v3;
long dp[40000][100];

int get_remainder(int num, string str2)
{
    for (int i = 0; i < str2.length(); i++)
    {
        num *= 10;
        num += str2[i] - '0';
        num %= k;
    }
    return num;
}
ll get_gcd(ll a, ll b)
{
    while (b > 0)
    {
        ll c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        v1.push_back(str);
    }
    cin >> k;

    for (int i = 0; i < n; i++)
    {
        int temp = get_remainder(0, v1[i]);
        v2.push_back(temp);
        dp[1 << i][temp]++;
    }

    v3.push_back(1 % k);
    for (int i = 0; i < 50; i++)
        v3.push_back(10 % k * v3[i] % k);

    for (int mask = 1; mask < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
        {
            int bit = (1 << i);
            if ((mask & bit) > 0)
                continue;

            int next_bit = (mask | bit);

            for (int j = 0; j < k; j++)
            {
                int next_r = ((j % k) * (v3[v1[i].length()] % k) % k + v2[i]) % k;
                if (dp[mask][j] > 0)
                    dp[next_bit][next_r] += dp[mask][j];
            }
        }
    }

    ll molecule = dp[(1 << n) - 1][0];
    ll denominator = 1;
    for (int i = 2; i <= n; i++)
        denominator *= i;
    ll gcd = get_gcd(denominator, molecule);
    cout << molecule / gcd << '/' << denominator / gcd;

    return 0;
}
