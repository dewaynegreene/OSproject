#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct cards
{
    int facedown;
    int symbol;
};

struct cards array[16];

//char symbol[16] = {};


int main()
{
    int i;
    int card1;
    int card2;
    int check;

    int numberofelements = sizeof(array)/sizeof(array[0]);

    while(numberofelements > 0)
    {
        for(i=1;i<17;i++)
        {   
            array[i].facedown = i;
            //Randomly generate the symbols to be stored in the card
            //a symbol can only be placed on two cards. once that symbol is used twice, we can no longer use it   
        }
        
        //Randomly generate the symbols to be stored in the card
        //a symbol can only be placed on two cards. once that symbol is used twice, we can no longer use it 
        
        char temp[8];
        int j = 0;
        int k, z;
        int flag = 0;

        for(i=1;i<9;i++)
        { 
            k = i;
            int character  = (rand() % (104 - 97 + 1)) + 97;
            for(z = 0; z < k; z++)
            {
              while(array[z].symbol == character)
              {
                  character  = (rand() % (104 - 97 + 1)) + 97;
                  array[i].symbol = character;
                  flag = 1;
              }        
            }
            if(flag)
                array[i].symbol = character;
            
            temp[j] = character;
            j++;
        }
        //int z = 0;
        int n;

        for(i = 9; i < 17; i++)
        {
            n = (rand() % (7 - 0 + 1)) + 0;

            while(temp[n] == '.') //array cant have . as symbol
            {
               n = (rand() % (7 - 0 + 1)) + 0;
            }
            
            array[i].symbol = temp[n];

        }


        for(i=1;i<17;i++)
        {    
            printf("\nFacedown:%d, Symbol:%c",array[i].facedown,array[i].symbol);    
        }


        printf("\nEnter card 1: ");    
        scanf("%d",&card1);
        printf("\nEnter card 2: ");  
        scanf("%d",&card2);
        
        //check = strcmp(array[card1].symbol, array[card2].symbol);

        if(array[card1].symbol == array[card2].symbol)
        {
            printf("Success");
            for(int c = card1; c < numberofelements-1; c++)
            {
                array[c]=array[c+1];
            }
            for(int c = card2; c < numberofelements-2; c++)
            {
                array[c]=array[c+1];
            }
        }
        else
        {
            printf("Fail");
        }

        numberofelements = sizeof(array)/sizeof(array[0]);
    }
}
