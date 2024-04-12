#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) 
{
    
    char *ptr;
    
    ptr = malloc ( sizeof(char)*10 );
    strcpy ( ptr, "Ritu" );
    printf ( "%s (%p)\n\n", ptr, ptr );
    
    ptr = realloc ( ptr, sizeof(char)*20000 );
    printf ( "%s (%p)\n\n", ptr, ptr );
    
    ptr = realloc ( ptr, sizeof(char)*2 );
    printf ( "%s (%p)\n", ptr, ptr );
    
    return 0;
    
}
