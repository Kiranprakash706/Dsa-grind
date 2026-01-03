class Solution {
public:
    #define ll long long int
    int mod = 1e9+7;
    int numOfWays(int n) {
        ll a = 6, b = 6;
        for(int i = 2 ; i<=n; i++)
        {
            ll na = (3*a+2*b) % mod;
            ll nb = (2*a+2*b) % mod;
            a = na; b = nb;
        }
        return (a+b)%mod;
    }
};