#include <bits/stdc++.h>

using namespace std;

int parseAndReturnUniqueValues(vector<string> arr) {
  set<char> unique;

  for(int i=0; i<arr.size(); i++) {
    for(int j=0; j<arr[i].length(); j++) {
      unique.insert(arr[i][j]);
    }
  }
  
  return unique.size();
}

int parseAndReturnYesForCommonQuestions(vector<string> arr) {
  int n = arr.size();
  int ch[26];
  for(int i=0; i<26; i++) {
    ch[i] = 0;
  }
  for(int i=0; i<arr.size(); i++) {
    for(int j=0; j<arr[i].length(); j++) {
      int c = arr[i][j]-'a';
      ch[c]++;
    }
  }

  int ans = 0;
  for(int i=0; i<26; i++) {
    if(ch[i] == n) {
      ans++;
    }
  }
  return ans;
}

int main()
{
  ifstream cin("input.txt");
  //ofstream cout("output.txt");
  std::cout.rdbuf(cout.rdbuf());
  string s;
  vector<string> arr;
  int cnt = 0;
  int cntCommon = 0;
  while(getline(cin, s)) {
    if(s.empty()) {
      cnt += parseAndReturnUniqueValues(arr);
      cntCommon += parseAndReturnYesForCommonQuestions(arr); 
      arr.clear();
      continue;
    } else {
      arr.push_back(s);
    }
  }

  // Sum of count of number of questions answered yes
  cout<<cnt<<endl;

  // Sum of count of number of common questions answered 
  cout<<cntCommon<<endl;
  return 0;
}