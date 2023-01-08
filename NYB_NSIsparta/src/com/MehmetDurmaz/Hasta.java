package com.MehmetDurmaz;

import jdk.swing.interop.SwingInterOpUtils;

import java.util.Random;
import java.util.Scanner;

public class Hasta extends Kisi  implements  Protokol{
    Scanner ipt = new Scanner(System.in);
    Random rand = new Random();

     String tanisi;
     Hasta  hastaKayıt[] = new Hasta[10]; // En Fazla 1500 Hasta KAyıt Edebirisiniz
    public int HastaCount = 0; // Bude bizim Hastaya Kayıt içşn degeri Veriyor Methodun içinde artıyorum zaten

    public Hasta(String ad, String soyad, long tcKimlikno) {
        super(ad, soyad, tcKimlikno);
    }


    public String hastaEkle(Hasta h1){

        hastaKayıt[HastaCount] = h1;
        HastaCount++;
    return "Hasta Eklendi";
}
public String hastaGuncelle(Hasta h1)
{
    for(int i = 0; i<hastaKayıt.length -1; i++)
    {
        if(h1 == hastaKayıt[i])
        {
            System.out.println("Neyi Güncellemk İstiyorsunuz");
            System.out.println("1. İsim\n2.Soyisim\n3.TCKN");
            int input = ipt.nextInt();
            switch (input)
            {
                case 1:
                {
                    System.out.println("Degiştimek istediginiz isim nedir girin");
                    String setName = ipt.next();
                    h1.setAd(setName);
                    break;
                }
                case 2:
                {
                    System.out.println("Degiştimek istediginiz Soyisim nedir girin");
                    String setSurName = ipt.next();
                    h1.setSoyad(setSurName);
                    break;
                }
                case 3:
                {
                    System.out.println("Degiştimek istediginiz TCKN nedir girin");
                     long setTCKN=ipt.nextLong();
                     h1.setTcKimlikno(setTCKN);
                     break;
                }
                default:
                    System.out.println("TEkrar Deneyiniz");
            }
        }
    }
    return "Hasta Güncellendi";
}

public void listele()
{
    for(int i = 0; i  < hastaKayıt.length -1 ; i++)
    {
        try {
            System.out.println( "adı : " + hastaKayıt[i].ad);
            System.out.println("soyad  :" + hastaKayıt[i].soyad);
            System.out.println("tc :"+hastaKayıt[i].tcKimlikno);
            System.out.println("tanısı : "+hastaKayıt[i].tanisi);
        }
        catch (Exception e)
        {
            System.out.println("Hasta yok Çünkü Daha eklenmedi");
        }

    }

}
public void hasatasil()
{
    System.out.println("silmek istediginiz hastanın tc sini yazın");
    long x =ipt.nextLong();
    try{
    for(int i = 0;  i < hastaKayıt.length -1 ; i++)
    {
        if(hastaKayıt[i].tcKimlikno == x)
        {


                hastaKayıt[i] = null;

        }
    }
    }catch (Exception e)
    {
        System.out.println("silindi");
    }

}
    @Override
    public int getProtokolNo() {
        int random =rand.nextInt(100) +1 ; // 1 ile 100 arasıdnda random sayı üretmek için
        return  random;
    }

    public String getTanisi() {
        return tanisi;
    }

    public void setTanisi(String tanisi) {
        this.tanisi = tanisi;
    }
}
