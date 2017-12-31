#include <iostream>
#include <map>

using namespace std;
typedef map<string,int> m1;

int countWays(string s, char result,map<string,int> &m)
{
  if(s.length()==0) return 0;

  if (s.length()==1) 
    return s[0]==result?1:0;
  if(m.find(result+s)!=m.end())
    return m[result+s];
  int ways = 0;
  char c;
  string left;
  string right;
  int lefttrue;
  int leftfalse;
  int righttrue;
  int rightfalse;
  int total;
  int totaltrue;
  int sum;
  for (int i = 1; i < s.length(); i+=2)
  {
      c = s[i];
      left = s.substr(0,i);
      right = s.substr(i+1,s.length());
      lefttrue = countWays(left,'1',m);
      leftfalse = countWays(left,'0',m);
      righttrue = countWays(right,'1',m);
      rightfalse = countWays(right,'0',m);
      total = (lefttrue+leftfalse)*(righttrue+rightfalse);
      
      if(c=='&')
        totaltrue = lefttrue*righttrue;
      else if(c=='^')
       totaltrue =  lefttrue*rightfalse + leftfalse*righttrue;
      else if(c=='|')
       totaltrue = lefttrue*righttrue + lefttrue*rightfalse + leftfalse*righttrue;

      sum = result=='1'?totaltrue:total-totaltrue;
      ways+=sum;
  }
  m.insert(pair<string,int> (result+s, ways));   
  return ways;
}

int main()
{
 int test;
 string s;
 char r;
 string p;
 int ways;
 map<string,int> m;
 cout<<"enter number of test"<<endl;
 cin>>test;
 while(test--) 
 {
   getline(cin,p);
   cout<<"enter expression"<<endl;
   getline(cin,s);
   cout<<"enter result"<<endl;
   cin>>r;
   cout<<"expression = "<<s<< " " << "result "<<r<<endl; 
   ways = countWays(s,r,m);
   cout<<"number of ways = "<<ways<<endl;
 }
 return 0;
}


