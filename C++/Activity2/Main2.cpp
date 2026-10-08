#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>

const std::string DEFAULT_GREETING = "Hello World";
const std::unordered_map<std::string, std::string> greetings = {
	{"formal", "Hello There"},
	{"friendly", "Hiya"},
	{"enthusiastic", "Ayeeee!! What is upp!!"}
};

std::string getGreeting(std::string greeting) {
	std::transform(greeting.begin(), greeting.end(), greeting.begin(),
				   [](unsigned char character) {
					   return static_cast<char>(std::tolower(character));
				   });

	const auto first = greeting.find_first_not_of(" \t\n\r\f\v");
	if (first == std::string::npos) {
		return DEFAULT_GREETING;
	}
	const auto last = greeting.find_last_not_of(" \t\n\r\f\v");
	greeting = greeting.substr(first, last - first + 1);

	const auto greetingIt = greetings.find(greeting);
	return greetingIt == greetings.end() ? DEFAULT_GREETING : greetingIt->second;
}

std::string getInput() {
	std::string input;
	std::cin >> input;
	return input;
}

std::string getPersonalisedGreeting(const std::string& name, const std::string& greeting) {
	return name + ", " + greeting;
}

int main() {
	std::cout << "Enter username: " << std::endl;
	const std::string name = getInput();

	std::cout << "Enter greeting type [formal, friendly, enthusiastic]. "
				 "Type anything else for default greeting: "
			  << std::endl;
	const std::string greeting = getGreeting(getInput());

	std::cout << getPersonalisedGreeting(name, greeting);
	return 0;
}
