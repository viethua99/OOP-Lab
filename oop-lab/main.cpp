
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
    
    
    void xuatSanPham(){
        cout << _maHang << setw(26) << _tenHang << setw(20) << _giaTien << setw(20) << _soLuong << endl;
    }
    
    void themSoLuong(){
        _soLuong++;
    }
    void giamSoLuong(){
        _soLuong--;
    }
    int getSoLuong(){
        return this->_soLuong;
    }
    void setMaHang(long maHang){
        this->_maHang = maHang;
    }
    long getMaHang(){
        return _maHang;
    }
    void setTenHang(string tenHang){
        this->_tenHang = tenHang;
    }
    string getTenHang(){
        return this->_tenHang;
    }
    void setGiaTien(int giaTien){
        this->_giaTien = giaTien;
    }
    int getGiaTien(){
        return this->_giaTien;
    }
    
    friend istream& operator >> (istream& is , SanPham& sanPham){
           sanPham.nhapSanPham();
           return is;
       }
    
    friend ostream& operator << (ostream& os,SanPham& sanPham){
        sanPham.xuatSanPham();
        return os;
    }
};


class MayTinhTien{
private:
    vector<SanPham> danhSachSanPham;
    vector<SanPham> gioHang;
public:
    void nhapDuLieuHangHoa(){
        int n;
        cout << "Nhap so luong hang hoa: ";
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
        cout << "******THONG TIN SAN PHAM******" << endl;
        cout << "Ma hang" << setw(20) << "Ten hang" << setw(20) << "Gia tien" << setw(20) << "So luong" << endl;
      
        for(int i = 0 ; i< danhSachSanPham.size();i++){
            cout << danhSachSanPham[i];
        }
    }
    
    void themVaoGioHang(){
        SanPham sanPham;
        long maHang;
        cout << "Xin nhap ma hang san pham: ";
        cin >> maHang;
        
        for(int i = 0 ; i< danhSachSanPham.size();i++){
            if(maHang == danhSachSanPham[i].getMaHang()){
                if(danhSachSanPham[i].getSoLuong() > 0){
                    sanPham.setMaHang(danhSachSanPham[i].getMaHang());
                    sanPham.setTenHang(danhSachSanPham[i].getTenHang());
                    sanPham.setGiaTien(danhSachSanPham[i].getGiaTien());
                    danhSachSanPham[i].giamSoLuong();
                    
                    if(gioHang.empty()){
                        sanPham.themSoLuong();
                        gioHang.insert(gioHang.end(), sanPham);
                    } else {
                        for(int i = 0 ; i< gioHang.size();i++){
                            if(maHang == gioHang[i].getMaHang()){
                                gioHang[i].themSoLuong();
                                break;
                              
                            }
                            if(i == gioHang.size() -1 && maHang != gioHang[i].getMaHang()){
                                gioHang.insert(gioHang.end(), sanPham);
                            }
                                  
                        }
                    }
                } else {
                    cout << "SAN PHAM DA HET" << endl;;
                }
                
                break;
            }
        }
        
      
       
    }
    
    void xuatGioHang(){
        cout << "******THONG TIN GIO HANG******" << endl;;
        cout << "Ma hang" << setw(20) << "Ten hang" << setw(20) << "Gia tien" << setw(20) << "So luong" << endl;
        for(int i = 0 ; i< gioHang.size();i++){
            cout << gioHang[i];
        }
        tinhTongSoLuongHangVaThanhTien();
    }
    
    void tinhTongSoLuongHangVaThanhTien(){
        int tongSoLuong = 0;
        int thanhTien = 0;
        for(int i = 0 ; i< gioHang.size();i++){
            tongSoLuong+= gioHang[i].getSoLuong();
            thanhTien+= gioHang[i].getSoLuong() * gioHang[i].getGiaTien();
        }
        
        cout << "Tong so luong: " << tongSoLuong << endl;
        cout << "Thanh tien: " << thanhTien << endl;
    }
    
    void inMenu(){
        int select;
        cout << "*******BAI 1**********" << endl;
        cout << "1.Nhap du lieu hang hoa" << endl;
        cout << "2.Xuat du lieu hang hoa" << endl;
        cout << "3.Them vao gio hang" << endl;
        cout << "4.Xuat gio hang" << endl;
        cout << "5.Thoat" << endl;
        do{
            cout << "Vui long nhap yeu cau: ";
            cin >> select;
            
            switch (select) {
                case 1:
                    nhapDuLieuHangHoa();
                    break;
                case 2:
                    xuatDuLieuHangHoa();
                    break;
                case 3:
                    themVaoGioHang();
                    break;
                case 4:
                    xuatGioHang();
                    break;
                default:
                    break;
            }
            
            
            
        }while(select!=5);
    }
    
    
};

int main(){
    MayTinhTien* mayTinhTien = new MayTinhTien();
    
    mayTinhTien->inMenu();
    delete mayTinhTien;
    return 0;
}


