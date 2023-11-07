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
problem 8
the four adjacent digits in the 1000-digit number
that have the greatest product are 9*9*8*9 = 5832.
find the thirteen adjacent digits in the 1000-digit number
that have the greatest product. what is the value of this product?
*/

int main() {
    string s = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
    int n = 13;
    ll ans = 0;
    for (int i=0; i<s.size()-n+1; ++i) {
        ll tmp = 1;
        for (int j=0; j<n; ++j) tmp *= s[i+j]-'0';
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}

/*
the answer is 23514624000
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

