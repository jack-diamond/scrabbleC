//
//Name: scrabble.c
//Purpose: Performs a simplified version of the Scrabble game.
//Author: Jack Diamond
//Date: 4-11-2017
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LETTERS 7

void generate_letter_set(int letter_set[], int size_letter_set, int num_letters)
{
    int i,j;
    int letter;
    int ray[27] = {9, 2, 2, 4, 12, 2, 3, 2, 9, 1, 1, 4, 2, 6, 8, 2, 1, 6, 4, 6, 4, 2, 2, 1, 2, 1, 2}; 
    srand((unsigned) time(NULL));
    for(i = 0; i < num_letters; i++)
    {
        letter = rand() % 27;
        if(ray[letter] > 0)
        {
            ray[letter]--;
            letter_set[letter]++;
        }
        else i--;
    }
    
    printf("Your letters are:");

    for(i=0;i<27;i++)
    {
        for(j = 0; j < letter_set[i]; j++)
        {
            if(i == 26)
                printf(" _");    
            else
                printf(" %c", i + 65);
 
        }
    }   
    printf("\n");
}
    

int read_word(char word[], int max_size_word)
{
    int i = 0;
    char temp = 'x';
    printf("Enter your word: ");
    while(temp != '\n')
	{
        temp = getchar();
        if(i < max_size_word)
        {
            word[i] = temp;
        }
        i++;
    }     
    return i - 1;
}

_Bool check_word(char word[], int size_word, int letter_set[], int size_letter_set)
{
    int letter;
    int i,j;
    if( size_word > 7)
    {
        printf("The word is not valid. Use your letters:");
        for(i=0;i<27;i++)
        {
			for(j = 0; j < letter_set[i]; j++)
        	{
            	if(i == 26)
                	printf(" _");    
           		else
                	printf(" %c", i + 65);
 
        	}                                     
        }
        printf("\n");
        return false;
    }
    int letter_count[27] = {0};
    int index;
    for(i=0; i < size_word; i++)
    {
        if(word[i] == '_')
			index = 26;
		else 
			index = word[i]-65;
        if(letter_set[index] == letter_count[index]) 
        {
            printf("The word is not valid. Use your letters:");
            for(i=0;i<27;i++)
            {
				for(j = 0; j < letter_set[i]; j++)
        		{
            		if(i == 26)
                		printf(" _");    
            		else
                		printf(" %c", i + 65);
 
        		}
            }
            printf("\n");    
            return false; 
        }
        letter_count[index]++;
    }
    return true;
}    

int compute_word_value(char word[], int size_word)
{
    int letter_value[27] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10, 0};
    int index;
    int i;
    int totalvalue = 0;
    for(i=0; i < size_word; i++)
    {
        if(word[i] == 95)
		{	
			index = word[i]-69;
        	totalvalue += letter_value[index];
		}
		else
		{
			index = word[i]-65;
        	totalvalue += letter_value[index];
		}
    }
    printf("The value of your word is: %d\n", totalvalue);   
}


int main()
{
    int ls[26] = {0}; 
    int sls = 26;
    char w[7];
    int msw = 7;
    int sw;

	char pa;
    int keepplaying = 0;
    
    
    printf("This program plays the game of scrabble.\n");
 
	while(keepplaying == 0)
	{
		generate_letter_set(ls, sls, NUM_LETTERS);
    
    	int cont = 0;
    	while(cont == 0)
    	{
    		sw = read_word(w, msw);
      		if(check_word(w, sw, ls, sls))
    		{
          		cont = 1;
    		}
    	}
    	compute_word_value(w,sw); 
    
      
      	printf("Do you want to play again (Y/N): ");
      	scanf(" %c", &pa);
      	char garbage;
      	garbage = getchar();
      	if(pa != 'Y')
      	{  
        	keepplaying = 1;
      	} 
        int x;
        for(x = 0; x < 26; x++)
        	ls[x] = 0;
      	sw = 0;
  	} 
    printf("Thank you for playing.\n");  
}
