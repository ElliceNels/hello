from io_handler import IOHandler
from greeting_builder import GreetingBuildler

class ProgramSequencer:

    @staticmethod
    def sequence_program():
        print("What's your name?: ")
        name = IOHandler.comamand_line_input()
        print(f"Choose greeting type! {GreetingBuildler.get_all_greetings()}. Type anything else for default greeting:")
        greeting = GreetingBuildler.get_greeting(IOHandler.comamand_line_input())
        print(GreetingBuildler.get_personalised_greeting(name, greeting))
