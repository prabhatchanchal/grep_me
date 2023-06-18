# Grep Utility

## Description

The Grep Utility is a command-line tool that searches for a specified pattern in a given file. It provides various functionality options to customize the search behavior. This utility is implemented in C and supports both Windows and Linux platforms.

## Functionality

1. **grep**: Searches for a pattern in a file and displays matching lines.

   - [Implementation code](src/grep.c)

2. **grep_count**: Prints the count of lines that match a pattern in a file.

   - [Implementation code](src/grep_count.c)

3. **grep_display**: Displays the matched lines, excluding filenames.

   - [Implementation code](src/grep_display.c)

4. **grep_ignore_case**: Performs a case-insensitive search for the pattern in a file.

   - [Implementation code](src/grep_ignore_case.c)

5. **grep_list_filenames**: Displays a list of filenames that contain the pattern.

   - [Implementation code](src/grep_list_filenames.c)

6. **grep_line_numbers**: Displays the matched lines along with their line numbers.

   - [Implementation code](src/grep_line_numbers.c)

7. **grep_invert_match**: Prints all the lines that do not match the pattern.
   - [Implementation code](src/grep_invert_match.c)

## How to Compile and Run

1. Clone the repository:

```bash
git clone <repository-url>
```

Change to the project directory:

```bash
cd grep-utility
```

Compile the project:

```bash
make
```

Run the Grep Utility:

```bash
./grep <pattern> <filename> <flags>
```

Replace <pattern> with the pattern you want to search, <filename> with the name of the file to search in, and <flags> with the desired functionality options (e.g., -c, -h, -i, -l, -n, -v).

Disclaimer
This Grep Utility is provided as-is without any warranty. Use it at your own risk. The authors and contributors of this project are not responsible for any damages or liabilities arising from the use of this software.
Feel free to customize the content, file paths, and instructions according to your project structure and requirements.
