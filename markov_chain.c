#include<stdio.h>
#include<stdlib.h>
#include<time.h>

    double a[5][5]={{0.5,0.2,0.1,0.2},{0.1,0.7,0.1,0.1},{0.1,0.2,0.3,0.4},{0.1,0.2,0.2,0.5}}; //Transition Matrix
    double first_day[5]={0.2,0.4,0.3,0.1}; //�Ĥ@�ѥX�{�Ustate�����v
    int count[5]={0}; //�����Ustate�X�{�`����
    double avg=0; //����"�Ustate�X�{�`����"��"����Ѽ�"���
    int i=0;
    int j=0;
    int type; //�Nstate�H�Ʀr���(0~3)
    int c; //�`�Ѽ�(10000)
    int act; //�����ϥΪ̦��(0,1)


int main(){

    srand(time(NULL)); //random

/*�Ustate�����Ӭݪ�steady-state prob(��by���)*/
    float SSP[4]={0.1667,0.4000,0.1592,0.2741};

/*�Ʀr0~3��ܪ��U�Ostate*/
    printf("State:\n");
    printf("   %-14s => type 0\n","low");
    printf("   %-14s => type 1\n","medium");
    printf("   %-14s => type 2\n","high");
    printf("   %-14s => type 3\n","extremely high");

/*�L�XTransition Matrix*/
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


/*�e�m�@�~*/
    c=10000; //�W�w�@�]10000��
    act=1;

/*�}�l����*/
    while(act==1){

        /*�ШϥΪ̨M�w�U�@�B*/
        printf("\n========================="
               "\nChoose act:\n"
               "1: Start simulating\n" //�}�l����
               "0: leave\n");          //���}�t��
        scanf("%d",&act);
        if(act==0)
            break; //���0-->���}�t��

        for(j=0;j<4;j++){
            count[j]=0;
        }//�M�ŭp�ƾ�


/*************************************************************
    �}�l�̫��w���v�A�v�鲣�ͷ��state
    (�̫��w���v����state���t��k��word�ɤ��Բӻ���)
**************************************************************/

    //�̫��w���v���Ͳ�1�Ѫ�state [0.2,0.4,0.3,0.1]
        int x=rand()%10+1;  //x�i��d��1~10
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


    //�̫��w���v���Ͳ�2~10000�Ѫ�state
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
                printf("error\n");//�ˬd�O�_���~
            }
            count[type]++;  //�p�ƾ�: ��type�ثe�X�{�`��+1


            //�b�S�w�ѼƮɦL�X�έp���G
            if(i==100||i==1000||i==10000){
                printf("\n**%d days later**",i);
                                            //State    �`�@�X�{����   �e������    �z�פ��
                printf("\n%s\t%s\t\t%s\t%s\n","STATE",   "Times",   "Proportion", "Theoretical(steady-state prob.)");
                for(j=0;j<4;j++){
                    avg= (double) count[j]/i;
                    printf("%2d\t%3d\t\t%.5f\t\t%.5f\t\n",j,count[j],avg,SSP[j]);
                }
            }//end if


        }//end for (for generating the state of each day)

    }//end while (for choosing action)

}// end main


