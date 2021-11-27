#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::cerr;

#include "bst.h"


int main()
{
	string command;

    while(cin >> command)
	{
		if(command == "findRank")
		{
			int size;
			int akey;
			cin >> size >> akey;
			BST numbers;
			for(int i = 0; i < size; i++)
			{
				int x;
				cin >> x;
				//cout << x << endl;
				numbers.insert(x);
			}
			int my_rank = numbers.findRank(akey);
			cout << "Rank of node " << akey << " is " << my_rank << endl;
		}
		else
		{
			cerr << "ERROR: the command " << command << " is not found." << endl;
		}
    }//while
    return 0;
}//main()
