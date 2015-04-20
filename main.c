/**
 * CPRESS!
 *
 * TODO: Still pretty much everything, but we are getting somewhere!
 */

#include "dbg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * The maximum number of bytes to read from a file
 */

const size_t MAX_BYTES = 0xFFFF;

/**
 * Print the usage of the program
 */

void print_usage()
{
    printf("USAGE:\n");
    printf("cpress [FILE]\n");
}

/**
 * Print a string as bytes
 */

void print_bytes(const char* str)
{
    int i = 0;
    check(str, "Empty file");

    for(i = 0; str[i] != '\0'; i++)
    {
        printf("%x ", (unsigned char)str[i]);
    }

    printf("\n");

error:
    return;
}

int main(int argc, char* argv[])
{
    FILE* fp = NULL;
    char* contents = NULL;
    char* in = NULL;
    size_t rc = 0;

    if(argc < 2)
    {
        print_usage();
        goto error;
    }

    fp = fopen(argv[1], "r");
    check(fp, "Error opening file: %s", argv[1]);

    contents = calloc(sizeof(char), MAX_BYTES);
    in = fgets(contents, MAX_BYTES-1, fp);
    check(in != NULL, "Error reading file: %s", argv[1]);

    print_bytes(contents);
    rc = strlen(contents);
    printf("Bytes read: %lu\n", rc);

    free(NULL);

    return 0;

error:
    if(fp)
    {
        fclose(fp);
    }

    if(contents)
    {
        free(contents);
    }

    return 1;
}
