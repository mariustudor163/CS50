/* Credit - Luhn's Algorithm - CS50 */

#import <cs50.h>
#import <stdio.h>
#import <math.h>


int main(void) {    
    
    long long int input;     
    long long int stored;

    /* Valid user input - credit/debit card - 16 or 19 char length only */
    do     
    {   
        input = get_long("Number: ");    
        printf("Number: %lli\n", input); 
    }    
    while (input < 0);    
    
    /* Checking input length */    
    stored = input;
    long long int totalDigits = 0;    
    // while(input!=0)  
    while (input > 10)  
    {    
        input = input / 10;    
        totalDigits++;
    }; 
    
    totalDigits++;
    
    /* Is credit card legit? */    
    if (totalDigits == 13 || totalDigits == 15 || totalDigits == 16)    
    {   
        // Mapping digits - from left to right - non-even
        long long int d1, d3, d5, d7, d9, d11, d13, d15; //15
        
        // Digit Indexation
        long long int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16;    
        
        // If card number is not EVEN.
        if (totalDigits == 13 || totalDigits == 15)    
        {    
            i1 = pow(10, totalDigits);
            i2 = pow(10, totalDigits - 1);
            i3 = pow(10, totalDigits - 2);    
            i4 = pow(10, totalDigits - 3);
            i5 = pow(10, totalDigits - 4);
            i6 = pow(10, totalDigits - 5);
            i7 = pow(10, totalDigits - 6);
            i8 = pow(10, totalDigits - 7);
            i9 = pow(10, totalDigits - 8);
            i10 = pow(10, totalDigits - 9);
            i11 = pow(10, totalDigits - 10);
            i12 = pow(10, totalDigits - 11);
            i13 = pow(10, totalDigits - 12);    
            
            // Avoid division by 0.    
            if(totalDigits > 13)    
            {    
                i14 = pow(10, totalDigits - 13);    
            }    
            else    
            {    
                i14 = 1;    
            };    
            if (totalDigits > 14)    
            {    
                i15 = pow(10, totalDigits - 14);    
            }    
            else    
            {    
                i15 = 1;    
            };    
            if (totalDigits > 15)    
            {    
                i16 = pow(10, totalDigits - 15);    
            }    
            else    
            {    
                i16 = 1;    
            };    
        }  
        // When card number is EVEN
        else    
        {    
            i1 = pow(10, totalDigits - 1);
            i2 = pow(10, totalDigits - 2);
            i3 = pow(10, totalDigits - 3);
            i4 = pow(10, totalDigits - 4);
            i5 = pow(10, totalDigits - 5);
            i6 = pow(10, totalDigits - 6);
            i7 = pow(10, totalDigits - 7);
            i8 = pow(10, totalDigits - 8);
            i9 = pow(10, totalDigits - 9);
            i10 = pow(10, totalDigits - 10);
            i11 = pow(10, totalDigits - 11);
            i12 = pow(10, totalDigits - 12);
            i13 = pow(10, totalDigits - 13);
            if (totalDigits > 13)    
            {    
                i14 = pow(10, totalDigits - 14);     
            }    
            else    
            {    
                i14 = 1;    
            };    
            if (totalDigits > 14)    
            {    
                i15 = pow(10, totalDigits - 15);    
            }    
            else    
            {    
                i15 = 1;    
            };    
            if (totalDigits > 15)    
            {    
                i16 = pow(10, totalDigits - 16);    
            }    
            else    
            {    
                i16 = 1;    
            };    
        }
      
        // Storing non even variables.
        d1 = (stored / i1) % 10 ; // 10 ^ 15
        d3 = (stored / i3) % 10 ; // 
        d5 = (stored / i5) % 10 ;
        d7 = (stored / i7) % 10 ;    
        d9 = (stored / i9) % 10 ;    
        d11 = (stored / i11) % 10 ;    
        d13 = (stored / i13) % 10 ;    
        d15 = (stored / i15) % 10 ;
        
        int f1 = d1;
        int f3 = d3;
        
        // Multiplication by 2 per Luhn's bright idea.
        d1 = d1 * 2;
        d3 = d3 * 2;
        d5 = d5 * 2;
        d7 = d7 * 2;
        d9 = d9 * 2;
        d11 = d11 * 2;
        d13 = d13 * 2;
        d15 = d15 * 2;
        
        // Transforming non even variables.
        if (d1 >= 10)    
        {    
            d1 = d1 % 10 + 1;    
        }    
        if (d3 >= 10)    
        {    
            d3 = d3 % 10 + 1;    
        }    
        if (d5 >= 10)    
        {    
            d5 = d5 % 10 + 1;    
        }    
        if (d7 >= 10)    
        {    
            d7 = d7 % 10 + 1;    
        }    
        if (d9 >= 10)    
        {    
            d9 = d9 % 10 + 1;    
        }    
        if (d11 >= 10)    
        {    
            d11 = d11 % 10 + 1;    
        }
        if (d13 >= 10)    
        {    
            d13 = d13 % 10 + 1;    
        }
        if (d15 >= 10)    
        {    
            d15 = d15 % 10 + 1;    
        }    
    
        // Sum of non evens.
        int sumNonEvenDigits = d1 + d3 + d5 + d7 + d9 + d11 + d13 + d15;
       
        // Other digits
        long long int d2, d4, d6, d8, d10, d12, d14, d16; 
        d2 = (stored / i2) % 10 ; 
        d4 = (stored / i4) % 10 ;  
        d6 = (stored / i6) % 10 ;
        d8 = (stored / i8) % 10 ;    
        d10 = (stored / i10) % 10 ;    
        d12 = (stored / i12) % 10 ;    
        d14 = (stored / i14) % 10 ;    
        d16 = (stored / i16) % 10 ;
        
        // Adding things up.
        int sumEvenDigits = d2 + d4 + d6 + d8 + d10 + d12 + d14 + d16;
        
        // Final sum.
        int finalSum = sumEvenDigits + sumNonEvenDigits;
        
        // Determining which is which. 
        if (finalSum % 10 == 0 && f1 == 4)    
        {
            printf("VISA\n");
        }     
        else if (finalSum % 10 == 0 && d2 == 4 && totalDigits == 13)    
        {    
            printf("VISA\n");
        }    
        else if (finalSum % 10 == 0 && f1 == 5 && f3 <= 5 && totalDigits == 16)    
        {
            printf("MASTERCARD\n");
        }    
        else if (finalSum % 10 == 0 && d2 == 3 &&  f3 == 4 && totalDigits == 15)    
        {
            printf("AMEX\n");
        }    
        else if (finalSum % 10 == 0 && d2 == 3 &&  f3 == 7 && totalDigits == 15)    
        {
            printf("AMEX\n");
        }    
        else    
        {    
            printf("INVALID\n");    
        }    
    }    
    else    
    {    
        printf("INVALID\n");    
    }   
}

// amex, mastercard, visa
// Visa cards – 16 or 13 digits. Begins with a 4;
// Mastercard cards – 16 digits. Begins with a 5;
// American Express cards – 15 digits, Begins with 34 or 37;

