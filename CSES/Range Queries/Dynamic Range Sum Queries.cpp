// Segement Tree
// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

// using namespace std;
// using namespace __gnu_pbds;

// #define endl '\n'
// #define int long long
// #define elif else if 
// #define inp freopen("file.inp", "r", stdin)
// #define out freopen("file.out", "w", stdout)
// #define TIME 1.0*clock()/CLOCKS_PER_SEC
// #define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
// #define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

// const int MAXN = 1e6 + 5;
// const int MOD = 1e9 + 7;

// int n, q;
// int a[MAXN];
// int st[4 * MAXN];

// void build(int id, int l, int r);
// void update(int id, int l, int r, int i, int val);
// int get(int id, int l, int r, int u, int v);

// signed main() {
//     fastIO;
//     cin >> n >> q;

// 	for (int i = 1; i <= n; i++)
// 		cin >> a[i];
// 	build(1, 1, n);

// 	while (q--) {
// 		int t, x, y;
// 		cin >> t >> x >> y;

// 		switch (t) {
// 			case 1: {
// 				update(1, 1, n, x, y);
// 				break;
// 			}

// 			case 2: {
// 				cout << get(1, 1, n, x, y) << endl;
// 				break;
// 			}
// 		}
// 	}

//     return 0;
// }

// void build(int id, int l, int r) {
// 	if (l == r) {
// 		st[id] = a[l];
// 		return;
// 	}

// 	int mid = (l + r) >> 1;
// 	build(2*id, l, mid);
// 	build(2*id + 1, mid+1, r);

// 	st[id] = st[2*id] + st[2*id + 1];
// }

// void update(int id, int l, int r, int i, int val) {
// 	if (l > i || r < i) 
// 		return;

// 	if (l == r) {
// 		st[id] = val;
// 		return;
// 	}

// 	int mid = (l + r) >> 1;
// 	update(2*id, l, mid, i, val);
// 	update(2*id + 1, mid + 1, r, i, val);

// 	st[id] = st[2*id] + st[2*id + 1];
// }

// int get(int id, int l, int r, int u, int v) {
// 	if (l > v || r < u)
// 		return 0;

// 	if (l >= u && r <= v) 
// 		return st[id];

// 	int mid = (l + r) >> 1;
// 	int a = get(2*id, l, mid, u, v);
// 	int b = get(2*id + 1, mid+1, r, u, v);

// 	return a + b;
// }


// Fenwick Tree
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, q;
int a[MAXN], BIT[MAXN];

void update(int pos, int k) {
    int idx = pos;
    
    while (idx <= n) {
        BIT[idx] += k;
        idx += idx & (-idx);
    }
}

int get(int pos) {
    int idx = pos, ans = 0;
    
    while (idx > 0) {
        ans += BIT[idx];
        idx -= idx & (-idx);
    }
    
    return ans;
}

signed main() {
    fastIO;
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i]);
    }
    
    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        
        if (t == 1) {
            update(u, v - a[u]);
            a[u] = v;
        } else 
            cout << get(v) - get(u-1) << endl;
    }
    
    return 0;
}