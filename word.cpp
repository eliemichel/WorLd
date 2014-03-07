
#include "word.hpp"


Word::Word() {
	
}

Word::~Word() {
	for (std::map<int, Sym*>::iterator it = m_data.begin() ; it != m_data.end() ; it++) {	
		delete it->second;
	}
}

Sym Word::lookat(int i){
	if (m_data.count(i) == 0) {
		return *(m_data[i] = new Sym(true));
	}
	else {
		return *m_data[i];
	}
}


Sym Rule::lookat(int i){
	if (m_data.count(i) == 0) {
		Sym *s = new Sym();
		if (i % 10 == 0) {
			std::stringstream ss;
			char c;
			s->push(0, 0, ACS_VLINE | COLOR_PAIR(1));
			ss << i;
			for (int j = 1 ; (bool)(ss >> c) ; j++) {
				s->push(j-1, 1, c);
			}
			if (i != 0) s->pop();
		}
		else if (i % 5 == 0) {
			s->push(0, 0, ACS_BULLET | COLOR_PAIR(1));
		}
		else {
			s->push(0, 0, ' ' | COLOR_PAIR(1));
		}
		return *(m_data[i] = s);
	}
	else {
		return *m_data[i];
	}
}

