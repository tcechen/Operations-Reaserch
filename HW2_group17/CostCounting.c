#include "Declare.h"

//ordering cost 3+2m
//holding cost Zn
//shortage cost -4Zn
                     //昨日X   //今日D
int CostCounting(int preX, int D){

    int Total; //今日總cost
    int HC=0;  //holding cost
    int OC=0;  //Ordering cost
    int SC=0;  //Shortage cost
    int m=0; //parameter of OC : 3+2m

    if(preX>D){
        HC=preX-D;           //若昨日剩下X足以應付今日D，僅增加HC
    }
    else if(preX<=D){        //若不足...
        SC=-4*(preX-D);          //計算SC
        m=(preX-D>=-1)? 1:2;     //計算OC
        OC=3+2*m;
    }
    else{
        printf("error: FUNC CC\n");
    }

    Total = HC+OC+SC;
    return Total;

}//end func.

