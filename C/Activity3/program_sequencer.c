#include "program_sequencer.h"

#include "greeting_builder.h"
#include "io_handler.h"
#include <stdio.h>

void sequence_program(void) {
    printf("What's your name?: \n");
    char name[256];
    if (!command_line_input(name, sizeof name)) return;

    printf("Choose greeting type! %s. Type anything else for default greeting:\n",
           get_all_greetings());
    char greeting_type[256];
    if (!command_line_input(greeting_type, sizeof greeting_type)) return;

    const char *greeting = get_greeting(greeting_type);
    printf("%s\n", get_personalised_greeting(name, greeting));
}
