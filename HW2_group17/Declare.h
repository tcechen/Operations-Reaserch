#ifndef _DECLARATION_H_
#define _DECLARATION_H_
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define n 10000


typedef struct PERIODS{
    int X;                 //�C��X
    int Demand;            //�C��Demand
    int PeriodCost;        //�C������

}PERIODS; //"��"
PERIODS P[n+1];            //�@n+1��

int Total_X1;  //�֭pX=1�X�{����
int Total_X2;  //�֭pX=2�X�{����
int TotalCost; //�֭p�`����

#endif
