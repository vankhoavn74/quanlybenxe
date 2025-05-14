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
	void setTen(string tenmoi) { hotenKH = tenmoi; }
	void setSdt(long long Sdtmoi) { sdtKH = Sdtmoi; }
	void setemail(string emailmoi) { emailKh = emailmoi; }
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
class Xe
{
private:
	string phuongTien;
	int soLuong; 
	long long TonggiaVe;
public:
	Xe() {}
	Xe(string phuongTien,int soLuong,long long TonggiaVe)
	{
		this->phuongTien = phuongTien;
		this->soLuong = soLuong;
		this->TonggiaVe = TonggiaVe;
	}
	virtual long long tinhTongTien() const {return 0;};
	void nhapThongTinxe() {
    	cout << "Nhap loai phuong tien: ";
        getline(cin, phuongTien);
        cout << "Nhap so luong: ";
        cin >> soLuong;
    }
    int getsoLuong() const { return soLuong; }
    string getphuongTien() const { return phuongTien; }
    long long  getTongGia()  const { return giaVe; }
    void setsoLuong(int soLuongmoi) { soLuong = soLuongmoi; }
    void setphuongTien(string phuongTienmoi) { phuongTien = phuongTienmoi; }
};
class XeKhach : public Xe 
{
private :
	long long giaVe;
public:
	long long tinhTongTien() const override {
		TonggiaVe = 150000 * soLuong;
		return TonggiaVe;
	}
};
class Taxi : public Xe 
{
private:
	long long giaVe;
public:
	long long tinhTongTien() const override {
		TonggiaVe =  300000 * soLuong;
		return TonggiaVe;
	}
};
void Thanhtoan(const vector<DonDatVe>& danhSach) {
	for (const auto& don : danhSach) {
	XeKhach xk;
	Taxi tx;
	if(don.xe.getphuongTien() = "Xe Khach") {
		xk.tinhTongTien();
	}
	else(don.xe.getphuongTien() = "Taxi") {
		tx.tinhTongTien();
	}
	}
}

class Thoigian
{
	string thoigian;
public:
	Thoigian(const string& t) : thoigian(t) {}
	Thoigian() {
	time_t now = time(nullptr);
	char buffer[100];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&now));
	thoigian = buffer;
	}
	string tg() const { return thoigian;}
	};

struct DonDatVe
{
	KhachHang kh;
	TuyenXe tx;
	Thoigian tgg;
	Xe xe;
};

void hienthids(const vector<DonDatVe>& danhSach) {
    cout << "===================DANH SACH DAT VE=================="<<"\n";
    cout << left << setw(3) <<"STT" << setw(10) << "Ten KH" << setw(10) << "Ten KH" setw(10) << "Ten KH" setw(10) << "Ten KH" setw(10) << "Ten KH"setw(10) << "Ten KH" setw(10) << "Ten KH" setw(10) << "Ten KH" ;
    int dem = 0;
    for (const auto& don : danhSach) {
        cout << left << setw(3) << ++dem << setw(10) << don.kh.XuathotenKH()  << setw(10) << <<setw(10)<<  ;
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
        get << don.xe.getphuongTien() << ";" <<don.xe.getsoLuong() << ";" <<  <<"\n";
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
	    long long thaydoisdtKH1 = stoll(sdtKH1); 
	    KhachHang kh(hotenKH1,diachiKH1,emailKH1,thaydoisdtKH1);

	    if (!getline(doc, line)) break;
	    stringstream ss2(line);
	    string diemDi1,diemDen1;
	    getline(ss2,diemDi1,';');
	    getline(ss2,diemDen1,';');
	    TuyenXe tx(diemDi1,diemDen1);

		if (!getline(doc, line)) break;
		ThoiGian tgg(line);

		if (!getline(doc, line)) break;
	    stringstream ss3(line);
	    string phuongTien1,soLuong1,TonggiaVe1;
	    getline(ss3,phuongTien1,';');
	    getline(ss3,soLuong1,';');
	    getline(ss3,TonggiaVe,';');
	    int thaydoisoLuong1 = stoi(soLuong1);
	    long long thaydoiTonggiaVe1 = stoll(TonggiaVe1);
	    Xe xe(phuongTien1,thaydoisoLuong1,thaydoiTonggiaVe1);

		danhSach.push_back({kh,tx,tgg,xe});
		}
}
void Nhapdanhsach(vector<DonDatVe>& danhSach) {
	KhachHang kh;
    TuyenXe tx;
    ThoiGian tgg;
    Xe xe;

    kh.NhapthongtinKH();
    tx.Nhaptuyenxe();
    tgg = ThoiGian();
    xe.nhapThongTinxe();
    danhSach.push_back({kh, tx, tgg,xe});
}
void xoaTheoTen(vector<DonDatVe>& danhSach) {
    string tenXoa;
    cout << "Nhap ten khach hang can xoa: ";
    getline(cin, tenXoa);

    vector<DonDatVe> tam;
    bool timThay = false;

    for (const auto& don : danhSach) {
        if (don.kh.XuathotenKH() != tenXoa) {
            tam.push_back(don);
        } else {
            timThay = true;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay khach hang co ten " << tenXoa << ".\n";
    } else {
        danhSach = tam;
        cout << "Da xoa khach hang \"" << tenXoa << "\" thanh cong.\n";
    }
}
void xoaTheoSdt(vector<DonDatVe>& danhSach) {
    long long tenXoatheosdt;
    cout << "Nhap so dien thoai khach hang can xoa: ";
    cin>>tenXoatheosdt;

    vector<DonDatVe> tam;
    bool timThay = false;

    for (const auto& don : danhSach) {
        if (don.kh.XuatsdtKH() != tenXoatheosdt) {
            tam.push_back(don);
        } else {
            timThay = true;
        }
    }

    if (!timThay) {
        cout << "Khong tim thay khach hang co so dien thoai \"" << tenXoatheosdt << "\".\n";
    } else {
        danhSach = tam;
        cout << "Da xoa khach hang co dien thoai "<< tenXoatheosdt <<" thanh cong.\n";
    }
}
void ThaydoittKH(vector<DonDatVe>& danhSach) {
	string tencheck;
    cout << "Nhap ho ten KH can thay doi: ";
    cin.ignore();
    getline(cin,tencheck);
    for(auto& don : danhSach) {
        if (don.kh.XuathotenKH() == tencheck) {
        	bool check1 = true;
        	while(check1) {
        		int luachon2;
        		cout<<"1. Thay doi so dien thoai.\n"
        			<<"2. Thay doi email.\n"
        			<<"3. Thay doi so luong ve\n"
        			<<"4. Thay doi loai phuong tien.\n"
        			<<"0. Thoat.\n";
        		cout<<"Nhap lua chon: ";
        		cin>>luachon2;
        		switch(luachon2) 
        		{
        			case 1 : 
        				{
        					long long sdtnew;
        					cout<<"Nhap so diem thoai can thay doi: ";
        					cin>>sdtnew;
        					don.kh.setSdt(sdtnew);
        					check1 = false;
                        	cout << "Da thay doi so diem thoai cho KH "<<tencheck<<".\n";
                        	break;
        				}
        			case 2 :
        				{
        					string mailnew;
        					cout<<"Nhap email can thay doi: ";
        					getline(cin,mailnew);
        					don.kh.setemail(mailnew);
        					check1 = false;
                        	cout << "Da thay doi email cho KH "<<tencheck<<".\n";
                        	break;
        				}
        			case 3 :
        				{
        					int soLuongvenew;
        					cout<<"Nhap so luong ve can thay doi: ";
        					cin>>soLuongvenew;
        					don.xe.setsoLuong(soLuongvenew);
        					check1 = false;
                        	cout << "Da thay doi so luong ve cho KH "<<tencheck<<".\n";
                        	break;
        				}
        			case 4 :
        				{
        					string phuongtiennew;
        					cout<<"Nhap phuong tien can thay doi: ";
        					getline(cin,phuongtiennew);
        					don.xe.setphuongTien(phuongtiennew);
        					check1 = false;
                        	cout << "Da thay doi phuong tien cho KH "<<tencheck<<".\n";
                        	break;
        				}
        			case 0 :
        				{
        					check1 = false;
        					break;
        				}
        			default :
							cout<<"Lua chon quy khach khong hop le xin nhap lai!";
        		}
        	}
       	}
}
void thongkesolieu(const vector<DonDatVe>& danhSach) {

}
void sapxepthongtin() {
	
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
						hienthids(danhSach);
						break;
					}
				case 2:
					{
						Nhapdanhsach(danhSach);
						break;
					}
				case 3:
					{
						bool check = true;
						while(check) {
							int luachon1;
							cout<<"1. Xoa khach hang theo ten.\n"
							<<"2. Xoa khach hang theo so dien thoai.\n"
							<<"3. Thoat.";
							cout<<"\nNhap lua chon: ";
							cin>>luachon1;
							switch(luachon1) {
							case 1 :
								xoaTheoTen(danhSach);
								break;
							case 2 :
								xoaTheoSdt(danhSach);
								break;
							case 3 :
								check = false;
								break;
							default :
								cout<<"Lua chon quy khach khong hop le xin nhap lai!";
							}
						}
						break;
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
						luuFile(danhSach);
						break;	
					}
				case 9:
					{
						cout<<"Ket thuc chuong trinh!";
						return 0;	
					}
				default :
					{
						cout<<"Lua chon quy khach khong hop le xin nhap lai!";
					}
				}
		}
	return 0;
}