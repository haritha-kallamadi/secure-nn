#include "tools.h"
#include "global.h"
#include <iostream>
#include <cstdint>
using namespace std;

smallType additionModPrime[PRIME_NUMBER][PRIME_NUMBER];
smallType multiplicationModPrime[PRIME_NUMBER][PRIME_NUMBER];
smallType subtractModPrime[PRIME_NUMBER][PRIME_NUMBER];
/*************************************************************************/
/* Populates the lookup tables fro prime additin and multiplication      */
/*************************************************************************/

void initializePrimeTables()
{
    smallType temp;
    cout << " In initializePrimeTables() : Initializing addition, multiplication and subtraction tables "<< endl;
    for(smallType i = 0; i < PRIME_NUMBER; i++)
    {
        for(smallType j = 0; j < PRIME_NUMBER; j++)
        {
            //cout << (i + j) % PRIME_NUMBER << "-" << (i * j) % PRIME_NUMBER << " ;";
            additionModPrime[i][j] = (i + j) % PRIME_NUMBER;
            multiplicationModPrime[i][j] = (i * j) % PRIME_NUMBER;
            //cout << additionModPrime[i][j] << "-" << multiplicationModPrime[i][j] << " ;";
        }
    } 
    for(smallType i = 0; i < PRIME_NUMBER; i++)
    {
        for(smallType j = 0; j < PRIME_NUMBER; j++)
        {
            if (j == 0)
                subtractModPrime[i][j] = i;
            else
               {
                temp = (PRIME_NUMBER - j);
                subtractModPrime[i][j] =  additionModPrime[i][temp];
               }
            
        }
    } 
   cout << " In initializePrimeTables() : Initializing complted "<< endl; 
}

