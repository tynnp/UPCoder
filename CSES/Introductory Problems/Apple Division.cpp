#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 20 + 5;
const int MOD = 1e9 + 7;

int n, a[MAXN];

int solve(int idx, int sumA, int sumB) {
    if (idx == n)
        return abs(sumA - sumB);
    
    int x = solve(idx + 1, sumA + a[idx], sumB);
    int y = solve(idx + 1, sumA, sumB + a[idx]);

    return min(x, y);
}

signed main() {
    fastIO;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    cout << solve(0, 0, 0);
    return 0;
}