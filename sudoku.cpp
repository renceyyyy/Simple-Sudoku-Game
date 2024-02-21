#include <iostream>
#include <graphics.h>
#include <conio.h>

const int GRID_SIZE = 9;
const int CELL_SIZE = 50;

int sudoku[GRID_SIZE][GRID_SIZE] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

int originalSudoku[GRID_SIZE][GRID_SIZE];  // Store the original puzzle

void copySudoku() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            originalSudoku[i][j] = sudoku[i][j];
        }
    }
}

void resetSudoku() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            sudoku[i][j] = originalSudoku[i][j];
        }
    }
}

void drawGrid() {
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(500, 200, "W - Move forward ");
    setcolor(RED);
    for (int i = 0; i <= GRID_SIZE; i++) {
        line(0, i * CELL_SIZE, GRID_SIZE * CELL_SIZE, i * CELL_SIZE);
        line(i * CELL_SIZE, 0, i * CELL_SIZE, GRID_SIZE * CELL_SIZE);
    }
}

void drawNumbers() {
    settextstyle(8, 0, 4);

    char buffer[2];

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (sudoku[i][j] != 0) {
                sprintf(buffer, "%d", sudoku[i][j]);
                outtextxy(j * CELL_SIZE + CELL_SIZE / 3, i * CELL_SIZE + CELL_SIZE / 4, buffer);
            }
        }
    }
}

void moveCursor(int &cursorX, int &cursorY, char key) {
    switch (key) {
        case 'W':
        case 'w':
            cursorY = (cursorY - 1 + GRID_SIZE) % GRID_SIZE;
            break;
        case 'S':
        case 's':
            cursorY = (cursorY + 1) % GRID_SIZE;
            break;
        case 'A':
        case 'a':
            cursorX = (cursorX - 1 + GRID_SIZE) % GRID_SIZE;
            break;
        case 'D':
        case 'd':
            cursorX = (cursorX + 1) % GRID_SIZE;
            break;
    }
}

bool isSudokuComplete() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (sudoku[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}
bool isDigitValid(int digit, int row, int col) {
    // Check if the digit already exists in the same row
    for (int i = 0; i < GRID_SIZE; i++) {
        if (sudoku[row][i] == digit) {
            return false;
        }
    }

    // Check if the digit already exists in the same column
    for (int i = 0; i < GRID_SIZE; i++) {
        if (sudoku[i][col] == digit) {
            return false;
        }
    }

    return true;
}


int main() {
    int gd = DETECT, gm;
    initwindow(800, 500, "Sudoku Game", 150, 50);
    int cursorX = 0, cursorY = 0;
    char key;

    copySudoku();  // Store the original puzzle

     while (1) {
        drawGrid();
        drawNumbers();

        setcolor(BLUE);
        rectangle(cursorX * CELL_SIZE, cursorY * CELL_SIZE, (cursorX + 1) * CELL_SIZE, (cursorY + 1) * CELL_SIZE);

        key = getch();

        if (key == 27) // ESC key
            break;

        if (isdigit(key) && originalSudoku[cursorY][cursorX] == 0) {
            int digit = key - '0';

            // Check if the digit is valid in the current position
            if (isDigitValid(digit, cursorY, cursorX)) {
                sudoku[cursorY][cursorX] = digit;
            }
        }

        moveCursor(cursorX, cursorY, key);

        cleardevice();

        if (isSudokuComplete()) {
            outtextxy(500, 250, "Completed!");
            delay(10000);
            break;
        }
    }

    resetSudoku();  // Reset the puzzle for future games

    closegraph();
    return 0;
}
