/*    Gray Code
A Gray code is a list of all 2n bit strings of length n, where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).

Your task is to create a Gray code for a given length n.

Input

The only input line has an integer n.

Output

Print 2n lines that describe the Gray code. You can print any valid solution.

Constraints
1≤n≤16
Example

Input:
2

Output:
00
01
11
10
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef priority_queue<int, vector<int>, greater<int> > MinHeap;
typedef priority_queue<int> MaxHeap;
typedef set<int> oset;
typedef unordered_set<int> uset;
typedef map<int, int> omap;
typedef unordered_map<int, int> umap;
typedef stack<int> Stack;
typedef queue<int> Q;
typedef deque<int> DQ;
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ln "\n"

void solve(ll n){
	for(int i = 0; i < 1 << n; i++){
		ll val = i ^ (i >> 1);
		bitset<32> a(val);
		string s = a.to_string();
		for(int j = 32 - n; j < 32; j++){
			cout << s[j];
		}
		cout << ln;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	solve(n);
}
