#include <iostream>
#include <vector>
#include <string>

struct Cell {
    char character = ' ';
    std::string color = "\033[37m";
};

const int COLS = 60;
const int ROWS = 15;

void drawScreen(const std::vector<Cell>& grid) {
    std::cout << "\033[H"; 
    for (int y = 0; y < ROWS; ++y) {
        for (int x = 0; x < COLS; ++x) {
            const Cell& c = grid[y * COLS + x];
            std::cout << c.color << c.character;
        }
        std::cout << "\033[0m\n";
    }
}

int main() {
    std::vector<Cell> grid(COLS * ROWS);
    std::string input;
    int currentRow = 0;

    std::cout << "\033[2J"; 

    while (true) {
        drawScreen(grid);
        std::cout << "\033[32mmy-lang> \033[0m";
        if (!std::getline(std::cin, input) || input == "exit") break;

        for (size_t i = 0; i < input.size() && i < COLS; ++i) {
            grid[currentRow * COLS + i].character = input[i];
            grid[currentRow * COLS + i].color = "\033[36m";
        }
        currentRow = (currentRow + 1) % ROWS;
    }
    return 0;
}

