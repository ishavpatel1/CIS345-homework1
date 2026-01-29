#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    FILE* input;
    if (argc < 2) {
        printf("File name missing!\n");
        exit(1);
    }

    input = fopen(argv[1], "r");
    int ch;
    int l_count = 0;
    int b_count = 0;


    while((ch = getc(input)) != EOF) {
 	b_count += 1;
  	if (ch == '\n') 
            l_count += 1;
    }
    fclose(input);

    printf("#lines:%i, #bytes: %i\n", l_count, b_count);
    return 0;
}
