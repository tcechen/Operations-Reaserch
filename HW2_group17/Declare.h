#ifndef _DECLARATION_H_
#define _DECLARATION_H_
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define n 10000


typedef struct PERIODS{
    int X;                 //每期X
    int Demand;            //每期Demand
    int PeriodCost;        //每期成本

}PERIODS; //"期"
PERIODS P[n+1];            //共n+1期

int Total_X1;  //累計X=1出現次數
int Total_X2;  //累計X=2出現次數
int TotalCost; //累計總成本

#endif
