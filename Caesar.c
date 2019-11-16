// Caesar - CS50 - 17 nov 2019
// We encrypt a message that is input by the user by adding a key
// 


#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// Main function;
int main(int argc, string argv[])
{    
    int k;    
    // User must input no more than ONE argument;
    if (argc == 2)    
    {    
        k = atoi(argv[1]);    
        
        // If the argument is a digit it can continue;
        for (int i = 0; i < strlen(argv[1]); i++)    
        {  
            // We want only digits in the argument;
            if (isdigit(argv[1][i]))    
            {    
            }    
            else    
            {    
                printf("Usage: ./caesar key\n");    
                return 1;    
            }    
        }
        
        // We want the user to input a plaintext;
        string inpt = get_string("plaintext:  "); 
        printf("ciphertext: ");    
        
        // Iterating over the argument above;
        for (int z = 0; z < strlen(inpt); z++)    
        {   
            // If block - Lowercase letters - ASCII : 65 - 90;
            if (inpt[z] < 90 && inpt[z] > 64)     
            {   
                // Took me 3 hours to come up with the lines of code inside this if statement*
                int index = (inpt[z] + 1)  % 66;     
                printf("%c", (index + k) % 26 + 65);    
            }    
            // If block - Uppercase letters - ASCII : 97 - 122;
            else if (inpt[z] > 96 && inpt[z] < 123)    
            {    
                int index = (inpt[z])  % 97;     
                printf("%c", (index + k) % 26 + 97);    
            }
            // Other characters remain unaffected;
            else {printf("%c", inpt[z]);}    
        }    
        printf("\n");    
    }    
    else    
    {    
        printf("Usage: ./caesar key\n");    
        return 1;   
    }    
}    

// 1337
