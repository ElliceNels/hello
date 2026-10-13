class GreetingBuildler:

    DEFAULT_GREETING = "Hello World"
    greetings = {
        "formal": "Hello There",
        "friendly": "Hiya",
        "Enthusiastic": "Ayeeee!! What is upp!!",
    }

    @staticmethod
    def get_personalised_greeting(name, greeting):
        return name + ", " + greeting

    @staticmethod
    def get_greeting(greeting_type):
        return GreetingBuildler.greetings.get(greeting_type, GreetingBuildler.DEFAULT_GREETING)

    @staticmethod
    def get_all_greetings():
        return list(GreetingBuildler.greetings.keys())