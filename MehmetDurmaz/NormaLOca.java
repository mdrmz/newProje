package com.MehmetDurmaz;

public abstract class NormaLOca extends Location{
    public NormaLOca(com.MehmetDurmaz.player player,String name) {
        super(player);
        this.Name=name;
    }

    @Override
    public  Boolean getLocation() {
        return true;
    }



}
