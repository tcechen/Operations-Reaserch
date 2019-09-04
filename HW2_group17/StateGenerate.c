#include "Declare.h"


/*
  本期X受昨日X(1或2)與今日Demand(0~4隨機等機率產生)影響!
  故本演算法跟隨題目公式。
*/

                      //前日X   //今日D
int StateGenerate(int preX, int D){

    int nowX;  //今日X

    switch(preX){
        case 1:
            if(D==0||D==2||D==4){       //Xn-1 =1, 而Dn =0/2/4時，Xn將=1
                nowX=1;
                Total_X1++;
            }
            else if(D==1||D==3){        //Xn-1 =1, 而Dn =1/3時，Xn將=2
                nowX=2;
                Total_X2++;
            }
            else{
                printf("Error: D isn't belongs to 0~4.\n");
            }
            break;

         case 2:                        //Xn-1 =2, 而Dn =1/3時，Xn將=1
            if(D==1||D==3){
                nowX=1;
                Total_X1++;
            }
            else if(D==0||D==2||D==4){  //Xn-1 =1, 而Dn =0/2/4時，Xn將=2
                nowX=2;
                Total_X2++;
            }
            else{
                printf("Error: D isn't belongs to 0~4.\n");
            }
            break;

         default:
            printf("Error: preX isn't belongs to 1,2 \n");
            break;
    }//end switch

    return nowX;
}
