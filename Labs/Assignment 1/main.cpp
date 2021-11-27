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



int findMin(const vector<int> &v)
{
	int size = (int)v.size();
		if(size == 0)
		{
			return 0;
		}
		int min = v[0];
		for(int i=0;i<size;i++)
		{
			if(min > v[i])
			{
				min = v[i];
			}
		}
		return min;
}

int findMax(const vector<int> &v)
{
	int size = (int)v.size();
		
		if(size == 0)
		{
			return 0;
		}
		int max = v[0];

		for(int i=0;i<size;i++)
		{
			if(max < v[i])
			{
				max = v[i];
			}
		}
		return max;
}

double findAve(const vector<int> &v)
{
	int size = (int)v.size();
	double sum = 0;
	for(int i=0; i< size; i++)
		sum = sum + v[i];
		double ave = sum/size;
		return ave;
	
}

void printStat(const vector<int> &A)
{
	int min = findMin(A);
	int max = findMax(A);
	double ave = findAve(A);
	cout<<min<<" "<<max<<" "<<ave<<endl;
}

bool findRange(const vector<int> &A, int k)
{
	int max = findMax(A);
	int min = findMin(A);
	int range = max - min + 1;
	if(k > range)
	return  true;	
	return false;
}

void countOccurrences(const vector<int> &A, int k)
{
int c[k],z,x=0;
for(int i=0;i<=11;i++)
{
	c[i]=0;
}
int size = (int)A.size();

  for(int i=0;i<size; i++)
  {
	  z = A[i];
	  c[z] = c[z]+1;
  }

  for(int i=0;i<=11;i++)
  {
	  if(c[i]>0)
	  {
        cout<<i<<" "<<c[i]<<endl;
	  }
  }
}

void countOccLarge(const vector<int> &A, int k)
{
  int mn,mx=0;
  mx = findMax(A);
  mn = findMin(A);
  int c[k];
  for(int i=0;i<=k;i++)
  {
	c[i]=0;
  }
  for(unsigned int i=0;i<A.size();i++)
  {
	int z=0;
    z = mx-A[i];
	c[z] = c[z] + 1;
}
  /*for(int i=k;i>=0;i--)
  {
	  if(c[i]>0)
	  {
		  int x = 0;
		  x = mx - i;
		  //cout<<"mn;"<<mn<<endl;
		  //cout<<"c[i]:"<<c[i]<<endl;
		  //cout<<"x:"<<x<<endl;
		  //cout<<"i:"<<i<<endl;
		  cout<<x<<" "<<c[i]<<endl;
	  }
  }*/
  for(int i=0;i<=k;i++)
  {
	  if(c[i]>0)
	  {
		  int x = 0;
		  x = mx - i;
		  cout<<x<<" "<<c[i]<<endl;
	  }
  }
}

bool areIdentical(const vector<int> &A, const vector<int> &B)
{
	if(A.size()==B.size())
	{
		for(unsigned int i=0;i<A.size();i++)
		{
			if(A[i]==B[i])
			{
				continue;
			}
			else
			{
				return false;
			}
		}
		return true;			
	}
	else
	{
		return false;	
	}
}

bool isPalindrome(const vector<int> &A)
{
	unsigned int j = A.size()-1;
	for(unsigned int i=0;i<A.size();i++)
	{
	 if(j>=i)
	 {
		 if(A[i]==A[j])
		 {
			 j--;
		 }
		 else
		 {
			return false;
		 }
	 } 
	}
	return true;	
}

bool isSubarray(const vector<int> &A, const vector<int> &B)
{
	unsigned int i=0;
		for(unsigned int j=0;j<B.size();j++)
		{
             if(A[i]==B[j])
			 {
				 i++;
				 for(unsigned int k=j+1; k<B.size();k++)
				 {
				   if(A[i]==B[k] && i<A.size())
				   {
					   i++;
				   }  
				   else if(i==A.size())
				   {
					   return true;
				   }
				   else
				   {
					   break;
				   }
				 }
			 }
			 if(i==A.size())
			 {
				 return true;
			 }
		}
}

int partitionAround(vector<int> &A, double k) 
{                                                
  int i=0,j=A.size()-1;	
  
  while(i<=j)
  {
	  while(A[i]<=k)
	  {
		  i++;
	  }
	  while(A[j]>=k)
	  {
		  j--;
	  }
	  if(i<=j)
	  {
		  int temp;
		  temp = A[i];
		  A[i] = A[j];
		  A[j] = temp;
	  }	  
  }
  return i-1;
}

bool areIdenticalNotSorted(const vector<int> &A, const vector<int> &B)
{
	
	if(A.size()!=B.size())
	{
		return false;
	}
	
	int c[A.size()];
	for(unsigned int i=0; i<A.size();i++)
	{
		c[i]=0;
	}

	bool elementFound = false;
	for(unsigned int i=0;i<A.size();i++)
	{
		elementFound = false;
		for(unsigned int j=0; j<B.size();j++)
		{
			if(A[i]==B[j] && c[j]==0)
			{
				c[j] = 1;
				elementFound = true;
				break;
			}
		}	
		if(elementFound == false)
		{
			return false;
		}	    
	}
	return true;
}

//Challenge problem
void mergeKqueues(vector<queue<int> > &A, vector<int> &result)
{
	
	for(unsigned int i=0;i<A.size();i++)
	{
	  while(!A[i].empty())
	  {
		  	  result.push_back(A[i].front());
		  	  A[i].pop();		  
	  }         
	}  
   
	 for(unsigned int i=0;i<result.size();i++)
	  {
		for(unsigned int j=0; j<(result.size()-1);j++)
		{
		    if(result[j]>result[j+1])
		    {
			 int temp = result[j];
			 result[j] = result[j+1];
			 result[j+1] = temp;
		    } 
		} 
	  }  
}

void print(const vector<int> &A){
	int size = (int)A.size();
	for(int i = 0; i < size; i++)
	cout << A[i] << " ";
	cout << endl;
}


int main(){
	string command;
	while(cin >> command)
	{
		if(command == "printStat")
		{
			int size;
			cin >> size;
			vector<int> A;
			for(int i = 0; i < size; i++)
			{	int x;
				cin >> x;
				A.push_back(x);
			}//for
			cout << "Array: " << endl;
			print(A);
			cout << "Min, max, average:" << endl;
			printStat(A);
		}//printStat

		else if(command == "findRange")
		{
			int size, k;
			cin >> size >> k;
			vector<int> A;
			for(int i = 0; i < size; i++){
				int x;
				cin >> x;
				A.push_back(x);
			}//for
			bool success = findRange(A, k);
			print(A);
			if(success)
				cout << k << " is greater than the range." << endl;
			else
				cout << k << " is NOT greater than the range." << endl;
		}//if findRange
		
		else if(command == "countOccurrences")
		{
			int size, k;
			cin >> size >> k;
			vector<int> A;
			for(int i = 0; i < size; i++){
				int x;
				cin >> x;
				A.push_back(x);
			}//for
			print(A);
			countOccurrences(A, k);
		}//if countOccurrences
		
		else if(command == "countOccLarge")
		{
			int size, k;
			cin >> size >> k;
			vector<int> A;
			for(int i = 0; i < size; i++){
				int x;
				cin >> x;
				A.push_back(x);
			}//for
			//print(A);
			cout << "Results of count occurrences of large integers:" << endl;
			countOccLarge(A, k);
		}//if countOccLarge
		
		else if(command == "areIdentical")
		{
			int size, sizeB;
			cin >> size >> sizeB ;
			vector<int> A;
			for(int i = 0; i < size; i++){
				int x;
				cin >> x;
				A.push_back(x);
			}//for
			vector<int> B;
			for(int i = 0; i < sizeB; i++){
				int x;
				cin >> x;
				B.push_back(x);
			}//for
			bool res = areIdentical(A, B);
			cout << "Size of A is " << size << ", size of B is " << sizeB << ", testing whether A and B are identical:" << endl;
			if(res)
				cout << "A and B are identical." << endl;
			else
				cout << "A and B are NOT identical." << endl;

		}//if areIdentical
		else if(command == "isPalindrome"){
			int size;
			cin >> size ;
			vector<int> A;
			for(int i = 0; i < size; i++){
				int x;
				cin >> x;
				A.push_back(x);
			}//for
			
			bool res = isPalindrome(A);
			print(A);
			if(res)
				cout << "A is a palindrome." << endl;
			else
				cout << "A is NOT a palindrome." << endl;

		}//if areIdentical
		else if(command == "isSubarray"){
			int size, sizeB;
			cin >> size >> sizeB ;
			vector<int> A;
			for(int i = 0; i < size; i++){
				int x;
				cin >> x;
				A.push_back(x);
			}//for
			vector<int> B;
			for(int i = 0; i < sizeB; i++){
				int x;
				cin >> x;
				B.push_back(x);
			}//for
			bool res = isSubarray(A, B);
			cout << "Checking if A is a subarray of B; A and B are:" << endl;
			print(A);
			print(B);
			if(res)
				cout << "A is a subarray of B." << endl;
			else
				cout << "A is NOT a subarray of B." << endl;

		}//if isSubarray
		else if(command == "partitionAround"){
			int size;
			double k;
			cin >> size >> k;
			vector<int> A;
			for(int i = 0; i < size; i++){
				int x;
				cin >> x;
				A.push_back(x);
			}//for
			cout << "Input array A is:" << endl;
			print(A);
			partitionAround(A, k);
			cout << "After partitioning of A around " << k << ", A is:" << endl;
			print(A);

		}//if partitionAround
		else if(command == "areIdenticalNotSorted"){
			int size, sizeB;
			cin >> size >> sizeB ;
			vector<int> A;
			for(int i = 0; i < size; i++){
				int x;
				cin >> x;
				A.push_back(x);
			}//for
			vector<int> B;
			for(int i = 0; i < sizeB; i++){
				int x;
				cin >> x;
				B.push_back(x);
			}//for
			cout << "Checking if not sorted A and B are identical; A and B are:" << endl;
			print(A);
			print(B);
			bool res = areIdenticalNotSorted(A, B);
			if(res)
				cout << "Not sorted A and B are identical." << endl;
			else
				cout << "Not sorted A and B are NOT identical." << endl;

		}//if areIdenticalNotSorted
		else if(command == "mergeKqueues"){
			int k;
			cin >> k;
			vector<queue<int> > A(k);
			for(int j = 0; j < k; j++){
				int size;
				cin >> size ;
				queue<int> v;
				for(int i = 0; i < size; i++){
					int x;
					cin >> x;
					v.push(x);
				}//for
				A[j] = v;
			}//for
			vector<int> result;
			mergeKqueues(A, result);
			cout << "After merging of " << k << " queues, the resulting vector is:" << endl;
			print(result);
		}//mergeKqueues
		else{
			cerr << "ERROR: the command " << command << " is not valid." << endl;
			exit(0);
		}
	}//while

}//main()

