#include <iostream>
#include <fstream>
#include <string>


using namespace std;

//constructor destructor pointer abstract friend kullan�lacak

class DosyaIslemleri {
public:
	// Dosyaya veri yazd�rma
	void yazDosya(string dosya_adi, string veri) {
		ofstream dosya(dosya_adi);
		dosya << veri << endl;
		dosya.close();
	}

	// Dosyadan veri okuma
	string okuDosya(string dosya_adi) {
		/*
		ifstream dosya(dosyaIsmi);
		// Dosya a��l�rken bir hata olu�tuysa hata mesaj� yaz
		if (!dosya.is_open())
		{
		cout << "Dosya bulunamad�." << endl;
		return;
		}
		// Dosyadaki sat�rlar� oku ve ekrana yaz
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

	// Dosyadan liste olu�turma
	void liste(string dosya_adi) {
		/*

if (!dosya.is_open())
{
	cout << "Dosya bulunamad�." << endl;
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

		cout << "----------------------------------------------------\nSat�� Asistan�na Ho� Geldin Patron \nBug�n Sana Nas�l Yard�mc� Olabilirim?\n----------------------------------------------------" << endl;
		cout << "�r�n ��lemleri [1]" << endl;
		cout << "M��teri ��lemleri [2]" << endl;
		cout << "Kasa ��lemleri [3]" << endl;
		cout << "��lem yapmak istedi�iniz men� numaras�n� giriniz: ";

		
	}




};




class UrunIslemler {
	DosyaIslemleri dosya;
public:
	Menu mn;

	void nagivasyon() {
		cout << "�r�n sto�u ekleme i�lemleri [1]" << endl;
		cout << "�r�n stok silme i�lemleri [2]" << endl;
		cout << "�r�n stok bilgileri i�lemleri [3]" << endl;
		cout << "Yapmak istedi�iniz i�lem numaras�n� giriniz: ";
		int secim;

		while (true) {
			cout << "[1] Ekle" << endl;
			cout << "[2] Sil" << endl;
			cout << "[3] G�ncelle" << endl;
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

	//�r�n ekleme bu fonksiyonda yap�l�r ve loga yaz�l�r.
	void ekle() {

		string marka, model, stok, maliyet, fiyat;
		cout << "Eklemek istediginiz g�zl�k markasini giriniz: ";
		cin >> marka;
		cout << "Eklemek istediginiz g�zl�k modelini giriniz: ";
		cin >> model;
		cout << "Eklemek istediginiz g�zl�k sto�unu giriniz: ";
		cin >> stok;
		cout << "Eklemek istediginiz g�zl�k maliyetini giriniz: ";
		cin >> maliyet;
		cout << "Eklemek istediginiz g�zl�k fiyatini giriniz: ";
		cin >> fiyat;
		string yaz�lacak = "Marka: " + marka + " Model: " + model + " Stok: "
			+ stok + " Fiyat: " + fiyat;

		dosya.yazDosya("G�zl�kler.txt", yaz�lacak);

	}
	//�r�n silme bu fonksiyonda yap�l�r ve loga yaz�l�r.
	void sil() {

		string dosya1;
		dosya1 = "g�zl�kler.txt";

		// Dosyay� okuma modunda a�

		ifstream inputFile(dosya1);

		// Yedek dosya olu�turma

		ofstream outputFile("temp.txt");

		// Dosya sat�r sat�r okunur ve yedek dosyaya yaz�l�r
		string line;
		int currentLine = 1;
		/*	while (getline(inputFile, line))
			{
				// Se�ilen sat�r silinir ve yaz�lmaz
				if (strcmp(currentLine != silinecekSat�r))
					outputFile << line << endl;

				currentLine++;
			}
			*/
			// Dosyalar kapat�l�r
		inputFile.close();
		outputFile.close();

		// �lk dosya silinir ve yedek dosya ad�yla yeniden adland�r�l�r
		remove(dosya1.c_str());
		rename("temp.txt", dosya1.c_str());

		cout << "sil fonksiyonu";

	}
	//�r�n g�ncelleme bu fonksiyonda yap�l�r ve loga yaz�l�r.
	void guncelle() {

		string dosya1;
		dosya1 = "g�zl�kler.txt";

		// Dosyay� okuma modunda a�

		ifstream inputFile(dosya1);

		// Yedek dosya olu�turma

		ofstream outputFile("temp.txt");

		// Dosya sat�r sat�r okunur ve yedek dosyaya yaz�l�r
		string line;
		int currentLine = 1;
		while (getline(inputFile, line))
		{
			// Se�ilen sat�r silinir ve yaz�lmaz
			/*if (currentLine != g�ncellenecekSat�r)
				outputFile << line << endl;
			else {
				string marka, model, stok, maliyet, fiyat;
				cout << "Eklemek istediginiz g�zl�k markasini giriniz: ";
				cin >> marka;
				cout << "Eklemek istediginiz g�zl�k modelini giriniz: ";
				cin >> model;
				cout << "Eklemek istediginiz g�zl�k sto�unu giriniz: ";
				cin >> stok;
				cout << "Eklemek istediginiz g�zl�k maliyetini giriniz: ";
				cin >> maliyet;
				cout << "Eklemek istediginiz g�zl�k fiyatini giriniz: ";
				cin >> fiyat;
				string g�ncellenecek = "Marka: " + marka + " Model: " + model + " Stok: "
					+ stok + " Fiyat: " + fiyat;
				outputFile << g�ncellenecek << endl;

			}

			currentLine++;*/
		}

		// Dosyalar kapat�l�r
		inputFile.close();
		outputFile.close();

		// �lk dosya silinir ve yedek dosya ad�yla yeniden adland�r�l�r
		remove(dosya1.c_str());
		rename("temp.txt", dosya1.c_str());

		cout << "g�ncelle fonksiyonu";

	}

	//	void ara() {} #filtreleme i�lemi bu fonksiyonda uygulanacak


};


//m��teriye sat�� yap�laca�� zaman ilk ad�m olan bilgiMusteri s�n�f�ndan yenim��teri eklemektir, e�er m��terinin kayd� varsa ge�mi�Musteri fonksiyonu kullan�l�r.
//kasadan sat�� i�lemi yap�laca�� zaman ilk olarak bu bilgiMusteri fonksiyonlar� taraf�ndan loga girilen verilerden yararlan�l�r.
//m��teri kayd� yoksa yeniMusteri'den kay�t olu�turulur loga yaz�l�r. kayd� var ise ge�mi�Musteri fonksiyonu ile loglardan kay�tlar id(tc kimlik no) ile bulunur.
class BilgiMusteri {
public:

	void nagivasyon() {
		cout << "Yeni m��teri i�lemleri [1]" << endl;
		cout << "Ge�mi� m��terileri i�lemleri [2]" << endl;
		cout << "Yapmak istedi�iniz i�lem numaras�n� giriniz: ";





	}

	void yeniMusteri() {


	}

	void ge�mi�Musteri() {


	}

};

//yapSatis fonksiyon kullan�l�rken ilk �nce id girilir ve sonras�nda �r�n bilgileri girilir bu �ekilde hangi m��teriye sat�� yap�ld��� loglarda tutulmu� olur.
//bilgiGelir fonksiyonu elde edilen geliri kar ve maliyet olarak verir.
//bilgiGider fonksiyonu giderleri verir.
//zRapor gelirler ve giderleri i�eren t�m loglar� ekrana yazd�r�r.
class Kasa {
public:

	void nagivasyon() {
		cout << "Sat�� yapma i�lemleri [1]" << endl;
		cout << "Gelir bilgisi g�r�nt�leme i�lemleri [2]" << endl;
		cout << "Gider bilgisi g�r�nt�leme i�lemleri [3]" << endl;
		cout << "Raporlama i�lemleri [3]" << endl;
		cout << "Yapmak istedi�iniz i�lem numaras�n� giriniz: ";



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

	// Dosyadan liste olu�turma
	dosya.liste("urunverisi.txt");




	Menu m;
	m.navigasyon();


	test t;
	t.print();

	return 0;
}