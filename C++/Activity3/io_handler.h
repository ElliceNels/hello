#pragma once
#include <string>

namespace IOHandler {
    std::string command_line_input();
    std::string clean_user_input(std::string dirty_input);
}
