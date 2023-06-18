#include "include/grep.h"
#include "include/grep_count.h"
#include "include/grep_display.h"
#include "include/grep_ignore_case.h"
#include "include/grep_list_filenames.h"
#include "include/grep_line_numbers.h"
#include "include/grep_invert_match.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void grep(const char *pattern, const char *filename)
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

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <pattern> <filename> <flags>\n", argv[0]);
        return 1;
    }

    const char *pattern = argv[1];
    const char *filename = argv[2];

    // Flags
    int count_flag = 0;
    int display_filenames = 0;
    int ignore_case = 0;
    int list_filenames = 0;
    int display_line_numbers = 0;
    int invert_match = 0;

    // Parse flags
    for (int i = 3; i < argc; i++)
    {
        if (strcmp(argv[i], "-c") == 0)
        {
            count_flag = 1;
        }
        else if (strcmp(argv[i], "-h") == 0)
        {
            display_filenames = 1;
        }
        else if (strcmp(argv[i], "-i") == 0)
        {
            ignore_case = 1;
        }
        else if (strcmp(argv[i], "-l") == 0)
        {
            list_filenames = 1;
        }
        else if (strcmp(argv[i], "-n") == 0)
        {
            display_line_numbers = 1;
        }
        else if (strcmp(argv[i], "-v") == 0)
        {
            invert_match = 1;
        }
    }

    // Call the appropriate function based on the flags
    if (count_flag)
    {
        grep_count(pattern, filename);
    }
    else if (display_filenames)
    {
        grep_display(pattern, filename);
    }
    else if (ignore_case)
    {
        grep_ignore_case(pattern, filename);
    }
    else if (list_filenames)
    {
        grep_list_filenames(pattern, filename);
    }
    else if (display_line_numbers)
    {
        grep_line_numbers(pattern, filename);
    }
    else if (invert_match)
    {
        grep_invert_match(pattern, filename);
    }
    else
    {
        grep(pattern, filename); // Default behavior
    }

    return 0;
}
