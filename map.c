#include <stdio.h>
#include <stdlib.h>

/* A recursive function */
int recur(int i, int p2, int p3, int p4, int p5, int p6, int p7) {
    /* A stack allocated variable within a recursive function */
    int j = i;
    int k[4];  
    printf("recur call \n");
    printf("  Local variable j's address : %p, Content: %d\n", &j, j); 
    printf("  Current frame base address(i.e. %%rbp) : %p, Content(i.e. saved rbp): %p\n", 
              __builtin_frame_address(0), __builtin_frame_address(1)) ;
    printf("  Return address location: %p, Content(i.e. saved %%rip): %p\n", 
              __builtin_frame_address(0)+8, __builtin_return_address(0));

    printf("  Parameter p7's address : %p, Content: %d\n\n", &p7, p7); 

    if (i > 0) {
        return recur(i-1, p2,p3,p4,p5,p6,p7);
    }

    return 0;
}

int stuff = 7;

int main(int argc, char *argv[]) {
    /* A stack allocated variable */
    int i;

    /* Dynamically allocate some stuff */
    char *buf1 = malloc(60);
    /* ... and some more stuff */
    char *buf2 = malloc(60);

    printf("_main  @ %p\n", main);
    printf("recur @ %p\n", recur);

    printf("_main stack: %p\n", &i);

    printf("static data: %p\n", &stuff);

    printf("Heap: malloc 1: %p\n", buf1);
    printf("Heap: malloc 2: %p\n\n", buf2);

    recur(2,2,3,4,5,6,7);
    return 0;
}
