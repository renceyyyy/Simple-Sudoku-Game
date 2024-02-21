#include <iostream>
#include <graphics.h>
#include <windows.h>
#include <conio.h> 
#include "functions.cpp"

const int GRID_SIZE = 9;
const int CELL_SIZE = 50;               //for the size of the sudoku cell
 
int sudoku[GRID_SIZE][GRID_SIZE] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},            //for the grid of the sudoku game
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},                 
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};
 
 int originalSudoku[GRID_SIZE][GRID_SIZE]; 

void SudokuNumber() {                         
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

    void Grid() {
	setcolor(BLACK);
	settextstyle(EUROPEAN_FONT,HORIZ_DIR,1);
	outtextxy(500, 50,  "W - Move Up ");
	outtextxy(500, 100, "S - Move Down ");            
	outtextxy(500, 150, "A - Move Left ");
	outtextxy(500, 200, "D - Move Right ");
    setcolor(LIGHTGREEN);
    for (int i = 0; i <= GRID_SIZE; i++) {
        line(0, i * CELL_SIZE, GRID_SIZE * CELL_SIZE, i * CELL_SIZE);
        line(i * CELL_SIZE, 0, i * CELL_SIZE, GRID_SIZE * CELL_SIZE);
    }
}
 
void Numbers() {
    settextstyle(10, 0, 4); 
 
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
 
void moveControl(int &controlX, int &controlY, char key) {
    switch (key) {
        case 'W':
        case 'w':
            controlY = (controlY - 1 + GRID_SIZE) % GRID_SIZE;          
            break;
        case 'S':
        case 's':
            controlY = (controlY + 1) % GRID_SIZE;                          //for the controls of the sudoku game
            break;
        case 'A':
        case 'a':                                                          
            controlX = (controlX - 1 + GRID_SIZE) % GRID_SIZE;
            break;
        case 'D':
        case 'd':
            controlX = (controlX + 1) % GRID_SIZE;
            break;
    }
}

bool completed() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {           
            if (sudoku[i][j] == 0) {
                return false;                  
            }
        }
    }
    return true;
}

bool Available(int number, int row, int col) {     // Check if the digit already exists in the same row
    for (int i = 0; i < GRID_SIZE; i++) {
        if (sudoku[row][i] == number) {
        	std::cout<< "Invalid Input";
            return false;
        }
    }
    for (int i = 0; i < GRID_SIZE; i++) {           // Check if the digit already exists in the same column
        if (sudoku[i][col] == number) {
        	std::cout<< "Invalid Input";
            return false;
        }
    }

    return true;
}

int main() {
    int gd = DETECT, gm;
    initwindow(800,500,"Sudoku Game",150,50);
    int controlX = 0, controlY = 0;
    Menu();
    
    char input;
    SudokuNumber();                // Store the original sudoku game
    
    do {
        input = getch();
        switch (input) {
            case '1':
            	cleardevice();
    while (1) {
        Grid(); 
        Numbers();     //for the numbers
 
        setcolor(BLACK); 
        rectangle(controlX * CELL_SIZE, controlY * CELL_SIZE, (controlX + 1) * CELL_SIZE, (controlY + 1) * CELL_SIZE);   
 
        input = getch();
        cleardevice();
            if (input == 27) // ESC key
            {
            	settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
            	outtextxy(220, 220, "Not Completed!!!");
            	delay(5000);
            	 break;
			}
            
             if (isdigit(input) && originalSudoku[controlY][controlX] == 0) {
            int number = input - '0';
            
             if (Available(number, controlY, controlX)) {
            sudoku[controlY][controlX] = number;
        }
 }
        moveControl(controlX, controlY, input);
 
        cleardevice();
        
        if (completed()) {
        	setcolor(YELLOW);
        	settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
            outtextxy(250, 250, "Completed!");
            delay(10000);                     // if the program will be true, display the game completed.
            break;
        }
    }
    resetSudoku();
    
    closegraph();
                break;
            case '2':
                cleardevice();           //the about of the game.
				about();
                break;
                
            case '3':
			    cleardevice();        //to display the names of the programmer.
			    programmer(); 
			    break;
			  
            case 27:  
                cleardevice();            //for the esc to go back in the game menu.
                Menu();
                break;
                
            case '4':
            	setbkcolor(RED);
                cleardevice();
                setcolor(BLACK);
                settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
                outtextxy(250, 200, "Exit the Game!!!");              //to exit the game
                delay(5000);
                break;
            default:
                break;
        }
    } while (input != '4');

    closegraph();

    return 0;
}

