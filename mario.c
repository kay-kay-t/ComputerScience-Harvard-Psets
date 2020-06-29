
int main(void)
{
    int n;

    do {
        n = get_int("Height: ");
       }
    while (n < 1 || n > 8);      
                             // n = height

    if (n > 0 || n < 9)
      {
        int i = 0; 
                             // i = counter
                             
        for (int j = 0; j < n; j++) 
                                      // j = row
         {
            if (i != n) 
                                      // != - not equal
            {
                for (int k = (n - 1) - i; k > 0; k--) 
                                                         // k = spaces
                 {
                    printf(" ");
                 }
                for (int m = 0; m <= i; m++) 
                                                          // m = hashes                 
                 {
                    printf("#");
                 }

                printf("  ");

                for (int m = 0; m <= i; m++) 
                 {
                    printf("#");
                 }

                printf("\n");
                
                i++;
            }
          }     
        }       
}