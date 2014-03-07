#ifndef H_UI
#define H_UI

#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <curses.h>

#include "word.hpp"

enum {
	POS_HEAD,
	POS_BODY,
	POS_FOOT
};

class WordView {
	public:
		int position;
		Word* word;
};


class Ui {
	public:
		Ui();
		~Ui();
		void wrender(WINDOW *win);
		void render();
		void move(int l);
		void pushView(Word* w, int pos);
	
	private:
		std::vector<WordView> m_words;
		int m_pos;
		int m_w, m_h;
		
};


#endif
