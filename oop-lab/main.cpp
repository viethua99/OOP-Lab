
#include<iostream>
#include<vector>
using namespace std;


class SinhVien{
protected:
    string hoTen;
    string he;
    float tienHocPhi;
    
public:
    virtual void nhapThongTin(){
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin,hoTen);
        cout << "Nhap he: ";
        getline(cin,he);
    }
    
    virtual void xuatThongTin(){
        
        cout << "Ho ten: " << hoTen << endl;
        cout << "He:" << he << endl;
    }
    
    void setHoTen(string hoTen){
        this->hoTen = hoTen;
    }
    
    void setHe(string he){
        this->he = he;
    }
    
    string getHoTen(){
        return this->hoTen;
    }
    
    string getHe(){
        return this->he;
    }
    
    friend istream& operator >> (istream& is , SinhVien& sinhVien){
           
           sinhVien.nhapThongTin();
           return is;
       }
       
       friend ostream& operator << (ostream& os , SinhVien& sinhVien){
           
           sinhVien.xuatThongTin();
           return os;
       }
};

class SinhVienCQ: public SinhVien{
private:
    int soChiLyThuyet;
    int soChiThucHanh;
    typedef SinhVien sinhVien;
public:
    
    SinhVienCQ(string hoTen,string he){
        this->hoTen = hoTen;
        this->he = he;
        
    }
    void nhapThongTin() override{
        cout << "Nhap so chi ly thuyet: ";
        cin >> soChiLyThuyet;
        cout << "Nhap so chi thuc hanh: ";
        cin >> soChiThucHanh;
    }
    
    void xuatThongTin() override {
        sinhVien::xuatThongTin();
        cout << "So chi ly thuyet: " << soChiLyThuyet << endl;
        cout << "So chi thuc hanh: " << soChiThucHanh << endl;
    }
    
    friend istream& operator >> (istream& is , SinhVienCQ* sinhVien){
        
        sinhVien->nhapThongTin();
        return is;
    }
    
    friend ostream& operator << (ostream& os , SinhVienCQ* sinhVien){
        
        sinhVien->xuatThongTin();
        return os;
    }
    
};

class SinhVienCLC: public SinhVien{
private:
    int hocKyDangHoc;
    typedef SinhVien sinhVien;
public:
    
    SinhVienCLC(string hoTen,string he){
        this->hoTen = hoTen;
        this->he = he;
        
    }
    void nhapThongTin() override {
        cout << "Nhap hoc ky dang hoc: ";
        cin >> hocKyDangHoc;
    }
    
    void xuatThongTin() override {
        sinhVien::xuatThongTin();
        cout << "Hoc ky dang hoc: " << hocKyDangHoc << endl;
    }
    
    
    friend istream& operator >> (istream& is , SinhVienCLC* sinhVien){
        
        sinhVien->nhapThongTin();
        return is;
    }
    
    friend ostream& operator << (ostream& os , SinhVienCLC* sinhVien){
        
        sinhVien->xuatThongTin();
        return os;
    }
};


class QuanLiHocPhi{
    
private:
    vector<SinhVien*> danhSachSinhVien;
public:
    void nhapDanhSach(){
        int n;
        cout << "Nhap so luong sinh vien: ";
        cin >> n;
        
        danhSachSinhVien.resize(n);
        
        for(int i = 0 ; i<danhSachSinhVien.size();i++){
            SinhVien sinhVien;
            cin >> sinhVien;
            
            if(danhSachSinhVien[i]->getHe() == "CQ"){
                SinhVienCQ* sinhVienCQ = new SinhVienCQ(sinhVien.getHoTen(),
                                                        sinhVien.getHe());
                
                cin >> sinhVienCQ;
                danhSachSinhVien[i] = sinhVienCQ;
                
            } else {
                SinhVienCLC* sinhVienCLC = new SinhVienCLC(sinhVien.getHoTen(),
                                                        sinhVien.getHe());
                
                
                cin >> sinhVienCLC;
                danhSachSinhVien[i] = sinhVienCLC;
                
                
            }
        }
        
    }
    
    void xuatDanhSach(){
        for(int i = 0; i< danhSachSinhVien.size();i++){
            cout << *danhSachSinhVien[i];
        }
    }
    
    void inMenu(){
        int select;
        cout << "*****BAI 4*****" << endl;
        cout << "1.Nhap danh sach" << endl;
        cout << "2.Xuat danh sach" << endl;
        do{
            cout << "Xin nhap yeu cau" << endl;
        }while(select!=3);
        
    }
    
    
};

int main(){
    
    
    return 0;
}






