#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
  // check there is two arguments and argv[1] is a digit  
    if (argc == 2 && isdigit(*argv[1]))
    {
      int k = atoi(argv[1]); //convert key into integer
    // getting plaintext  
      string p = get_string("plaintext:");
      printf("ciphertext:");
       
      
    for (int i = 0, n = strlen(p); i < n; i++) //checks if all char are numerical
     {
    //check if it's uppercase; change to alphabetic; apply formula ci = (pi + k) % 26; change back to ascii
      if(p[i]>64 && p[i]<91)
       {
         printf("%c",(((p[i] - 64) + k) % 26) + 64);
       }
    //check if it's lowercase; change to alphabetic; apply formula ci = (pi + k) % 26; change back to ascii
      else if(p[i] > 96 && p[i] < 123)
      {
        printf("%c",(((p[i] - 97) + k) % 26) + 97);
      }
    //non-letters do not change
      else
      {
        printf("%c", p[i]);
      }
      
      }
      
      printf("\n");
      return 0;

    }
    else if(argc != 2)
      {
        printf("Usage: ./caesar key\n");
        return 1;
      }
    else 
    {
      return 1;
    }
     
}
