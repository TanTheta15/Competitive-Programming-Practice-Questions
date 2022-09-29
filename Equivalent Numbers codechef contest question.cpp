/*      Equivalent Numbers
Chef calls a pair of integers (A, B)(A,B) equivalent if there exist some positive integers XX and YY such that A^X = B^YA 
X
 =B 
Y
 .

Given AA and BB, determine whether the pair is equivalent or not.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of two space-separated integers AA and BB, as mentioned in statement.
Output Format
For each test case, output YES if (A, B)(A,B) is an equivalent pair, NO otherwise.

The output is case-insensitive. Thus, the strings Yes, YES, yes, and yeS are all considered identical.

Constraints
1 \leq T \leq 10^51≤T≤10 
5
 
2 \leq A, B \leq 10^62≤A,B≤10 
6
 
Sample 1:
Input
Output
3
2 3
8 4
12 24
NO
YES
NO
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<char, char> pc;
typedef priority_queue<int, vector<int>, greater<int> > MinHeap;
typedef priority_queue<int> MaxHeap;
typedef multiset<int> moset;
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

const static int N = 1e6 + 1;
vector<bool> isPrime(N, false);
vi prime;

void sieve(){
	int maxN = 1e6;
	for(int i = 2; i * i <= maxN; i++){
		if(isPrime[i]) continue;
		prime.pb(i);
		for(int j = i * i; j <= maxN; j += i){
			isPrime[j] = true;
		}
	}
	for(int i = 1e3; i <= maxN; i++){
		if(isPrime[i]){
			continue;
		}
		prime.pb(i);
	}
}

vector<pi> factors(int a){
	vector<pi> fac;
	for(int i = 0; i < prime.size() and prime[i] * prime[i] <= a; i++){
		int cnt = 0;
		int x = prime[i];
		while(a % x == 0){
			cnt++;
			a /= x;
		}
		if(cnt > 0){
			fac.pb(make_pair(x, cnt));
		}
	}
	if(a > 1){
		fac.pb(make_pair(a, 1));
	}
	return fac;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	sieve();
	while(t--){
		int a, b;
		cin >> a >> b;
		vector<pi> factor_a = factors(a);
		vector<pi> factor_b = factors(b);
		int n = factor_a.size();
		int m = factor_b.size();
		if(n != m){
			cout << "NO" << ln;
			continue;
		}
		bool flag = 1;
		set<pi> s;
		for(int i = 0; i < n; i++){
			if(factor_a[i].first != factor_b[i].first){
				flag = 0;
				break;
			}
			int x = factor_a[i].second;
			int y = factor_b[i].second;
			int gcd = __gcd(x, y);
			x /= gcd; 
			y /= gcd;
			s.insert(make_pair(x, y));
		}
		if(flag and s.size() == 1){
			cout << "YES" << ln;
		}
		else{
			cout << "NO" << ln;
		}
	}
}
