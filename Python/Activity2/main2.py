DEFAULT_GREETING = "Hello World"
greetings = {"formal": "Hello There", "friendly": "Hiya", "Enthusiastic": "Ayeeee!! What is upp!!"}

def get_some_input():
    user_input = ""
    while user_input == "":
        user_input = input()
    return user_input

def get_personalised_greeting(name, greeting):
    return name + ", " + greeting

def get_greeting(greeting_type):
    return greetings.get(greeting_type.lower().strip(), DEFAULT_GREETING)

if __name__ == "__main__":
    print("What's your name?: ")
    name = get_some_input()
    print("Choose greeting type! [formal, friendly, enthusiastic]. Type anything else for default greeting:")
    greeting = get_greeting(get_some_input())
    print(get_personalised_greeting(name, greeting))
