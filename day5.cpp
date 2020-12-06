#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>

#define lli long long int

using namespace std;

int main()
{
  ifstream cin("input.txt");
  lli ans = 0;
  string s;
  vector<lli> A;
  while(cin>>s) {
    int l = 0;
    int r = 127;

    for(int i=0; i<7; i++) {
      int mid = (l+r)/2;
      if(s[i] == 'F') {
        r = mid;
      } else {
        l = mid+1;
      }
    }

    //cout<<l<<" "<<r<<endl;

    int left = 0;
    int right = 7;
    for(int i=7; i<s.length(); i++) {
      int mid = (left+right)/2;
      if(s[i] == 'L') {
        right = mid;
      } else {
        left = mid+1;
      }
    }

    //cout<<left<<" "<<right<<endl;

    lli calc = l*8+left;
    A.push_back(calc);
    ans = max(ans, calc);
  }

  sort(A.begin(), A.end());

  for(int i=1; i<A.size(); i++) {
    if(A[i]-A[i-1] != 1) {
      // This is our missing seat
      cout<<A[i]-1<<endl;
      break;
    }
  }

  // This is largest seat ID present
  cout<<ans<<endl;

  return 0;
}