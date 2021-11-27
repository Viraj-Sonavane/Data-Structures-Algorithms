#include<iostream>
using namespace std;

#include "tnode.h"
#ifndef BST_H
#define BST_H

class BST{
        public:
                BST():  root(NULL) {};
                ~BST(){ clean(root); root = NULL; };
                
				void insert(int akey){
					if(root == NULL){
						root = new Tnode(akey);
						return;
					}
					root = insert(root, akey);
					updateHeight(root);
					
				};
				void print_inorder(){ 
					print_inorder(root);
                    cout << endl;
				};

				//given a key, find it's rank in in-order traversal in AVL-tree
				//if does not exist in the tree, return -1
				int findRank(int k);
				
				
				
		private:

			Tnode* balance(Tnode *cur);
			int getSize(Tnode *cur){
				if(cur == NULL)
					return 0;
				return cur->size;
			}
			void updateSize(Tnode *cur){
				if(cur == NULL)
					return;
				cur->size = 1 + getSize(cur->left) + getSize(cur->right);
			}//updateSize

			Tnode* getLeftmost(Tnode* cur);
			int getHeight(Tnode *cur){
				if(cur == NULL)
					return -1;
				else
					return cur->height;
			};
			void updateHeight(Tnode *cur);
			int balanceFactor(Tnode *cur);
			Tnode* rightRotation(Tnode *cur);
			Tnode* leftRotation(Tnode *cur);
			Tnode* insert(Tnode *cur, int akey);
			void print_inorder(Tnode *cur);
			Tnode *root = NULL;
			void clean(Tnode* cur);
			Tnode* copy(Tnode* cur);
			int findnode(Tnode*cur, int rank,int k);
};


#endif
