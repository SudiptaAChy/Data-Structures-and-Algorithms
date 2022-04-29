/**
 * https://shakilcompetitiveprogramming.blogspot.com/2015/09/digit-dp.html
 * https://lightoj.com/problem/how-many-zeroes
 * https://www.youtube.com/watch?v=heUFId6Qd1A&t=1532s
 *
 * Application: work on digit within a range.
 *
 * steps:
 *      - choose a rage of digit for current position and put a constraints on digits if the number is not small than R
 *      - for each digit within range check if the current value is small or can be placed 0 in that position
 *      - go to next index position and increament the value by 1 if the asked condition met
 *
 * Time = O(10*len_of_total_position*value*isSmall*isStart)
 * Memory = O(len_of_total_position*value*isSmall*isStart)
 */

#include <bits/stdc++.h>
#define pb push_back
#define sf scanf
#define pf printf
using namespace std;
#define ll long long

string s;
ll n, dp[15][500][2][2];

ll DigitDP(ll pos, ll value, bool isSmall, bool isStart)
{
    if (pos >= n)
        return value;

    ll &ret = dp[pos][value][isSmall][isStart];
    if (ret != -1)
        return ret;

    ret = 0LL;
    ll lo = 0, hi = 9; // choose a range of digit
    if (!isSmall)
        hi = s[pos] - '0'; // if current number is not small from 'R' then we have to put constraint of current digit of current number
    for (ll i = lo; i <= hi; i++)
    {
        bool small = isSmall | (i < hi);                                    // if current digit is smaller then Maximum digit or the current number is already small
        bool start = isStart | (i > 0);                                     // if current digit is not 0 or current position is not already a starting position
        ret += DigitDP(pos + 1, value + (isStart && i == 0), small, start); // go to next index position and add 1 to value if current digit hold some property told in question (i.e. in this problem it's said digit have to be 0)
    }

    return ret;
}

ll cal(ll x)
{
    if (x < 0)
        return 0;
    if (x < 10)
        return 1;
    s = to_string(x);
    n = s.size();
    memset(dp, -1, sizeof dp);
    return DigitDP(0, 0, 0, 0) + 1; // 1 is added in advance for value 0 And we are counting total number of permutations starting from value 1
}

void slv()
{
    ll a, b;
    sf("%lld %lld", &a, &b);
    pf("%lld\n", cal(b) - cal(a - 1));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    // t = 1;
    for (int cas = 1; cas <= t; cas++)
    {
        printf("Case %d: ", cas);
        // cout << "Case " << cas << ": ";
        slv();
    }
    return 0;
}
