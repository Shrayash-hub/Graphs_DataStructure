class Fancy {
public:
    using ll = long long;
    const ll MOD = 1e9+7;
    
    vector<ll> v;
    ll mul = 1, add = 0;

    ll modPow(ll a, ll b){
        ll r = 1;
        while(b){
            if(b&1) r = (r*a)%MOD;
            a = (a*a) % MOD;
            b >>= 1;
        }
        return r;
    }

    Fancy() {

    }

    void append(int val) {
        ll inv = modPow(mul, MOD-2);
        ll x = ((val-add)%MOD+MOD)%MOD;
        x = (x*inv)%MOD;
        v.push_back(x);
    }

    void addAll(int inc) {
        add = (add+inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul*m) % MOD;
        add = (add*m) % MOD;
    }

    int getIndex(int idx) {
        if(idx >= v.size()) return -1;
        return (v[idx] * mul % MOD + add) % MOD;
    }
};