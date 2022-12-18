package com.MehmetDurmaz;

import java.util.Scanner;

public  abstract class Location {
    Scanner md=new Scanner(System.in);

     protected player player;
    protected  String Name;

    Location(player player){

        this.player=player;
    }
public abstract  Boolean getLocation();

    public com.MehmetDurmaz.player getPlayer() {
        return player;
    }

    public void setPlayer(com.MehmetDurmaz.player player) {
        this.player = player;
    }

    public String getName() {
        return Name;
    }

    public void setName(String name) {
        Name = name;
    }
}
