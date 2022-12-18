package com.MehmetDurmaz;

import java.util.Random;
import java.util.RandomAccess;

public class Monster {
    private  String name;
    private  int Damage,healty,odul,maxmonster;

    public Monster(String name, int damage, int healty, int odul, int maxmonster) {
        this.name = name;
        Damage = damage;
        this.healty = healty;
        this.odul = odul;
        this.maxmonster = maxmonster;
    }

public  int MonsterCount(){

    Random rand=new Random();
    int Count= rand.nextInt(this.maxmonster)+1;
    return Count;
}
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getDamage() {
        return Damage;
    }

    public void setDamage(int damage) {
        Damage = damage;
    }

    public int getHealty() {
        return healty;
    }

    public void setHealty(int healty) {
        this.healty = healty;
    }

    public int getOdul() {
        return odul;
    }

    public void setOdul(int odul) {
        this.odul = odul;
    }

    public int getMaxmonster() {
        return maxmonster;
    }

    public void setMaxmonster(int maxmonster) {
        this.maxmonster = maxmonster;
    }
}
