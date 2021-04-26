/*
https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/D
*/

#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;
typedef long double ld;

#define FOR(i,a,b) for (int i=(a),_b=(b);i<_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) ll((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define vll vector<ll>
#define pll pair<ll,ll>
#define x first
#define y second

#define endl '\n'
#define int ll
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);


const int INF = 0x3f3f3f3f;//1e9+*
const ll INFLL = 0x3f3f3f3f3f3f3f3f;//1e18+*
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;



//General Purpose vars
string str;
ll n,m,k,t,a,b,sc;
ll arr[3*NMAX];

bool allIn(vll& v)
{
    REP(i,4) if(v[i]==0)return false;
    return true;
}
void solve()
{

    vector<pll> vec;
    REP(i,4)
    {
        cin>>n;
        REP(j,n)
        {
            cin>>t;
            vec.push_back({t,i});
        }
    }
    sort(all(vec));

    vll freq(4,0);
    int best = INF;
    pll bestRng;
    int j=0;
    REP(i,vec.size())
    {
        freq[vec[i].y]++;

        while(allIn(freq))
        {
            if(vec[i].x-vec[j].x<best)
            {
                best = vec[i].x-vec[j].x;
                bestRng = {j,i};
            }
            freq[vec[j].y]--;
            j++;
        }
    }
    vll ans(4);
    FOR(i,bestRng.x,bestRng.y+1)
    {
        ans[vec[i].y] = vec[i].x;
    }

    REP(i,4)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;


}


int32_t main()
{
    fastIO;
    ll T = 1;
#ifdef LOCAL
    freopenI;
    cin>>T;
#endif

    sc = 1;
    while(T--)
    {
        solve();
        sc++;
    }

    return 0;
}
