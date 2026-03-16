#include <iostream>
#include <vector>

using namespace std;

/*
    このファイルで学ぶこと:
      - 繰り返し二乗法による mod 累乗
      - フェルマーの小定理による逆元
      - factorial / inverse factorial を使った nCr mod MOD

    入力:
      n r base exponent

    出力:
      nCr(n, r) mod MOD
      base^exponent mod MOD

    注意:
      - ここでは MOD = 1,000,000,007 を使う
      - MOD が素数だから逆元を a^(MOD-2) で求められる
*/

using ll = long long;
constexpr ll MOD = 1'000'000'007LL;

ll mod_pow(ll base, ll exponent) {
    ll result = 1;
    base %= MOD;

    while (exponent > 0) {
        if (exponent & 1LL) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent >>= 1LL;
    }

    return result;
}

struct Combination {
    vector<ll> fact;
    vector<ll> inv_fact;

    explicit Combination(int n) : fact(n + 1, 1), inv_fact(n + 1, 1) {
        for (int i = 1; i <= n; ++i) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        inv_fact[n] = mod_pow(fact[n], MOD - 2);
        for (int i = n; i >= 1; --i) {
            inv_fact[i - 1] = (inv_fact[i] * i) % MOD;
        }
    }

    ll nCr(int n, int r) const {
        if (r < 0 || r > n) {
            return 0;
        }
        return (((fact[n] * inv_fact[r]) % MOD) * inv_fact[n - r]) % MOD;
    }
};

int main() {
    int n, r;
    ll base, exponent;
    cin >> n >> r >> base >> exponent;

    Combination comb(n);

    cout << "nCr_mod: " << comb.nCr(n, r) << '\n';
    cout << "pow_mod: " << mod_pow(base, exponent) << '\n';
    return 0;
}
