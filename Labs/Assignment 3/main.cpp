#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<climits>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::cerr;

void print(const vector<int> &A)
{
	int size = (int)A.size();
	for(int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}

void print(const vector<vector<int> > &P)
{
	int size = (int)P.size();
	for(int i = 0; i < size; i++){
		print(P[i]);
	}//for
}

void print(queue<string> &p)
{
	while(!p.empty()){
		string s = p.front();
		p.pop();
		cout << s << endl;
	}//while
}

int recMin(const vector<int> &A, int start, int fin)
{
int res = 0;
if(start == fin)
{
	return A[start];
}

	int m = 0;
	m = (start+fin)/2;
	int L = recMin(A,start,m);
	int R = recMin(A,m+1,fin);

	if(L<R)
	{
		res = L;
		return res;
	}

	if(R<L)
	{
		res = R;
		return res;
	}
	if(L == R)
	{
		res = L;
		return res;
	}
	return res;
}

void subarraySums(const vector<int> &A, vector<int> &B, int fin)
{ 
	if(fin == 0)
 	{ 
		B[0]=A[0];	 
 	}
 	else
 	{
 		subarraySums(A,B,fin-1);
    	B[fin] = B[fin-1]+A[fin];
	}
}

bool recPal(const vector<int> &A, int first, int last)
{
	int m = (int)A.size()/2;	
	if(first == m)
	{
		return true;
	}
	
	if(first == last)
	{
		return true;
	}
	
	if(A[first] == A[last])
	{
		return recPal(A,first+1,last-1);
	}

	else
	{
		return false;
	}
	
}

bool recFindSorted(const vector<int> &A, int k, int start, int fin)
{
int m = (start+fin)/2;

	if(A[m]==k)
	{
	   return true;  	
	}

	if(k>A[m])
	{
		if(start == fin)
		{
			return false;
		}

		if(A[start]==k)
		{
			return true;	
		}
		return recFindSorted(A,k,m+1,fin);	
	}

	if(k<A[m])
	{	
		if(start == fin)
		{
			return false;
		}

		if(A[fin]==k)
		{
			return true;
		}
		return recFindSorted(A,k,start,m);
	}	

}

int findIndex(const vector<int> &A, int start, int fin)
{
	if(A[start]==start)
	{
		return start;
	}

	if(A[fin]==fin)
	{	
		return fin;
	}

	if(start >= fin)
	{
		return -1;
	}
	return findIndex(A,start+1,fin-1);
}

bool recFind(const vector<int> &A, int k, int start, int fin)
{
   int m = (start+fin)/2;
   bool res1,res2;

	if(A[m]==k)
	{
	   return true;  	
	}

	if(start == fin)
		{
			return false;
		}

		if(A[start]==k)
		{
			return true;	
		}
		
		if(A[fin]==k)
		{
			return true;
		}
		    res1 = recFind(A,k,m+1,fin);	
		    res2 = recFind(A,k,start,m);
		
		if(res1 == true)
		{
			return true;
		}
		else if(res2 == true)
		{
			return true; 
		}		
		
}


void powerSet(const vector<int> &A, vector< vector<int> > &P, int last)
{
  if(last==0)
  {
	 vector<int>t;
	 t.push_back(A[last]);
	 P.push_back(t);
  }
  
  else
  {
	powerSet(A,P,last-1); 
	
	vector<int>r;
	r.push_back(A[last]);
	P.push_back(r);
	
	int q = P.size()-1;  
	for(int i=0;i<q;i++)
	{
		vector<int>s;
		s = P[i];
		s.push_back(A[last]);
		P.push_back(s);
	}  
  }
}

void insertAtEachIndex(string front,char inserted,queue<string> &p)
{
	int result_index = 0;
	int insertion_index = 0;

		while(insertion_index <= front.length())
		{
			result_index = 0;
			int front_length = front.length();
			char result[front_length+1];

			for(int i=0;i<front.length();)
			{
				if(result_index == insertion_index)
				{
					result[result_index] = inserted;
					result_index++;
				}
				else
				{
					result[result_index] = front[i];
					result_index++;
					i++;
				}
			}
		
		if(insertion_index == front.length())
		{
			result[result_index] = inserted;
		}
		string result_string = ""; 

    	for (int i = 0; i < front_length+1; i++) 
		{ 
        	result_string = result_string + result[i]; 
    	} 
		p.push(result_string);
		insertion_index++;
	}
}

void findPerms(const string &s, queue<string> &p, int first)
{	
  int last = s.size()-1;	
  if(first == last)
  {
	string t = "";  
	t+=s[first];
    p.push(t);
	return;
  }
  
	findPerms(s,p,first+1);
    int size = p.size();
	for(int i=0; i<size;i++)
	{
	   string front = p.front();
	   p.pop();
	   char inserted = s[first];
	   insertAtEachIndex(front,inserted, p);   
	}
}	


//Challenge problem
bool findInMatrix(const vector<vector<int> > &M, int uR, int uC, int lR, int lC, int k)
{
	//This method gives segmentation fault
	/*if(uR == lR && uC == lC)//if only one element in matrix
	{
		if(k == M[uR][uC]) 
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if(k == M[uR][uC] || k == M[lR][lC])//if multiple element left top or right bottom matched K
	{
		return true;
	}
	else 
	{
		int mid_r = (uR+lR)/2; 
		int mid_c = (uC+lC)/2;

		if(k == M[mid_r][mid_c])//if mid matches k
		{
			return true;
		}

		else if(k<M[mid_r][mid_c])//if k < mid search quadrant 1,2,3
		{
			if(mid_r<uR && mid_c<uC)//if mid<upper limit then search 1,3
			{
				return (findInMatrix(M,mid_r+1,uC,lR,mid_c,k)|| findInMatrix(M,uR,mid_c+1,mid_r,lC,k)); 
			}	
		    
			return (findInMatrix(M,uR,uC,mid_r,mid_c,k)||
			findInMatrix(M,mid_r+1,uC,lR,mid_c,k)||
			findInMatrix(M,uR,mid_c+1,mid_r,lC,k));
		}
		else//if k > mid then search quadrant 1,3,4
		{
			if(mid_r>lR && mid_c>uC)//if mid>lower then search for quadrant 1,3
			{
				return(findInMatrix(M,mid_r+1,uC,lR,mid_c,k)||findInMatrix(M,lR,mid_c+1,mid_r,lC,k));
			}
			return (findInMatrix(M,mid_r+1,mid_c+1,lR,lC,k)||
			findInMatrix(M,mid_r+1,uC,lR,mid_c,k)||
			findInMatrix(M,lR,mid_c+1,mid_r,lC,k));
		}
	}
	return false;*/
	
	if(M[uR][lC]==k)//if k is at uR and uC location
    {
        return true;
    }
	else if(M[uR][lC]>k)
    {
        if(uC<lC)
		{
        	return findInMatrix(M,uR,uC,lR,lC-1,k);//reducing column index by 1
		}
		else
		{
        	return false;
		}
    }
	else if(M[uR][lC]<k)
    {
        if(uR<lR)
        {
			return findInMatrix(M,uR+1,uC,lR,lC,k);//Increasing row by 1
		}
		else
		{
        	return false;//if not in-between uR and uC quadrant
		}
    }
}


int main(){
	string command;
	while(cin >> command){
		if(command == "recMin"){
			int size;
			cin >> size;
			vector<int> A;
			for(int i = 0; i < size; i++)
			{	int x;
				cin >> x;
				A.push_back(x);
			}//for
			cout << "Array A: " << endl;
			print(A);
			int amin = recMin(A, 0, size - 1);
			cout << "Min of A: " << amin << endl;
		}//recMin
		else if(command == "subarraySums"){
			int size;
			cin >> size;
			vector<int> A;
			for(int i = 0; i < size; i++){
				int x;
				cin >> x;
				A.push_back(x);
			}//for
			vector<int> B(A.size(), 0);
			cout << "Array A:" << endl;
			print(A);
			subarraySums(A, B, size - 1);
			cout << "The sums of subarrays of A are:" << endl;
			print(B);
		}//subarraySums
		else if(command == "recPal"){
			int size;
			cin >> size;
			vector<int> A;
			for(int i = 0; i < size; i++){
				int x;
				cin >> x;
				A.push_back(x);
			}//for
			cout << "Array A:" << endl;
			print(A);
			bool res = recPal(A, 0, size-1);
			if(res)
				cout << "A is a palindrome." << endl;
			else
				cout << "A is NOT a palindrome." << endl;
		}//recPal
		else if(command == "recFindSorted"){
			int size, k;
			cin >> size >> k;
			vector<int> A;
			for(int i = 0; i < size; i++){
				int x;
				cin >> x;
				A.push_back(x);
			}//for
			cout << "Array A:" << endl;
			print(A);
			bool res = recFindSorted(A, k, 0, size - 1);
			if(res)
				cout << k << " is in A." << endl;
			else
				cout << k << " is NOT in A." << endl;
		}//if recFindSorted
		else if(command == "findIndex"){
			int size;
			cin >> size ;
			vector<int> A;
			for(int i = 0; i < size; i++){
				int x;
				cin >> x;
				A.push_back(x);
			}//for
			cout << "Array A:" << endl;
			print(A);
			int index = findIndex(A, 0, size);
			if(index < 0 || index >= size)
				cout << "Index i such that i = A[i] is NOT found." << endl;
			else 
				cout << "Index " << index << " is equal to A[" << index << "] = " << A[index] << endl;

		}//findIndex
		else if(command == "recFind"){
			int size, k;
			cin >> size >> k ;
			vector<int> A;
			for(int i = 0; i < size; i++){
				int x;
				cin >> x;
				A.push_back(x);
			}//for
			cout << "Array A:" << endl;
			print(A);
			bool res = recFind(A, k, 0, size - 1);
			if(res)
				cout << k << " is found in unordered A." << endl;
			else
				cout << k << " is NOT found in unordered A." << endl;

		}//recFind
		else if(command == "powerSet"){
			int size;
			cin >> size;
			vector<int> A;
			for(int i = 0; i < size; i++){
				int x;
				cin >> x;
				A.push_back(x);
			}//for
			vector< vector<int> > P;
			cout << "Array A:" << endl;
			powerSet(A, P, size - 1);
			print(P);

		}//powerSet
		else if(command == "findPerms"){
			string s;
			cin >> s;
			queue<string> p;
			findPerms(s, p, 0);
			cout << "String s = " << s << ", all permutations of s are:" << endl;
			print(p);
		}//findPerms
		else if(command == "findInMatrix"){
			//bool findInMatrix(const vector<vector<int> > &M, int uR, int uC, int lR, int lC, int k);
			int rows, cols, k, x;
			cin >> rows >> cols >> k ;
			vector< vector<int> > M;
			for(int i = 0; i < rows; i++){
				vector<int> arow;
				for(int j = 0; j < cols; j++){
					cin >> x;
					arow.push_back(x);
				}
				M.push_back(arow);
			}//for

			bool res = findInMatrix(M, 0, 0, rows-1, cols - 1, k);
			if(res)
				cout << k << " is found in matrix M." << endl;
			else
				cout << k << " is NOT found in matrix M." << endl;
		}//findInMatrix
		else{
			cerr << "ERROR: the command " << command << " is not valid." << endl;
			exit(0);
		}
	}//while

}//main()

