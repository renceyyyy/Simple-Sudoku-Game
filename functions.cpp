#include <iostream>
#include <windows.h>
#include <graphics.h>

//for the game menu
void Menu() {
	setbkcolor(CYAN);
    cleardevice();
    setcolor(BLACK);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
    outtextxy(250, 100, "Sudoku Game");
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
    outtextxy(290, 200, "Start");
    outtextxy(290, 260, "About");
    outtextxy(290, 320, "Programmer");
    outtextxy(290, 380, "Exit");
}

// for the about page
void about(){
	 cleardevice();
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
    outtextxy(50, 50, "About Game");
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,2);
    outtextxy(70, 150, "The Sudoku rules emphasize using logic,deduction");
    outtextxy(70, 200, "and pattern identification to fill in the grid ");
    outtextxy(70, 250, "without guessingor experimenting. the solver's");
    outtextxy(70, 300, "objective is to logically determine and arrange");
    outtextxy(70, 350, "the remaining numbers in a fashion that satisfies");
    outtextxy(70, 400, "the requirements and yields a single solution.");
}
//for the programmer page
    void programmer(){
    	cleardevice();
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
    outtextxy(50, 50, "Programmer");
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,2);
    outtextxy(70, 150, "Clyde Cahayag");
    outtextxy(70, 200, "Laurence James Balon");
    outtextxy(70, 250, "John Mark Cahayag");
    outtextxy(70, 300, "Renz Espino");
    outtextxy(70, 350, "John Mark Mayote");
    outtextxy(70, 400, "Errol Montoya");
	}
