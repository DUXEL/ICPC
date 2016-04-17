//============================================================================
// Name        : duxel.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>


using namespace std;


vector<string> split(string str, string sep) {
	char * cstr = const_cast<char*>(str.c_str());
	char* current;
	vector<string> arr;
	current = strtok(cstr, sep.c_str());
	while(current != NULL) {
		arr.push_back(current);
		current = strtok(NULL, sep.c_str());
	}
	return arr;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<string> v1;
	vector<string> v2;
	string line1, line2, res;
	bool flag;
	while(getline(cin, line1)) {
		getline(cin, line2);
		v1 = split(line1, " ");
		v2 = split(line2, " ");
		if(v1.size() != v2.size()) res = "no";
		else {
			flag = true;
			for(int i = 0; i < v1.size(); i++) {
				if(v1[i][0] != v2[i][0]) {
					flag = false;
					break;
				}
			}
			if(flag) res = "yes";
			else res = "no";
		}
		cout << res << "\n";
	}
	return 0;
}
