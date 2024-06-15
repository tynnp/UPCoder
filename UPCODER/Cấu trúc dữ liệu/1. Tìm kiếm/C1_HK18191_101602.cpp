#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int x) {
    int res = -1, maxVal = INT_MAX;
    
    for (int i = 0; i < n; i++) 
        if (arr[i] == x)
            res = i;

    if (res == -1) {
    for (int i = 0; i < n; i++) 
        if (arr[i] > x)
            return i;
    }

    return res;
}

int main() {
    int n, x, ans;
    cin >> n >> x;
    
    int arr[n];
    for (int &i : arr) cin >> i;
    
    ans = search(arr, n, x);
    if (ans == -1) cout << "N\n-1";
    else cout << (arr[ans] == x ? "Y\n" : "N\n") << ans;
    return 0;
}