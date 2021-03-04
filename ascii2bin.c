#include <stdio.h>
#include <unistd.h> 

int main()
{
    int retval;
    int offset = 48;  
    int number = 0;
    int error = 0;
    char ascii_value = 0;
    char digit = 0;
    
    
    retval = read(0, &ascii_value, 1);
    while ((retval == 1) && (ascii_value != '\n')) {
        
        if(ascii_value == offset || ascii_value == 49) {
        int digit = ascii_value - offset;
        number = (number << 1) + digit;  
        retval = read(0, &ascii_value, 1);
    } 
    else {
         error = error + 1;
         printf("%d\n", error);
         break;
         }
    }
    if (error == 0) {  
    printf("%d\n", number);
    return 0;
    }
    else{
    return 1;
    }
   }