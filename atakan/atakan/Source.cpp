#include <iostream>
#include <fstream>
#include <string>


using namespace std;

//constructor destructor pointer abstract friend kullanýlacak

class DosyaIslemleri {
public:
	// Dosyaya veri yazdýrma
	void yazDosya(string dosya_adi, string veri) {
		ofstream dosya(dosya_adi);
		dosya << veri << endl;
		dosya.close();
	}

	// Dosyadan veri okuma
	string okuDosya(string dosya_adi) {
		/*
		ifstream dosya(dosyaIsmi);
		// Dosya açýlýrken bir hata oluþtuysa hata mesajý yaz
		if (!dosya.is_open())
		{
		cout << "Dosya bulunamadý." << endl;
		return;
		}
		// Dosyadaki satýrlarý oku ve ekrana yaz
		string satir;
		int n = 1;
		while (getline(dosya, satir))
		{
		cout << n << ") " << satir << endl;
		n++;
		}
		// Dosya nesnesini kapat
		dosya.close();
		*/

		string veri;
		ifstream dosya(dosya_adi);
		getline(dosya, veri);
		dosya.close();
		return veri;
	}

	// Dosyadan liste oluþturma
	void liste(string dosya_adi) {
		/*

if (!dosya.is_open())
{
	cout << "Dosya bulunamadý." << endl;
	return;
}
string line;
while (getline(dosya, line))
{
	liste.push_back(line);
}
dosya.close();
cout << "-----------------" << endl
	<< "    GOZLUKLER" << endl
	<< "-----------------" << endl;
int id = 1;
for (auto a : liste)
{
	cout << id << ") " << a << endl;
	id++;
}
		*/

		string veri;
		ifstream dosya(dosya_adi);
		while (getline(dosya, veri)) {
			cout << veri << endl;
		}
		dosya.close();
	}
};


class Menu {
public:
	

	void navigasyon() {

		cout << "----------------------------------------------------\nSatýþ Asistanýna Hoþ Geldin Patron \nBugün Sana Nasýl Yardýmcý Olabilirim?\n----------------------------------------------------" << endl;
		cout << "Ürün Ýþlemleri [1]" << endl;
		cout << "Müþteri Ýþlemleri [2]" << endl;
		cout << "Kasa Ýþlemleri [3]" << endl;
		cout << "Ýþlem yapmak istediðiniz menü numarasýný giriniz: ";

		
	}




};




class UrunIslemler {
	DosyaIslemleri dosya;
public:
	Menu mn;

	void nagivasyon() {
		cout << "Ürün stoðu ekleme iþlemleri [1]" << endl;
		cout << "Ürün stok silme iþlemleri [2]" << endl;
		cout << "Ürün stok bilgileri iþlemleri [3]" << endl;
		cout << "Yapmak istediðiniz iþlem numarasýný giriniz: ";
		int secim;

		while (true) {
			cout << "[1] Ekle" << endl;
			cout << "[2] Sil" << endl;
			cout << "[3] Güncelle" << endl;
			cout << "[0] Geri" << endl;
			cout << "Seciminiz: ";
			cin >> secim;
			if (secim == 0)
			{
				mn.navigasyon();
				break;
			}
			switch (secim) {
			case 1:
			{
				ekle();

				nagivasyon();
				break;
			}
			case 2:
			{
				sil();
				nagivasyon();
				break;
			}
			case 3:
			{
				guncelle();
				nagivasyon();
				break;
			}
			default:
				break;
			}
		}
	}

	//ürün ekleme bu fonksiyonda yapýlýr ve loga yazýlýr.
	void ekle() {

		string marka, model, stok, maliyet, fiyat;
		cout << "Eklemek istediginiz gözlük markasini giriniz: ";
		cin >> marka;
		cout << "Eklemek istediginiz gözlük modelini giriniz: ";
		cin >> model;
		cout << "Eklemek istediginiz gözlük stoðunu giriniz: ";
		cin >> stok;
		cout << "Eklemek istediginiz gözlük maliyetini giriniz: ";
		cin >> maliyet;
		cout << "Eklemek istediginiz gözlük fiyatini giriniz: ";
		cin >> fiyat;
		string yazýlacak = "Marka: " + marka + " Model: " + model + " Stok: "
			+ stok + " Fiyat: " + fiyat;

		dosya.yazDosya("Gözlükler.txt", yazýlacak);

	}
	//ürün silme bu fonksiyonda yapýlýr ve loga yazýlýr.
	void sil() {

		string dosya1;
		dosya1 = "gözlükler.txt";

		// Dosyayý okuma modunda aç

		ifstream inputFile(dosya1);

		// Yedek dosya oluþturma

		ofstream outputFile("temp.txt");

		// Dosya satýr satýr okunur ve yedek dosyaya yazýlýr
		string line;
		int currentLine = 1;
		/*	while (getline(inputFile, line))
			{
				// Seçilen satýr silinir ve yazýlmaz
				if (strcmp(currentLine != silinecekSatýr))
					outputFile << line << endl;

				currentLine++;
			}
			*/
			// Dosyalar kapatýlýr
		inputFile.close();
		outputFile.close();

		// Ýlk dosya silinir ve yedek dosya adýyla yeniden adlandýrýlýr
		remove(dosya1.c_str());
		rename("temp.txt", dosya1.c_str());

		cout << "sil fonksiyonu";

	}
	//ürün güncelleme bu fonksiyonda yapýlýr ve loga yazýlýr.
	void guncelle() {

		string dosya1;
		dosya1 = "gözlükler.txt";

		// Dosyayý okuma modunda aç

		ifstream inputFile(dosya1);

		// Yedek dosya oluþturma

		ofstream outputFile("temp.txt");

		// Dosya satýr satýr okunur ve yedek dosyaya yazýlýr
		string line;
		int currentLine = 1;
		while (getline(inputFile, line))
		{
			// Seçilen satýr silinir ve yazýlmaz
			/*if (currentLine != güncellenecekSatýr)
				outputFile << line << endl;
			else {
				string marka, model, stok, maliyet, fiyat;
				cout << "Eklemek istediginiz gözlük markasini giriniz: ";
				cin >> marka;
				cout << "Eklemek istediginiz gözlük modelini giriniz: ";
				cin >> model;
				cout << "Eklemek istediginiz gözlük stoðunu giriniz: ";
				cin >> stok;
				cout << "Eklemek istediginiz gözlük maliyetini giriniz: ";
				cin >> maliyet;
				cout << "Eklemek istediginiz gözlük fiyatini giriniz: ";
				cin >> fiyat;
				string güncellenecek = "Marka: " + marka + " Model: " + model + " Stok: "
					+ stok + " Fiyat: " + fiyat;
				outputFile << güncellenecek << endl;

			}

			currentLine++;*/
		}

		// Dosyalar kapatýlýr
		inputFile.close();
		outputFile.close();

		// Ýlk dosya silinir ve yedek dosya adýyla yeniden adlandýrýlýr
		remove(dosya1.c_str());
		rename("temp.txt", dosya1.c_str());

		cout << "güncelle fonksiyonu";

	}

	//	void ara() {} #filtreleme iþlemi bu fonksiyonda uygulanacak


};


//müþteriye satýþ yapýlacaðý zaman ilk adým olan bilgiMusteri sýnýfýndan yenimüþteri eklemektir, eðer müþterinin kaydý varsa geçmiþMusteri fonksiyonu kullanýlýr.
//kasadan satýþ iþlemi yapýlacaðý zaman ilk olarak bu bilgiMusteri fonksiyonlarý tarafýndan loga girilen verilerden yararlanýlýr.
//müþteri kaydý yoksa yeniMusteri'den kayýt oluþturulur loga yazýlýr. kaydý var ise geçmiþMusteri fonksiyonu ile loglardan kayýtlar id(tc kimlik no) ile bulunur.
class BilgiMusteri {
public:

	void nagivasyon() {
		cout << "Yeni müþteri iþlemleri [1]" << endl;
		cout << "Geçmiþ müþterileri iþlemleri [2]" << endl;
		cout << "Yapmak istediðiniz iþlem numarasýný giriniz: ";





	}

	void yeniMusteri() {


	}

	void geçmiþMusteri() {


	}

};

//yapSatis fonksiyon kullanýlýrken ilk önce id girilir ve sonrasýnda ürün bilgileri girilir bu þekilde hangi müþteriye satýþ yapýldýðý loglarda tutulmuþ olur.
//bilgiGelir fonksiyonu elde edilen geliri kar ve maliyet olarak verir.
//bilgiGider fonksiyonu giderleri verir.
//zRapor gelirler ve giderleri içeren tüm loglarý ekrana yazdýrýr.
class Kasa {
public:

	void nagivasyon() {
		cout << "Satýþ yapma iþlemleri [1]" << endl;
		cout << "Gelir bilgisi görüntüleme iþlemleri [2]" << endl;
		cout << "Gider bilgisi görüntüleme iþlemleri [3]" << endl;
		cout << "Raporlama iþlemleri [3]" << endl;
		cout << "Yapmak istediðiniz iþlem numarasýný giriniz: ";



	}

	void yapSatis() {


	}

	void bilgiGelir() {


	}

	void bilgiGider() {


	}

	void zRapor() {


	}

};


class test {
public:
	void print() {
		cout << "test";
	}
};


int main() {
	setlocale(LC_ALL, "Turkish");

	DosyaIslemleri dosya;

	// Dosyaya veri yazma
	dosya.yazDosya("urunverisi.txt", "Ray-Ban Mavi 500 10");

	// Dosyadan veri okuma
	string veri = dosya.okuDosya("urunverisi.txt");
	cout << veri << endl;

	// Dosyadan liste oluþturma
	dosya.liste("urunverisi.txt");




	Menu m;
	m.navigasyon();


	test t;
	t.print();

	return 0;
}