
#include <stdio.h>

int ptrace(long a, long b, long c) { 
    printf("a : %d b %d c : %d\n", a,b,c);
 	return c;                      
 }                                    

