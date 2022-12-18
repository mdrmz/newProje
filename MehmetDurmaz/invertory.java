package com.MehmetDurmaz;

public class invertory {
    private boolean water,food,firewood;
    private String wName,AName;
    private  int damage,armor;
    private  String ARmorName;

    public String getARmorName() {
        return ARmorName;
    }

    public void setARmorName(String ARmorName) {
        this.ARmorName = ARmorName;
    }

    public boolean isWater() {
        return water;
    }

    public void setWater(boolean water) {
        this.water = water;
    }

    public boolean isFood() {
        return food;
    }

    public void setFood(boolean food) {
        this.food = food;
    }

    public boolean isFirewood() {
        return firewood;
    }

    public void setFirewood(boolean firewood) {
        this.firewood = firewood;
    }

    public String getwName() {
        return wName;
    }

    public void setwName(String wName) {
        this.wName = wName;
    }

    public String getAName() {
        return AName;
    }

    public void setAName(String AName) {
        this.AName = AName;
    }

    public int getDamage() {
        return damage;
    }

    public void setDamage(int damage) {
        this.damage = damage;
    }

    public int getArmor() {
        return armor;
    }

    public void setArmor(int armor) {
        this.armor = armor;
    }

    public invertory(){
         this.water=false;
         this.firewood=false;
         this.food=false;
         this.damage=0;
         this.AName=null;
         this.wName=null;



     }

}
