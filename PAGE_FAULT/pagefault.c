#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

#define BUFFER_SIZE (1024 * 1024)   // 1 MB

void print_pgfaults(void)
{
    struct rusage usage;

    if (getrusage(RUSAGE_SELF, &usage) == -1) {
        perror("getrusage");
        return;
    }

    printf("Major Page Faults : %ld\n", usage.ru_majflt);
    printf("Minor Page Faults : %ld\n", usage.ru_minflt);
}

int main(void)
{
    unsigned char *p;

    printf("=== Initial State ===\n");
    print_pgfaults();

    p = malloc(BUFFER_SIZE);
    if (!p) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    printf("\n=== After malloc() ===\n");
    print_pgfaults();

    /* Touch each page */
    for (size_t i = 0; i < BUFFER_SIZE; i += 4096) {
        p[i] = 0;
    }

    printf("\n=== After accessing memory ===\n");
    print_pgfaults();

    free(p);

    return 0;
}
