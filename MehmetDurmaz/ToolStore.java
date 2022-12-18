package com.MehmetDurmaz;

public class ToolStore extends NormaLOca {

    public ToolStore(com.MehmetDurmaz.player player) {
        super(player, "  magaza");

    }

    public Boolean getLocation() {
        System.out.println("Para: " + player.getMoney());
        System.out.println();
        System.out.println("=======================");
        System.out.println();
        System.out.println("1: Silahlar\n2:Zırhlar\n3:Çıkış");
        System.out.print("Seçimiz: ");
        int sellto = md.nextInt();
        int sellItemID;
        int sellArmId;
        switch (sellto) {
            case 1: {
                sellItemID = weaponMenu();
                buyWeapon(sellItemID);
                break;
            }
            case 2: {
                sellArmId = arMenu();
                buyArm(sellArmId);
                break;

            }
            case 3: {
                break;
            }
            default:
                break;
        }
        return true;
    }

    public void buyArm(int ArmID) {
        int damegeLower = 0, price = 0;
        String aName = null;
        switch (ArmID) {
            case 1: {
                damegeLower = 2;
                price = 20;
                aName = "Çelik yelek";
                break;
            }
            case 2: {
                damegeLower = 1;
                price = 15;
                aName = "Kask";
                break;
            }
            case 3: {
                damegeLower = 4;
                price = 45;
                aName = "Adrenalin İgnesi";
                break;
            }
            default: {
                System.out.println("Geçeresiz İşlem");
            }
        }
        if (player.getMoney() > price) {
            player.setHealty(damegeLower + player.getHealty());
            player.getInv().setwName(aName);
            player.setMoney(player.getMoney() - price);
            System.out.println();
            System.out.println("=======================");
            System.out.println();
            System.out.println(" Karakter ismi:"+player.getcName()+
                    "\n" +
                    " Karakter Hasarı: "+player.getDamage()+
                    "\n Karakter Saglıkgı:"+player.getHealty()+
                    "\n Karakter Parası: "+player.getMoney());
            System.out.println(" Seçilen Zırh: " + player.inv.getARmorName() + "\t  Şimdiki Dayanıklık : +" + player.getHealty());
            System.out.println(" Kalan Para:" + player.getMoney());
        }
        else {
            System.out.println("Para yok");
        }

        }
        public int arMenu () {
          System.out.println();
            System.out.println("=======================");
            System.out.println();
            System.out.println("1.Çelik yelek\t <Hasardan Düşen :2\t Para:20>");
            System.out.println("2.Kask\t <Hasardan Düşen:1\t Para:15>");
            System.out.println("3.Adrenalin İgnesi\t <Hasardan Düşen :4\t Para:45>");
            System.out.println("4.Çıkıs");

            int sellArmory = md.nextInt();
            if (sellArmory==1){
            player.inv.setARmorName("Çelik yelek");
            }
            else if (sellArmory==2) {
                player.inv.setARmorName("Kask");
            }
            else if (sellArmory==3){
                player.inv.setARmorName("Adrenalin İgnesi");
            }
            else {

            }


            return sellArmory;
        }
        public int weaponMenu () {
            System.out.println();
            System.out.println("=======================");
            System.out.println();
            System.out.println("1.Tabanca\t <Hasar:2\t Para:25>");
            System.out.println("2.Kılıç\t <Hasar:3\t Para:35>");
            System.out.println("3.Tüfek\t <Hasar:7\t Para:45>");
            System.out.println("4.Çıkıs");
            System.out.print("Silah Şecin: ");
            int sellWeapon = md.nextInt();
            return sellWeapon;

        }
        public void buyWeapon ( int itemID){
            int damege = 0, price = 0;
            String wName = null;
            switch (itemID) {
                case 1: {
                    damege = 2;
                    price = 25;
                    wName = "Tabanca";

                    break;
                }
                case 2: {
                    damege = 3;
                    price = 35;
                    wName = "Kılıç";

                    break;
                }
                case 3: {
                    damege = 7;
                    price = 45;
                    wName = "Tüfek";

                    break;
                }
                default:
                    System.out.println("Geçersiz İşlem");
                    break;
            }
            if (player.getMoney() > price) {
                player.setDamage(damege + player.getDamage());
                player.getInv().setwName(wName);
                player.setMoney(player.getMoney() - price);
                System.out.println();
                System.out.println("=======================");
                System.out.println();
                System.out.println(" Karakter ismi:"+player.getcName()+
                        "\n" +
                        " Karakter Hasarı: "+player.getDamage()+
                        "\n Karakter Saglıkgı:"+player.getHealty()+
                        "\n Karakter Parası: "+player.getMoney());
                System.out.println("Seçilen silah: " + wName + "  Şimdiki Hasar: " + player.getDamage());
                System.out.println("Kalan Para:" + player.getMoney());
            } else {
                System.out.println("Para yok");
            }
        }


    }





