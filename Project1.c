#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int Arr[4][4];        //matrix
    int Max_Move = 0;    //Maximum Move
    char name[50];

    printf("Enter Player Name : ");
    scanf("%s",name);

    system("cls");      //clear screen

    while(1)
    {
        Create_Matrix(Arr);            //Function call to create matrix
        Display_Rule(Arr);             //Display game rule

        while(!Winner(Arr))            //Check win situation
        {
            system("cls");
            if(!Max_Move)
            {
                break;
            }
            printf("\nPlayer Name : %s ,Move remaining : %d\n",name,Max_Move);
            Show_Matrix(Arr);
            int key  = Key();

            switch(key)
            {
                case 101:

                case 69:
                    printf("Thanks for playing...\n");
                    printf("\nHit 'Enter' to exit the game\n");
                    key = Key();
                    return 0;

                case 72:
                    if(shiftUp(Arr))
                    {
                        Max_Move--;
                        break;
                    }

                case 80:
                    if(shiftDown(Arr))
                    {
                        Max_Move--;
                        break;
                    }
                
                case 77:
                    if(shiftRight(Arr))
                    {
                        Max_Move--;
                        break;
                    }

                case 75:
                    if(shiftLeft(Arr))
                    {
                        Max_Move--;
                        break;
                    }
                
                default:
                    printf("\nNot Allowed");
            }
        }

        if(!Max_Move)
        {
            printf(ANSI_COLOR_RED"\n\a     YOU LOSE!       \a\n"ANSI_COLOR_RESET);
        }
        else
        {
            printf(ANSI_COLOR_GREEN"\n\a     CONGTRATUIALTION       \a\n"ANSI_COLOR_RESET);

        }
    }


}
