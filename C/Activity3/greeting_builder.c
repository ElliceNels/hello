#include "greeting_builder.h"

#include <stdio.h>
#include <string.h>

#define DEFAULT_GREETING "Hello World"

typedef struct {
    const char *type;
    const char *message;
} Greeting;

static const Greeting greetings[] = {
    {"formal", "Hello There"},
    {"friendly", "Hiya"},
    {"enthusiastic", "Ayeeee!! What is upp!!"}
};

const char *get_greeting(const char *greeting_type) {
    size_t count = sizeof greetings / sizeof greetings[0];
    for (size_t i = 0; i < count; ++i) {
        if (strcmp(greetings[i].type, greeting_type) == 0) {
            return greetings[i].message;
        }
    }
    return DEFAULT_GREETING;
}

const char *get_personalised_greeting(const char *name, const char *greeting) {
    static char result[512];
    snprintf(result, sizeof result, "%s, %s", name, greeting);
    return result;
}

const char *get_all_greetings(void) {
    static char keys[256];
    size_t count = sizeof greetings / sizeof greetings[0];
    size_t used = 0;

    used += (size_t)snprintf(keys + used, sizeof keys - used, "[");
    for (size_t i = 0; i < count; ++i) {
        used += (size_t)snprintf(keys + used, sizeof keys - used,
                                 "%s'%s'", i ? ", " : "", greetings[i].type);
    }
    snprintf(keys + used, sizeof keys - used, "]");
    return keys;
}
