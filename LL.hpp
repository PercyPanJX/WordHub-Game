/*
 * LL.hpp
 *
 *  Created on: Nov 4, 2017
 *      Author: Percy
 */

#ifndef LL_HPP_
#define LL_HPP_
#include "NodeL.hpp"
#include <string>

class LL{
	friend class Game;
public:
	NodeL *first;
	NodeL *last;
	int size;
	int score;

	LL();
	void push(string s);
	void addFirst(string s);
	void printList();
	void getScore();

};


#endif /* LL_HPP_ */
