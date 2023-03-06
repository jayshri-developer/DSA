// Approach 1 (backtracking)
//GFG link: https://www.geeksforgeeks.org/match-a-pattern-and-string-without-using-regular-expressions/
// TC: O(2^m)


// C++ program to find out if string follows
// a given pattern or not
#include <bits/stdc++.h>
using namespace std;

bool patternMatchUtil(string str, int n, int i, string pat, int m, int j,
					unordered_map<char, string>& map)
{
	// If both string and pattern reach their end
	if (i == n && j == m)
		return true;

	// If either string or pattern reach their end
	if (i == n || j == m)
		return false;

	// read next character from the pattern
	char ch = pat[j];

	// if character is seen before
	if (map.find(ch)!= map.end())
	{
		string s = map[ch];
		int len = s.size();

		// consider next len characters of str
		string subStr = str.substr(i, len);

		// if next len characters of string str
		// don't match with s, return false
		if (subStr.compare(s))
			return false;

		// if it matches, recurse for remaining characters
		return patternMatchUtil(str, n, i + len, pat, m,
											j + 1, map);
	}

	// If character is seen for first time, try out all
	// remaining characters in the string
	for (int len = 1; len <= n - i; len++)
	{
		// consider substring that starts at position i
		// and spans len characters and add it to map
		map[ch] = str.substr(i, len);

		// see if it leads to the solution
		if (patternMatchUtil(str, n, i + len, pat, m,
										j + 1, map))
			return true;

		// if not, remove ch from the map
		map.erase(ch);
	}

	return false;
}

// A wrapper over patternMatchUtil()function
bool patternMatch(string str, string pat, int n, int m)
{
    if(n < m)
    {
        return false;
    }
	
    unordered_map<char, string> map; // create an empty hashmap
	bool res = patternMatchUtil(str, n, 0, pat, m, 0, map); // store result in a boolean variable res

	// if solution exists, print the mappings
	for (auto it = map.begin(); res && it != map.end(); it++)
		cout << it->first << "->" << it->second << endl;

	// return result
	return res;
}

// Driver code
int main()
{
	string str = "GeeksforGeeks", pat = "GfG";

	int n = str.size(), m = pat.size();

	if (!patternMatch(str, pat, n, m))
		cout << "No Solution exists";

	return 0;
}

o/p:- 
f->for
G->Geeks
