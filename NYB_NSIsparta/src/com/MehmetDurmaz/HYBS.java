package com.MehmetDurmaz;

public class HYBS extends Recete {
    Recete onaylıReceterler[] = new Recete[100];

    boolean dentele(Recete r1)
    {
        for(int i = 0; i <onaylıReceterler.length -1 ; i++)
        {
            if(onaylıReceterler[i] == r1)
            {
                return true;
            }



        }
      return false ;
    }


}
