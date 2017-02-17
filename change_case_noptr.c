
/*   Converting lowercase letters to uppercase letters
    using a non-constant pointer to non-constant data */ 
#include <stdio.h> 
#include <ctype.h> 


void convertToUppercase( char * ); 
int main() 
{   
    char string[] = "characters and $32.98";    
printf( "The string before conversion is: %s", string );    
convertToUppercase( string );    
printf( "\nThe string after conversion is: %s\n", string );      
return 0; 
} 
void convertToUppercase( char *sPtr ) 
{   while ( *sPtr != '\0' )    
{   if ( islower( *sPtr ) )          *sPtr = toupper( *sPtr );  
/* convert to uppercase */       
++sPtr;  /* move sPtr to the next character */    
} 
}

 