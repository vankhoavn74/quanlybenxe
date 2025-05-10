#include<iostream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;

class KhachHang 
{
private:
	string hotenKH;
	string diachiKH;
	string emailKH;
	long long sdtKH;
public:
	KhachHang() {}
	KhachHang(string hotenKH,string diachiKH,string emailKH,long long sdtKH) {
		this->hotenKH = hotenKH;
		this->diachiKH = diachiKH;
		this->emailKH = emailKH;
		this->sdtKH = sdtKH;
		}
	void NhapthongtinKH()
	{
		cout<<"Nhap ho ten KH: ";
		getline(cin,hotenKH);
		cout<<"Nhap dia chi KH: ";
		getline(cin,diachiKH);
		cout << "Nhap email cua KH: ";
	    cin >> emailKH;
		cout<<"Nhap SDT cua KH: ";
		cin>>sdtKH;
		}
	string XuathotenKH() { return hotenKH; }
	string XuatdiachiKH() { return diachiKH; }
	string XuatemailKH() { return emailKH; }
	long long XuatsdtKH() { return sdtKH; }
	};
class TuyenXe
{
private:
	string diemDi;
	string diemDen;
public:
	TuyenXe() {}
	TuyenXe(string diemDi,string diemDen) {
		this->diemDi = diemDi;
		this->diemDen = diemDen;
	}
	void Nhaptuyenxe()
	{
		cout<<"Nhap diem don cua KH: ";
		getline(cin,diemDi);
		cout<<"Nhap diem den cua KH: ";
		getline(cin,diemDen);
		}
		string XuatdiemDi() { return diemDi; }
		string XuatdiemDen() { return diemDen; }

	};
/*class VeXe
{
private:
	static int demMaVe;
	string maVe;
	int soLuong; 
	string loaiVe;
public:
	VeXe(int s1,string loaiVe) : soLuong(sl) {
    maVe = "VEXE" + to_string(++demMaVe); }
    virtual double tinhTongTien() const {
        return giaVe * soLuong;
    }
};
int VeXe::demMaVe = 0;
class VexeThuong : public VeXe 
{
public:
};
class VexeVIP : public VeXe 
{
private:


public:

};*/
class Thoigian
{
	string thoigian;
public:
	Thoigian(const string& t) : thoigian(t) {}
	Thoigian() {
	time_t now = time(nullptr);
	thoigian = ctime(&now);
	thoigian.erase(thoigian.find_last_not_of("\n") + 1);
	}
	string tg() const { return thoigian;}
	};

struct DonDatVe
{
	KhachHang kh;
	TuyenXe tx;
	Thoigian tgg;
};
void hienthids(const vector<DonDatVe>& danhSach) {
    cout << "===================DANH SACH DAT VE=================="<<"\n";
    cout << left << setw(3) <<"STT" << setw(10) << "Ten KH" << setw(10) << "Ten KH" setw(10) << "Ten KH" setw(10) << "Ten KH" setw(10) << "Ten KH"setw(10) << "Ten KH" setw(10) << "Ten KH" setw(10) << "Ten KH" ;
    int dem = 0;
    for (const auto& don : danhSach) {
        cout << left << setw(3) << ++dem << setw(10) << don.kh.XuathotenKH()  <<   ;
    }
}
void luuFile(const vector<DonDatVe>& danhSach) {
    ofstream get("PBL1.txt", ios::trunc);
    if (!get) {
	    cout << "Khong mo duoc file!\n";
	    	return ;
	}
    for (const auto& don : danhSach) {
        get << don.kh.XuathotenKH() << ";" << don.kh.XuatdiachiKH() << ";" << don.kh.XuatemailKH() << ";" << don.kh.XuatsdtKH() << "\n";
        get << don.tx.XuatdiemDi() << ";" << don.tx.XuatdiemDen() << "\n";
        get << don.tgg.tg() << "\n";
    }
    get.close();
    cout << "\n=>Luu thanh cong!";
}
void docfile(vector<DonDatVe>& danhSach) {
	ifstream doc("PBL1.txt");
	if (!doc) {
	    cout << "Khong mo duoc file!\n";
	    	return ;
	}
	string line;
	while(true)
	{
		if (!getline(doc, line)) break;
	    stringstream ss1(line);
	    string hotenKH1,diachiKH1,emailKH1,sdtKH1;
	    getline(ss1,hotenKH1,';');
	    getline(ss1,diachiKH1,';');
	    getline(ss1,emailKH1,';');
	    getline(ss1,sdtKH1,';');
	    long long sdtKH1s = stoll(sdtKH1); 
	    KhachHang kh(hotenKH1,diachiKH1,emailKH1,sdtKH1s);

	    if (!getline(doc, line)) break;
	    stringstream ss2(line);
	    string diemDi1,diemDen1;
	    getline(ss2,diemDi1,';');
	    getline(ss2,diemDen1,';');
	    TuyenXe tx(diemDi1,diemDen1);

	    /*if (!getline(fin, line)) break;
	    stringstream ss3(line);

	    VeXe objVe();
	    dsVe.push_back();*/

		if (!getline(doc, line)) break;
		ThoiGian tgg(line);

		danhSach.push_back({kh,tx,tgg});
		}
}
int main()
{
	vector<DonDatVe> danhSach;
    docfile(danhSach);

	while(true) {
		cout <<"1. In danh sach cua KH.\n"
	    << "2. Nhap thong tin cua KH moi.\n"
	    << "3. Xoa thong tin cua KH.\n"
	    << "4. Thay doi thong tin cua KH.\n"
	    << "5. Sap xep thong tin cua KH.\n"
	    << "6. Tra cuu thong tin cua KH.\n"
	    << "7. Thong ke doanh thu.\n"
	    << "8. Luu vao file.\n"
	    << "9. Thoat.\n";
	   	int luachon;
	    cout << "Nhap lua chon: ";
		cin>>luachon;

		switch(luachon) {
				case 1: 
					{

					}
				case 2:
					{

					}
				case 3:
					{

					}
				case 4:
					{
						
					}
				case 5:
					{
						
					}
				case 6:
					{
						
					}
				case 7:
					{
						
					}
				case 8:
					{
						
					}
				case 0:
					{
						cout<<"Ket thuc chuong trinh!"
						return 0;	
					}
				default :
					{
						cout<<"Lua chon quy khach khong hop le xin nhap lai!"	
					}
				}
		}
		return 0;
	}