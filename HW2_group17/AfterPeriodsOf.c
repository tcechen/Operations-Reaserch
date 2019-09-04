#include "Declare.h"

void AfterPeriodsOf(int N){

/*共模擬10000天*/
    Total_X1=0;
    Total_X2=0;
    int c=1;
    while(c<=N){

    /*每日狀況模擬過程*/

                         //(今日D)為0~4數字等機率隨機出現
        P[c].Demand     = rand()%5;

                         //pass(昨日剩下的X)與(今日D) to 能產生(今日X)的函式，回傳(今日X)
        P[c].X          = StateGenerate(P[c-1].X, P[c].Demand);

                         //pass(昨日剩下的X)與(今日D) to 能計算今日總cost的函式，回傳(今日Cost)
        P[c].PeriodCost = CostCounting(P[c-1].X, P[c].Demand);


        TotalCost = TotalCost+ P[c].PeriodCost; //至今累計總花費


        /*逢特定天數時印出*/
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
