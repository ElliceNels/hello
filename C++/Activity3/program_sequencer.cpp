#include "program_sequencer.h"
#include "greeting_builder.h"
#include "io_handler.h"
#include <iostream>

namespace ProgramSequencer {
    void sequence_program() {
        std::cout << "What's your name?: \n";
        const std::string name = IOHandler::command_line_input();
        std::cout << "Choose greeting type! [";
        const auto options = GreetingBuilder::get_all_greetings();
        for (std::size_t i = 0; i < options.size(); ++i) {
            if (i) std::cout << ", ";
            std::cout << "'" << options[i] << "'";
        }
        std::cout << "]. Type anything else for default greeting:\n";
        const auto greeting = GreetingBuilder::get_greeting(IOHandler::command_line_input());
        std::cout << GreetingBuilder::get_personalised_greeting(name, greeting) << '\n';
    }
}
