#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cerr;
using std::ifstream;
using std::ofstream;
using std::ios;


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

void convertToLower(string &s)
{
    for(int i=0;i<=s.size();i++)
    {
        s[i]=tolower(s[i]);
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
        
        if(S[first]==S[second])
        {
            first++;
            second++;
        }
          
    }  
    // if all character are equals in strings then
    if(first>second || S[first] == S[second])
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
    swap1 = indices[pivotIndex];
    indices[pivotIndex]=indices[high];
    indices[high]= swap1;

    int i = low;
    int j = high-1;

    while(i <= j)
    {
        while(lessThan(s,indices[i],indices[high]))
        {
         i++;
        }    
        
        while(lessThan(s,indices[high],indices[j]))
        {
          j--;
        }

        if(i<j && (!lessThan(s,indices[i],indices[high])) && (!lessThan(s,indices[high],indices[j])))
        {  
            swap2 = indices[i];
            indices[i] = indices[j];
            indices[j] = swap2;
            i++;
            j--;
        }
    }        
    indices[high] = indices[i];
    indices[i] = pivotIndex;
    return i;
}

int main(int argc, char* argv[])
{
   int first = 0, second = 0; 
   string file;
   string s;
   int m =s.size();

   if(argc==2)
   {
       file = argv[1];
       readFromFile(s, file);
       convertToLower(s);
       cout<<s<<endl;
   }

   if(argc==4)
   {
       file = argv[1];
       readFromFile(s, file);
       convertToLower(s);
       cout<<s<<endl;  
       first = atoi(argv[2]);
       second = atoi(argv[3]);
       
       bool yes = lessThan(s,first,second);
       
       if(yes)
       {
           cout<<"True."<<endl;
       }
       else
       {
           cout<<"False."<<endl;
       }   
   }

   if(argc==3)
   {   
       vector<int>indices;
       file = argv[1];
       readFromFile(s, file);
       convertToLower(s);
       int n = s.size();
     
       int index = atoi(argv[2]);
       
       first = 0;
       second = n-1;  
       
       for(int i=0;i<n;i++)
       {
           indices.push_back(i);
       }
       
       partition(s,indices,first,second,index); 
       
       for(int i=0;i<indices.size();i++)
       {
           cout<<indices[i]<<" ";
       }
    cout<<endl;
    }     
}








