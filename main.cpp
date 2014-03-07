#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <curses.h>
#include <signal.h>

#include "ui.hpp"

//void resizeHandler(int);



int main(int argc, char **arv) {
	Ui disp;
	
	disp.render();
	
	int ch;
	bool run = true;
	while (run) {
		switch (ch = getch()) {
			case 'q':
				run = false;
				break;
			
			case 'k':
				disp.move(1);
				disp.render();
				break;
			
			case 'l':
				disp.move(5);
				disp.render();
				break;
			
			case 'j':
				disp.move(-1);
				disp.render();
				break;
			
			case 'h':
				disp.move(-5);
				disp.render();
				break;
			
			case KEY_RIGHT:
				disp.move_cursor(1);
				disp.render();
				break;

			
			case KEY_LEFT:
				disp.move_cursor(-1);
				disp.render();
				break;
			
		}
	}
	
	return 0;
}

/*void resizeHandler(int sig) {
	disp.render();
	std::cout << "problème..." << std::endl;
}*/

