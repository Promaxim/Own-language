#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::string evaluate_custom_language(const std::string& input) {
    size_t start = input.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) return "";
    size_t end = input.find_last_not_of(" \t\n\r");
    std::string trimmed = input.substr(start, end - start + 1);

    if (trimmed.empty()) return "";

    std::stringstream ss(trimmed);
    std::string command;
    ss >> command;

    if (command == "exit") {
        std::cout << "Exiting terminal. Goodbye!\n";
        std::exit(0);
    } 
    else if (command == "say") {
        std::string message;
        std::getline(ss, message);
        if (!message.empty() && message[0] == ' ') {
            message = message.substr(1);
        }
        return message.empty() ? "Usage: say [your message]" : message;
    } 
    else {
        return "Unknown command in your language: '" + command + "'";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << "========================================\n";
    std::cout << "      Custom C++ Terminal v1.0          \n";
    std::cout << "      Type 'exit' to quit               \n";
    std::cout << "========================================\n\n";

    std::string input_buffer;
    input_buffer.reserve(512);

    while (true) {
        std::cout << "mylang> ";
        std::cout.flush(); 

        if (!std::getline(std::cin, input_buffer)) {
            break; 
        }

        std::string result = evaluate_custom_language(input_buffer);
        if (!result.empty()) {
            std::cout << result << "\n";
        }
    }

    return 0;
}
