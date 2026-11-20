#include<iostream>
#include<string>

int main(){
	std::string command;
	while (true){
		std::cout << "<>@ "; std::getline(std::cin, command);
		if (command == "exit") {std::cout << "exited successfully"; return 1;}
	}
	return 0;
}
