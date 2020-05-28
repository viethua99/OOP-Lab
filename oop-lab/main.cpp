
#include<iostream>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std;


class SinhVien{
protected:
    string hoTen;
    string he;
    float hocPhi;
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
    
    virtual float tinhHocPhi() {
        return 0;
    }
    
    virtual void ghiFile(ofstream& file){
        
        file << "Ho ten: " << hoTen << endl;
        file << "He:" << he << endl;
        
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
        cout << "Tong hoc phi:" << setprecision(15) << tinhHocPhi()  << endl;
    }
    
    virtual void ghiFile(ofstream& file) override{
        sinhVien::ghiFile(file);
        file << "So chi ly thuyet: " << soChiLyThuyet << endl;
        file << "So chi thuc hanh: " << soChiThucHanh << endl;
        file << "Tong hoc phi:" << setprecision(15) << tinhHocPhi()  << endl;
        
    }
    
    float tinhHocPhi() override{
        int tongSoChi = (soChiLyThuyet * 2) + (soChiThucHanh *3);
        hocPhi = tongSoChi * 200000.0;
        return hocPhi;
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
        cout << "Tong hoc phi:" << setprecision(15) << tinhHocPhi() << endl;
    }
    
    virtual void ghiFile(ofstream& file) override{
        sinhVien::ghiFile(file);
        file << "Hoc ky dang hoc: " << hocKyDangHoc << endl;
        file << "Tong hoc phi:" << setprecision(15) << tinhHocPhi() << endl;
        
    }
    
    float tinhHocPhi() override {
        hocPhi = 20000000;
        for(int i = 0 ; i<hocKyDangHoc-1;i++){
            hocPhi += (hocPhi * 0.1f);
        }
        return hocPhi;
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
            
            if(sinhVien.getHe() == "CQ"){
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
    
    void chenSinhVien(){
        int viTri;
        SinhVien sinhVien;
        cout << "Nhap vi tri muon chen:";
        cin >> viTri;
        
        cin >> sinhVien;
        
        if(sinhVien.getHe() == "CQ"){
            SinhVienCQ* sinhVienCQ = new SinhVienCQ(sinhVien.getHoTen(),
                                                    sinhVien.getHe());
            
            cin >> sinhVienCQ;
            danhSachSinhVien.insert(danhSachSinhVien.begin() + viTri,  sinhVienCQ);
            
        } else {
            SinhVienCLC* sinhVienCLC = new SinhVienCLC(sinhVien.getHoTen(),
                                                       sinhVien.getHe());
            
            cin >> sinhVienCLC;
            danhSachSinhVien.insert(danhSachSinhVien.begin() + viTri,  sinhVienCLC);
        }
    }
    
    void xoaSinhVien(){
        int viTri;
        cout << "Nhap vi tri sinh vien muon xoa:";
        cin >> viTri;
        danhSachSinhVien.erase(danhSachSinhVien.begin() + viTri);
    }
    
    void sapXepTheoHocPhi(){
        //Bubble sort
        cout << "Da sap xep" << endl;
        for(int i = 0 ; i<danhSachSinhVien.size() -1;i++){
            for(int j = 0 ; j< danhSachSinhVien.size() - i -1;j++){
                if(danhSachSinhVien[j]->tinhHocPhi() > danhSachSinhVien[j+1]->tinhHocPhi()){
                    SinhVien* temp = danhSachSinhVien[j];
                    danhSachSinhVien[j] = danhSachSinhVien[j+1];
                    danhSachSinhVien[j+1] = temp;
                }
            }
        }
        
    }
    
    void lietKeSinhVienCaoHonTrungBinh(){
        cout << "Bat dau liet ke" << endl;
        float trungBinh = 0;
        float tong = 0;
        for(int i = 0 ; i<danhSachSinhVien.size();i++){
            tong +=  danhSachSinhVien[i]->tinhHocPhi();
        }
        trungBinh = tong / danhSachSinhVien.size();
        cout << "Trung binh hoc phi:" << trungBinh << endl;
        
        
        for(int i = 0 ; i<danhSachSinhVien.size();i++){
            if(danhSachSinhVien[i]->tinhHocPhi() > trungBinh){
                cout << *danhSachSinhVien[i];
            }
        }
    }
    
    void inFile(){
        
        ofstream file;
        
        file.open("danhsach.txt",ios::out);
        if(file.is_open()){
            for(int i = 0 ; i<danhSachSinhVien.size();i++){
                danhSachSinhVien[i]->ghiFile(file);
            }
            file.close();
        } else {
            
            cout << "Khong the mo file" << endl;
        }
        
        
        
    }
    
    void inMenu(){
        int select;
        cout << "*****BAI 4*****" << endl;
        cout << "1.Nhap danh sach" << endl;
        cout << "2.Xuat danh sach" << endl;
        cout << "3.Chen sinh vien" << endl;
        cout << "4.Xoa sinh vien" << endl;
        cout << "5.Sap xep sinh vien" << endl;
        cout << "6.Liet ke sinh vien" << endl;
        cout << "7.In file" << endl;
        cout << "8.Thoat" << endl;
        do{
            cout << "Xin nhap yeu cau:";
            cin >> select;
            
            switch (select) {
                case 1:
                    nhapDanhSach();
                    break;
                case 2:
                    xuatDanhSach();
                    break;
                case 3:
                    chenSinhVien();
                    break;
                case 4:
                    xoaSinhVien();
                    break;
                case 5:
                    sapXepTheoHocPhi();
                    break;
                case 6:
                    lietKeSinhVienCaoHonTrungBinh();
                    break;
                case 7:
                    inFile(); 
                    break;
                default:
                    break;
            }
        }while(select!=8);
        
    }
    
    
};

int main(){
    QuanLiHocPhi* quanLiHocPhi = new QuanLiHocPhi();
    
    quanLiHocPhi->inMenu();
    
    delete quanLiHocPhi;
    return 0;
}






