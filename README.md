// Intro to void pointers!C code to print the num. 3 in the screen from the table.

#include <stdio.h>

void * go_to(void * string, int offset) {

    return string + offset;
    
}

int main() {

    int table[4] = {0, 1, 2, 3};
    
    printf("%d", * (int * )go_to(table, 3 * sizeof(int)));
    
    return 0;
    
}

Output : 3 
