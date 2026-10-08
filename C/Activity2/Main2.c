#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define DEFAULT_GREETING "Hello World"

static int getInput(const char *prompt, char *input, size_t input_size)
{
    size_t length;
    int character;

    if (input_size == 0) {
        return 0;
    }

    printf("%s", prompt);
    if (fgets(input, (int)input_size, stdin) == NULL) {
        return 0;
    }

    length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
        input[length - 1] = '\0';
    } else {
        while ((character = getchar()) != '\n' && character != EOF) {
        }
    }

    return 1;
}

static void trim_and_lower(char *text)
{
    int i = 0;
    int j = 0;

    // Skip leading spaces
    while (isspace((unsigned char)text[i]))
        i++;

    // Copy characters while converting to lowercase
    while (text[i] != '\0') {
        text[j++] = (char)tolower((unsigned char)text[i++]);
    }

    // Remove trailing spaces
    while (j > 0 && isspace((unsigned char)text[j - 1]))
        j--;

    text[j] = '\0';
}
static const char *get_greeting(char *greeting)
{
	trim_and_lower(greeting);

	if (strcmp(greeting, "formal") == 0) {
		return "Hello There";
	} else if (strcmp(greeting, "friendly") == 0) {
		return "Hiya";
	} else if (strcmp(greeting, "enthusiastic") == 0) {
		return "Ayeeee!! What is upp!!";
	} else {
		return DEFAULT_GREETING;
	}	
		
}

int main(void)
{
	char name[256];
	char greeting_input[256];

	if (!getInput("Enter username: ", name, sizeof(name))) {
		return 1;
	}

	if (!getInput("Enter greeting type [formal, friendly, enthusiastic]. "
		      "Type anything else for default greeting: ",
		      greeting_input, sizeof(greeting_input))) {
		return 1;
	}

	printf("%s, %s", name, get_greeting(greeting_input));
	return 0;
}
