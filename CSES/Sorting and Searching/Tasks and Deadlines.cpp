#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, ans, sum;
pair<int, int> a[MAXN];

signed main() {
    fastIO;
    cin >> n;
    
    for (int i = 0; i < n; i++) 
        cin >> a[i].first >> a[i].second;
    
    sort(a, a + n);
    
    for (int i = 0; i < n; i++) {
        sum += a[i].first;
        ans += a[i].second - sum;
    }
    
    cout << ans;
    return 0;
}