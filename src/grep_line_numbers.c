#include "../include/grep_line_numbers.h"
#include <stdio.h>
#include <string.h>

void grep_line_numbers(const char *pattern, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char line[256];
    int line_number = 1;
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, pattern) != NULL)
        {
            printf("%s:%d:%s", filename, line_number, line);
        }
        line_number++;
    }

    fclose(file);
}
