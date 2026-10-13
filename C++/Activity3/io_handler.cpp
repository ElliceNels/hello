#include "io_handler.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <stdexcept>

namespace IOHandler {
    std::string clean_user_input(std::string dirty_input) {
        const auto first = dirty_input.find_first_not_of(" \t\n\r\f\v");
        if (first == std::string::npos) return "";
        const auto last = dirty_input.find_last_not_of(" \t\n\r\f\v");
        std::string clean = dirty_input.substr(first, last - first + 1);
        std::transform(clean.begin(), clean.end(), clean.begin(),
                       [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
        return clean;
    }

    std::string command_line_input() {
        std::string user_input;
        while (user_input.empty()) {
            if (!std::getline(std::cin, user_input)) {
                throw std::runtime_error("Input ended before a non-empty value was provided");
            }
            user_input = clean_user_input(user_input);
        }
        return user_input;
    }
}
