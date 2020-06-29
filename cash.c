#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void)

{   int c;
    float n;     
 //promting for an answer, c - amount of coins, n - change owed
    do
   { 
     n = get_float ("Change owed:");
   }
    
   while (n < 0);
   
   n = n * 100;
   n = round(n);
   
   while (n > 0)
   {
       if (n >= 25)
       {
           n = n - 25;
           c = c + 1;
       }
       else if (n >= 10)
       {
           n = n - 10;
           c = c + 1;
       }
       else if (n >= 5)
       {
           n = n - 5;
           c = c + 1;
       }
       else if (n >= 1)
       {
           n = n - 1;
           c = c + 1;
       }
   }
   printf("Coins Used: %d\n", c);
}   