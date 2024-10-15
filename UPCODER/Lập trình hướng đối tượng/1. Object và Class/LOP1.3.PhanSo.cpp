#include <iostream>
#include <algorithm>
using namespace std;

class PhanSo {
private:
    int tuSo, mauSo;

public:
    void nhap();                    // thao tác nhập
    void xuat();                    // thao tác xuất

    int getTuSo();                  // lấy tử số
    int getMauSo();                 // lấy mẫu số

    void setTuSo(int tuSo);         // gán giá trị cho tử số
    void setMauSo(int mauSo);       // gán giá trị cho mẫu số

    PhanSo nghichDao();             // nghịch đảo
    PhanSo rutGon();                // rút gọn

    PhanSo cong(PhanSo other);      // cộng với phân số khác
    PhanSo tru(PhanSo other);       // trừ với phân số khác
    PhanSo nhan(PhanSo other);      // nhân với phân số khác
    PhanSo chia(PhanSo other);      // chia với phân số khác

    PhanSo();                       // khởi tạo mặc định
    PhanSo(int tuSo, int mauSo);    // khởi tạo với tử và mẫu
    PhanSo(int soNguyen);           // khởi tạo từ giá trị nguyên cho trước
    PhanSo(const PhanSo &other);    // khởi tạo từ một phân số khác
    ~PhanSo();                      // hủy
};

int main() {
    int a, b;
    cin >> a >> b;
    
    PhanSo p(a, b);
    p.xuat();
    
    cout << p.getTuSo() << endl;
    cout << p.getMauSo() << endl;
    
    (p.nghichDao()).xuat();
    (p.rutGon()).xuat();
    
    (p.cong(p.nghichDao())).xuat();
    return 0;
}

void PhanSo::nhap() {
    cin >> tuSo >> mauSo;
}

void PhanSo::xuat() {
    cout << tuSo << '/' << mauSo << endl;
}

int PhanSo::getTuSo() {
    return tuSo;
}

int PhanSo::getMauSo() {
    return mauSo;
}

void PhanSo::setTuSo(int tuSo) {
    this->tuSo = tuSo;
}

void PhanSo::setMauSo(int mauSo) {
    this->mauSo = mauSo;
}

PhanSo PhanSo::nghichDao() {
    PhanSo res; 
    res.tuSo = mauSo;
    res.mauSo = tuSo;
    return res;
}

PhanSo PhanSo::rutGon() {
    int ucln = __gcd(tuSo, mauSo);
    PhanSo res;
    res.tuSo = tuSo / ucln;
    res.mauSo = mauSo / ucln;
    return res;
}

PhanSo PhanSo::cong(PhanSo other) {
    PhanSo res;
    res.tuSo = tuSo*other.mauSo + mauSo*other.tuSo;
    res.mauSo = mauSo * other.mauSo;
    return res.rutGon();
}

PhanSo PhanSo::tru(PhanSo other) {
    PhanSo res;
    res.tuSo = tuSo*other.mauSo - mauSo*other.tuSo;
    res.mauSo = mauSo * other.mauSo;
    return res.rutGon();
}

PhanSo PhanSo::nhan(PhanSo other) {
    PhanSo res;
    res.tuSo = tuSo * other.tuSo;
    res.mauSo = mauSo * other.mauSo;
    return res;
}

PhanSo PhanSo::chia(PhanSo other) {
    PhanSo res;
    res.tuSo = tuSo * other.mauSo;
    res.mauSo = mauSo * other.tuSo;
    return res;
}

PhanSo::PhanSo() {
    tuSo = 0;
    mauSo = 1;
}

PhanSo::PhanSo(int tuSo, int mauSo) {
    this->tuSo = tuSo;
    this->mauSo = mauSo;
}

PhanSo::PhanSo(int soNguyen) {
    this->tuSo = soNguyen;
    this->mauSo = 1;
}

PhanSo::PhanSo(const PhanSo &other) {
    tuSo = other.tuSo;
    mauSo = other.mauSo;
}

PhanSo::~PhanSo() {
    // không cần định nghĩa
}