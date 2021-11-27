#include <stdlib.h>
#include<iostream>
#include<string>
#include<iomanip>
#include<stdio.h>
#include<cstdio>
#include<cmath>
#include<fstream>
using namespace std;

#include "bst.h"


int main(int argc, char* argv[]){

	
    BST numbers;//Object 
	string command;
	while(cin >> command){//
		if(command == "print_inorder"){
			numbers.print_inorder();
			cout << endl;
		}else if(command == "heightPrint"){
			numbers.heightPrint();
			cout << endl;
		}else if(command == "printBF"){
			numbers.printBF();
			cout << endl;
		}
		else if(command == "findPrint"){
			string akey;
			cin >> akey;
			numbers.findPrint(akey);
		}else if(command == "insert"){
			string word;
			cin >> word;
			int len ;
			cin >> len;
			string akey = word.substr(0, len);
			numbers.insert(akey, word);
		}else if(command == "remove"){
			string akey;
			cin >> akey;
			numbers.remove(akey);
		}else if(command == "printSize"){
			numbers.printSize();
			cout << endl;
		}else if(command == "findLCA"){
			string k1;
			string k2;
			cin >> k1;
			cin >> k2;
			cout<< numbers.findLCA(k1,k2)<<endl;
		}else if(command == "findKthSmallest"){
			int K;
			cin>>K;
			cout<<numbers.findKthSmallest(K)<<endl;
		}
		else if(command == "printLongestPath"){
			numbers.printLongestPath(); 
			cout <<endl;
	 	}
		else if(command == "collectSubtree"){
	
			vector <string> vtr; 
			string K; 
			cin>>K; 
			numbers.collectSubtree(K, vtr);
				for (int i =0; i<vtr.size(); i++)
				{
					cout <<vtr[i]<<" "; 
				}  
				cout <<end`l;
		}
		else{
			cerr << "ERROR: command " << command << " is not found." << endl;
		}
	}//while

    return 0;

}//main()
