#include<iostream> 
using namespace std;

#include "bst.h"

void BST::heightPrint(Tnode *cur)
{
	if(cur != NULL)
	{
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
  if(akey < cur->key)
  {
    if(cur->left == NULL)
	{
     cur->left = new Tnode(akey, aval);
	 updateHeight(cur);
	 //updateSize(cur);
     return cur;
    }
	
	else
	{
    cur->left = insert(cur->left, akey, aval);
	int bfactor = balanceFactor(cur);
	if(bfactor<-1 || bfactor>1)
	cur = restoreBalance(cur);
	updateHeight(cur);
	//updateSize(cur);
	return cur;
	}
  }

	else if(akey > cur->key)
	{
		if(cur->right == NULL)
		{
 	 	cur->right = new Tnode(akey, aval);
 	 	updateHeight(cur);
		//updateSize(cur);
 	 	return cur;
	}
    	else
		{
		 cur->right = insert(cur->right, akey, aval);
		 int bfactor = balanceFactor(cur);
		 if(bfactor< -1 ||bfactor > 1)
		 cur = restoreBalance(cur);
		 updateHeight(cur);
		 //updateSize(cur);
		 return cur;
		} 
	}//else if
    
	else
	{
	(cur->value).push_back(aval);
     return cur ;
    }
updateHeight(cur);
//updateSize(cur);
return cur;
}//insert()

int BST:: getHeight(Tnode *cur)
{
	if(!cur)
	return -1;
	else
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
	else
	return getHeight(cur->left)-getHeight(cur->right);
}

Tnode* BST::rightRotation(Tnode *cur)
{
Tnode *leftChild = cur->left;
cur->left = cur->left->right;
updateHeight(cur);
//updateSize(cur);
leftChild->right = cur;
updateHeight(leftChild);
//updateSize(leftChild);
return leftChild;
}


Tnode* BST::leftRotation(Tnode *cur)
{
Tnode *rightChild = cur->right;
cur->right = cur->right->left;
updateHeight(cur);
//updateSize(cur);
rightChild->left = cur;
updateHeight(rightChild);
//updateSize(rightChild);
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
			 //updateSize(cur);
		 }//else		 
	 }
	 else if(akey< cur->key)
	 {
		 cur->left = remove(cur->left,akey);	
		 int bfactor = balanceFactor(cur);
		 if(bfactor<-1|| bfactor>1)
		 cur = restoreBalance(cur);
		 updateHeight(cur); 
		 //updateSize(cur);
	 }//elseif
	 else
	 {
		 cur->right = remove(cur->right,akey);
		 int bfactor = balanceFactor(cur);
		 if(bfactor<-1||bfactor>1)
		 cur = restoreBalance(cur);
		 updateHeight(cur);
		 //updateSize(cur);
	 }//else
	return cur;	 
} 

int BST:: getSize(Tnode* cur)
{
 if(cur!=NULL)
 {	
 	return 0;
 }
 else
 {
 	return cur->size;
 }
}

void BST:: printSize(Tnode *cur)
{
		if(cur!=NULL)
	{
		printSize(cur->left);
		cout<<cur->size<<" ";
		printSize(cur->right);	
	}
}

void BST:: updateSize(Tnode *cur)
{
	if(!cur)
	{
		return;
	}
	else
	{
		int left = getSize(cur->left);
		int right= getSize(cur->right);
		cur->size = left + right + 1;
	}	
}

string BST::findLCA(Tnode *cur,string  akey1, string akey2)
{
	if(!cur)
	{
		return "";
	}
	else if(cur->key<akey1 && cur->key<akey2)
	{
		return findLCA(cur->right,akey1,akey2);
	}
	else if(cur->key>akey1 && cur->key>akey2)
	{
		return findLCA(cur->left,akey1,akey2);
	}
	else
	{
		return cur->key; 
	}
}

string BST::findKthSmallest(Tnode * cur , int k)
{
	if(!cur)\
	{
		return ""; 
	}

	int s =0;
	
	if (cur->left != NULL)
	{
		s = cur->left->size; 
		if(k<=s)
		{
			return findKthSmallest(cur->left ,k); 
		}
	} 
 	
	 if (k==s+1)
 	 {
		return cur->key; 
	 }
	
	else if (cur->right != NULL)
	{
		k = k-s-1; 	
		return findKthSmallest(cur->right , k); 		
	}
} 

void BST::printLongestPath(Tnode*cur)
{
	if(!cur)
	return;

	int lh = getHeight(cur->left);
	int rh = getHeight(cur->right);
	if(lh>=rh)
	{
		cout<<cur->key<<" ";
		printLongestPath(cur->left);
	}
	else
	{
		cout<<cur->key<<" ";
		printLongestPath(cur->right);
	}
}

Tnode * findNode (Tnode *cur , string k)
{
	if(!cur)
	{
		return NULL;
	}
	if(cur->key==k)
	{
		return cur;
	}
	else if(k<cur->key)
	{
		return findNode(cur->left,k);
	}
	else if(k>cur->key)
	{
		return findNode(cur->right,k);
	}
}

void BST::collectSubtree(Tnode * cur  , string k, vector<string> &v)
{
	if(cur == NULL)
    {
		return;
	}    
	collectSubtree(cur->left, k,v);
	v.push_back(cur->key);
	collectSubtree(cur->right, k , v);		
}


