#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define forn(i,n) for(int i=0;i<n;++i)
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define foreach(a) for(auto it = a.begin(); it != a.end(); it++)
#define mem(a,b) memset(a, (b), sizeof(a))
template<typename T>
inline T cei(T x, T y){T t = (x+y-1)/y;return t;}

template<typename T>
inline T power(T base, T powerRaised){if (powerRaised != 0) return (base*power(base, powerRaised-1)); else return 1;}

template<typename T>
inline T gcd(T x, T y){ T ans = x; T temp = y; while(ans != temp){if(ans < temp){ temp -= ans;} else{ans -= temp;}} return ans;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;

ll mod_exponentiation(int a, int b, int n) {
    int c = 0;
    ll d = 1;
    // let c is traversing from msb -> lsb, in the end: c should equal to b
    // b_k, b_(k-1), ... , b_0 be binary representation of b
    for (int i = 31; i >= 0; i--){
        // seudo assume that 1 0 0 0 0
        c *= 2; // ^2 everytime
        d = (d*d) % n; // ^2 everytime
        if ((b >> i) & 1) {
            // if there is 1 one along the way traversing from msb to lsb
            // add that to c: 1 0 0 0 1
            // and multiply a, since a^c = a^(2^t + 1) = d * a^1
            c = c+1;
            d = (d*a) % n;
        }
    }
    return d;
}

void solve(){
    // Question: how to compute the constant 10^(m-1) fast in only O(lg m)
    // A frequently occurring operation in number-theoretic computations is raising one number 
    // to a power modulo another number, also known as modular exponentia- tion. More precisely, 
    // we would like an efficient way to compute ab mod n, where a and b are nonnegative integers and n is a positive integer.
    cout << mod_exponentiation(2, 4, 7) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c = 1;
    while(c--){
        solve();
    }
}

