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

vi solve1 (int n, int m, string s, string t) {
    //Sol 1:  naive. for beginning position in s, check if t is match, by traversing through string t.
    // Time: O((n-m+1)*m);
    // Worst case: if m = n/2 -> O(n^2)
    vi ans;
    for (int i = 0; i+m-1 < n; i++) {
        for (int j = 0; j < m; j++){
            if (s[i+j] == t[j]) {
                if (j == m-1) {
                    ans.push_back(i);
                }
                continue;
            } else {
                break;
            }
        }
    }
    return ans;
}


int add(int a, int b) {
    return (a+b)%MOD;
}

int mul(int a, int b) {
    ll ans = (ll) a*b;
    return ans%MOD;
}

int sub(int a, int b) {
    return (a + MOD - b)%MOD;
}

int expo_mod (int a, int b){
    int c = 0;
    int d = 1;
    for (int i = 31; i >= 0; i--) {
        c = 2*c;
        d = mul(d, d);
        if ((b >> i)&1) {
            c += 1;
            d = mul(d, a);
        }
    }
    return d;
}

vi solve2 (int n, int m, string s, string t) {
    // Sol 2: Rabin-Karp
    // time compelxity: O(m) preprocessing time + O((n-m+1)*m) worst case
    // on average: it's better
    // idea: hash t -> value v
    // for each position start in s -> hash compute s[start:start+m] -> value v'
    // if v == v'; -> ok
    // however we can compute hash(s[start+1:start+m+1]) (hash_s+1) from s[start:start+m] (hash_s) in just O(1)
    // hash_s+1 = 26*(hash_s - s[start] * 26^(m-1)) + s[start+m+1]
    // but whenever the hash values are equal together -> we must compare two strings again in O(m)
    // but this rarelly happen. so O(m) prepocess.
    // and O(n-m+1 + cm): c is means the number of times we have to recheck. In reality, c approachs constant
    // So O(n) in searching and confirming
    // Overall time complexity is O(m + n)
    vi ans;
    int hash_t = 0;
    int hash_s_window_m = 0;
    for (int i = 0; i < m; i++) {
        hash_t = add(mul(expo_mod(26, i), hash_t), (t[i] - 'a'));
        hash_s_window_m = add(mul(expo_mod(26, i), hash_s_window_m), (s[i] - 'a'));
    }
    // cout << hash_t << " " << hash_s_window_m << endl;
    for (int i = 0; i + m - 1 < n; i++) {
        // cout << hash_s_window_m << endl;
        if (hash_s_window_m == hash_t) {
            // check if match or not
            for (int j = 0; j < m; j++) {
                if (s[i+j] == t[j]) {
                    if (j == m-1) {
                        ans.push_back(i);
                    }
                    continue;
                } else {
                    break;
                }
            }
        } else {
            //  if not match then calculate the next window size m
            if (i+m < n) {
                int tmp = mul(expo_mod(26, m-1), (s[i] - 'a'));
                hash_s_window_m = add(mul(26, sub(hash_s_window_m, tmp)), s[i+m] - 'a'); // minus the first value
            }
        }
    }
    return ans;
}

// String matching with finite automata
vi solve3 (int n, int m, string s, string t) {
    // precompute the transistion[i][char] which is defined within string t first. Is to find the longest
    // prefix of t such that it is suffix of (t[0:i] + char). (this prefix can not be longger t[0:i])
    auto check = [&] (string prefix, string target) {
        int n1 = prefix.size();
        int m1 = target.size();
        // check if this string prefix is the suffix of target or not?
        for (int i = n1-1; i >= 0; i--) {
            if (prefix[i] != target[m1 - n1 + i]) {
                return false;
            }
        }
        return true;
    };
    vector<vector<int>> trans(m, vi(26, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 26; j++) {
            int k = i+1; // traverse k backward to find the prefix that match with suffix (including itself)
            while (k >= 0 && !check(t.substr(0, k), t.substr(0, i) + char(j + 'a'))) {
                k--;
            }
            if (k >= 0) {
                trans[i][j] = k;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 26; j++) {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }
    vi ans;
    int q = 0; // current maximum matched prefix
    for (int i = 0; i < n; i++) {
        q = trans[q][s[i] - 'a'];
        if (q == m) {
            ans.push_back(i-m+1);
            q = 0;
        }
    }
    return ans;
}

void solve(){
    // Task: Given two strings s and t. Find the matched position (beginning of t in s)
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vi ans = solve3(n, m, s, t);
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c = 1;
    // cin >> c;
    while(c--){
        solve();
    }
}

