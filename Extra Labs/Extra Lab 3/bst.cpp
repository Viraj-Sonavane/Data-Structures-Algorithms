#include<iostream>
#include<climits>
using std::string;
using std::cout;
using std::endl;
//using std::INT_MIN;

#include "bst.h"


void BST::print_inorder(Tnode *cur){
        if(cur == NULL)
                return;
        print_inorder(cur->left);
        cout << cur->value <<  " "  ;
        print_inorder(cur->right);
}//print_inorder


void BST::clean(Tnode *cur){
        if(cur == NULL)
                return;
        clean(cur->left);
        clean(cur->right);
        delete cur;
}//clean()

bool BST::insert(Tnode *cur, int aval){
			  
               if(aval < cur->value){
                        if(cur->left == NULL){
                                cur->left = new Tnode(aval);
								cur->size = cur->size + 1;
                                return true;
                                }
                        else{
                                bool res = insert(cur->left, aval);
								if(res)
									cur->size = cur->size + 1;
								return res;
								
						}
                }//if 
                else if(aval > cur->value){
                        if(cur->right == NULL){
                                cur->right = new Tnode(aval);
								cur->size = cur->size + 1;
                                return true;
                                }
                        else{
                                bool res = insert(cur->right, aval);
								if(res)
									cur->size = cur->size + 1;
								return res;
						}
                }//else if
                else{
                        return false;//only distinct integers are allowed
                }      
}//insert()

Tnode* BST::findLeftmost(Tnode* r){
	if(r == NULL)
		return NULL;
	if(r->left != NULL)
		return findLeftmost(r->left);
	else
		return r;
}

Tnode* BST::findRightmost(Tnode* r){
	if(r == NULL)
		return NULL;
	if(r->right != NULL)
		return findRightmost(r->right);
	else
		return r;
}


int BST::previous(int val)
{
     Tnode* temp = getPrevious(val);
     if(temp->left==NULL && temp->right==NULL)
        {
          return INT32_MIN;
        }
     return temp->value;
}

Tnode* BST::getPrevious(int val)
{
  Tnode* temp1 = findNode(root,val);
  Tnode* s = root;
  Tnode* a;

        if(val<s->value) 
        {
            while(temp1->left!=NULL)
            {          
                temp1=temp1->left;
            }
            if(temp1->left==NULL && temp1->right==NULL)
            {
                return temp1;
            }
            else
            {
                return temp1 = temp1->right;
            }
            
        }

        if(temp1->left!=NULL)
        {
          Tnode* temp2 = temp1->left;
          while(temp2->right!=NULL)
          {    
             temp2 = temp2->right;     
          }
          return temp2;                
        }

        if(val!=s->value)
        {
          while(val!=s->value)
          {
           if(val > s->value)
           {
             a = s;
             s = s->right; 
           }
           else
           {
             s = s->left;
           }
          }
          return a;
        }
 }

Tnode* BST::findNode(Tnode* cur,int val)
{
  if(cur->value == val)
  {
          return cur;
  }
  else if(val<cur->value)
  {
        return findNode(cur->left,val);
  }
  else if(val>cur->value)
  {
          return findNode(cur->right,val);
  }
}