#include <iostream>
#include <vector>
#include <fstream>
using namespace std;



class SinhVien{
protected:
    int maSo;
    string hoTen;
    string he;
    float diemTrungBinh;
    float diemLapTrinhC;
public:
    
    virtual float tinhDiemTrungBinh() {
        return diemTrungBinh;
    }
    virtual void nhapThongTin(){
        cout << "Nhap ma so: ";
        cin >> maSo;
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin,hoTen);
        cout << "Nhap he: ";
        getline(cin,he);
        cout << "Nhap diem lap trinh C:";
        cin >> diemLapTrinhC;
    }
    virtual void xuatThongTin(){
        cout << "Ma so: " << maSo << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "He: " << he << endl;
        cout << "Diem lap trinh C: " << diemLapTrinhC << endl;
    }
    virtual void inThongTin(ofstream& file){
        file << "Ma so: " << maSo << endl;
        file << "Ho ten: " << hoTen << endl;
        file << "He: " << he << endl;
        file << "Diem lap trinh C: " << diemLapTrinhC << endl;
    }
    string getHe(){
        return this->he;
    }
    int getMaSo(){
        return this->maSo;
    }
    string getHoTen(){
        return this->hoTen;
    }
    float getDiemLapTrinhC(){
        return this->diemLapTrinhC;
    }
    
    
    friend istream& operator >> (istream& is , SinhVien& sinhVien){
        sinhVien.nhapThongTin();
        return is;
    }
    friend ostream& operator << (ostream& os, SinhVien& sinhVien){
        sinhVien.xuatThongTin();
        return os;
    }
    
};

class SinhVienCLC: public SinhVien{
private:
    float diemDienTuCanBan;
    typedef SinhVien sinhVien;
public:
    SinhVienCLC(){
        
    }
    SinhVienCLC(int maSo,string hoTen,string he,float diemLapTrinhC){
        this->maSo = maSo;
        this->hoTen = hoTen;
        this->he = he;
        this->diemLapTrinhC = diemLapTrinhC;
    }
    float tinhDiemTrungBinh() override {
        diemTrungBinh = ((2* diemLapTrinhC) + diemDienTuCanBan) / 3;
        return diemTrungBinh;
    }
    void nhapThongTin() override {
        cout << "Nhap diem dien tu can ban: ";
        cin >> diemDienTuCanBan;
    }
    void xuatThongTin() override{
        sinhVien::xuatThongTin();
        cout << "Diem dien tu can ban: " << diemDienTuCanBan << endl;
        cout << "Diem trung binh: " << tinhDiemTrungBinh() << endl;
    }
    
    void inThongTin(ofstream& file) override {
        sinhVien::inThongTin(file);
        file << "Diem dien tu can ban: " << diemDienTuCanBan << endl;
        file << "Diem trung binh: " << tinhDiemTrungBinh() << endl;
    }
    
    friend istream& operator >> (istream& is , SinhVienCLC* sinhVien){
        sinhVien->nhapThongTin();
        return is;
    }
    friend ostream& operator << (ostream& os, SinhVienCLC* sinhVien){
        sinhVien->xuatThongTin();
        return os;
    }
};

class SinhVienCQ : public SinhVien{
private:
    typedef SinhVien sinhVien;
    float diemNhapMonKyThuat;
public:
    SinhVienCQ(int maSo,string hoTen,string he,float diemLapTrinhC){
        this->maSo = maSo;
        this->hoTen = hoTen;
        this->he = he;
        this->diemLapTrinhC = diemLapTrinhC;
    }
    float tinhDiemTrungBinh() override {
        diemTrungBinh = ((3 * diemLapTrinhC) + (2 * diemNhapMonKyThuat)) /5;
        return diemTrungBinh;
    }
    
    void nhapThongTin() override {
        cout << "Nhap diem nhap mon ky thuat: ";
        cin >> diemNhapMonKyThuat;
    }
    void xuatThongTin() override{
        sinhVien::xuatThongTin();
        cout << "Diem nhap mon ky thuat: " << diemNhapMonKyThuat << endl;
        cout << "Diem trung binh: " << tinhDiemTrungBinh() << endl;
    }
    void inThongTin(ofstream& file) override {
        sinhVien::inThongTin(file);
        file << "Diem nhap mon ky thuat: " << diemNhapMonKyThuat << endl;
        file << "Diem trung binh: " << tinhDiemTrungBinh() << endl;
    }
    
    friend istream& operator >> (istream& is , SinhVienCQ* sinhVien){
        sinhVien->nhapThongTin();
        return is;
    }
    friend ostream& operator << (ostream& os, SinhVienCQ* sinhVien){
        sinhVien->xuatThongTin();
        return os;
    }
};

class QuanLiSinhVien {
private:
    vector<SinhVien*> danhSachSinhVien;
public:
    void nhapDanhSach(){
        int n;
        cout << "Nhap so luong sinh vien: ";
        cin >> n;
        
        danhSachSinhVien.resize(n);
        for(int i = 0 ; i< danhSachSinhVien.size(); i++){
            cout << "NHAP SINH VIEN THU " << i+1 << endl;
            SinhVien sinhVien;
            cin >> sinhVien;
            if(sinhVien.getHe() == "CQ"){
                SinhVienCQ* sinhVienCQ = new SinhVienCQ(sinhVien.getMaSo(),sinhVien.getHoTen(),
                                                        sinhVien.getHe(),sinhVien.getDiemLapTrinhC());
                cin >> sinhVienCQ;
                danhSachSinhVien[i] = sinhVienCQ;
            } else {
                SinhVienCLC* sinhVienCLC =  new SinhVienCLC(sinhVien.getMaSo(),sinhVien.getHoTen(),
                                                            sinhVien.getHe(),sinhVien.getDiemLapTrinhC());
                cin >> sinhVienCLC;
                danhSachSinhVien[i] = sinhVienCLC;
            }
            
        }
    }
    
    void xuatDanhSach(){
        cout << "***XUAT DANH SACH SINH VIEN***" << endl;
        for(int i = 0 ; i< danhSachSinhVien.size();i++){
            cout << *danhSachSinhVien[i];
        }
    }
    
    void timSinhVienCoDiemTrungBinhCaoNhat(){
        cout << "***SINH VIEN CO DTB CAO NHAT***"  << endl ;
        float maxIndex = 0;
        float max = danhSachSinhVien[maxIndex]->tinhDiemTrungBinh();
        for(int i = 0 ; i< danhSachSinhVien.size();i++){
            if(danhSachSinhVien[i]->tinhDiemTrungBinh() > max){
                max = danhSachSinhVien[i]->tinhDiemTrungBinh();
                maxIndex = i;
            }
        }
        cout << *danhSachSinhVien[maxIndex];
        
    }
    void sapXepSinhVienTheoDTBTangDan(){
        //Su dung bubble sort
        for(int i = 0 ; i < danhSachSinhVien.size() - 1;i++){
            for(int j = 0 ; j < danhSachSinhVien.size() - i -1;j++){
                if(danhSachSinhVien[j]->tinhDiemTrungBinh() > danhSachSinhVien[j+1]->tinhDiemTrungBinh()){
                    SinhVien* temp = danhSachSinhVien[j];
                    danhSachSinhVien[j] = danhSachSinhVien[j+1];
                    danhSachSinhVien[j+1] = temp;
                }
            }
        }
        xuatDanhSach();
    }
    void xoaSinhVienBatKy(){
        int maSo;
        cout << "Vui long nhap MSSV: ";
        cin >> maSo;
        for(int i = 0 ; i<danhSachSinhVien.size();i++){
            if(maSo == danhSachSinhVien[i]->getMaSo()){
                danhSachSinhVien.erase(danhSachSinhVien.begin() + i);
                cout << "Xoa thanh cong" << endl;
            }
        }
    }
    void chenThemSinhVien(){
        int viTri;
        SinhVien sinhVien;
        cout << "Vui long nhap vi tri muon chen:";
        cin >> viTri;
        cin >> sinhVien;
        
        
        if(sinhVien.getHe() == "CQ"){
            SinhVienCQ* sinhVienCQ = new SinhVienCQ(sinhVien.getMaSo(),sinhVien.getHoTen(),
                                                    sinhVien.getHe(),sinhVien.getDiemLapTrinhC());
            cin >> sinhVienCQ;
            
            danhSachSinhVien.insert(danhSachSinhVien.begin() + viTri, sinhVienCQ);
        } else {
            SinhVienCLC* sinhVienCLC =  new SinhVienCLC(sinhVien.getMaSo(),sinhVien.getHoTen(),
                                                        sinhVien.getHe(),sinhVien.getDiemLapTrinhC());
            cin >> sinhVienCLC;
            danhSachSinhVien.insert(danhSachSinhVien.begin() + viTri, sinhVienCLC);
            
        }
    }
    
    void inFile(){
        ofstream file;
        
        file.open("danhsach.txt",ios::out);  //Bo ios::out neu su dung he dieu hanh window
        if(file.is_open()){
            for(int i = 0 ; i<danhSachSinhVien.size();i++){
                danhSachSinhVien[i]->inThongTin(file);
            }
            
            file.close();
        } else {
            cout << "Khong mo duoc file" << endl;
        }
        
    }
    
    
    void inMenu(){
        int select;
        cout << "******BAI2******" << endl;
        cout << "1.Nhap danh sach sinh vien" << endl;
        cout << "2.Xuat danh sach sinh vien" << endl;
        cout << "3.Tim sinh vien co DTB cao nhat" << endl;
        cout << "4.Sap xep sinh vien theo DTB tang dan" << endl;
        cout << "5.Xoa thong tin 1 sinh vien" << endl;
        cout << "6.Chen them 1 sinh vien" << endl;
        cout << "7.Sap xep tong diem" << endl;
        cout << "8.In ra file" << endl;
        cout << "9.Thoat" << endl;
        do{
            cout << "Vui long chon yeu cau: ";
            cin >> select;
            
            switch (select) {
                case 1:
                    nhapDanhSach();
                    break;
                case 2:
                    xuatDanhSach();
                    break;
                case 3:
                    timSinhVienCoDiemTrungBinhCaoNhat();
                    break;
                case 4:
                    sapXepSinhVienTheoDTBTangDan();
                    break;
                case 5:
                    xoaSinhVienBatKy();
                    break;
                case 6:
                    chenThemSinhVien();
                    break;
                case 7:
                    break;
                case 8:
                    inFile();
                    break;
                default:
                    break;
            }
        }while(select != 9);
        
        
        
        
    }
};


int main(){
    QuanLiSinhVien* qlsv = new QuanLiSinhVien();
    qlsv->inMenu();
    
    
    delete qlsv;
    return 0;
}

