#ifndef H_SYM
#define H_SYM

#include <cstdlib>
#include <sstream>
#include <iostream>
#include <vector>
#include <curses.h>

class Symel {
	public:
		int x, y;
		chtype ch;
};

class Sym {
	public:
		Sym();
		Sym(bool isWorld);
		Sym(chtype ch);
		void wdraw(WINDOW *win);
		void push(int x, int y, chtype ch);
		void pop();
		const char *read_description();
	
	private:
		std::vector<Symel> m_data;
		std::string m_description;
};


#endif

