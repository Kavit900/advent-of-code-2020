#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>

#define lli long long int

using namespace std;

int main()
{
  int num;
  ifstream cin("input.txt");
  vector<int> A;
  while(cin>>num) {
    A.push_back(num);
  }

  unordered_map<int, int> um;
  lli ans = 0;
  for(int i=0; i<A.size(); i++) {
    int diff = 2020 - A[i];

    if(um.find(diff) != um.end()) {
      ans = diff*A[i];
      break;
    } else {
      um[A[i]] = 1;
    }
  }
  cout<<ans<<endl;

  for(int i=0; i<A.size(); i++) {
    for(int j=i+1; j<A.size(); j++) {
      int diff = 2020 - (A[i]+A[j]);

      if(um.find(diff) != um.end()) {
        ans = diff*A[i]*A[j];
      } else {
        um[A[j]] = 1;
      }
    } 
    um[A[i]] = 1;
  }
  cout<<ans<<endl;
  return 0;
}