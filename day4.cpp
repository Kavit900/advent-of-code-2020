#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

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

bool validByr(int byr) {
  if(byr >= 1920 && byr <= 2002) {
    return true;
  }
  return false;
}

bool validIyr(int iyr) {
  if(iyr >= 2010 && iyr <= 2020) {
    return true;
  }
  return false;
}

bool validEyr(int eyr) {
  if(eyr >= 2020 && eyr <= 2030) {
    return true;
  }
  return false;
}

bool validHeightCm(int hgt) {
  cout<<"hgt"<<hgt<<endl;
  if(hgt >= 150 && hgt <= 193) {
    return true;
  }
  return false;
}

bool validHeightIn(int hgt) {
  if(hgt >= 59 && hgt <= 76) {
    return true;
  }
  return false;
}

bool validEyeColor(string eyeColor) {
  set<string> validColors;
  validColors.insert("amb");
  validColors.insert("blu");
  validColors.insert("brn");
  validColors.insert("gry");
  validColors.insert("grn");
  validColors.insert("hzl");
  validColors.insert("oth");

  if(validColors.find(eyeColor) != validColors.end()) {
    return true;
  }
  return false;
}

bool validHairColor(string hairColor) {
  std::regex e ("^#[a-z0-9]{6,6}$");

  if (std::regex_match ( hairColor.begin(), hairColor.end(), e )) {
    return true;
  }

  return false;
}

bool validPassportID(string passportId) {
  if(passportId.length() != 9) {
    return false;
  } 
  int index = 0;
  bool flag = true;
  for(int i=index; i<passportId.length(); i++) {
    int ch = (int)passportId[i];
    if(ch>=48 || ch<=57) {
      flag = true;
    } else {
      flag = false;
      break;
    }
  }

  return flag;
}

bool isValidInfo(unordered_map<string, string> passportDetails) {
  bool isValid = true;
  cout<<endl;
  cout<<"INPUT PARSED"<<endl;
  cout<<"byr:- "<<stoi(passportDetails["byr"])<<endl;
  cout<<"iyr:- "<<stoi(passportDetails["iyr"])<<endl;
  cout<<"eyr:- "<<stoi(passportDetails["eyr"])<<endl;
  cout<<"ecl:- "<<passportDetails["ecl"]<<endl;
  cout<<"pid:- "<<passportDetails["pid"]<<endl;
  cout<<"hcl:- "<<passportDetails["hcl"]<<endl;
  cout<<"hgt:- "<<passportDetails["hgt"]<<endl;

  cout<<"IsValid 0:- "<<isValid<<endl;

  isValid &= validByr(stoi(passportDetails["byr"]));

  cout<<"IsValid 1:- "<<isValid<<endl;

  isValid &= validIyr(stoi(passportDetails["iyr"]));

  cout<<"IsValid 2:- "<<isValid<<endl;

  isValid &= validEyr(stoi(passportDetails["eyr"]));

  cout<<"IsValid 3:- "<<isValid<<endl;

  isValid &= validEyeColor(passportDetails["ecl"]);

  cout<<"IsValid 4:- "<<isValid<<endl;

  isValid &= validPassportID(passportDetails["pid"]);

  cout<<"IsValid 5:- "<<isValid<<endl;

  isValid &= validHairColor(passportDetails["hcl"]);

  cout<<"IsValid 6:- "<<isValid<<endl;
  
  cout<<"IsValid 7:- "<<isValid<<endl;

  string heightEndUnit = "";
  int i = passportDetails["hgt"].length()-1;
  string height = passportDetails["hgt"];
  if(height.length() <= 2) {
    return false;
  }
  heightEndUnit = height.substr(i-1,2);

  cout<<"heightEndUnit:- "<<heightEndUnit<<endl;

  if(heightEndUnit == "in") {
    isValid &= validHeightIn(stoi(height.substr(0,i-1)));
    cout<<"IsValid 8:- "<<isValid<<endl;
  } else if(heightEndUnit == "cm") {
    isValid &= validHeightCm(stoi(height.substr(0,i-1)));
    cout<<"IsValid 9:- "<<isValid<<endl;
  } else {
    return false;
  }

  cout<<"IsValid 10:- "<<isValid<<endl;
  return isValid;
}

bool parseAndReturnValidPassport(vector<string> arr) {

    unordered_map<string, string> passportDetails;

    // send the array for parsing and check for the values
    vector<string> tempArr;

    for(int i=0; i<arr.size(); i++) {
      vector<string> temp = split(arr[i], ' ');

      for(int j=0; j<temp.size(); j++) {
        tempArr.push_back(temp[j]);
      }
    }

    set<string> unique;
    // once all the computation is done, we check for different keys
    for(int i=0; i<tempArr.size(); i++) {
      vector<string> temp = split(tempArr[i], ':');
      unique.insert(temp[0]);
      passportDetails[temp[0]] = temp[1];
    }

    if(unique.size()==8 && isValidInfo(passportDetails)) {
      return true;
    } else if(unique.size()==7 && unique.find("cid") == unique.end() && isValidInfo(passportDetails)) {
      return true;
    }
    return false;
}

int main()
{
  ifstream cin("input.txt");
  ofstream cout("output.txt");
  std::cout.rdbuf(cout.rdbuf());
  string s;
  vector<string> arr;
  int cnt = 0;
  while(getline(cin, s)) {
    if(s.empty()) {
      if(parseAndReturnValidPassport(arr)) {
        cnt++;
      }
      arr.clear();
      continue;
    } else {
      arr.push_back(s);
    }
  }

  // We need to check for the last passport as well
  if(parseAndReturnValidPassport(arr)) {
    cnt++;
  }
  cout<<cnt<<endl;
  return 0;
}