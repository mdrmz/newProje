package com.MehmetDurmaz;

public abstract class Kisi
{

    String ad,soyad;
    long tcKimlikno;

    public String getAd() {
        return ad;
    }

    public void setAd(String ad) {
        this.ad = ad;
    }

    public String getSoyad() {
        return soyad;
    }

    public void setSoyad(String soyad) {
        this.soyad = soyad;
    }

    public long getTcKimlikno() {
        return tcKimlikno;
    }

    public void setTcKimlikno(long tcKimlikno) {
        this.tcKimlikno = tcKimlikno;
    }

    public Kisi(String ad, String soyad, long tcKimlikno) {
        this.ad = ad;
        this.soyad = soyad;
        this.tcKimlikno = tcKimlikno;

    }
}
