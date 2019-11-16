/* Greedy Algorithm CS50 */

#include <stdio.h>
#include <cs50.h>
#include <math.h>

/* Main function */
int main(void)
{ 
    /* Make sure user's input is a number larger than zero */
    
    float a;
    int total;
    do     
    {
    a = get_float("Change: ");
    total = round(a * 100);
    }     
    while (a < 0);    
    
    /* Vars repr. types of coins used */
    int q, d, n, p;   
    
    /* Finding quarters */
    q = total / 25;    
    total = total % 25;
    
    /* Finding dimes */
    d = total / 10;
    total = total % 10;
    
    /* Finding nickles */
    n = total / 5;
    total = total % 5;
      
    /* Finding pennies */
    p = total;   
    printf("remainder is %d\n", total);
    
   /* Adding the no of coins and final output */ 
    int sum = q + d + p + n;
    printf("%d\n", sum);    
}




