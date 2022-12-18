package com.MehmetDurmaz;

import java.util.Scanner;

public class player {
    private int damage,healty,money,rHealty;
    private String name,cName;
    invertory inv;
Scanner md=new Scanner(System.in);
    public player(String name) {

        this.name = name;
        this.inv=new invertory();
    }
    public void selectCha(){

        switch (chaMenu()){
            case 1:{

                initPlaye("Samuray "+name,5,21,15);
                setDamage(5);
                setHealty(21);
                setMoney(150);
                break;
            }
            case 2:{

                initPlaye("Okçu "+name,7,18,20);
                setDamage(7);
                setHealty(18);
                setMoney(20);
                break;
            }
            case 3:{

                initPlaye("Şövolye "+name,8,24,5);
                setDamage(8);
                setHealty(24);
                setMoney(5);
                break;
            }
            default:
                initPlaye("Samuray "+name,5,21,15);
                setDamage(5);
                setHealty(21);
                setMoney(15);
                break;
        }
        System.out.println();
        System.out.println("=======================");
        System.out.println();
        System.out.println(" Karakter ismi:"+getcName()+
                           "\n" +
                            " Karakter Hasarı: "+getDamage()+
                           "\n Karakter Saglıkgı:"+getHealty()+
                           "\n Karakter Parası: "+getMoney()+
                           "\n Gerçek can: +"+getrHealty());

    }
    public int chaMenu(){
        System.out.println();
        System.out.println("=======================");
        System.out.println();
        System.out.println(name+": Lütfen Bir Karakter Seçin");
        System.out.println("1=Samuray\tDamege=5\tHealty=21\tMoney=150\n" +
                           "2=Okçu    \tDamege=7\tHealty=18\tMoney=20\n" +
                           "3=Şövelye \tDamege=8\tHealty=24\tMoney=5\n");
        System.out.println("Karakter Şeçin" +
                "");
        int chaId=md.nextInt();
        while(chaId<1||chaId>3){
            System.out.println("Geçerli Bir Sayı Girin");
             chaId=md.nextInt();
        }
        return chaId;
    }
    public  void  initPlaye(String cName,int damage,int healty,int money){
        setHealty(healty);
        setMoney(money);
        setDamage(damage);
        setcName(cName);
        setrHealty(healty);
    }

    public int getDamage() {
        return damage;
    }

    public void setDamage(int damage) {
        this.damage = damage;
    }

    public int getHealty() {
        return healty;
    }

    public void setHealty(int healty) {
        this.healty = healty;
    }

    public int getMoney() {
        return money;
    }

    public void setMoney(int money) {
        this.money = money;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getcName() {
        return cName;
    }

    public void setcName(String cName) {
        this.cName = cName;
    }

    public invertory getInv() {
        return inv;
    }

    public int getrHealty() {
        return rHealty;
    }

    public void setrHealty(int rHealty) {
        this.rHealty = rHealty;
    }
    public  int totalDamage(){
        return this.getDamage()+this.getInv().getDamage();
    }
}
