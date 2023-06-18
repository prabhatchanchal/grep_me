#include "../include/grep_count.h"
#include <stdio.h>
#include <string.h>

void grep_count(const char *pattern, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char line[256];
    int match_count = 0;
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, pattern) != NULL)
        {
            match_count++;
        }
    }

    fclose(file);
    printf("%s:%d\n", filename, match_count);
}
