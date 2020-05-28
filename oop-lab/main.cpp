#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>

using namespace std;

class NhanVien{
protected:
    string hoTen;
    string loai;
    float luong;
public:
    virtual void nhapThongTin(){
        cout << "Nhap ho ten:";
        cin.ignore();
        getline(cin,hoTen);
        cout << "Nhap loai:";
        getline(cin,loai);
    }
    
    virtual void xuatThongTin(){
        cout << "Ho ten: " << hoTen << endl;
        cout << "Loai: " << loai << endl;
    }
    
    virtual float tinhLuong(){
        return 0;
    }
    
    virtual void ghiFile(ofstream& file){
        file << "Ho ten: " << hoTen << endl;
        file << "Loai: " << loai << endl;
    }
    
    void setHoTen(string hoTen){
        this->hoTen = hoTen;
    }
    
    void setLoai(string loai){
        this->loai = loai;
    }
    
    string getHoTen(){
        return this->hoTen;
    }
    string getLoai(){
        return this->loai;
    }
    
    
    friend istream& operator >> (istream& is,NhanVien& nhanVien){
        nhanVien.nhapThongTin();
        return is;
        
    }
    
    friend ostream& operator << (ostream& os,NhanVien& nhanVien){
        nhanVien.xuatThongTin();
        return os;
        
    }
    
};

class NhanVienVanPhong: public NhanVien{
private:
    int heSoChucVu;
public:
    NhanVienVanPhong(string hoTen,string loai){
        this->hoTen = hoTen;
        this->loai = loai;
        
    }
    void nhapThongTin() override{
        cout << "Nhap he so chuc vu: ";
        cin >> heSoChucVu;
    }
    
    void xuatThongTin() override {
        NhanVien::xuatThongTin();
        cout << "He so chuc vu: " << heSoChucVu << endl;
        cout << "Luong hang thang:" << setprecision(15) << tinhLuong() << endl;
        
    }
    
    void ghiFile(ofstream& file) override{
        NhanVien::ghiFile(file);
        file << "He so chuc vu: " << heSoChucVu << endl;
        file << "Luong hang thang:"  << setprecision(15) << tinhLuong() << endl;
    }
    float tinhLuong() override {
        luong = 1000000*heSoChucVu;
        return  luong;
    }
    
    friend istream& operator >> (istream& is,NhanVienVanPhong* nhanVien){
        nhanVien->nhapThongTin();
        return is;
        
    }
    
    friend ostream& operator << (ostream& os,NhanVienVanPhong* nhanVien){
        nhanVien->xuatThongTin();
        return os;
        
    }
};

class LapTrinhVien: public NhanVien{
private:
    int soPhanMem;
public:
    LapTrinhVien(string hoTen,string loai){
        this->hoTen = hoTen;
        this->loai = loai;
    }
    void nhapThongTin() override{
        cout  << "Nhap so phan mem: ";
        cin >> soPhanMem;
        
    }
    
    void xuatThongTin() override {
        NhanVien::xuatThongTin();
        cout << "So phan mem: " << soPhanMem << endl;
        cout << "Luong hang thang:"  << setprecision(15)<< tinhLuong() << endl;
        
    }
    
    void ghiFile(ofstream& file) override{
        NhanVien::ghiFile(file);
        file << "So phan mem: " << soPhanMem << endl;
        file << "Luong hang thang:"  << setprecision(15) << tinhLuong() << endl;
    }
    float tinhLuong() override {
        luong = 5000000 * soPhanMem;
        return luong;
    }
    
    friend istream& operator >> (istream& is,LapTrinhVien* lapTrinhVien){
        lapTrinhVien->nhapThongTin();
        return is;
        
    }
    
    friend ostream& operator << (ostream& os,LapTrinhVien* lapTrinhVien){
        lapTrinhVien->xuatThongTin();
        return os;
        
    }
    
};
class NhanVienPhucVu: public NhanVien{
private:
    float thuong;
public:
    NhanVienPhucVu(string hoTen,string loai){
        this->hoTen = hoTen;
        this->loai = loai;
    }
    void nhapThongTin() override{
        cout << "Nhap muc thuong: ";
        cin >> thuong;
        
    }
    
    void xuatThongTin() override {
        NhanVien::xuatThongTin();
        cout << "Luong hang thang:"  << setprecision(15) << tinhLuong() << endl;
        
    }
    
    void ghiFile(ofstream& file) override{
        NhanVien::ghiFile(file);
        cout << "Luong hang thang:"  << setprecision(15) <<  tinhLuong() << endl;
    }
    float tinhLuong() override {
        luong = 3000000 + thuong;
        return luong;
    }
    friend istream& operator >> (istream& is,NhanVienPhucVu* nhanVien){
        nhanVien->nhapThongTin();
        return is;
        
    }
    
    friend ostream& operator << (ostream& os,NhanVienPhucVu* nhanVien){
        nhanVien->xuatThongTin();
        return os;
        
    }
    
};
class QuanLiNhanVien{
private:
    vector<NhanVien*> danhSachNhanVien;
public:
    void nhapDanhSach(){
        int n;
        cout << "Nhap so luong nhan vien: ";
        cin >> n;
        
        danhSachNhanVien.resize(n);
        
        for(int i = 0;i<danhSachNhanVien.size();i++){
            NhanVien nhanVien;
            cin >> nhanVien;
            if(nhanVien.getLoai() == "VPhong"){
                NhanVienVanPhong* nhanVienVanPhong = new NhanVienVanPhong(nhanVien.getHoTen(),nhanVien.getLoai());
                cin >> nhanVienVanPhong;
                danhSachNhanVien[i] = nhanVienVanPhong;
            } else if(nhanVien.getLoai() == "LTV"){
                LapTrinhVien* lapTrinhVien = new LapTrinhVien(nhanVien.getHoTen(),nhanVien.getLoai());
                cin >> lapTrinhVien;
                danhSachNhanVien[i] = lapTrinhVien;
            }else{
                NhanVienPhucVu* nhanVienPhucVu = new NhanVienPhucVu(nhanVien.getHoTen(),nhanVien.getLoai());
                cin >> nhanVienPhucVu;
                danhSachNhanVien[i] = nhanVienPhucVu;
            }
            
        }
        
    }
    
    void xuatDanhSach(){
        for(int i = 0 ;i<danhSachNhanVien.size();i++){
            cout << *danhSachNhanVien[i];
        }
    }
    
    void chenThemNhanVien(){
        int viTri;
        NhanVien nhanVien;
        cout << "Xin nhap vi tri: ";
        cin >> viTri;
        cin >> nhanVien;
        
        if(nhanVien.getLoai() == "VPhong"){
            NhanVienVanPhong* nhanVienVanPhong = new NhanVienVanPhong(nhanVien.getHoTen(),nhanVien.getLoai());
            cin >> nhanVienVanPhong;
            danhSachNhanVien.insert(danhSachNhanVien.begin() + viTri, nhanVienVanPhong);
        } else if(nhanVien.getLoai() == "LTV"){
            LapTrinhVien* lapTrinhVien = new LapTrinhVien(nhanVien.getHoTen(),nhanVien.getLoai());
            cin >> lapTrinhVien;
            danhSachNhanVien.insert(danhSachNhanVien.begin() + viTri, lapTrinhVien);
        }else{
            NhanVienPhucVu* nhanVienPhucVu = new NhanVienPhucVu(nhanVien.getHoTen(),nhanVien.getLoai());
            cin >> nhanVienPhucVu;
            danhSachNhanVien.insert(danhSachNhanVien.begin() + viTri, nhanVienPhucVu);
        }
    }
    
    void xoaMotNhanVien(){
        int viTri;
        cout << "Xin nhap vi tri:";
        cin >> viTri;
        danhSachNhanVien.erase(danhSachNhanVien.begin() + viTri);
    }
    void timNhanVienLuongCaoNhat(){
        int max = 0;
        
        for(int i= 0;i<danhSachNhanVien.size();i++){
            if(danhSachNhanVien[i]->tinhLuong() > danhSachNhanVien[max]->tinhLuong()){
                max = i;
            }
        }
        cout << "***Nhan vien luong cao nhat****" << endl;
        cout << *danhSachNhanVien[max];
        
        
    }
    
    void lietKeNhanVienLuongThapHonTB(){
        cout << "*****Bat dau liet ke*****" << endl;
        float trungBinh = 0;
        float tong = 0;
        for(int i = 0 ;i<danhSachNhanVien.size();i++){
            tong+= danhSachNhanVien[i]->tinhLuong();
        }
        trungBinh = tong / danhSachNhanVien.size();
        
        for(int i = 0 ;i<danhSachNhanVien.size();i++){
            
            if(danhSachNhanVien[i]->tinhLuong() < trungBinh){
                cout << *danhSachNhanVien[i];
            }
        }
        
    }
    
    void sapXepTheoLuongGiamDan(){
        //Bubble sort
        for(int i = 0;i<danhSachNhanVien.size()-1;i++){
            for(int j = 0 ; j<danhSachNhanVien.size()-i-1;j++){
                if(danhSachNhanVien[j]->tinhLuong() < danhSachNhanVien[j+1]->tinhLuong()){
                    NhanVien* temp = danhSachNhanVien[j];
                    danhSachNhanVien[j] = danhSachNhanVien[j+1];
                    danhSachNhanVien[j+1] = temp;
                }
            }
            
        }
        
    }
    
    void inFile(){
        ofstream file;
        file.open("danhsach.txt",ios::out);
        
        if(file.is_open()){
            for(int i=0;i<danhSachNhanVien.size();i++){
                danhSachNhanVien[i]->ghiFile(file);
            }
            
            file.close();
        } else {
            
            cout << "Khong the mo file" << endl;
        }
        
    }
    
    void inMenu(){
        int select;
        cout << "*****BAI 6*****" << endl;
        cout << "1.Nhap danh sach" << endl;
        cout << "2.Xuat danh sach" << endl;
        cout << "3.Chen them nhan vien" << endl;
        cout << "4.Xoa mot nhan vien" << endl;
        cout << "5.Tim kiem nhan vien co luong cao nhat" << endl;
        cout << "6.Liet ke nhan vien thap hon trung binh" << endl;
        cout << "7.Sap xep theo luong giam dan" << endl;
        cout << "8.In file" << endl;
        
        do {
            cout << "Xin nhap yeu cau: ";
            cin >> select;
            
            switch (select) {
                case 1 :
                    nhapDanhSach();
                    break;
                case 2:
                    xuatDanhSach();
                    break;
                case 3 :
                    chenThemNhanVien();
                    break;
                case 4 :
                    xoaMotNhanVien();
                    break;
                case 5 :
                    timNhanVienLuongCaoNhat();
                    break;
                case 6 :
                    lietKeNhanVienLuongThapHonTB();
                    break;
                case 7 :
                    sapXepTheoLuongGiamDan();
                    break;
                case 8:
                    inFile();
                default:
                    break;
            }
            
        }while(select!=9);
        
    }
    
};
int main(){
    QuanLiNhanVien* quanLiNhanVien = new QuanLiNhanVien();
    
    quanLiNhanVien->inMenu();
    delete quanLiNhanVien;
    return 0;
}

