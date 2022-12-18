package com.MehmetDurmaz;

public  abstract class BattleLoc extends  Location {
   private Monster mns;

   protected  String ItemName;
    public BattleLoc(com.MehmetDurmaz.player player,String name,Monster mns,String itemName) {
        super(player);
        this.Name=name;
        this.mns=mns;
        this.ItemName=itemName;


    }
    public Boolean getLocation(){

   int mnsCount=mns.MonsterCount();
        System.out.println("Şu an  Burdasınız  :"+this.getName());
        System.out.println("Dikkatali ol "+mnsCount+" Tane"+mns.getName()+" Yaşıyor!!");
        System.out.println("Şavaş için <s> kullan");
        System.out.print("Kaçmak için <k> kullan");
        String selCase=md.nextLine();
        if(selCase.equalsIgnoreCase("s")){
            if(combat(mnsCount)){
                System.out.println(this.getName()+"  Bölgesindeki  tüm Düşamlar Temizlendi");
                 if(this.ItemName.equalsIgnoreCase("Food")&&player.inv.isFood()==false){
                     System.out.println(this.ItemName+"KAzndınız");
                     player.getInv().setFood(true);
                 }
                 else if(this.ItemName.equalsIgnoreCase("Water")&&player.inv.isWater()==false){
                    System.out.println(this.ItemName+"KAzndınız");
                    player.getInv().setFood(true);
                }
              else   if(this.ItemName.equalsIgnoreCase(" FireWood ")&&player.inv.isFirewood()==false){
                    System.out.println(this.ItemName+"KAzndınız");
                    player.getInv().setFood(true);
                }
            }
            else{
                System.out.println("Öldün");
                return  false;
            }


}
        return true;
    }
    public boolean combat(int MnsCount){
        int defMnsHealtY= mns.getHealty();
   for (int i=0;i<MnsCount;i++){
    playerStats();
    enmeyStats();
      while(player.getHealty()>0 && mns.getHealty()>0){
        System.out.print("<V> vur veya <K> kaç");
        String SelCase= md.nextLine();
     if (SelCase.equalsIgnoreCase("v")){
         System.out.println("Siz Vurdunuz !!");
         afterHit();
         if (mns.getHealty()<=0){

         }
         mns.setHealty(mns.getHealty()-player.totalDamage());
         System.out.println(player.getName()+" Canı :"+player.getHealty());
         System.out.println();
         System.out.println("Canavar size Vurdu");
         player.setHealty(player.getHealty()-(mns.getDamage()-player.inv.getArmor()));
         System.out.println(mns.getName()+" Canı : "+mns.getHealty());
         System.out.println();


     }
     else {
         break;
     }
     }
    if (mns.getHealty()<0 && player.getHealty()>0){

        System.out.println("Tüm Düşümalrı yendiniz");

        System.out.println("Hesabınıza"+ (mns.getOdul()*mns.MonsterCount()) + "kadar  Para Geldi");
          int MoneyGeldi=mns.getOdul()*mns.MonsterCount();
         player.setMoney(MoneyGeldi+player.getMoney());
        System.out.println("Güncel Para: "+player.getMoney());
        mns.setHealty(defMnsHealtY);
    }
    else {
        break;
    }
    }


return true;
    }
public  void afterHit(){
    System.out.println(" Karakter ismi:"+player.getcName()+
            "\n" +
            " Karakter Hasarı: "+player.getDamage()+
            "\n Karakter Saglıkgı:"+player.getHealty()+
            "\n Karakter Parası: "+player.getMoney()
            );

}



    public void   playerStats(){
        System.out.println();
        System.out.println("========================");
        System.out.println();
        System.out.println("İsminiz: "+player.getName());
        System.out.println("Saglık : "+player.getHealty());
        System.out.println("Senin Vurdugun "+player.getDamage());
        System.out.println("Paran: "+player.getHealty());
        System.out.println("Silahın :"+player.inv.getwName());
        System.out.println("Zırhın : "+player.inv.getAName());



    }
    public  void  enmeyStats(){
        System.out.println(mns.getName()+" Değerleri");
        System.out.println();
        System.out.println("========================");
        System.out.println();
        System.out.println("Can: "+mns.getHealty());
        System.out.println("Hasar: "+mns.getDamage());
        System.out.println("Ödül"+mns.getOdul());


    }
}
