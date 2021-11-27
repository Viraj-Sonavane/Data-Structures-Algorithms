#include<algorithm>
#include<math.h>
#include<vector>
#include<iostream>
#include<string>
#include<fstream>
#include <ctime>
#include <ctime> 

using namespace std;

void readFromFile(string &s, string file)
{
    ifstream input;
    string line;
    input.open(file);
    {
        while(!input.eof())
        {
            getline(input, line);
            s=s+line;
        }
    }
}

bool lessThan(const string &S, int first, int second)
{
   while(first<S.size() && second<S.size()) 
   {
        if(S[first]<S[second])
        {
            return true;
        }
        
        if(S[first]>S[second])
        {
            return false; 
        }       
        
        if(S[first]==S[second])//If string is equal
        {
            first++;
            second++;
        }       
    } 

    
    // if all character are equals in strings then
    if(first > second || S[first]==S[second] ) 
    {
       return true;
    }
    
    else 
    {
      return false;
    }
}

int partition(const string &s, vector<int> &indices, int low, int high, int pivotIndex)
{
    int swap1,swap2;
    int i = low;
    int j = high-1;

    while(i <= j)
    {
        while(i<high && lessThan(s,indices[i],indices[high]))
        {
          i++;
        }    

        while(j>=low && lessThan(s,indices[high],indices[j]))
        {
         j--;
        }

       if(i<j)
        { 
            swap2 = indices[i];
            indices[i] = indices[j];
            indices[j] = swap2;
            i++;
            j--;
        }
    }
    swap1 = indices[high];
    indices[high] = indices[i];
    indices[i] = swap1;
    return i;
}

void insertion(const string &s,vector<int> &indices, int low, int high)
{
  
  for(int j = low; j<=high;j++)
  {
    int key = indices[j]; //key is used to hold indices value temporarily
    int i = j-1;// i will start from low-1 i.e left side of key element indices
   
    if(i>=low && key != 0)
    {
      while(i>=low && lessThan(s,key,indices[i]))//if indices element is greater than value stored in key then 
      {
        indices[i+1] = indices[i];//advance indices element by 1
        i = i-1;//if i becomes smaller than low while loop stops
      }
      indices[i+1]= key;//Replacing indices value with key element
    }
  }
}

void QuickSort(const string &s, vector<int> &v, int low, int high)
{
  if(low < high)
  {
    int pivotIndex = partition(s,v,low,high,high);
    QuickSort(s,v,low,pivotIndex-1);
    QuickSort(s,v,pivotIndex+1,high);
  }
}


int main(int argc, char* argv[])
{
    string s;
    string file;

    if(argc==2)
    {
    file = argv[1];
    readFromFile(s, file);
    //convertToLower(s);
    int ssize = s.size();    
    int slength = s.length();

    vector<int> A;
    vector<int> B;
    int isize = A.size();


    int low = 0;
    int high = ssize -1;
      
    for(int i=0;i<s.size();i++)
    {
        A.push_back(i);
    }

     for(int i=0;i<s.size();i++)
    {
        B.push_back(i);
    }

    double t1 = clock();
    QuickSort(s,A,low, high);
    double t2 = clock();
    double elapsed1 = (double)(t2 -t1) / CLOCKS_PER_SEC; 
    
    double t3 = clock();
    insertion(s,B,low,high);
    double t4 = clock();
    double elapsed2 = (double)(t4 -t3) / CLOCKS_PER_SEC;

    cerr<< "String Length: "<<slength<<endl;
    cerr << "Time to run Quick Sort :     " << elapsed1 << " seconds." << endl;
    cerr << "Time to run Insertion Sort : " << elapsed2 << " seconds." << endl;
    }
    return 0;
}
