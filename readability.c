#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text:");

    int lettercount = 0;
    int wordcount = 1;
    int sentencecount = 0;


  // i = amount of symbols
  // letterscount // wordscount // sentencecount
     
  
    
    for(int i=0; i<strlen(text);i++)
      {
          if((text[i]>= 65 && text[i] <= 90) || (text[i]>=97 && text[i]<=122))
           {
              lettercount++;
           }
          else if(text[i] == ' ')
          {
              wordcount++;
          }
          else if(text[i] == '.' || text[i] == '!' || text[i] == '?')
          {
              sentencecount++;
          }
       }
      // finding the sum of letters, words, sentences 
    int sum0 = 0+lettercount; 
    int sum1= 0+wordcount;
    int sum2= 0+sentencecount;
    
    printf("%i letter(s)\n", sum0);
    printf("%i word(s)\n", sum1);
    printf("%i sentence(s)\n", sum2);
    
    // calculating the grade by formula
    
    float grade = 0.0588 * (100 * (float) lettercount / (float) wordcount) - 0.296 * (100 * (float) sentencecount / (float) wordcount) - 15.8;
    
    if(grade<16 && grade >1)
      {
        printf("Grade %.f\n", round(grade));
      }
    else if(grade<1)
      {
        printf("Before grade 1\n");
      }
    else if(grade>16)
      {
        printf("Grade 16+\n");
      }
}