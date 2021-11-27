#include<vector>
#include<list>

#include "tnode.h"

#ifndef BST_H
#define BST_H

using std::vector;
using std::list;

class BST{
        public:
                BST():  root(NULL) {};
                ~BST(){ clean(root); root = NULL; };
                
				void insert(int aval){
					if(root == NULL){
						root = new Tnode(aval);
						return;
					}
					insert(root, aval);
					
				};

				void print_inorder(){ print_inorder(root);
                        cout << endl;
				};
				int size(){ return root->size; }

				int previous(int val);

		private:
				Tnode* root = NULL;
				bool insert(Tnode *cur, int aval);
				void print_inorder(Tnode *cur);
				void clean(Tnode* cur);
				Tnode* findLeftmost(Tnode *cur);
				Tnode* findRightmost(Tnode *cur);
				Tnode* findNode(Tnode* cur,int val);
				Tnode* getPrevious(int val);
				
};


#endif
