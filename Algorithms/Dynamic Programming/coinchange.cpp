/**
 * http://www.shafaetsplanet.com/?p=3638
 * Time = O(number of coin * make)
 * Memory = O(number of coin * make)
 */

#include <bits/stdc++.h>
#define ll long long
#define mod 100000007
using namespace std;
ll make, coin[] = {500, 499, 498, 497, 496, 495, 494, 493, 492, 491, 100, 5, 2, 1}; /// coin[]={1,5,10,25,50};
ll dp[6][7900];
ll call(ll i, ll amount)
{
    if (i >= 14)
    { /// All coins have been taken
        if (amount == 0)
            return 1;
        else
            return 0;
    }
    if (dp[i][amount] != -1)
        return dp[i][amount]; /// no need to calculate same state twice
    ll ret1 = 0, ret2 = 0;
    if (amount - coin[i] >= 0)
        ret1 = call(i, amount - coin[i]); /// try to take coin i
    ret2 = call(i + 1, amount);           /// dont take coin i
    return dp[i][amount] = (ret1 + ret2); /// storing and returning.
}
int main()
{
    memset(dp, -1, sizeof dp);
    while (cin >> make)
    {
        cout << call(0, make) << endl;
    }
    return 0;
}

/* less efficient
ll call(ll i,ll amount)
{
    if(i>=5)
    {
        if(amount==make) return 1;
        else return 0;
    }
    if(dp[i][amount]!=-1) return dp[i][amount];
    ll ret1=0,ret2=0;
    if(amount+coin[i]<=make) ret1=call(i,amount+coin[i]);
    ret2=call(i+1,amount);
    return dp[i][amount]=ret1+ret2;
}
main()
{
    while(cin>>make)
    {
        memset(dp,-1,sizeof dp);
        cout<<call(0,0)<<endl;
    }
}
*/
