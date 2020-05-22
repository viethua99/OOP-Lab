
#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;



class SanPham{
private:
    long _maHang;
    string _tenHang;
    int _giaTien;
    int _soLuong;
public:
    void nhapSanPham(){
        cout << "Nhap ma hang: ";
        cin >> _maHang;
        cout << "Nhap ten hang: ";
        cin.ignore();
        getline(cin,_tenHang);
        cout << "Nhap gia tien: ";
        cin >> _giaTien;
        cout << "Nhap so luong: ";
        cin >> _soLuong;
    }
    
    friend istream& operator >> (istream& is , SanPham& sanPham){
        sanPham.nhapSanPham();
        return is;
    }
    
    
    void xuatSanPham(){
        cout << _maHang << setw(26) << _tenHang << setw(20) << _giaTien << setw(20) << _soLuong << endl;
    }
    
    
    friend ostream& operator << (ostream& os,SanPham& sanPham){
        sanPham.xuatSanPham();
        return os;
    }
};


class MayTinhTien{
private:
    vector<SanPham> danhSachSanPham;
public:
    void nhapDuLieuHangHoa(){
        int n;
        cout << "Nhap so luong hang hoa:";
        cin >> n;
        
        danhSachSanPham.resize(n);
        for(int i = 0 ; i < n ; i++){
            cout << "Nhap san pham thu " << i+1 << endl;
            SanPham sanPham;
            cin >> sanPham;
            
            danhSachSanPham[i] = sanPham;
        }
    }
    
    void xuatDuLieuHangHoa(){
        cout << "Ma hang" << setw(20) << "Ten hang" << setw(20) << "Gia tien" << setw(20) << "So luong" << endl;
      
        for(int i = 0 ; i< danhSachSanPham.size();i++){
            cout << danhSachSanPham[i];
        }
    }
};

int main(){
    MayTinhTien* mayTinhTien = new MayTinhTien();
    
    mayTinhTien->nhapDuLieuHangHoa();
    mayTinhTien->xuatDuLieuHangHoa();
    
    
    delete mayTinhTien;
    return 0;
}


