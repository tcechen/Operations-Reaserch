#include "Declare.h"

void AfterPeriodsOf(int N){

/*�@����10000��*/
    Total_X1=0;
    Total_X2=0;
    int c=1;
    while(c<=N){

    /*�C�骬�p�����L�{*/

                         //(����D)��0~4�Ʀr�����v�H���X�{
        P[c].Demand     = rand()%5;

                         //pass(�Q��ѤU��X)�P(����D) to �ಣ��(����X)���禡�A�^��(����X)
        P[c].X          = StateGenerate(P[c-1].X, P[c].Demand);

                         //pass(�Q��ѤU��X)�P(����D) to ��p�⤵���`cost���禡�A�^��(����Cost)
        P[c].PeriodCost = CostCounting(P[c-1].X, P[c].Demand);


        TotalCost = TotalCost+ P[c].PeriodCost; //�ܤ��֭p�`��O


        /*�{�S�w�ѼƮɦL�X*/
        if(c==100||c==1000){
            printf("\n----------------------------------------\n");
            printf("        After %5d periods                  \n",c);
            printf("----------------------------------------\n");
            printf("\t%s\t  %s\t\t\n","Appeared times","Proportion");
            printf("%s\t%7d\t%15.2f\t\t\n","X=1",Total_X1,(float)Total_X1/c);
            printf("%s\t%7d\t%15.2f\t\t\n","X=2",Total_X2,(float)Total_X2/c);
            printf("\n#Actual average total cost = %.3f\n",(float)TotalCost/c);
        }
        if(c==10000){
            printf("\n----------------------------------------\t  -----------------------\n");
            printf("        After %5d periods                             Theoretical      \n",c);
            printf("----------------------------------------\t  -----------------------\n");
            printf("\t%s\t  %s\t\t   %s\n","Appeared times","Proportion","#Steady-state prob.");
            printf("%s\t%7d\t%15.2f\t\t   %15.2f\n","X=1",Total_X1,(float)Total_X1/c,0.5);
            printf("%s\t%7d\t%15.2f\t\t   %15.2f\n","X=2",Total_X2,(float)Total_X2/c,0.5);
            printf("\n#Actual average total cost = %.3f",(float)TotalCost/c);
            printf("\t\t   #Expected average total cost = %.3f\n\n",8.1);
        }//end printing

        c++;
    }//end while
}//end FUNC.
