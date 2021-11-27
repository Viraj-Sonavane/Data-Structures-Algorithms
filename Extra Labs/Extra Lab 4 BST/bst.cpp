#include<iostream>
using namespace std;

#include "bst.h"
	

Tnode* BST::balance(Tnode *cur){
								int bf = balanceFactor(cur);
								if(bf > 1){//left subtree is higher
									if(getHeight(cur->left->left) >= getHeight(cur->left->right)){
										cur = rightRotation(cur);//height is updated
									}//outside case
									else{
										cur->left = leftRotation(cur->left);
										cur = rightRotation(cur);
									}//inside case
								}//bf = 2
								else if(bf < -1){
									if(getHeight(cur->right->right) >= getHeight(cur->right->left)){
										cur = leftRotation(cur);
									}//outside case
									else{
										cur->right = rightRotation(cur->right);
										cur = leftRotation(cur);
									}
								}//if bf = -2
								else{
									updateHeight(cur);
									updateSize(cur);
								}
								return cur;
}


Tnode* BST::getLeftmost(Tnode* cur){
	if(cur == NULL)
		return NULL;
	if(cur->left == NULL)
		return cur;
	return getLeftmost(cur->left);
}//getLeftmost

void BST::updateHeight(Tnode *cur){
	if(cur == NULL)
		return;
	int hl = -1, hr = -1;
	if(cur->left != NULL)
		hl = cur->left->height;
	if(cur->right != NULL)
		hr = cur->right->height;
	cur->height = (hl > hr) ? (hl + 1) : (hr + 1);

}//updateHeight
				
int BST::balanceFactor(Tnode *cur){
	int hl = -1, hr = -1;
	if(cur->left != NULL)
		hl = cur->left->height;
	if(cur->right != NULL)
		hr = cur->right->height;
	return (hl - hr);
}
				
Tnode* BST::rightRotation(Tnode *cur){
	Tnode *L = cur->left;
	cur->left = L->right;
	updateHeight(cur);
	updateSize(cur);
	L->right = cur;
	updateHeight(L);
	updateSize(L);
	return L;
}

Tnode* BST::leftRotation(Tnode *cur){
	Tnode *R = cur->right;
	cur->right = R->left;
	updateHeight(cur);
	updateSize(cur);
	R->left = cur;
	updateHeight(R);
	updateSize(R);
	return R;
}

void BST::print_inorder(Tnode *cur){
		if(cur == NULL)
                return;				
        print_inorder(cur->left);
		cout << cur->key<< " ";
        print_inorder(cur->right);
	    
}//print_inorder

void BST::clean(Tnode *cur){
        if(cur == NULL)
                return;
        clean(cur->left);
        clean(cur->right);
        delete cur;
}//clean()

Tnode* BST::insert(Tnode *cur, int akey){
               if(akey < cur->key){
                        if(cur->left == NULL){
                                cur->left = new Tnode(akey);
								updateHeight(cur);
								updateSize(cur);
                                }//if found place
                        else{
                                cur->left = insert(cur->left, akey);
								cur = balance(cur);
						}//else
						
                }//if 
                else if(akey > cur->key){
                        if(cur->right == NULL){
                                cur->right = new Tnode(akey);
								updateHeight(cur);
								updateSize(cur);
                                }
                        else{
                                cur->right = insert(cur->right, akey);
								cur = balance(cur);
						
						}
						
                }//else if
                else{
					//do nothing, do not insert a copy 
                        }

				return cur;
      
}//insert()


int BST:: findRank(int k)
{
	int degree=0;
	int m = findnode(root,k,degree);	 
    return m;   
}

int BST:: findnode(Tnode*cur,int k,int degree)
{
	int initial;
	
	if(!cur)
	{
		return 0;
	}
	if(k!=cur->key)
	{
		if(k < cur->key)
		{
			return findnode(cur->left,k,degree);
		}
		if(k > cur->key)
		{
			
			initial = getSize(cur->left)+degree;
			degree = initial+1;
			return findnode(cur->right,k,degree);
		}	
	}
	if(k==cur->key && k<root->key && cur->left==NULL && cur->right==NULL)
	{
		return 0;
	}
	else
	{	
	 int final = getSize(cur->left)+degree;
	 return final;
	}
}

