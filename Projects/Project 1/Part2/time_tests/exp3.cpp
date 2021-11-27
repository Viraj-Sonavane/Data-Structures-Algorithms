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

int select(const string &S,vector<int> &v, int start, int fin, int k)
{
    int vsize = fin - start + 1;

    if(start == fin)
        return v[start];
    else if(start > fin)
        return -1;
    
    if(vsize <= 5)
   {
        insertion(S,v,start,fin);
        //sort(v.begin() + start, v.begin() + fin + 1);
        return v[k];
    }
    
    int msize = ceil((double)vsize/5);

    vector<int> medians(msize, 0);
    int med_ind = 0;
    for(int i = start; i <= fin; i = i + 5)
    {
        vector<int> temp(5, 0);
        int j = 0;
        for(; j < 5 && (i + j)<= fin; j++)
        {
            temp[j] = v[i+j];
        }//for j
        if(j < 5)
            temp.resize(j);
            insertion(S,temp,0,temp.size()-1);
        //sort(temp.begin(), temp.end());
        if(j == 5)
            medians[med_ind++] = temp[2];
        else{
            int jmid = j >> 1;//divide by 2
            if(j % 2 == 0)
                jmid--;
            medians[med_ind++] = temp[jmid];
            }
    }//for i

    //so far we selected the medians of n/5 groups, each group of 5 elements
    int mid = msize >> 1; //divide by 2
    if((msize % 2) == 0)
        mid--;

    //find the median of the medians
    int x = select(S,medians, 0, msize - 1, mid);
    if(x == -1)
    {
        cerr << "ERROR: returned value of median of medians is -1." << endl;
        exit(0);
    }

    //partition elements of v around x
    //find the index of x in v
    int ind_of_x = -1;
    for(int i = start; i <= fin; i++)
    {
        if(v[i] == x)
        {
            ind_of_x = i;
            break;
        }//if
    }//for

    int pivotIndex = partition(S,v, start, fin, ind_of_x);

    if(k == pivotIndex)
        return v[k];
    else if(pivotIndex < k)
        return select(S,v, pivotIndex + 1, fin, k);
    else
        return select(S,v, start, pivotIndex - 1, k);
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
    vector<int> C;
    int isize = A.size();
   
    int k = atoi(argv[2]);

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
    insertion(s,A,low,high);
    double t2 = clock();
    double elapsed1 = (double)(t2 -t1) /CLOCKS_PER_SEC; 
    
    double t3 = clock();
   // select(s,B,0,B.size()-1,B.size()-2);
    
    for(int i=0;i<B.size();i++)
    {
        int m = select(s,B,0,B.size()-1,k);
        C.push_back(m);
    }

    double t4 = clock();
    double elapsed2 = (double)(t4 -t3) / CLOCKS_PER_SEC;

    cerr<< "String Length: "<<slength<<endl;
    cerr << "Time to run Insertion Sort is " << elapsed1 << " seconds." << endl;
    cerr << "Time to run Selection Sort is " << elapsed2 << " seconds." << endl;
    }
    return 0;
}
