package com.MehmetDurmaz;

import java.util.Date;
import java.util.Random;

public class Recete implements Protokol{

    public Recete() {
    }

    İlaç İlaçlar[] = new İlaç[32];
    Date Zaman = new Date();
    String reçeteno;
    Random rand = new Random();
    public void operations(){

    }

    @Override
    public int getProtokolNo() {
        int random =rand.nextInt(100) +1 ; // 1 ile 100 arasıdnda random sayı üretmek için
        return  random;
    }
}
