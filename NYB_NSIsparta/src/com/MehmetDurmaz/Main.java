package com.MehmetDurmaz;

public class Main {

    public static void main(String[] args) {
        Hasta hastaislemleri ;
        Doktor doktorislmeleri;
        Hasta h1 =new Hasta("admin","non",1);
        Hasta h2 =new Hasta("havva","ilk",00000000002);
        Hasta h3 =new Hasta("adaem","ilk",00000000001);
        Doktor d1 = new Doktor("mehmet","durmaz",010,"01");

        System.out.println(h1.hastaEkle(h2));
        h1.hastaEkle(h3);
        h1.hastaGuncelle(h2);
        h1.listele();
        h1.hasatasil();
        h1.listele();
        d1.tanıGir(h2);

    }
}
