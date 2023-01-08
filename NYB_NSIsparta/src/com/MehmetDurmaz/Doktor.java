package com.MehmetDurmaz;

import java.util.Scanner;

public class Doktor extends  Kisi {
    Scanner md = new Scanner(System.in);
    String sicilNo;
    Hasta hasta;
    Hasta hastayeniKayıt[] = new Hasta[10];
    int HastaCount = 0;

    public Doktor(String ad, String soyad, long tcKimlikno, String sicilNo) {
        super(ad, soyad, tcKimlikno);
        this.sicilNo = sicilNo;
    }

    public long tcBul(Hasta h1) {
        return h1.tcKimlikno;
    }

    public String hastaEkle(Hasta h1) {

        hastayeniKayıt[HastaCount] = h1;
        HastaCount++;
        return "Hasta Eklendi";
    }

    public void tanıGir(Hasta h2){
        System.out.println("tanı gir");
        String tanı = md.next();
        h2.tanisi =tanı;
        System.out.println("Hasta Bulundu");
        System.out.println("Adı : " + h2.ad);
        System.out.println("Soyadı : "+ h2.soyad);
        System.out.println("TC : " + h2.tcKimlikno);
        System.out.println("tanısı " + h2.tanisi);
        hastaEkle(hasta);
    }


    public  Hasta hastaListele(long a)
    {
        if(a == super.tcKimlikno )
        {
            System.out.println("Hasta Bulundu");
            System.out.println("Adı : " + super.ad);
            System.out.println("Soyadı : "+ super.soyad);
            System.out.println("TC : " + super.tcKimlikno);
            System.out.println("tanısı" + hasta.tanisi);
            return hasta;
        }
        else {


            return hasta;
        }
    }
}
