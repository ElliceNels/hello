#include <iostream>
#include <string>

class Main1 {
public:
	static std::string greeting;

	static const std::string& getGreeting() {
		return greeting;
	}
};

std::string Main1::greeting = "Hello World";

int main() {
	std::cout << Main1::getGreeting();
	return 0;
}