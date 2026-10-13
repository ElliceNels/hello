#pragma once
#include <string>
#include <vector>

namespace GreetingBuilder {
    std::string get_personalised_greeting(const std::string& name,
                                          const std::string& greeting);
    std::string get_greeting(const std::string& greeting_type);
    std::vector<std::string> get_all_greetings();
}
