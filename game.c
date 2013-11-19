#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct player
{
        int  number[13];
        char card[13][3];
};

void get_number(int a[13][4]);
void arrange(int a[13]);
void get_card(struct player *A);

int main()
{
        int i, j, a[13][4];
        struct player A, B, C, D;

        memset(&A, 0, sizeof(struct player));
        memset(&B, 0, sizeof(struct player));
        memset(&C, 0, sizeof(struct player));
        memset(&D, 0, sizeof(struct player));

        get_number(a);

        for(i=0; i<13; i++)
        {
                A.number[i]=a[i][0];
                B.number[i]=a[i][1];
                C.number[i]=a[i][2];
                D.number[i]=a[i][3];
                printf("%d, %d, %d, %d\n", A.number[i], B.number[i], C.number[i], D.number[i]);
        }
        printf("\n");

        arrange(A.number);
        arrange(B.number);
        arrange(C.number);
        arrange(D.number);

        for(i=0; i<13; i++)
        {
                printf("%d, %d, %d, %d\n", A.number[i], B.number[i], C.number[i], D.number[i]);
        }
		printf("\n");

        get_card(&A);
        get_card(&B);
        get_card(&C);
        get_card(&D);

        printf("cards of player 1:\n");
        for(i=0; i<13; i++)
        {
                for(j=0; j<3; j++)
                {
                        printf("%c", A.card[i][j]);
                }
                printf(" ");
        }
        printf("\n\n");

        printf("cards of player 2:\n");
        for(i=0; i<13; i++)
        {
                for(j=0; j<3; j++)
                {
                        printf("%c", B.card[i][j]);
                }
                printf(" ");
        }
        printf("\n\n");

        printf("cards of player 3:\n");
        for(i=0; i<13; i++)
        {
                for(j=0; j<3; j++)
                {
                        printf("%c", C.card[i][j]);
                }
                printf(" ");
        }
        printf("\n\n");

        printf("cards of player 4:\n");
        for(i=0; i<13; i++)
        {
                for(j=0; j<3; j++)
                {
                        printf("%c", D.card[i][j]);
                }
                printf(" ");
        }
        printf("\n\n");

        return 0;
}

void get_number(int a[13][4])
{
        int i,j;
        int b[53];
        memset(b, 0, 53*sizeof(int));
        srand((unsigned)time(NULL));

        for(i=1; i<=52; i++)
        {
                while(b[j=rand()%52]);
                b[j] = i;
        }

        for(i=0; i<13; i++)
        {
                for(j=0; j<4; j++)
                        a[i][j]=b[4*i+j];
        }
}

void arrange(int a[13])
{
        int i, j, temp;
        for(i=12; i>=0; i--)
        {
                for(j=0; j<i; j++)
                {
                        if(a[j]>a[j+1])
                        {
                                temp=a[j];
                                a[j]=a[j+1];
                                a[j+1]=temp;
                        }
                }
        }
}

void get_card(struct player *A)
{
        int i, j;
        for(i=0; i<13; i++)
        {
                for(j=0; j<3; j++)
                {
                        if(A->number[i]<=13)
                                A->card[i][0]=6;
                        else if((A->number[i]>=14)&&(A->number[i]<=26))
                                A->card[i][0]=3;
                        else if((A->number[i]>=27)&&(A->number[i]<=39))
                                A->card[i][0]=5;
                        else
                                A->card[i][0]=4;

                        switch(A->number[i]%13)
                        {
                                case 1:  A->card[i][1]='A';  A->card[i][2]=' ';  break;
                                case 2:  A->card[i][1]='2';  A->card[i][2]=' ';  break;
                                case 3:  A->card[i][1]='3';  A->card[i][2]=' ';  break;
                                case 4:  A->card[i][1]='4';  A->card[i][2]=' ';  break;
                                case 5:  A->card[i][1]='5';  A->card[i][2]=' ';  break;
                                case 6:  A->card[i][1]='6';  A->card[i][2]=' ';  break;
                                case 7:  A->card[i][1]='7';  A->card[i][2]=' ';  break;
                                case 8:  A->card[i][1]='8';  A->card[i][2]=' ';  break;
                                case 9:  A->card[i][1]='9';  A->card[i][2]=' ';  break;
                                case 10: A->card[i][1]='1';  A->card[i][2]='0';  break;
                                case 11: A->card[i][1]='J';  A->card[i][2]=' ';  break;
                                case 12: A->card[i][1]='Q';  A->card[i][2]=' ';  break;
                                case 0:  A->card[i][1]='K';  A->card[i][2]=' ';  break;
                        }
                }
        }
}