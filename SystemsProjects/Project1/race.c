#include <stdlib.h>
#include <stdio.h>
#include "animals.h"
#include <unistd.h>
#include <stdbool.h>
/***************************************************
* int main(void)
* Determines the new position of the hare after 1 second
*
* Parameters:
* current_position: the current location of the hare
* Returns:
* The new position of the hare
************************************************/
int main(void)
{
    int seed;
    int harePosition = 0;
    int tortPosition = 0;
    int beePosition = 0;
    int winner = 0;
    int t = 0;
    bool hareInFirst = false;
    bool tortInFirst = false;
    bool beeInFirst = false;
    puts("Please enter a random number seed.");
    scanf("%d", &seed);
    srand(seed);
    
    while ((harePosition < 70) && (tortPosition < 70) && (beePosition < 70)){
        //update hare first, then tortoise, then the bee
        harePosition = update_hare(harePosition);
        tortPosition = update_tortoise(tortPosition);
        beePosition = update_bee(beePosition);
        t++;
        //check for first place ties
        if((tortPosition <= beePosition) && (beePosition == harePosition)){}
        else if((beePosition <= tortPosition) && (tortPosition == harePosition)){}
        else if((harePosition <= tortPosition) && (tortPosition == beePosition)){}
        else if ( (beePosition <= tortPosition) && (tortPosition <= harePosition))
        {
            winner = 1;
            //check if the hare is already in first place, this is replicated for the other scenarios/if else statements
            if((hareInFirst != true) && (winner == 1)){
                printf("At t = %d, the hare (square %d) has taken the lead.\n", t, harePosition);
            }
            hareInFirst = true;
            tortInFirst = false;
            beeInFirst = false;
        }
        
        else if ( (tortPosition <= beePosition) && (beePosition <= harePosition))
        {
            winner = 1;
            if(hareInFirst != true && winner == 1){
                printf("At t = %d, the hare (square %d) has taken the lead.\n", t, harePosition);
            }
            hareInFirst = true;
            tortInFirst = false;
            beeInFirst = false;
            
        }
        else if ( (beePosition <= harePosition) && (harePosition <= tortPosition))
        {
            winner = 0;
             if(tortInFirst != true && winner == 0){
                printf("At t = %d, the tortoise (square %d) has taken the lead.\n", t, tortPosition);
            }
            hareInFirst = false;
            tortInFirst = true;
            beeInFirst = false;
        }
        else if ( (harePosition <= beePosition) && (beePosition <= tortPosition) )
        {
            winner = 0;
            if(tortInFirst != true && winner == 0){
                printf("At t = %d, the tortoise (square %d) has taken the lead.\n", t, tortPosition);
            }
            hareInFirst = false;
            tortInFirst = true;
            beeInFirst = false;
        }
        else if ( (tortPosition <= harePosition) && (harePosition <= beePosition))
        {
            winner = 2;
            if(beeInFirst != true && winner == 2){
                printf("At t = %d, the bee (square %d) has taken the lead.\n", t, beePosition);
            }
            hareInFirst = false;
            tortInFirst = false;
            beeInFirst = true;
            
        }
        else if ( (harePosition <= tortPosition) && (tortPosition <= beePosition))
        {
            winner = 2;
            if(beeInFirst != true && winner == 2){
                printf("At t = %d, the bee (square %d) has taken the lead.\n", t, beePosition);
            }
            hareInFirst = false;
            tortInFirst = false;
            beeInFirst = true;
        }
        else
        {   
            // any other scenario, there must be no one in first
            hareInFirst = false;
            tortInFirst = false;
            beeInFirst = false;
        }
        // sleep(1);
    }
// check who the last winner was when one of the animals reached square 70 
    if (winner == 1)
    {
        printf("After %d seconds, the hare wins!!\n", t);
    }
    else if (winner == 0)
    {
        printf("After %d seconds, the tortoise wins!!\n", t);
    }
    else 
    {
        printf("After %d seconds, the bee wins!!\n", t);
    }
//
    return 0;
}
