#include<iostream>
using namespace std;

#include "bst.h"

void BST::heightPrint(Tnode *cur){
	if(cur != NULL){
		heightPrint(cur->left);
		cout << cur->height << " ";
		heightPrint(cur->right);
	}

}
void BST::findPrint(Tnode *cur, string akey){
	if(cur != NULL){
		if(cur->key == akey){
			int asize = (int)(cur->value).size();
			for(int i = 0; i < asize ; i++)
				cout << (cur->value)[i] << " ";
			cout << endl;
			return;
		}else if(akey < cur->key)
			findPrint(cur->left, akey);
		else
			findPrint(cur->right, akey);
	}
}//findPrint()

void BST::print_inorder(Tnode *cur){
        if(cur == NULL)
                return;
        print_inorder(cur->left);
        cout << "(" << cur->key << "){";
		int asize = (int)(cur->value).size();
		for(int i = 0; i < asize; i++)
			cout << (cur->value)[i] << " " ;
		cout << "} ";
        print_inorder(cur->right);
}//print_inorder


void BST::clean(Tnode *cur){
        if(cur == NULL)
                return;
        clean(cur->left);
        clean(cur->right);
        delete cur;
}//clean()

Tnode* BST::insert(Tnode *cur, string akey, string aval)
{
int bfactor = 0;
  if(akey < cur->key)
  {
    if(cur->left == NULL)
	{
     cur->left = new Tnode(akey, aval);
	 updateHeight(cur);
     return cur;
    }
	
	else
	{
    cur->left = insert(cur->left, akey, aval);
	bfactor = balanceFactor(cur);
	if(bfactor<-1 || bfactor>1)
	cur = restoreBalance(cur);
	updateHeight(cur);
	return cur;
	}
  }

	else if(akey > cur->key)
	{
		if(cur->right == NULL)
		{
 	 	cur->right = new Tnode(akey, aval);
 	 	updateHeight(cur);
 	 	return cur;
	}
    	else
		{
		 cur->right = insert(cur->right, akey, aval);
		 bfactor = balanceFactor(cur);
		 if(bfactor< -1 ||bfactor > 1)
		 cur = restoreBalance(cur);
		 updateHeight(cur);
		 return cur;
		} 
	}//else if
    
	else
	{
	(cur->value).push_back(aval);
     return cur ;
    }


}//insert()

int BST:: getHeight(Tnode *cur)
{
	if(!cur)
	return -1;
	return cur->height;
}

void BST:: updateHeight(Tnode *cur)
{
	if(!cur)
	{
		return;
	}
	int lh = getHeight(cur->left);
	int rh = getHeight(cur->right);
	int myh = (lh>rh)? lh+1 : rh+1;
	cur->height = myh;
}

int BST:: balanceFactor(Tnode *cur)
{
	if(!cur)
	{
		return 0;
	}
	return getHeight(cur->left)-getHeight(cur->right);
}

Tnode* BST::rightRotation(Tnode *cur)
{
Tnode *leftChild = cur->left;
cur->left = cur->left->right;
updateHeight(cur);
leftChild->right = cur;
updateHeight(leftChild);
return leftChild;
}


Tnode* BST::leftRotation(Tnode *cur)
{
Tnode *rightChild = cur->right;
cur->right = cur->right->left;
updateHeight(cur);
rightChild->left = cur;
updateHeight(rightChild);
return rightChild;
}

Tnode* BST::restoreBalance(Tnode *cur)
{
	
	if(balanceFactor(cur)==2)
	{
		if(balanceFactor(cur->left)>=0)
		{
			cur = rightRotation(cur); 
		}
	
		else if(balanceFactor(cur->left)<0)
		{
			cur->left = leftRotation(cur->left);
			cur = rightRotation(cur);
		}			
	}

	else if(balanceFactor(cur)==-2)
	{
		if(balanceFactor(cur->right)<=0)
		{
			cur = leftRotation(cur);
		}
		else if(balanceFactor(cur->right)>0)
		{
	   		cur->right = rightRotation(cur->right);
	   		cur = leftRotation(cur);
		}
	}
	return cur;
}

void BST:: printBF(Tnode *cur)
{
	int bfactor = 0;
	if(cur != NULL)
	{
	printBF(cur->left);
	bfactor = balanceFactor(cur);
	cout<<bfactor<<" ";
	printBF(cur->right);
	}
}

Tnode* BST::getleftmost(Tnode*cur)
{
	if(cur->left == NULL)
	{
		return cur;
	}
	else if(cur->left!=NULL)
	{
		return getleftmost(cur->left);
	}	
}

Tnode* BST:: remove(Tnode* cur,string akey)
{
 if(!cur)
 return cur;
	 if(akey == cur->key)
	 {
		 if(!cur->left && !cur->right)
		 {
			 delete cur;
			 return NULL;
		 }//if
		 else if(!cur->left || !cur->right)
		 {
			 Tnode *t = cur->left;
			 if(!cur->left)
			 t = cur->right;
			 delete cur;
			 return t;
		 }//elseif
		 else
		 {
			 Tnode *lmn = getleftmost(cur->right);
			 cur->key = lmn->key;
			 cur->value = lmn->value;
			 cur->right = remove(cur->right,lmn->key);
			 int bfactor = balanceFactor(cur);
			 if(bfactor<-1||bfactor>1)
			 cur = restoreBalance(cur);
			 updateHeight(cur);
		 }//else		 
	 }
	 else if(akey< cur->key)
	 {
		 cur->left = remove(cur->left,akey);	
		 int bfactor = balanceFactor(cur);
		 if(bfactor<-1|| bfactor>1)
		 cur = restoreBalance(cur);
		 updateHeight(cur); 
	 }//elseif
	 else
	 {
		 cur->right = remove(cur->right,akey);
		 int bfactor = balanceFactor(cur);
		 if(bfactor<-1||bfactor>1)
		 cur = restoreBalance(cur);
		 updateHeight(cur);
	 }//else
	return cur;	 
 } 
