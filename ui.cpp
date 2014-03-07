
#include "ui.hpp"


Ui::Ui() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	start_color();
	init_pair(1, 4, 0);
	
	//signal(SIGWINCH, resizeHandler);
	
	pushView(new Word(), POS_BODY);
	pushView(new Rule(), POS_BODY);
	
	m_pos = 0;
}

Ui::~Ui() {
	for(int j = 0 ; j < m_words.size() ; j++) {
		delete m_words[j].word;
	}
	endwin();
}

void Ui::wrender(WINDOW *win) {
	werase(win);
	getmaxyx(win, m_h, m_w);
	int y, count_head = 0, count_body = 0, count_foot = 0;
	for(int j = 0 ; j < m_words.size() ; j++) {
		switch (m_words[j].position) {
			case POS_HEAD:
				y = count_head++;
				break;
			case POS_BODY:
				y = m_h/2 + (count_body++);
				break;
			case POS_FOOT:
				y = m_h - 1 - (count_foot++);
				break;
			default:
				std::cerr << "Position invalide !" << std::endl;
		}
		wmove(win, y, 0);
		for (int i = 0 ; i < m_w ; i++) m_words[j].word->lookat(i + m_pos).wdraw(win);
	}
	refresh();
}

void Ui::render() {
	wrender(stdscr);
}


void Ui::move(int l) {
	m_pos += l;
}

void Ui::pushView(Word* w, int pos) {
	WordView wv;
	wv.word = w;
	wv.position = pos;
	m_words.push_back(wv);
}



