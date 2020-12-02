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

  string s1,s2,s3;
  int cnt = 0;
  int cntPartTwo = 0;
  while(cin>>s1 && cin>>s2 && cin>>s3) {
    //cout<<s1<<endl;
    int index = 0;
    int number1 = 0;
    int number2 = 0;

    while(index < s1.length()) {
      if(s1[index] == '-') {
        break;
      }
      index++;
    }

    number1 = stoi(s1.substr(0,index));
    number2 = stoi(s1.substr(index+1));

    int charCnt = 0;
    for(int i=0; i<s3.length(); i++) {
      if(s3[i] == s2[0]) {
        charCnt++;
      }
    }

    if(charCnt >= number1 && charCnt <= number2) {
      cnt++;
    }

    // PART TWO
    if(s3[number1-1]==s2[0] && s3[number2-1] != s2[0]) {
      cntPartTwo++;
    } else if(s3[number1-1] != s2[0] && s3[number2-1] == s2[0]){
      cntPartTwo++;
    }

  }

  cout<<cnt<<endl;
  cout<<cntPartTwo<<endl;

  return 0;
}