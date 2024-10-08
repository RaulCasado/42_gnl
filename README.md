Get Next Line
=============

Description
-----------

This project aims to implement the `get_next_line` function in C, which allows reading line by line from a file descriptor. This project not only helps you manage file reading in C, but also introduces you to the use of **static variables**.

The **bonus** part of the project extends the functionality of `get_next_line` to handle multiple file descriptors simultaneously.

Functionality
-------------

### Mandatory Part

The `get_next_line` function allows reading lines from a file or from standard input (stdin). Each call to the function returns the next available line until the end of the file is reached or an error occurs. The function uses a buffer whose size can be configured using the `BUFFER_SIZE` macro.

#### Prototype:

    char *get_next_line(int fd);

#### Usage:

*   **fd**: File descriptor of the file to be read.
*   **Returns**: The line read, or `NULL` in case of error or if the end of the file is reached.

### Bonus Part

In the bonus part, the `get_next_line` function is designed to handle **multiple file descriptors simultaneously**. This allows you to switch between several open files without losing the reading progress of each one.

Usage Rules
-----------

*   The buffer size used for reading is defined at compile time using the `BUFFER_SIZE` macro.
*   The function must handle errors properly and free all allocated memory.
*   The use of `lseek`, global variables, and the `libft` library is prohibited.

Project Files
-------------

*   `get_next_line.c`: Implementation of the main function.
*   `get_next_line_utils.c`: Helper functions used by `get_next_line`.
*   `get_next_line.h`: Header with necessary prototypes and declarations.
*   `get_next_line_bonus.c`: Implementation of the bonus version.
*   `get_next_line_utils_bonus.c`: Helper functions for the bonus version.
*   `get_next_line_bonus.h`: Header for the bonus version.
*   `main.c`: Test file for the mandatory part.
*   `main_bonus.c`: Test file for the bonus part.

Compilation and Execution
-------------------------

### Mandatory Part

To compile and run the program for the mandatory part, use the following command:

    gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o program
    ./program

### Bonus Part

To compile and run the program that handles multiple file descriptors, use the following command:

    gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c -o program_bonus
    ./program_bonus

You can change the `BUFFER_SIZE` value to test different buffer sizes.

Examples
--------

### Example for Mandatory Part:

    int fd = open("file.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);

### Example for Bonus Part (multiple file descriptors):

    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);
    char *line1, *line2;
    
    line1 = get_next_line(fd1);
    line2 = get_next_line(fd2);
    printf("From file1: %s\n", line1);
    printf("From file2: %s\n", line2);
    
    free(line1);
    free(line2);
    close(fd1);
    close(fd2);

Requirements
------------

*   Allowed functions: `read`, `malloc`, `free`
*   Use of the `libft` library is not allowed.

Considerations
--------------

*   The function must work with different `BUFFER_SIZE` values, from 1 to very large values.
*   The implementation must avoid memory leaks and behave properly for both text files and standard input.
*   In the bonus part, it must be able to switch between multiple file descriptors without losing the position in each one.

Evaluation
----------

The bonus part will only be evaluated if the mandatory part is **perfectly** completed. All compilation rules must be followed, and the code must adhere to the project's style guidelines.
