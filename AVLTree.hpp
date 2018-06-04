/*
 * Authors: Jiaxuan Pan, Qun Chen
 */

#ifndef AVLTREE_HPP_
#define AVLTREE_HPP_
#include "NodeT.hpp"
#include <string>

class AVLTree{
	friend class Game;
public:
	NodeT *root; // holds the root of the bst
	bool AVLflag; // flag for whether to adjust bst to be an avl tree

	AVLTree(bool flag); //constructor
	bool findWord (string s, NodeT *n);
	void addNode(string s,NodeT *r);
	void printIO(NodeT *root);
	void printPre(NodeT *root);
	void printPost(NodeT *root);

	void adjustHeights(NodeT *n);
	int getMax(NodeT *n);

	//the below methods are just for AVL Trees and are only called when the AVL flag is set to true.
	NodeT *rotateRight(NodeT *n);
	NodeT *rotateLeft(NodeT *n);
	int getDiff(NodeT *n);

};



#endif /* AVLTREE_HPP_ */
