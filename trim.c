#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Reads a trace file produced by valgrind and an address marker file produced
 * by the program being traced. Outputs only the memory reference lines in
 * between the two markers
 */

int main(int argc, char **argv) {
    
    if(argc != 3) {
         fprintf(stderr, "Usage: %s tracefile markerfile\n", argv[0]);
         exit(1);
    }

    unsigned long start_marker, end_marker;
    FILE *tracefile_fp = fopen(argv[1], "r");
    FILE *markerfile_fp = fopen(argv[2], "r");
    fscanf(markerfile_fp, "%lx %lx", &start_marker, &end_marker);

    /* For printing output, use this exact formatting string where the
     * first conversion is for the type of memory reference, and the second
     * is the address
     */
    unsigned long address;
    char c;
    int i;
    int enable = 0;
    while (fscanf(tracefile_fp, " %c %lx,%d", &c, &address, &i) != EOF) {
        if (address == start_marker) {
            enable = 1;
            continue;
        } else if (address == end_marker) {
            enable = 0;
            continue;
        }
        if (enable == 1) {
            printf("%c,%#lx\n", c, address);
        }
    }
    
    return 0;
}
