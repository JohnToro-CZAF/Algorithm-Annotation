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

vi solve2 (int n, int m, string s, string t) {
    // Sol 2: Rabin-Karp
    // time compelxity: O(m) preprocessing time + O((n-m+1)*m) worst case
    // on average: it's better
    // idea: hash t -> value v
    // for each position start in s -> hash compute s[start:start+m] -> value v'
    // if v == v'; -> ok
    // however we can compute hash(s[start+1:start+m+1]) (hash_s+1) from s[start:start+m] (hash_s) in just O(1)
    // hash_s+1 = 26*(hash_s - s[start] * 26^(m-1)) + s[start+m+1]
    

}

void solve(){
    // Task: Given two strings s and t. Find the matched position (beginning of t in s)
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vi ans = solve1(n, m, s, t);
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}

