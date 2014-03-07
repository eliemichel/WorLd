#ifndef H_WORD
#define H_WORD

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <curses.h>

#include "sym.hpp"


class Word {
	public:
		Word();
		~Word();
		virtual Sym lookat(int i);
	
	protected:		
		std::map<int, Sym*> m_data;
};

class Rule : public Word {
	public:
		Sym lookat(int i);
};



#endif

