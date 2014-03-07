
#include "sym.hpp"


Sym::Sym() {
}

Sym::Sym(bool isWorld) {
	if (isWorld) {
		int j, maxj = rand() % 5 + 1;
		switch (rand() % 10) {
			case 0:
				for (j = 0 ; j < maxj ; j++)
					push(0, -j, 'T');
				break;
			case 1:
				push(0, 0, 'H');
				break;
			case 2:
				for (j = 0 ; j < maxj ; j++)
					push(0, -j, 'C');
				break;
		}
	}
}

Sym::Sym(chtype ch) {
	push(0, 0, ch);
}

void Sym::wdraw(WINDOW *win) {
	int oldX, oldY;
	getyx(win, oldY, oldX);
	int x, y;
	getyx(win, y, x);
	Symel sl;
	for (int i = 0 ; i < m_data.size() ; i++) {
		sl = m_data[i];
		mvwaddch(win, y + sl.y, x + sl.x, sl.ch);
	}
	wmove(win, oldY, oldX + 1);
}


void Sym::push(int x, int y, chtype ch) {
	Symel sl;
	sl.ch = ch;
	sl.x = x;
	sl.y = y;
	m_data.push_back(sl);
}

void Sym::pop() {
	m_data.pop_back();
}


