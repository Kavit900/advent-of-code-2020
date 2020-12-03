#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>

#define lli long long int

using namespace std;

int main()
{
  ifstream cin("input.txt");

  vector<string> mat;
  string s;
  int cnt = 0;
  lli ans = 1;
  while(cin>>s) {
    mat.push_back(s);
  }
  int n = mat.size();
  int m = mat[0].length();

  for(int i=0; i<n; i++) {
    int m1 = m;
    string temp = mat[i];
    string temp1 = mat[i];
    while(m1 <= n*10) {
      temp1 += temp;
      m1 += m;
    }
    mat[i] = temp1;
    //cout<<temp1<<endl;
  }

  int i = 0;
  int j = 0;

  // slope right 1 and down 1
  while(i<n) {
    i+=1;
    j+=1;
    if(i >= n) {
      break;
    }
    if(mat[i][j] == '#') {
      cnt++;
    }
  }
  ans *= cnt;

  i=0;
  j=0;
  cnt = 0;
  // slope right 3 and down 1
  while(i<n) {
    i += 1;
    j += 3;
    if(i>=n) {
      break;
    }
    if(mat[i][j] == '#') {
      cnt++;
    }
  }
  ans *= cnt;

  i=0;
  j=0;
  cnt=0;

  // slope right 5 and down 1
  while(i<n) {
    i += 1;
    j += 5;
    if(i>=n) {
      break;
    }
    if(mat[i][j] == '#') {
      cnt++;
    }
  }
  ans *= cnt;

  i=0;
  j=0;
  cnt=0;

  // slope right 7 and down 1
  while(i<n) {
    i += 1;
    j += 7;

    if(i>=n) {
      break;
    }
    if(mat[i][j] == '#') {
      cnt++;
    }
  }
  ans *= cnt;

  i=0;
  j=0;
  cnt=0;

  // slope right 1 and down 2
  while(i<n) {
    i += 2;
    j += 1;

    if(i>=n) {
      break;
    }
    if(mat[i][j] == '#') {
      cnt++;
    }
  }
  ans *= cnt;

  cout<<ans<<endl;

  return 0;
}