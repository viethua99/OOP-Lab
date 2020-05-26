
#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>

using namespace std;


class Phong{
    
private:
    long maPhong;
    string tenPhong;
    int giaTien;
    int soLuong;
public:
    void nhapPhong(){
        cout << "Nhap ma phong: ";
        cin >> maPhong;
        cout << "Nhap ten phong: ";
        cin.ignore();
        getline(cin,tenPhong);
        cout << "Nhap gia tien: ";
        cin >> giaTien;
        cout << "Nhap so luong: ";
        cin >> soLuong;
    }
    
    void xuatPhong(){
        
        cout << maPhong << setw(10) << tenPhong << setw(10) << giaTien << setw(10) << soLuong << endl;
    }
    
    long getMaPhong(){
        return this->maPhong;
    }
    string getTenPhong(){
        return this->tenPhong;
    }
    int getGiaTien(){
        return this->giaTien;
    }
    int getSoLuong(){
        return this->soLuong;
    }
    void giamSoLuongPhong(){
        soLuong--;
    }
    
    void ghiFile(ofstream& file){
        
        file << maPhong << setw(10) << tenPhong << setw(10) << giaTien << setw(10) << soLuong << endl;
        
    }
    
    friend istream& operator >> (istream& is, Phong& phong){
        phong.nhapPhong();
        return is;
    }
    
    friend ostream& operator << (ostream& os,Phong& phong){
        phong.xuatPhong();
        return os;
    }
    
};

class DangKi{
private:
    long maPhong;
    string tenPhong;
    int giaTien;
    int soDem;
public:
    
    DangKi(long maPhong, string tenPhong,int giaTien,int soDem){
        this->maPhong = maPhong;
        this->tenPhong = tenPhong;
        this-> giaTien = giaTien;
        this->soDem = soDem;
    }
    void setMaPhong(long maPhong){
        this->maPhong = maPhong;
    }
    void setTenPhong(string tenPhong){
        this->tenPhong = tenPhong;
    }
    void setGiaTien(int giaTien){
        this->giaTien = giaTien;
    }
    void setSoDem(int soDem){
        this->soDem = soDem;
    }
    long getMaPhong(){
        return this->maPhong;
    }
    string getTenPhong(){
        return this->tenPhong;
    }
    int getGiaTien(){
        return this->giaTien;
    }
    int getSoDem(){
        return this->soDem;
    }
    
};
class QuanLiPhong{
private:
    vector<Phong> danhSachPhong;
    vector<DangKi> danhSachDangKi;
    
public:
    void nhapDuLieuPhong(){
        int n;
        cout << "Nhap so luong du lieu:";
        cin >> n;
        
        danhSachPhong.resize(n);
        
        for(int i = 0 ; i< danhSachPhong.size();i++){
            cout << "Du lieu thu" << i+1 << endl;
            cin >> danhSachPhong[i];
        }
    }
    
    void xuatDuLieuPhong(){
        cout << "Ma phong" << setw(10) << "Ten phong" << setw(10) << "Gia tien" << setw(10) << "So luong" << endl;
        for(int i=0;i<danhSachPhong.size();i++){
            cout << danhSachPhong[i];
        }
    }
    
    void dangKiPhong(){
        int luachon;
        int soDem;
        cout << "Nhap ma phong muon dang ki:";
        cin >> luachon;
        cout << "Nhap so dem o: ";
        cin >> soDem;
        
        for(int i = 0 ; i<danhSachPhong.size();i++){
            if(luachon == danhSachPhong[i].getMaPhong() && danhSachPhong[i].getSoLuong() > 0){
                
                DangKi dangKi(danhSachPhong[i].getMaPhong(),
                              danhSachPhong[i].getTenPhong(),
                              danhSachPhong[i].getGiaTien(),soDem);
                danhSachDangKi.push_back(dangKi);
                
                
                danhSachPhong[i].giamSoLuongPhong();
                
            }
            if(danhSachPhong[i].getSoLuong() <= 0) {
                danhSachPhong.erase(danhSachPhong.begin() + i);
            }
        }
        
        
    }
    
    
    void tinhTongTienPhong(){
        
        int tong = 0;
        for(int i = 0; i< danhSachDangKi.size();i++){
            
            tong+= danhSachDangKi[i].getGiaTien() * danhSachDangKi[i].getSoDem();
        }
        cout << "Tong tien phai tra:" << tong << endl;
    }
    
    void sapXepDanhSachPhong(){
        //Bubble sort
        for(int i = 0;i<danhSachPhong.size() -1;i++){
            for(int j = 0 ;j < danhSachPhong.size() - i -1;j++){
                if(danhSachPhong[j].getGiaTien() > danhSachPhong[j+1].getGiaTien()){
                    Phong temp = danhSachPhong[j];
                    danhSachPhong[j] = danhSachPhong[j+1];
                    danhSachPhong[j+1] = temp;
                }
            }
        }
    }
    
    void inFile(){
        ofstream file;
        file.open("danhsachtrong.txt",ios::out);
        if(file.is_open()){
            file << "Ma phong" << setw(10) << "Ten phong" << setw(10) << "Gia tien" << setw(10) << "So luong" << endl;
            
            for(int i = 0 ; i<danhSachPhong.size();i++){
                
                danhSachPhong[i].ghiFile(file);
            }
            file.close();
        } else {
            
            cout << "Khong the mo file" << endl;
        }
        
    }
    
    
    void inMenu(){
        int select;
        cout << "*****BAI 3 *****" << endl;
        cout << "1.Nhap du lieu phong" << endl;
        cout << "2.Xuat du lieu phong" << endl;
        cout << "3.Thoat" << endl;
        do {
            
            cout << "Xin nhap yeu cau: ";
            cin >> select;
            
            switch (select) {
                case 1:
                    nhapDuLieuPhong();
                    break;
                case 2:
                    xuatDuLieuPhong();
                    break;
                case 3:
                    
                    break;
                case 4:
                    dangKiPhong();
                    break;
                case 5:
                    tinhTongTienPhong();
                    break;
                case 6:
                    sapXepDanhSachPhong();
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
    
    QuanLiPhong* quanLiPhong = new QuanLiPhong();
    quanLiPhong->inMenu();
    
    delete quanLiPhong;
    return 0;
}


