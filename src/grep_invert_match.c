#include "../include/grep_invert_match.h"
#include <stdio.h>
#include <string.h>

void grep_invert_match(const char *pattern, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char line[256];
    int match_found = 0;
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, pattern) == NULL)
        {
            match_found = 1;
            printf("%s", line);
        }
    }

    fclose(file);
    if (!match_found)
    {
        printf("%s\n", filename);
    }
}
