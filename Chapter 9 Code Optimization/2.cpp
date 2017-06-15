#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  
#define in_area(x, a, b) ((x)>=(a) && (x)<=(b))  
#define isxdigit(x) (isdigit(x) || in_area(x, 'a', 'f') || in_area(x, 'A', 'F') )  
  
void print( int boolean )  
{  
    printf( "%s\n", boolean ? "true" : "false" );  
}  
  
int main(int argc, char *argv[])  
{    
    print(isxdigit('0'));  
    print(isxdigit('9'));  
    print(isxdigit('5'));  
    print(isxdigit('A'));  
    print(isxdigit('F'));  
    print(isxdigit('a'));  
    print(isxdigit('f'));  
    print(isxdigit('z'));  
    print(isxdigit('M'));  
    print(isxdigit('L'));  
    return 0;  
}  
