#ifndef IO_HANDLER_H
#define IO_HANDLER_H

#include <stddef.h>

int command_line_input(char *user_input, size_t input_size);
void clean_user_input(char *dirty_input);

#endif