#include <iostream>
#include <locale>
#include <string>
#include <fstream>
#include <iterator>
#include <list>

using namespace std;

class Hero
{
public:
	string weaponName;
	string name;
	int id;
	int damege;
	int weapon;
	int odul;
	int armor;
	Hero() {};
	Hero(string weaponName, string name, int  id, int damege, int weapon, int armaor)
	{
		odul = 0;
		this->weaponName = weaponName;
		this->armor = armaor;
		this->damege = damege;
		this->id = id;
		this->weapon = weapon;
		this->name = name;
	}
	void karaktersec();

	// set ve get methodlarýný yazdým
	int getDamege()
	{
		return  damege;
	}
	void setDamege(int dmg)
	{
		damege = dmg;
	}

	int getweapon()
	{
		return  weapon;
	}
	void setweapon(int dmg)
	{
		weapon = dmg;
	}
	int getArmor()
	{
		return  armor;
	}
	void setARmor(int dmg)
	{
		armor = dmg;
	}

	string getName()
	{
		return  name;
	}
	void setARmor(string dmg)
	{
		name = dmg;
	}
	int getodul()
	{
		return  odul;
	}
	void setodul(int dmg)
	{
		odul = dmg;
	}
};
void Hero::karaktersec()
{
	string weaponName;
	string name;
	int id;
	int damege;
	int weapon;
	int armor;

	cout << "Hangi Karaketri Seçmek Ýstiyrosunuz?" << endl << endl;

	cout << "********************Heros*************************" << endl;
	cout << "\t1.Bozayý\t\t\t\t |\nZýrh: 50\t\t\t\t\t |\nHasar : 5\t\t\t\t\t |\nSilah Gücü : 2\t\t\t\t\t |\nSilah Adý : Mavi Pençe" << "\t\t\t\t |" << endl;
	cout << "\t\t\t\t\t\t |" << endl;
	cout << "**************************************************" << endl;


	cout << "********************Heros*************************" << endl;
	cout << "\t2.Ay Þavasçýsý\t\t\t\t |\nZýrh: 20\t\t\t\t\t |\nHasar : 10\t\t\t\t\t |\nSilah Gücü : 3\t\t\t\t\t |\nSilah Adý : Gece Oku" << "\t\t\t\t |" << endl;
	cout << "\t\t\t\t\t\t |" << endl;
	cout << "**************************************************" << endl;




	cout << "********************Heros*************************" << endl;
	cout << "\t3.Kara Büyücü\t\t\t\t |\nZýrh: 5\t\t\t\t\t\t |\nHasar : 1\t\t\t\t\t |\nSilah Gücü : 9\t\t\t\t\t |\nSilah Adý : Merlin Asaý" << "\t\t\t\t |" << endl;
	cout << "\t\t\t\t\t\t |" << endl;
	cout << "**************************************************" << endl;

	cin >> id;
	if (id == 1)
	{
		string weaponName = "Mavi Pençe";
		string name = "Bozayý";
		int damege = 5;
		int weapon = 2;
		int armor = 50;
		Hero(weaponName, name, id, damege, weapon, armor);
	}
	if (id == 2)
	{
		string weaponName = "Gece Oku";
		string name = "Ay Þavasçýsý";
		int damege = 10;
		int weapon = 3;
		int armor = 20;
		Hero(weaponName, name, id, damege, weapon, armor);
	}
	if (id == 3)
	{
		string weaponName = "Merlin Asaý";
		string name = "Kara Büyücü";
		int damege = 1;
		int weapon = 9;
		int armor = 5;
		Hero(weaponName, name, id, damege, weapon, armor);
	}
} // hero þeçeme methodu




class Location  // nerede oldugunu bilmek için bir abstarct class oluþturdum ve burda extensdds iþlemi uygulacagým
{
protected:
	Hero hero;
	string name;
public:
	Location(Hero hero)
	{
		this->hero = hero;
	}
	virtual bool getLocation() = 0;

	string getName()
	{
		return name;
	}
	void setName(string name)
	{
		this->name = name;

	}
};

class NormLoc : public Location {
public:
	string name;
	NormLoc(Hero hero, string name) : Location(hero) {
	}

	bool getLocation()
	{
		return true;
	}
};

class SafeHouse : public NormLoc
{
public:
	SafeHouse(Hero hero) :NormLoc(hero, "Güvenli ev") {}

	bool getLocation()
	{

		hero.setARmor(hero.getArmor());
		cout << "Can Doldu" << endl;
		cout << "Yenilenmiþ Canýnýz : " + hero.getArmor();
		return true;

	}
};


// burada Canavarlarýn ait olan tüm özelkleri bir class da topladým ve burdan extends ettim
class Monster {
private:
	string name;
	int Damage, healty, odul, maxmonster;

public:
	Monster() {}
	Monster(string name, int damage, int healty, int odul, int maxmonster) {
		this->name = name;
		this->Damage = damage;
		this->healty = healty;
		this->odul = odul;
		this->maxmonster = maxmonster;
	}

	int MonsterCount()
	{
		// Bu fonkisiyonun amcý Bize Karþýmýza KAç adet Düþman Çýkartýcak RAndým SAyý Üreticek

		int Count;
		for (int i = 0; i <= 3; i++)
		{
			Count = rand();
		}

		return Count;
	}
	string getName()
	{
		return name;
	}

	void setName(string name) {
		this->name = name;
	}

	int getDamage() {
		return Damage;
	}

	void setDamage(int damage) {
		Damage = damage;
	}

	int getHealty() {
		return healty;
	}

	void setHealty(int healty) {
		this->healty = healty;
	}

	int getOdul() {
		return odul;
	}

	void setOdul(int odul) {
		this->odul = odul;
	}

	int getMaxmonster() {
		return maxmonster;
	}

	void setMaxmonster(int maxmonster) {
		this->maxmonster = maxmonster;
	}
};

// Burasý Monster Classtan Türettigimiz Düþmanlar Burada Extends iþlemi uyguladýk
class Vampire : public Monster {
public:


	Vampire() : Monster("Vampire", 3, 7, 2, MonsterCount())
	{

	}
};

class Zombie : public Monster {
public:

	Zombie() : Monster("zombie", 3, 7, 2, MonsterCount())
	{

	}
};

class Bear : public Monster {
public:

	Bear() : Monster("Bear", 3, 7, 2, MonsterCount())
	{

	}
};




class BattleLoc : Location {
private:
	Monster  mns;
protected:
	string ItemName;
public:

	BattleLoc(Hero hero, string name, Monster mns, string ItemName) :Location(hero)
	{
		this->mns = mns;
		this->name = name;
		this->ItemName = ItemName;

	}

	bool getLocation()
	{
		string input;
		int mnsCount = mns.MonsterCount();
		cout << "SU an Burdasýnýz : " + getName() << endl;
		cout << "Dikatli ol " + mnsCount << " Kadar Düþman var" + mns.getName() + " yaþýyor" << endl;
		cout << "Þavaþ için <s> kullan" << endl;
		cout << "Kaçmak için <k> kullan" << endl;
		cin >> input;

	}

	void   playerStats() {
		// tamamlanmadý
		cout << endl;
		cout << "========================" << endl;
		cout << endl;
		cout << "Ýsminiz: " + hero.getName() << endl;
		cout << "Saglýk : " + hero.getArmor() << endl;
		cout << "Senin Vurdugun " + hero.getDamege() << endl;
		cout << "Paran: " + hero.getodul() << endl;
		//cout << "zýrh";// buraya inv clþasý oluþtur öyle bak
			//cout << "silkah;
	}
	void  enmeyStast()
	{
		// burasý canvarlarý   degerlerini görecegimiz yer tamamnlandý
		cout << mns.getName() + " degerleri: " << endl;
		cout << endl;
		cout << "========================" << endl;
		cout << endl;
		cout << "Can: " + mns.getHealty() << endl;
		cout << "Hasar: " + mns.getDamage() << endl;
		cout << "Ödül" + mns.getOdul() << endl;
	}

	void afterHit()
		// saldýrdan sonra ne oldugu tamanlandý
	{
		cout << " Karakter ismi:" + hero.getName() << endl;
		cout << " Karakter Hasarý: " + hero.getDamege() << endl;
		cout << "Karakter Saglýkgý : " + hero.getArmor() << endl;
		cout << "Karakter Parasý: " + hero.getodul() << endl;

	}
	bool combat(int mnsCount)
	{
		char input;
		int defMnsHelty = mns.getHealty();
		for (int i = 0; i < mnsCount; i++)
		{
			playerStats();
			enmeyStast();
			while (hero.getArmor() > 0 && mns.getHealty() > 0)
			{
				cout << "<V> vur veya <K> kaç" << endl;
				cin >> input;
				if (input == 'v')
				{
					cout << "Vurdunuz " << endl;
					afterHit();
					if (mns.getHealty() <= 0)
					{

					}

					mns.setHealty(mns.getHealty() - hero.getDamege());
					cout << hero.getName() + " CAný :" << hero.getArmor() << endl;
					cout << endl;
					cout << "Canvar size Vurdu" << endl;
					hero.setARmor(hero.getArmor() - mns.getDamage());
					cout << mns.getName() + " Caný : " << mns.getHealty();
					cout << endl;
				}
				else
				{
					break;
				}
			}
			if (mns.getHealty() < 0 && hero.getArmor() > 0)
			{
				cout << "Tüm Düþümalrý yendiniz" << endl;
				cout << "Hesabýnýza" + mns.getOdul() * mns.MonsterCount() << endl;
				int MoneyGeldi = mns.getOdul() * mns.MonsterCount();


				hero.setodul(MoneyGeldi + hero.getodul());
				cout << "Güncel Para: " + hero.getodul() << endl;
				mns.setHealty(defMnsHelty);

				// Dosyalama iþlmlerini vurada baþlýyorum
				ofstream Myfile("diedMonster.txt");
				Myfile << "Tüm Düþümalrý yendiniz" << endl;
				Myfile << "Hesabýnýza" + mns.getOdul() * mns.MonsterCount() << endl;
				Myfile << "Güncel Para: " + hero.getodul() << endl;
				Myfile << "Öldürdügün Düþman" + mns.getName() << endl;
			}
			else
			{
				break;
			}

		}
		return true;
	}
};
class river : public BattleLoc
{
public:
	river(Hero hero) : BattleLoc(hero, "river", Bear(), "water")
	{
	}
};

class cave : public BattleLoc
{
public:
	cave(Hero hero) : BattleLoc(hero, "Magara", Zombie(), "food")
	{
	}
};

class foerst : public BattleLoc
{
public:
	foerst(Hero hero) : BattleLoc(hero, "Orman", Vampire(), "ateþ cubugu")
	{
	}
};

class item {
public:
	string name;
	int dmg;

	list <item> ::iterator a;


	void listShow(list<item> x)
	{
		list <item> ::iterator a;
		for (a = x.begin(); a != x.end(); ++a)
		{
			cout << a->name << endl;
			cout << a->dmg << endl;
		}
	}
	void add(list <item> r, item* x)
	{
		r.push_back(*x);
	}
};

class ToolStore : public NormLoc {
public:
	// burada linklist ile magazadaki itemleri sýrayalacagýz ve almak istedigi eþyalarý alacak
	ToolStore(Hero hero) : NormLoc(hero, "MAgaza")
	{}
	bool getLocation() {


		return true;
	}

};

class Game
{
public:
	Location location();
	Hero hero();
	void login();
	void start();
};
void Game::start()
{
	while (true)
	{
		cout << endl;
		cout << "=======================" << endl;
		cout << endl;
		cout << "Eylem Gerçeleþtirmek için bir yer þeç" << endl;
		cout << "1->   Güvenli ev <-> Size ait bir ev Düþman yok" << endl;
		cout << "2->   Magara <->  Belki Karþýnýza Zombi Çýkabilir" << endl;
		cout << "3->   Orman <->  Belki Karþýnýza Vampir Çýkabilir" << endl;
		cout << "4->   Nehir <->  Belki Karþýnýza Ayý Çýkabilir" << endl;
		cout << "5->   Maðaza <->  Zýrh ve Silah Satýn Alabilirsiniz" << endl;
	}
}








int main()
{
	setlocale(LC_ALL, "Turkish");
	Hero dnm;
	dnm.karaktersec();
}