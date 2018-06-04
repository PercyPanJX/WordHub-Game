# WordHub-Game

The game: WordHub
The idea: A player gets a set of letters of size x (you pick) and then generates as many words as possible with those letters only. The words are then checked for validity or not, and a player gets a final score that is the total number of words that used only the letters and occur in a dictionary versus the words that either use invalid letters or don’t occur in the dictionary.

The crux of this: Reading in a dictionary file into either a Binary Search Tree or a BST modified using AVL (an AVL tree). For this, I used a flag to set whether, as words are being inserted into the binary search tree, the tree is also balanced and updated using AVL techniques or not.

