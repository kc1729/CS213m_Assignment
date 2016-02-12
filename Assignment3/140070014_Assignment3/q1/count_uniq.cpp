#include <iostream>
#include <algorithm>
#include <vector>
#include "mfile.hpp"
#include <string>
#include <unordered_set>
#include <fstream>
#include <functional>

using namespace std;

int main() {

	string fname;
	int len_of_line;
	cin >> fname;
	cin >> len_of_line;

	MFile mfile;
	mfile.init(fname, len_of_line);
	string s = "a";
	hash<string> str_hash;
	unordered_set<long> all_lines;
	s = mfile.readNext();
	long a = str_hash(s);
	while(s != "\0") {
		s = mfile.readNext();
		a = str_hash(s);
		all_lines.emplace(a);
	}

	mfile.close();
	cout << all_lines.size();
}