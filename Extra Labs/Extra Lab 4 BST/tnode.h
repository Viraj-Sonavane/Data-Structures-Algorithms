#include<iostream>
#include<vector>
#include<string>
using namespace std;

#ifndef TNODE_H
#define TNODE_H


class Tnode{
        public:
                Tnode(): left(NULL), right(NULL) {};
				Tnode(int akey){
					key = akey;
					height = 0;
					left = NULL;
					right = NULL;
					size = 1;
				};
                int key;
				int height;
                Tnode* left;
                Tnode* right;
				int size;
};

#endif
