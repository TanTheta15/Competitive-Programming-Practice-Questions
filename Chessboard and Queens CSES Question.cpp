/*    Chessboard and Queens
Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

How many possible ways are there to place the queens?

Input

The input has eight lines, and each of them has eight characters. Each square is either free (.) or reserved (*).

Output

Print one integer: the number of ways you can place the queens.

Example

Input:
........
........
..*.....
........
........
.....**.
...*....
........

Output:
65
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<char, char> pc;
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

bool isValid(int i, int j, char arr[][8]){
	int duprow = i, dupcol = j;
	if(arr[i][j] == '*'){
		return false;
	}
	while(duprow >= 0 and dupcol >= 0){
		if(arr[duprow--][dupcol--] == 'Q'){
			return false;
		}
	}
	duprow = i;
	dupcol = j;
	while(dupcol >= 0){
		if(arr[duprow][dupcol--] == 'Q'){
			return false;
		}
	}
	duprow = i;
	dupcol = j;
	while(duprow < 8 and dupcol >= 0){
		if(arr[duprow++][dupcol--] == 'Q'){
			return false;
		}
	}
	return true;
}

int solve(char arr[][8], int j = 0, int prob = 0){
	if(j == 8){
		return 1;
	}
	int sum = 0;
	for(int i = 0; i < 8; i++){
		if(isValid(i, j, arr)){
			arr[i][j] = 'Q';
			sum += solve(arr, j + 1, prob);
			arr[i][j] = '.';
		}
	}
	return sum;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	char arr[8][8];
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			cin >> arr[i][j];
		}
	}
	cout << solve(arr) << ln;
}
