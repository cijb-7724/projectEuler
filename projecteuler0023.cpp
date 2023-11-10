#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
#include <string>
#include <cstdlib>
#include <iomanip> //出力桁数
#include <queue> // queue
#include <stack> // stack
#include <deque> // deque
#include <sstream> //基数変換
#include <bitset> //2進数に変換


using namespace std;

#define pi 3.14159265358979323846
#define yes "Yes"
#define no "No"
#define yesno(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define alphabet "abcdefghijklmnopqrstuvwxyz"
#define Alpahbet "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, l, r) for (int i = l; i < r; ++i)
#define rrep(i, r, l) for (int i = r; i >= l; --i)
#define tp() cout << "here~~" << endl
#define el '\n'

const int dx[4] = {1, 0, -1, 0};//グリッド上の探索
const int dy[4] = {0, 1, 0, -1};//上下左右移動方向
const int dxdi[4] = {1, 1, -1, -1};//グリッド上の探索
const int dydi[4] = {1, -1, 1, -1};//斜め移動方向


//型エイリアス vector<set<pair<tuple : bool<char<string<int<ll<ull
using ll = long long;
using ull = unsigned long long;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vi = vector<int>;
using vll = vector<long long>;
using si = set<int>;
using sll = set<ll>;
using msi = multiset<int>;
using msll = multiset<ll>;
using mss = multiset<string>;
using pii = pair<int, int>;
using pill = pair<int, ll>;
using plli = pair<ll, int>;
using pllll = pair<long long, long long>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvs = vector<vector<string>>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vsi = vector<set<int>>;
using vpii = vector<pair<int, int>>;
using vpllll = vector<pair<long long, long long>>;
using spii = set<pair<int, int>>;

using stst = stringstream;

// [ノード][(接続ノード, 重み)]
using Graph = vector<vector<int>>;//重みなしグラフ構造
using GraphWeight = vector<vector<pair<int,int>>>;//重みありグラフ構造
using GraphCh = vector<vector<char>>;//charGridの探索
using GraphIn = vector<vector<int>>;//charGridの探索
using GridPos = pair<int, int>;//グリッド上の位置・座標

//関数定義群
vector<pair<long long, long long> > prime_factorize(long long); //素因数分解
bool contain_string(string, string); //部分文字列の一致判定
ll gcd(ll, ll); //最大公約数
ll lcm(ll, ll); //最小公倍数
ll powll(ll, ll); //llの累乗
bool in_table(int, int); //添え字が１次元配列内か判定
bool in_table(int, int, int, int); //添え字が２次元配列内か判定
ll minll(ll, ll);
ll maxll(ll, ll);
ll modPow(ll, ll, ll);
ll modInv(ll, ll);



//Union Find
struct UnionFind {//頂点数N, クエリ数Q -> O(Q log N)
    vi p; //自分の親を管理
    vi r;
    UnionFind(int n) { //コンストラクタ インスタンス生成時に初期化
        p.resize(n);
        rep(i, n) {
            p[i] = i;
        }
        r.resize(n, 1);
    }
    int find(int x) { // 均し計算量O(log N)
        if (p[x] == x) return x;
        else return p[x] = find(p[x]);//パス圧縮　自分の親を代表元に張りなおす
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (r[x] > r[y]) {// Union by rank
            swap(x, y);
        }
        if (r[x] == r[y]) {
            ++r[y];
        }
        p[x] = y;
    }
};




// vb seen;
// void dfs (const Graph &G, int v) {
//     seen[v] = true;
//     //cout << "v = " << v+1 << el;
//     for (auto nextv : G[v]) {
//         if (seen[nextv] == true) {
//             continue;
//         }
//         dfs(G, nextv);
//     }
// }

// vi dist;
// int bfs (const Graph &G, int v) {
//     queue<int> que;
//     dist[v] = 0;
//     que.push(v);
//     while(!que.empty()) {
//         v = que.front();
//         que.pop();
//         // cout << "v = " << v+1 << el;
//         for(int nv: G[v]) {
//             if (dist[nv] == -1) {
//                 dist[nv] = dist[v] + 1;
//                 que.push(nv);
//             } else {
//                 //tuiki
//                 continue;
//             }
//         }
//     }
//     return 0;
// }

/*
-----
---------------
-------------------------
---------------
-----
*/



/*
problem 23
a perfect number is a number for which the sum of its proper divisors is exactoly equal to the number.
for example, the sum of the proper divisors of 28 would be 1+...+14=28, 
which means that 28 is a perfect number.

a number n is called dificient if the sum of its proper divisor is less than n 
and is called abundant if this sum exceeds n.

as 12 is the smallest abundant number, 1+2+3+4+6=16, the smallest number
that can be written as the sum of two abundant numbers is 24.
by mathematical analysis, it can be shown that all integers greater than 28123
can by written as the sum of two abundant numbers.
however, this upper limit cannot be reduced any further by analysis
even though it is known that the greatest number that cannot be expressed as the sum of
two abundant numbers is less than this limit.

find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

int judgeAbundant(int n) {
    int sum = 1;
    for (int i=2; i<=sqrt(n); ++i) if (n%i == 0) sum += i+n/i;
    if ((int)sqrt(n)*(int)sqrt(n) == n) sum -= sqrt(n);
    return sum > n ? true : false;
}
int main() {
    ll mx = 28123, ans = 0;
    vi abundants, abundant2Sum(mx*2, 0);
    for (int i=1; i<=mx; ++i) if (judgeAbundant(i)) abundants.push_back(i);
    for (int i=0; i<abundants.size(); ++i) for (int j=i; j<abundants.size(); ++j) 
        abundant2Sum[abundants[i] + abundants[j]] = 1;
    for (int i=1; i<=mx; ++i) if (1-abundant2Sum[i]) ans += i;
    cout << ans << endl;
}

/*
the answer is 4179871
*/
















//関数群---------------------------------------------------

 
// 素因数分解
// 460 = 2^2 x 5 x 23 の場合
// 返り値は {{2, 2}, {5, 1}, {23, 1}}
vector<pair<long long, long long> > prime_factorize(long long N) {
    // 答えを表す可変長配列
    vector<pair<long long, long long> > res;

    // √N まで試し割っていく
    for (long long p = 2; p * p <= N; ++p) {
        // N が p で割り切れないならばスキップ
        if (N % p != 0) {
            continue;
        }

        // N の素因数 p に対する指数を求める
        int e = 0;
        while (N % p == 0) {
            // 指数を 1 増やす
            ++e;

            // N を p で割る
            N /= p;
        }

        // 答えに追加
        res.emplace_back(p, e);
    }

    // 素数が最後に残ることがありうる
    if (N != 1) {
        res.emplace_back(N, 1);
    }
    return res;
}

//文字列sにtが含まれているかを判定する
// s.size() >= t.size()に注意
bool contain_string(string s, string t) {
    if ((int)s.size() < (int)t.size()) {
        return false;
    }
    int cnt;
    for (int i=0;i<(int)s.size(); i++) {
        cnt = 0;
        for (int j = 0; j<(int)t.size(); j++) {
            if (i+j <(int)s.size() && s[i+j] == t[j]) {
                cnt ++;
            }
        }
        if (cnt == (int)t.size()) {
            return true;
        }
    }
    return false;
}

ll gcd(ll a, ll b) {
    if (a < b) {
        ll tmp = a;
        a = b;
        b = tmp;
    }
    while(b) {
        ll aa = b;
        ll bb = a%b;
        a = aa;
        b = bb;
    }
    return a;
}
ll lcm(ll a, ll b) {
    return a*b/gcd(a, b);
}
ll powll(ll a, ll b) {
    ll k = 1;
    rep(i, b) {
        k *= a;
    }
    return k;
}
ll modPow(ll a, ll n, ll mod) {
    ll res = 1;
    while(n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
ll modInv(ll a, ll mod) {
    return modPow(a, mod-2, mod);
}
bool in_table(int i, int h) {
    if (i<0 || i>=h) {
        return false;
    } else {
        return true;
    }
}
bool in_table(int i, int j, int h, int w) {
    if (i<0 || i>=h || j<0 || j>=w) {
        return false;
    }
    return true;
}

