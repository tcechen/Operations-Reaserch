#include "Declare.h"

//ordering cost 3+2m
//holding cost Zn
//shortage cost -4Zn
                     //�Q��X   //����D
int CostCounting(int preX, int D){

    int Total; //�����`cost
    int HC=0;  //holding cost
    int OC=0;  //Ordering cost
    int SC=0;  //Shortage cost
    int m=0; //parameter of OC : 3+2m

    if(preX>D){
        HC=preX-D;           //�Y�Q��ѤUX���H���I����D�A�ȼW�[HC
    }
    else if(preX<=D){        //�Y����...
        SC=-4*(preX-D);          //�p��SC
        m=(preX-D>=-1)? 1:2;     //�p��OC
        OC=3+2*m;
    }
    else{
        printf("error: FUNC CC\n");
    }

    Total = HC+OC+SC;
    return Total;

}//end func.

