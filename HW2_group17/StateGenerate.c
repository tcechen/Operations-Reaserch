#include "Declare.h"


/*
  ����X���Q��X(1��2)�P����Demand(0~4�H�������v����)�v�T!
  �G���t��k���H�D�ؤ����C
*/

                      //�e��X   //����D
int StateGenerate(int preX, int D){

    int nowX;  //����X

    switch(preX){
        case 1:
            if(D==0||D==2||D==4){       //Xn-1 =1, ��Dn =0/2/4�ɡAXn�N=1
                nowX=1;
                Total_X1++;
            }
            else if(D==1||D==3){        //Xn-1 =1, ��Dn =1/3�ɡAXn�N=2
                nowX=2;
                Total_X2++;
            }
            else{
                printf("Error: D isn't belongs to 0~4.\n");
            }
            break;

         case 2:                        //Xn-1 =2, ��Dn =1/3�ɡAXn�N=1
            if(D==1||D==3){
                nowX=1;
                Total_X1++;
            }
            else if(D==0||D==2||D==4){  //Xn-1 =1, ��Dn =0/2/4�ɡAXn�N=2
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
