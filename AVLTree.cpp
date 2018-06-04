/*
  * Authors: Jiaxuan Pan, Qun Chen
 */
#include "NodeT.hpp"
#include "AVLTree.hpp"
#include <string>
#include <iostream>
using namespace std;

AVLTree::AVLTree(bool flag){
	AVLflag = flag;
	root = NULL;
}

int checkwords(string s, NodeT *r){
	int flag; 						//if s > r->word, 1; if =, 0; if <, -1;
		int i = 0;
		if(s == r->word){
			flag = 0;
		}else{
			while(r->word[i]){
				if(int(r->word[i]) > int(s[i])) {
					flag = -1;
					break;
				}
				if(int(r->word[i]) < int(s[i])) {
					flag = 1;
					break;
				}
				if(int(r->word[i]) == int(s[i]))i++;
			}
		}								//check the relationship between s and r
		return flag;
}

bool AVLTree::findWord (string s, NodeT *n){
	if(!n) return false;
	if(s == n->word) return true;
	int flag = checkwords(s,n);
	if(flag == 1) return findWord(s, n->right);
	if(flag == -1) return findWord(s, n->left);
}

void AVLTree::addNode(string s, NodeT *r){
	if(!r){
		r = root = new NodeT(s);
		return;
	}

	int flag = checkwords(s, r);

	if(flag == 1 && !r->right){
		NodeT *nnode = new NodeT(s);
		r->right = nnode;
		r->right->parent = r;
		if(AVLflag == true)	adjustHeights(nnode);
		return;
	}

	if(flag == -1 && !r->left){
		NodeT *nnode = new NodeT(s);
		r->left = nnode;
		r->left->parent = r;
		if(AVLflag == true)	adjustHeights(nnode);
		return;
	}

	if(flag == 1){
		addNode(s, r->right);
		return;
	}
	if(flag == -1){
		addNode(s,r->left);
		return;
	}
	if(flag == 0){
		return;
	}


}

void AVLTree::printIO(NodeT *root){
	if(!root) return;
	printIO(root->left);
	cout << root->word << ", ";
	printIO(root->right);
}

void AVLTree::printPre(NodeT *root){
	if(!root) return;
	cout << root->word << ", ";
	printPre(root->left);
	printPre(root->right);
}

void AVLTree::printPost(NodeT *root){
	if(!root) return;
	printPost(root->left);
	printPost(root->right);
	cout << root->word << ", ";
}

void AVLTree::adjustHeights(NodeT *n){
	if(!n) return;

	int diff = getDiff(n);
	int ldiff = getDiff(n->left);
	int rdiff = getDiff(n->right);

	if(diff==-2){
		if(rdiff ==-1){
			if(!n->parent)	root = rotateLeft(n);
			else if(n->parent->left == n) n->parent->left = rotateLeft(n);
			else n->parent->right = rotateLeft(n);
		}
		else if(rdiff == 1){
			n->right = rotateRight(n->right);
			if(!n->parent) root = rotateLeft(n);
			else if(n->parent->left == n) n->parent->left  =  rotateLeft(n);
			else n->parent->right = rotateLeft(n);
		}
	}

	if(diff == 2){
		if(ldiff == 1){
			if(!n->parent) root = rotateRight(n);
			else if(n->parent->left == n) n->parent->left  = rotateRight(n);
			else n->parent->right  = rotateRight(n);
		}
		else if(ldiff == -1){
			n->left = rotateLeft(n->left);
			if(!n->parent) root  = rotateRight(n);
			else if(n->parent->left == n) n->parent->left  = rotateRight(n);
			else n->parent->right  = rotateRight(n);
		}
	}

	adjustHeights(n->parent);
}

int AVLTree::getMax(NodeT *n){
	if(!n) return 0;
	int lmax = getMax(n-> left) + 1;
	int rmax = getMax(n-> right) + 1;
	return max(lmax,rmax);
}

NodeT *AVLTree::rotateRight(NodeT *n){

	NodeT *nparent = n->left;
	if(nparent->right != NULL) nparent->right->parent = n;
	n->left = nparent->right;
	nparent->parent = n->parent;
	n->parent = nparent;
	nparent->right = n;
	return nparent;
}

NodeT *AVLTree::rotateLeft (NodeT *n){

	NodeT *nparent = n->right;
	if(nparent->left != NULL) nparent->left->parent = n;
	n->right = nparent->left;
	nparent->parent = n->parent;
	n->parent = nparent;
	nparent->left = n;
	return nparent;
}

int AVLTree::getDiff(NodeT *n){
	if(!n) return 0;
	else return getMax(n->left) - getMax(n->right);
}
