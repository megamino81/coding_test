// 수퍼바이러스

#include <cstdio>

using ll = long long;

ll K,P,N,mod=1000000007;

ll sol(ll n) 
{
    if (n == 1)
        return P;

    ll ret = sol(n / 2);
    ret = (ret * ret) % mod;

    if (n % 2)
        ret = (ret * P) % mod;

    return ret;
}

int main(int argc, char **argv)
{
    scanf("%lld%lld%lld",&K,&P,&N);

    printf("%lld", (sol(N * 10) * K) % mod);
}