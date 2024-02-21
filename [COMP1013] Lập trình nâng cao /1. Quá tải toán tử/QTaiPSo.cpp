#include <iostream>
#include <algorithm>
using namespace std;

struct PhanSo {
    int tu;
    int mau;

    friend istream& operator >> (istream& in, PhanSo& p);
    friend ostream& operator << (ostream& out, PhanSo p);
    PhanSo operator + (PhanSo p);
    bool operator == (PhanSo p);
    bool operator != (PhanSo p);
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    PhanSo a, b;
    cin >> a >> b;
    cout << a + b;
    return 0;
}

istream& operator >> (istream& in, PhanSo& p) {
    in >> p.tu >> p.mau;
    return in;
}

ostream& operator << (ostream& out, PhanSo p) {
    int ucln = __gcd(p.tu, p.mau);
    p.tu /= ucln;
    p.mau /= ucln;
    out << p.tu << "/" << p.mau;
    return out;
}

PhanSo PhanSo::operator + (PhanSo p) {
    PhanSo res;
    res.tu = this->tu*p.mau + p.tu*this->mau;
    res.mau = this->mau * p.mau;
    return res;
}

bool PhanSo::operator == (PhanSo p) {
    return this->tu*p.mau == p.tu*this->mau;
}

bool PhanSo::operator != (PhanSo p) {
    return !(*this == p);
}