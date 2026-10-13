class IOHandler:

    @staticmethod
    def comamand_line_input() -> str:
        user_input = ""
        while not user_input:
            user_input = IOHandler.clean_user_input(input())
        return user_input

    @staticmethod
    def clean_user_input(dirty_input: str) -> str:
        return dirty_input.strip().lower()
