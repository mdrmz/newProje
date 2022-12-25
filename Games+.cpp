#include <iostream>
#include <locale>
#include <string>
#include <fstream>
#include <iterator>


using namespace std;

class inventory {
private:
     bool water, food, firewood;
    string weaponName, armorName;
     int damage, armor;
public:
    inventory() {
        this->water = false;
        this->food = false;
        this->firewood = false;
        this->damage = 0;
        this->armor = 0;
        this->weaponName;
        this->armorName;

    }

     bool isWater() {
        return water;
    }

    void setWater(bool water) {
        this->water = water;
    }

   bool isFood() {
        return food;
    }

     void setFood(bool food) {
        this->food = food;
    }

    bool isFirewood() {
        return firewood;
    }

     void setFirewood(bool firewood) {
        this->firewood = firewood;
    }

     string getWeaponName() {
        return weaponName;
    }

     void setWeaponName(string weaponName) {
        this->weaponName = weaponName;
    }

    string getArmorName() {
        return armorName;
    }

     void setArmorName(string armorName) {
        this->armorName = armorName;
    }

    int getDamage() {
        return damage;
    }

  void setDamage(int damage) {
        this->damage = damage;
    }

    int getArmor() {
        return armor;
    }
 void setArmor(int armor) {
        this->armor = armor;
    }
};


class player
{
private:
    int damage;
    int health;
    int money;
    int rHealth;
    string name, charName;
public:
    inventory *inv;
    player() {}
    player(string name) {
        inv = new inventory();
        this->name = name;
    }
    int getDamage() {
        return damage;
    }
    void setDamage(int damage) {
        this->damage = damage;
    }
    int getHealth() {
        return health;
    }
    void setHealth(int health) {
        this->health = health;
    }

    int getMoney() {
        return money;
    }

    void setMoney(int money) {
        this->money = money;
    }
    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    string getCharName() {
        return charName;
    }

    void setCharName(string charName) {
        this->charName = charName;
    }

    inventory getInv() {
        return *inv;
    }

   /* void setInv(inventory* inv) {
        this->inv = *inv;
    }
    */
    int getrHealth() {
        return rHealth;
    }

    void setrHealth(int rHealth) {
        this->rHealth = rHealth;
    }
    int gettotalDamage() {

        return this->getDamage() + this->getInv().getDamage();
    }

    void initChar(string charName, int dmg, int hlth, int mny) {
        setCharName(charName);
        setDamage(dmg);
        setHealth(hlth);
        setMoney(mny);
        setrHealth(hlth);

    }
    int charMenu() {

        cout <<"Lütfen bir karakter seçiniz: ";
        cout << endl;
        cout << "1- Samuray \t Hasar: 5 \t Sağlık: 21 \t Para: 15 ";
        cout << "2- Okçu \t Hasar: 7 \t Sağlık: 18 \t Para: 20";
        cout << "3- Şövalye \t Hasar: 8 \t Sağlık: 24 \t Para: 5";

        int charSelect;
        cin >> charSelect;
       cout << "Seçiminiz: " + charSelect;

        while (charSelect < 1 || charSelect > 3) {

            cout <<"Hatalı giriş yaptınız. Tekrar giriniz: ";
            cin >> charSelect;


        }
        return charSelect;
    }
    void selectChar() {


        switch (charMenu()) {

        case 1:

            initChar("Samuray", 4, 18, 15);//21 dmg 5

            break;

        case 2:

            initChar("Okçu", 6, 15, 20);//18 dmg 7

            break;

        case 3:

            initChar("Şövalye", 7, 21, 5);//24dmg 8

            break;

        default:

            setCharName("Samuray");

            break;

        }
    }
   
}; 
class location
{
protected:
    player plyr;
    string name;
public:

    location(player player) {
        this->plyr = player;
    }
    virtual bool getLocation();

    void setPlayer(player player) {
        this->plyr = player;
    }
    player getPlayer() {
        return plyr;
    }
    string getName() {
        return name;
    }
    void setName(string name) {
        this->name = name;
    }
};

class normalLoc : public location {
public:
    normalLoc(player plyr, string name) : location(plyr)
    {
        this->name = name;
    }
    bool getLocation()
    {
        return true;
    }
};

class safeHouse : public normalLoc
{
public:
    safeHouse(player plyr) : normalLoc(plyr,"Güvenli ev") {
       
    }
    bool getLocation()
    {
        plyr.setHealth(plyr.getrHealth());
        cout << "Canınız Yenilendi";
        return true;
    }
  
};
class toolStore : public normalLoc
{
public : 
    toolStore(player plyr): normalLoc(plyr,"Magaza") {
       
    }
    int armorMenu() {
       cout << "Zırh seçiniz: " << endl;
       cout << "1- Hafif Zırh\t Engellenen Hasar: 1\t Fiyat: 15" <<endl;
       cout << "2- Orta Zırh\t Engellenen Hasar: 3\t Fiyat: 25"<< endl;
       cout << "3- Ağır Zırh\t Engellenen Hasar: 5\t Fiyat: 40" << endl;
       cout << "4- Çıkış" << endl;
       int selArmorID;
       cin >> selArmorID;
       return selArmorID;

    }
    void buyArmor(int itemID) {

        int avoid = 0, price = 0;
        string aName;
        switch (itemID) {
        case 1:
            avoid = 1;
            aName = "Hafif Zırh";
            price = 15;
            break;

        case 2:
            avoid = 3;
            aName = "Orta Zırh";
            price = 25;
            break;

        case 3:
            avoid = 5;
            aName = "Ağır Zırh";
            price = 40;
            break;

        case 4:
            break;
        default:
            cout << "Geçersiz seçim!" << endl;
            break;
            if (price > 0) {
                if (plyr.getMoney() >= price) {
                    plyr.getInv().setArmor(avoid);
                    plyr.getInv().setArmorName(aName);
                    plyr.setMoney(plyr.getMoney() - price);
                   cout << aName + " satın aldınız!\nEngellenen Hasar: "  <<  plyr.getInv().getArmor();
                   cout <<"Paranız: " + plyr.getMoney() << endl;
                }
                else {
                    cout << "Yeterli paranız yok!" << endl;
                }
            }
        }
    }
    int weaponMenu() {
        cout << "Silah seçiniz: " << endl;
        cout << "1- Tabanca\t Hasar: 2\t Fiyat: 25" << endl;
        cout << "2- Kılıç\t Hasar: 3\t Fiyat: 35" << endl;
        cout << "3- Tüfek\t Hasar: 7\t Fiyat: 45" << endl;
        cout << "4- Çıkış" << endl;
        int selWeaponID;
        cin >> selWeaponID;
        return selWeaponID;
    }
    void buyWeapon(int itemID) {

        int damage = 0, price = 0;
        string wName;
        switch (itemID) {
        case 1:
            damage = 2;
            wName = "Tabanca";
            price = 25;
            break;

        case 2:
            damage = 3;
            wName = "Kılıç";
            price = 35;
            break;

        case 3:
            damage = 7;
            wName = "Tüfek";
            price = 45;
            break;

        case 4:
            break;
        default:
            cout << "Geçersiz seçim!" << endl;
            break;
            if (price > 0) {
                if (plyr.getMoney() >= price) {
                    plyr.getInv().setDamage(damage);
                    plyr.getInv().setWeaponName(wName);
                    plyr.setMoney(plyr.getMoney() - price);
                    cout << wName + " satın aldınız!\nEski Hasar: " << plyr.getDamage() << "\tYeni Hasar: " << plyr.gettotalDamage();

                    cout << "Paranız: " + plyr.getMoney() << endl;
                }
                else {
                    cout << "Yeterli paranız yok!" << endl;
                }
            }
        }
    }

    bool getLocation()
    {
        cout << "paranız : " << plyr.getMoney() << endl;
        cout << "1- Silah" << endl;
        cout << "2- Zırh" << endl;
        cout << "3- Çıkış" << endl;
        int selectTool;
        int selectItemID;
        cin >> selectTool;

        switch (selectTool) {

        case 1:
            selectItemID = weaponMenu();
            buyWeapon(selectItemID);
            break;

        case 2:
            selectItemID = armorMenu();
            buyArmor(selectItemID);

        }
        return true;


    }
};
class  obstacle {
private:
    string name;
    int damage, health, award, maxNumber;
public:
    obstacle() {}
    obstacle(string name, int damage, int health, int award, int maxNumber) {
        this->name = name;
        this->damage = damage;
        this->health = health;
        this->award = award;
        this->maxNumber = maxNumber;
    }
    int MonsterCount()
    {
        int count;
        // Bu fonkisiyonun amc� Bize Kar��m�za KA� adet D��man ��kart�cak RAnd�m SAy� �reticek
        int enFazla = 3, enAz = 1;

        for (int i = 0; i < 3; i++) {
            count = rand() % (enFazla - enAz + 1) + enAz;
        }
        return count;
    }
    string getName() {
        return name;
    }

     void setName(string name) {
        this->name = name;
    }
     int getDamage() {
         return damage;
     }
     void setDamage(int damage) {
         this->damage = damage;
     }
     int getHealth() {
         return health;
     }
     void setHealth(int health) {
         this->health = health;
     }
     int getAward() {
         return award;
     }
     void setAward(int award) {
         this->award = award;
     }
     int getMaxNumber() {
         return maxNumber;
     }
     void setMaxNumber(int maxNumber) {
         this->maxNumber = maxNumber;
     }
};

class zombie : public obstacle
{
public : 
    zombie() : obstacle("Zombi",3,10,4,3)
    {}
};

class bear : public obstacle
{
public:
    bear() : obstacle("Ayı", 7, 20, 12, 2)
    {}
};

class vampire : public obstacle
{
public:
    vampire() : obstacle("Vampir", 7, 20, 12, 2)
    {}
};

class battleLoc : public location
{
protected:
    obstacle mns;
    string award;
public:
    battleLoc(player plyr, string name, obstacle mns, string award) :location(plyr)
    {
      
        this->mns = mns;
        this->name = name;
        this->award = award;
    }
   
    void afterHit() {

        cout << "Düşman Sağlığı: "  << mns.getHealth() << endl;
        cout << endl;
        cout << "Oyuncu Sağlığı: "  << plyr.getHealth() << endl;
       cout << "=======================================" << endl;

    }
    void playerStats() {
        cout << "Oyuncu Değerleri: \n===================================" << endl;
        cout << "Sağlık: " + plyr.getHealth() << endl;
        cout << "Hasar: "  <<  plyr.gettotalDamage() << endl;
        cout << "Para: " + plyr.getMoney() << endl;

        if (plyr.getInv().getDamage() > 0) {
            cout << "Silah: " + plyr.getInv().getWeaponName()  << endl;
        }
        if (plyr.getInv().getArmor() > 0) {
            cout << "Zırh: " + plyr.getInv().getArmorName() << endl;
        }
    }
     void enemyStats() {
         cout << endl;
        cout << mns.getName() + " Değerleri: \n===================================" << endl;
        cout << "Sağlık: "  << mns.getHealth() << endl;
        cout << "Hasar: "  <<  mns.getDamage() << endl;
        cout << "Ödül: "  <<  mns.getAward() << endl;
    }

     bool combat(int obsCount) {
         int defObsHealth = mns.getHealth();

         for (int i = 0; i < obsCount;i++) {
             playerStats();
             enemyStats();
             while (plyr.getHealth() > 0 && mns.getHealth() > 0) {
                 cout << "<V>ur ya da <K>aç!" << endl;
                 string selectCase;
                 cin >> selectCase;
                 if (selectCase._Equal("V")) {
                     cout << "Düşmana vurdunuz!" << endl;
                     mns.setHealth(mns.getHealth() - plyr.gettotalDamage());
                     afterHit();
                     if (mns.getHealth() > 0) {
                         cout << endl;
                         cout << mns.getName() <<  " size vurdu!" << endl;
                         plyr.setHealth(plyr.getHealth() - (mns.getDamage() - plyr.getInv().getArmor()));
                         afterHit();
                     }
                 }
                 else {
                     return false;
                 }


             }


             if (mns.getHealth() < plyr.getHealth()) {
                 cout << "Düşmanı yendiniz!" << endl;
                 plyr.setMoney(plyr.getMoney() + mns.getAward());
                 cout << "Güncel Paranız: "  <<  plyr.getMoney() << endl;
                 mns.setHealth(defObsHealth);
             }
             else {
                 return false;
             }
            cout <<"==========================" << endl;


         }
         return true;
     }
     bool getLocation()
     {
         int obsCount = mns.MonsterCount();
         cout << "Şuan buradasınız: " + this->getName() << endl;
         cout << "Dikkatli ol! Burada " << obsCount << " tane " << mns.getName() << " var!" << endl;
         cout << "<S>avaş ya da <K>aç!" << endl;
         string selectCase;
         cin >> selectCase;
         if (selectCase._Equal("s"))
         {
             if (combat(obsCount))
             {
                cout << this->getName()  <<  " bölgesindeki tüm düşmanları öldürdünüz!" << endl;
                 if (this->award._Equal("Food") && plyr.getInv().isFood() == false) {
                     cout << this->award  <<  " kazandınız!" << endl;
                     plyr.getInv().setFood(true);
                 }
                 else if (this->award._Equal("Firewood") && plyr.getInv().isFirewood() == false) {
                     cout << this->award  <<  " kazandınız!"<< endl;
                     plyr.getInv().setFirewood(true);
                 }
                 else if (this->award._Equal("Water") && plyr.getInv().isWater() == false) {
                     cout << this->award + " kazandınız!" << endl;
                     plyr.getInv().setWater(true);
                 }
                 return true;

             }
             if (plyr.getHealth() <= 0) {
                 cout << "Öldünüz!" << endl;
                 return false;
             }
         }
         return true;
     }
};

class cave : public battleLoc
{
public:
    cave(player plyr) : battleLoc(plyr, "Mağara", zombie(), "Food")
    {
    }
};

class river : public battleLoc
{
public:
    river(player plyr) : battleLoc(plyr, "Nehir", bear(), "Water")
    {
    }
};

class forest : public battleLoc
{
public:
    forest(player plyr) : battleLoc(plyr, "Nehir", vampire(), "Water")
    {
    }
};


class game {
public:
    player plyr;
    location lc;
    void start() {
        while (true) {
            cout << endl;
            cout << "==================================================="<< endl;
            cout << endl;
            cout << "Gitmek istediğiniz mekanı seçiniz: " << endl;
            cout << "1- Güvenli Ev ---> Düşman yok, canınız yenilenir!" << endl;
            cout << "2- Mağara ---> Karşınıza zombi çıkabilir!" << endl;
            cout << "3- Orman ---> Karşınıza vampir çıkabilir!" << endl;
            cout << "4- Nehir ---> Karşınıza ayı çıkabilir!" << endl;
            cout << "5- Mağaza ---> Silah veya zırh alabilirsiniz!" << endl;

            int selectLoc;
            cin >> selectLoc;
            while (selectLoc < 0 || selectLoc>5) {
                cout << "Lütfen geçerli bir mekan seçiniz!" << endl;
                cin >> selectLoc;
            }

            switch (selectLoc) {

            case 1:
                location = new safeHouse(plyr);
                break;
            case 2:
                location = new cave(plyr);
                break;
            case 3:
                location = new forest(plyr);
                break;
            case 4:
                location = new river(plyr);
                break;
            case 5:
                location = new toolStore(plyr);
                break;
            default:
                location = new safeHouse(plyr);

            }
            if (lc.getName()._Equal("safeHouse")) {
                if (plyr.getInv().isWater() && plyr.getInv().isFirewood() && plyr.getInv().isFood()) {
                    cout << "Tebrikler! Oyunu Kazandınız!" << endl;
                    break;
                }
            }
            if (!lc.getLocation()) {
                cout << "Oyun Bitti!" << endl;
                break;
            }


        }
    }
};

