#include "io_handler.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

void clean_user_input(char *dirty_input) {
    int i = 0;
    int j = 0;

    // Skip leading spaces
    while (isspace((unsigned char)dirty_input[i]))
        i++;

    // Copy characters while converting to lowercase
    while (dirty_input[i] != '\0') {
        dirty_input[j++] = (char)tolower((unsigned char)dirty_input[i++]);
    }

    // Remove trailing spaces
    while (j > 0 && isspace((unsigned char)dirty_input[j - 1]))
        j--;

    dirty_input[j] = '\0';
}

int command_line_input(char *user_input, size_t input_size) {
    int ch;

    if (input_size < 2) {
        return 0;
    }

    while (1) {
        if (fgets(user_input, input_size, stdin) == NULL) {
            return 0;
        }

        // Discard remaining characters if input exceeds buffer.
        if (strchr(user_input, '\n') == NULL && !feof(stdin)) {
            while ((ch = getchar()) != '\n' && ch != EOF) {}
        }

        clean_user_input(user_input);

        if (user_input[0] != '\0') {
            return 1;
        }
    }
}
