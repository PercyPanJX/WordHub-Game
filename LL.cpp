/*
 * LL.cpp
 *
 *  Created on: Nov 4, 2017
 *      Author: Percy
 */

#include "LL.hpp"
#include "NodeL.hpp"
#include <iostream>
#include <string>
using namespace std;

LL::LL(){
	first = NULL;
	last = NULL;
	size = 0;
	score = 0;
}

void LL::push(string s){
	if(first == NULL){
		addFirst(s);
	}
	else{
		last->next = new NodeL(s);
		last = last->next;
		size ++;
	}
}

void LL::addFirst(string s){
	first = new NodeL(s);
	last = first;
	size ++;
}

void LL::printList(){
	NodeL *temp = first;
	while(temp){
		cout << temp->word << ": " << temp->wscore <<", ";
		temp = temp->next;
	}
	cout <<endl;
}

void LL::getScore(){
	NodeL *temp = first;
	while(temp){
		score += temp->wscore;
		temp = temp->next;
	}
}
