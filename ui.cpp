
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
	m_pos_cursor = 0;
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
		for (int i = 0 ; i < m_w ; i++)
			m_words[j].word->lookat(i + m_pos).wdraw(win);
		
		if (j == 1) {
			chtype ch = 0;
			wmove(stdscr, y, m_pos_cursor - m_pos);
			inchnstr(&ch, 1);
			addch(ch | A_REVERSE);
		}
	}
	
	wmove(win, m_h - 1, 0);
	printw(m_words[0].word->lookat(m_pos_cursor).read_description());
	
	refresh();
}

void Ui::render() {
	wrender(stdscr);
}


void Ui::move(int l) {
	m_pos += l;
	if ((m_pos_cursor - m_pos) < 0) {
		move_cursor(m_pos - m_pos_cursor);
	}
	else if ((m_pos_cursor - m_pos) >= m_w) {
		move_cursor(m_pos - m_pos_cursor + m_w - 1);
	}
}

void Ui::move_cursor(int l) {
	m_pos_cursor += l;
	if ((m_pos_cursor - m_pos) < 0) {
		move(m_pos_cursor - m_pos);
	}
	else if ((m_pos_cursor - m_pos) >= m_w) {
		move(m_pos_cursor - m_pos - m_w + 1);
	}
}

void Ui::pushView(Word* w, int pos) {
	WordView wv;
	wv.word = w;
	wv.position = pos;
	m_words.push_back(wv);
}



