package com.MehmetDurmaz;

public class SafeHous extends  NormaLOca {
    public SafeHous(com.MehmetDurmaz.player player) {
        super
                (player, "Güvenli ev");
    }

    @Override
    public Boolean getLocation() {
        player.setHealty(player.getrHealty());
        System.out.println("Canınız Doldurldu");
        System.out.println("Canınız: "+player.getHealty());
        System.out.println("Şuan Güvenli evdesiniz");

        return true;
    }
}

