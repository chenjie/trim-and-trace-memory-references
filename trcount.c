#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Constants that determine that address ranges of different memory regions

#define GLOBALS_START 0x400000
#define GLOBALS_END   0x700000
#define HEAP_START   0x4000000
#define HEAP_END     0x8000000
#define STACK_START 0xfff000000

int main(int argc, char **argv) {
    
    FILE *fp = NULL;

    if(argc == 1) {
        fp = stdin;

    } else if(argc == 2) {
        fp = fopen(argv[1], "r");
        if(fp == NULL){
            perror("fopen");
            exit(1);
        }
    } else {
        fprintf(stderr, "Usage: %s [tracefile]\n", argv[0]);
        exit(1);
    }

    int i = 0;
    int m = 0;
    int l = 0;
    int s = 0;

    int global = 0;
    int heap = 0;
    int stack = 0;

    unsigned long address;
    char c;

    while (fscanf(fp, "%c,%lx", &c, &address) != EOF) {
        switch (c) {
            case 'I':
                i++;
                break;
            case 'S':
                s++;
                break;
            case 'L':
                l++;
                break;
        }
        if (c == 'S' || c == 'L' || c == 'M') {
            if (address > GLOBALS_START && address < GLOBALS_END) {
                global++;
            } else if (address > HEAP_START && address < HEAP_END) {
                heap++;
            } else if (address > STACK_START) {
                stack++;
            }
        }
    }

    /* Use these print statements to print the ouput. It is important that 
     * the output match precisely for testing purposes.
     */
    
    printf("Reference Counts by Type:\n");
    printf("    Instructions: %d\n", i);
    printf("    Modifications: %d\n", m);
    printf("    Loads: %d\n", l);
    printf("    Stores: %d\n", s);
    printf("Data Reference Counts by Location:\n");
    printf("    Globals: %d\n", global);
    printf("    Heap: %d\n", heap);
    printf("    Stack: %d\n", stack);
    

    return 0;
}
