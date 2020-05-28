
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

class DocGia{
protected:
    string hoTen;
    string loai;
    float tongTienTra;
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
    
    virtual float tinhTongTien(){
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
    
    
    friend istream& operator >> (istream& is,DocGia& docGia){
        docGia.nhapThongTin();
        return is;
        
    }
    
    friend ostream& operator << (ostream& os,DocGia& docGia){
        docGia.xuatThongTin();
        return os;
        
    }
    
};

class DocGiaNguoiLon: public DocGia{
private:
    int soThangDangKy;
public:
    DocGiaNguoiLon(string hoTen,string loai){
        this->hoTen = hoTen;
        this->loai = loai;
        
    }
    void nhapThongTin() override{
        cout << "Nhap so thang dang ky: ";
        cin >> soThangDangKy;
    }
    
    void xuatThongTin() override {
        DocGia::xuatThongTin();
        cout << "So thang dang ky: " << soThangDangKy << endl;
        cout << "Tong tien tra:" << tinhTongTien() << endl;
        
    }
    
    void ghiFile(ofstream& file) override{
        DocGia::ghiFile(file);
        file << "So thang dang ky: " << soThangDangKy << endl;
        file << "Tong tien tra:" << tinhTongTien() << endl;
    }
    float tinhTongTien() override {
        tongTienTra = 100000*soThangDangKy;
        return  tongTienTra;
    }
    
    friend istream& operator >> (istream& is,DocGiaNguoiLon* docGia){
        docGia->nhapThongTin();
        return is;
        
    }
    
    friend ostream& operator << (ostream& os,DocGiaNguoiLon*& docGia){
        docGia->xuatThongTin();
        return os;
        
    }
};

class DocGiaTreEm: public DocGia{
private:
    int soTuoi;
public:
    DocGiaTreEm(string hoTen,string loai){
        this->hoTen = hoTen;
        this->loai = loai;
    }
    void nhapThongTin() override{
        cout  << "Nhap so tuoi: ";
        cin >> soTuoi;
        
    }
    
    void xuatThongTin() override {
        DocGia::xuatThongTin();
        cout << "So tuoi: " << soTuoi << endl;
        cout << "Tong tien tra:" << tinhTongTien() << endl;
        
    }
    
    void ghiFile(ofstream& file) override{
        DocGia::ghiFile(file);
        file << "So tuoi: " << soTuoi << endl;
        file << "Tong tien tra:" << tinhTongTien() << endl;
    }
    float tinhTongTien() override {
        tongTienTra = 20000 * soTuoi;
        return tongTienTra;
    }
    
    friend istream& operator >> (istream& is,DocGiaTreEm* docGia){
        docGia->nhapThongTin();
        return is;
        
    }
    
    friend ostream& operator << (ostream& os,DocGiaTreEm* docGia){
        docGia->xuatThongTin();
        return os;
        
    }
    
};
class DocGiaNguoiGia: public DocGia{
private:
    
public:
    DocGiaNguoiGia(string hoTen,string loai){
        this->hoTen = hoTen;
        this->loai = loai;
    }
    void nhapThongTin() override{
        
        
    }
    
    void xuatThongTin() override {
        DocGia::xuatThongTin();
        cout << "Tong tien tra:" << tinhTongTien() << endl;
        
    }
    
    void ghiFile(ofstream& file) override{
        DocGia::ghiFile(file);
        cout << "Tong tien tra:" << tinhTongTien() << endl;
    }
    float tinhTongTien() override {
        return 0;
    }
    friend istream& operator >> (istream& is,DocGiaNguoiGia* docGia){
        docGia->nhapThongTin();
        return is;
        
    }
    
    friend ostream& operator << (ostream& os,DocGiaNguoiGia* docGia){
        docGia->xuatThongTin();
        return os;
        
    }
    
};
class QuanLiThuVien{
private:
    vector<DocGia*> danhSachDocGia;
public:
    void nhapDanhSach(){
        int n;
        cout << "Nhap so luong doc gia: ";
        cin >> n;
        
        danhSachDocGia.resize(n);
        
        for(int i = 0;i<danhSachDocGia.size();i++){
            DocGia docGia;
            cin >> docGia;
            if(docGia.getLoai() == "NgLon"){
                DocGiaNguoiLon* docGiaNguoiLon = new DocGiaNguoiLon(docGia.getHoTen(),docGia.getLoai());
                cin >> docGiaNguoiLon;
                danhSachDocGia[i] = docGiaNguoiLon;
            } else if(docGia.getLoai() == "TreE"){
                DocGiaTreEm* docGiaTreEm = new DocGiaTreEm(docGia.getHoTen(),docGia.getLoai());
                cin >> docGiaTreEm;
                danhSachDocGia[i] = docGiaTreEm;
            }else{
                DocGiaNguoiGia* docGiaNguoiGia = new DocGiaNguoiGia(docGia.getHoTen(),docGia.getLoai());
                cin >> docGiaNguoiGia;
                danhSachDocGia[i] = docGiaNguoiGia;
            }
            
        }
        
    }
    
    void xuatDanhSach(){
        for(int i = 0 ;i<danhSachDocGia.size();i++){
            cout << *danhSachDocGia[i];
        }
    }
    
    void chenThemDocGia(){
        int viTri;
        DocGia docGia;
        cout << "Xin nhap vi tri: ";
        cin >> viTri;
        cin >> docGia;
        
        if(docGia.getLoai() == "NgLon"){
            DocGiaNguoiLon* docGiaNguoiLon = new DocGiaNguoiLon(docGia.getHoTen(),docGia.getLoai());
            cin >> docGiaNguoiLon;
            danhSachDocGia.insert(danhSachDocGia.begin() + viTri, docGiaNguoiLon);
        } else if(docGia.getLoai() == "TreE"){
            DocGiaTreEm* docGiaTreEm = new DocGiaTreEm(docGia.getHoTen(),docGia.getLoai());
            cin >> docGiaTreEm;
            danhSachDocGia.insert(danhSachDocGia.begin() + viTri, docGiaTreEm);
        }else{
            DocGiaNguoiGia* docGiaNguoiGia = new DocGiaNguoiGia(docGia.getHoTen(),docGia.getLoai());
            cin >> docGiaNguoiGia;
            danhSachDocGia.insert(danhSachDocGia.begin() + viTri, docGiaNguoiGia);
        }
    }
    
    void xoaMotDocGia(){
        int viTri;
        cout << "Xin nhap vi tri:";
        cin >> viTri;
        danhSachDocGia.erase(danhSachDocGia.begin() + viTri);
    }
    void timDocGiaDongTienNhieuNhat(){
        int max = 0;
        
        for(int i= 0;i<danhSachDocGia.size();i++){
            if(danhSachDocGia[i]->tinhTongTien() > danhSachDocGia[max]->tinhTongTien()){
                max = i;
            }
        }
        cout << "***Doc gia dong tien nhieu nhat****" << endl;
        cout << *danhSachDocGia[max];
        
        
    }
    
    void lietKeDocGiaCaoHonTrungBinh(){
        cout << "*****Bat dau liet ke*****" << endl;
        float trungBinh = 0;
        float tong = 0;
        for(int i = 0 ;i<danhSachDocGia.size();i++){
            tong+= danhSachDocGia[i]->tinhTongTien();
        }
        trungBinh = tong / danhSachDocGia.size();
        
        for(int i = 0 ;i<danhSachDocGia.size();i++){
            
            if(danhSachDocGia[i]->tinhTongTien() > trungBinh){
                cout << *danhSachDocGia[i];
            }
        }
        
    }
    
    void sapXepTheoTongTienTangDan(){
        //Bubble sort
        for(int i = 0;i<danhSachDocGia.size()-1;i++){
            for(int j = 0 ; j<danhSachDocGia.size()-i-1;j++){
                if(danhSachDocGia[j]->tinhTongTien() > danhSachDocGia[j+1]->tinhTongTien()){
                    DocGia* temp = danhSachDocGia[j];
                    danhSachDocGia[j] = danhSachDocGia[j+1];
                    danhSachDocGia[j+1] = temp;
                }
            }
            
        }
        
    }
    
    void inFile(){
        ofstream file;
        file.open("danhsach.txt",ios::out);
        
        if(file.is_open()){
            for(int i=0;i<danhSachDocGia.size();i++){
                
                
                danhSachDocGia[i]->ghiFile(file);
            }
            
            file.close();
        } else {
            
            cout << "Khong the mo file" << endl;
        }
        
    }
    
    void inMenu(){
        int select;
        cout << "*****BAI 5*****" << endl;
        cout << "1.Nhap danh sach" << endl;
        cout << "2.Xuat danh sach" << endl;
        cout << "3.Chen them doc gia" << endl;
        cout << "4.Xoa mot doc gia" << endl;
        cout << "5.Tim doc gia dong nhieu tien nhat" << endl;
        cout << "6.Liet ke doc gia cao hon trung binh" << endl;
        cout << "7.Sap xep theo tong tien tang dan" << endl;
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
                    chenThemDocGia();
                    break;
                case 4 :
                    xoaMotDocGia();
                    break;
                case 5 :
                    timDocGiaDongTienNhieuNhat();
                    break;
                case 6 :
                    lietKeDocGiaCaoHonTrungBinh();
                    break;
                case 7 :
                    sapXepTheoTongTienTangDan();
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
    QuanLiThuVien* quanLiThuVien = new QuanLiThuVien();
    
    quanLiThuVien->inMenu();
    delete quanLiThuVien;
    return 0;
}


