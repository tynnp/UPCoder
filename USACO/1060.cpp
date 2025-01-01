#include <iostream>
using namespace std;

int n, ans;
int p[101];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> p[i];

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int k = j - i + 1;
            int s = 0;

            for (int x = i; x <= j; x++)
                s += p[x];

            if (s % k != 0)
                continue;
            
            for (int x = i; x <= j; x++) {
                if (p[x] == s/k) {
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans;
    return 0;
}