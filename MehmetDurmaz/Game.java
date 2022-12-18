package com.MehmetDurmaz;

import java.util.Scanner;

public class Game {
    Scanner md = new Scanner(System.in);
    Location location;
    player player;

    public void login(){

        System.out.println("Devam Etmek İçin İsim Girin");
        String name=md.next();
        player  =new player(name);
        player.selectCha();
        start();
    }

public  void start(){
 while (true){
     System.out.println();
     System.out.println("=======================");
     System.out.println();
     System.out.println("Eylem Gerçeleştirmek için bir yer şeç");
     System.out.println("1->   Güvenli ev <-> Size ait bir ev Düşman yok");
     System.out.println("2->   Magara <->  Belki Karşınıza Zombi Çıkabilir");
     System.out.println("3->   Orman <->  Belki Karşınıza Vampir Çıkabilir");
     System.out.println();
     System.out.println("5->   Mağaza <->  Zırh ve Silah Satın Alabilirsiniz");
     int seLoc=md.nextInt();
     while(seLoc<1||seLoc>5){
         System.out.println("Geçersiz deger Tekrar Gir");
         seLoc=md.nextInt();
     }
     switch (seLoc){
         case 1:{
             location =new SafeHous(player);
             break;
         }
         case 2:{
             location =new Cave(player);
         break;
         }
         case 3:{
             location =new foerst(player);
         break;
         }
         case 4:{
             location =new River(player);
         break;
         }
         case 5:{
             location =new ToolStore(player);
             break;
         }
         default:location=new SafeHous(player);
     }
     location.getLocation();
 }
}
}
