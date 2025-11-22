#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

/* Abort malloc on allocation failure */
void *xmalloc(size_t size) {

    void *ptr = malloc(size);

    if (!ptr) {

        perror("malloc");
        exit(EXIT_FAILURE);

    }

    return ptr;

}

/* Abort strdup on allocation failure */
char *xstrdup(const char *str) {

    if (!str) return NULL;

    char *ptr = strdup(str);

    if (!ptr) {

        perror("strdup");
        exit(EXIT_FAILURE);

    }

    return ptr;

}
