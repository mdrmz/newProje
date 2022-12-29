package com.MehmetDurmaz;

public class Doktor extends  Kisi{
    String sicilNo;
     Hasta hasta;

    public Doktor(String ad, String soyad, long tcKimlikno, String sicilNo) {
        super(ad, soyad, tcKimlikno);
        this.sicilNo = sicilNo;
    }

    public long tcBul(Hasta h1)
    {
        return h1.tcKimlikno;
    }



    public  Hasta hastaListele(long a)
    {
        if(a == super.tcKimlikno )
        {
            System.out.println("Hasta Bulundu");
            System.out.println("Adı : " + super.ad);
            System.out.println("Soyadı : "+ super.soyad);
            System.out.println("TC : " + super.tcKimlikno);
            return hasta;
        }
        else {
            return null;
        }
    }
}
