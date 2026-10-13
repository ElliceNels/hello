#include "greeting_builder.h"
#include <map>

namespace GreetingBuilder {
    constexpr const char* DEFAULT_GREETING = "Hello World";
    const std::map<std::string, std::string> greetings = {
        {"formal", "Hello There"},
        {"friendly", "Hiya"},
        {"enthusiastic", "Ayeeee!! What is upp!!"}
    };

    std::string get_personalised_greeting(const std::string& name,
                                          const std::string& greeting) {
        return name + ", " + greeting;
    }

    std::string get_greeting(const std::string& greeting_type) {
        auto match = greetings.find(greeting_type);
        return match != greetings.end() ? match->second : DEFAULT_GREETING;
    }

    std::vector<std::string> get_all_greetings() {
        std::vector<std::string> keys;
        for (const auto& entry : greetings) {
            keys.push_back(entry.first);
        }
        return keys;
    }
}
