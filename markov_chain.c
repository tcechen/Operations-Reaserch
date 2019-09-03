#include<stdio.h>
#include<stdlib.h>
#include<time.h>

    double a[5][5]={{0.5,0.2,0.1,0.2},{0.1,0.7,0.1,0.1},{0.1,0.2,0.3,0.4},{0.1,0.2,0.2,0.5}}; //Transition Matrix
    double first_day[5]={0.2,0.4,0.3,0.1}; //第一天出現各state的機率
    int count[5]={0}; //紀錄各state出現總次數
    double avg=0; //紀錄"各state出現總次數"佔"整體天數"比例
    int i=0;
    int j=0;
    int type; //將state以數字表示(0~3)
    int c; //總天數(10000)
    int act; //紀錄使用者行動(0,1)


int main(){

    srand(time(NULL)); //random

/*各state長遠來看的steady-state prob(值by手算)*/
    float SSP[4]={0.1667,0.4000,0.1592,0.2741};

/*數字0~3表示的各別state*/
    printf("State:\n");
    printf("   %-14s => type 0\n","low");
    printf("   %-14s => type 1\n","medium");
    printf("   %-14s => type 2\n","high");
    printf("   %-14s => type 3\n","extremely high");

/*印出Transition Matrix*/
    printf("\nTransition Matrix:\n");
    printf("    \t%2d\t%2d\t%2d\t%2d\n",0,1,2,3);
    for(i=0;i<4;i++){
        printf("   %d\t",i);
        for(j=0;j<4;j++){
            printf("%.1f\t",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");


/*前置作業*/
    c=10000; //規定共跑10000天
    act=1;

/*開始模擬*/
    while(act==1){

        /*請使用者決定下一步*/
        printf("\n========================="
               "\nChoose act:\n"
               "1: Start simulating\n" //開始模擬
               "0: leave\n");          //離開系統
        scanf("%d",&act);
        if(act==0)
            break; //選擇0-->離開系統

        for(j=0;j<4;j++){
            count[j]=0;
        }//清空計數器


/*************************************************************
    開始依指定機率，逐日產生當日state
    (依指定機率產生state的演算法於word檔中詳細說明)
**************************************************************/

    //依指定機率產生第1天的state [0.2,0.4,0.3,0.1]
        int x=rand()%10+1;  //x可能範圍1~10
        if(x==1||x==2){
            type=0;
        }
        else if(x==3||x==4||x==5||x==6){
            type=1;
        }
        else if(x==7||x==8||x==9){
            type=2;
        }
        else{
            type=3;
        }
        count[type]++;

        printf("\n**Day 1**\n");
        printf("%s %d\t%s %d\t\n","rand value:",x,"STATE:",type);


    //依指定機率產生第2~10000天的state
        for(i=0;i<c+1;i++){
            x=rand()%10+1;

            if(type==0){
               if(x>=1&&x<=5){
                    type=0;
               }
               else if(x>=6&&x<=7){
                    type=1;
               }
               else if(x==8){
                    type=2;
               }
               else{
                    type=3;
               }
            }
            else if(type==1){
               if(x==1){
                    type=0;
               }
               else if(x>=2&&x<=8){
                    type=1;
               }
               else if(x==9){
                    type=2;
               }
               else{
                    type=3;
               }
            }
            else if(type==2){
               if(x==1){
                    type=0;
               }
               else if(x>=2&&x<=3){
                    type=1;
               }
               else if(x>=4&&x<=6){
                    type=2;
               }
               else{
                    type=3;
               }
            }
            else if(type==3){
                if(x==1){
                    type=0;
               }
               else if(x>=2&&x<=3){
                    type=1;
               }
               else if(x>=4&&x<=5){
                    type=2;
               }
               else{
                    type=3;
               }
            }
            else{
                printf("error\n");//檢查是否有誤
            }
            count[type]++;  //計數器: 該type目前出現總數+1


            //在特定天數時印出統計結果
            if(i==100||i==1000||i==10000){
                printf("\n**%d days later**",i);
                                            //State    總共出現次數   占整體比例    理論比例
                printf("\n%s\t%s\t\t%s\t%s\n","STATE",   "Times",   "Proportion", "Theoretical(steady-state prob.)");
                for(j=0;j<4;j++){
                    avg= (double) count[j]/i;
                    printf("%2d\t%3d\t\t%.5f\t\t%.5f\t\n",j,count[j],avg,SSP[j]);
                }
            }//end if


        }//end for (for generating the state of each day)

    }//end while (for choosing action)

}// end main


