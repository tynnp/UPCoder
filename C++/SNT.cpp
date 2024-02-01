#include <iostream>
using namespace std;

bool soNguyenTo(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

int main() {
    int n; cin >> n;
    if (soNguyenTo(n)) cout << "true";
    else cout << "false";
}