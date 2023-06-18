#include "../include/grep_display.h"
#include <stdio.h>
#include <string.h>

void grep_display(const char *pattern, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, pattern) != NULL)
        {
            printf("%s", line);
        }
    }

    fclose(file);
}
