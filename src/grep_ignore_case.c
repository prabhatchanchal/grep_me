#include "../include/grep_ignore_case.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void grep_ignore_case(const char *pattern, const char *filename)
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
        char *line_ptr = line;
        char *pattern_ptr = (char *)pattern;

        while (*line_ptr)
        {
            *line_ptr = tolower(*line_ptr);
            line_ptr++;
        }
        while (*pattern_ptr)
        {
            *pattern_ptr = tolower(*pattern_ptr);
            pattern_ptr++;
        }

        if (strstr(line, pattern) != NULL)
        {
            printf("%s", line);
        }
    }

    fclose(file);
}
