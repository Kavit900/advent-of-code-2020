#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

vector<pair<int, int>> g[10005];
vector<int> parentBags;

int totalAmount;

int dfs(int s, set<int> visited) {
  if(visited.find(s) != visited.end()) {
    return 0;
  }

  int sum = 0;
  visited.insert(s);
  for(int i=0; i<g[s].size(); i++) {
    int val = g[s][i].second;
    int d = g[s][i].first;
    sum += val;
    sum += val * dfs(d, visited);
  }
  return sum;
}

vector<string> split(string str, char delimiter) { 
  vector<string>vs; 
  string k; 
  for (char t : str) 
  {		 
    if (t==delimiter &&k.length() > 1) 
    { 
      vs.push_back(k); 
      k=""; 
    } 
    else if (t!=delimiter) 
      k += t; 
  } 
  if (k!="") 
  vs.push_back(k); 
  return vs;
}

int main() 
{
  ifstream cin("input.txt");
  ofstream cout("output.txt");
  std::cout.rdbuf(cout.rdbuf());
  string s;
  vector<string> arr;
  totalAmount = 0;
  int cnt = 0;
  unordered_map<string, int> bagToId;
  unordered_map<int, string> Idtobag;
  int id = 0;
  while(getline(cin, s)) {
    vector<string> tempArr = split(s, ' ');

    // First bag 
    string parentBag = "";
    int index = 0;
    for(int i=0; i<tempArr.size(); i++) {
      if(tempArr[i] == "bags") {
        index = i+1;
        break;
      }
      parentBag += tempArr[i];
    }

    // find intervals
    vector<pair<int, int>> intervals;
    vector<string> childBags;
    vector<int> childBagsNumbers;

    for(int i=index; i<tempArr.size(); ) {
      string t = tempArr[i];
      int tVal = t[0];
      if(tVal >= 48 && tVal<= 57) {
        int first = i;
        int j = i+1;
        while(1 && j<tempArr.size()) {
          if(tempArr[j] == "bags," || tempArr[j] == "bag," || tempArr[j] == "bag." || tempArr[j] == "bags.") {
            break;
          }
          j++;
        }
        intervals.push_back(make_pair(first, j));
        i = j+1;
      } else {
        i++;
      }
    }

    for(int i=0; i<intervals.size(); i++) {
      pair<int, int> t = intervals[i];
      string chBag = "";

      // The first letter will have number attached to it, so let's remove it
      string s1 = tempArr[t.first];
      int k = 0;
      while(1) {
        int val = s1[k];
        if(val >= 48 && val <= 57) {
          k++;
        } else {
          break;
        }
      }

      string s2 = s1.substr(0,k);
      s1 = s1.substr(k);
      chBag += s1;
      for(int j=t.first+1; j<t.second; j++) {
        chBag += tempArr[j];
      }

      childBagsNumbers.push_back(stoi(s2));
      childBags.push_back(chBag);
    }

    if(bagToId.find(parentBag) == bagToId.end()) {
      //cout<<"Parent Bag:- "<<parentBag<<endl;
      bagToId[parentBag] = id;
      Idtobag[id] = parentBag;
      id++;
    }

    for(int i=0; i<childBags.size(); i++) {
      string chBag = childBags[i];
      int idVal;
      if(bagToId.find(chBag) == bagToId.end()) {
        Idtobag[id] = chBag;
        bagToId[chBag] = id;
        idVal = id;
        id++;
      } else {
        idVal = bagToId[chBag];
      }
      g[bagToId[parentBag]].push_back(make_pair(idVal, childBagsNumbers[i]));
    }

    parentBags.push_back(bagToId[parentBag]);
  }

  string dest = "shinygold";
  int destId = bagToId[dest];
  unordered_map<string, int>::iterator it;
  //cout<<parentBags.size()<<endl;
  for(int i=0; i<parentBags.size(); i++) {
    int parentBag = parentBags[i];
    if(parentBag == destId) {
      continue;
    }
    //cout<<"Parent Bag:- "<<Idtobag[parentBag]<<endl;
    queue<int> q;
    set<int> visited;

    q.push(parentBag);

    while(!q.empty()) {
      int id = q.front();
      q.pop();
      visited.insert(id);
      //cout<<"Child Bag:- "<<Idtobag[id]<<endl;
      if(id == destId) {
        cnt++;
        break;
      }
      for(int j=0; j<g[id].size(); j++) {
        if(visited.find(g[id][j].first) == visited.end()) {
          q.push(g[id][j].first);
        }
      }
    }
  }

  set<int> visited1;
  // To find the total number of bags inside 1 shiny gold bag, we will apply dfs approach
  cout<<"Sum Total is:- "<<dfs(destId, visited1)<<endl;

  cout<<cnt<<endl;
  return 0;
}