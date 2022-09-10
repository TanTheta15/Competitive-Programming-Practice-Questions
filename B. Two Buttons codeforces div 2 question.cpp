/*    B. Two Buttons
Vasya has found a strange device. On the front panel of a device there are: a red button, a blue button and a display showing some positive integer. After clicking the red button, device multiplies the displayed number by two. After clicking the blue button, device subtracts one from the number on the display. If at some point the number stops being positive, the device breaks down. The display can show arbitrarily large numbers. Initially, the display shows number n.

Bob wants to get number m on the display. What minimum number of clicks he has to make in order to achieve this result?

Input
The first and the only line of the input contains two distinct integers n and m (1 ≤ n, m ≤ 104), separated by a space .

Output
Print a single number — the minimum number of times one needs to push the button required to get the number m out of number n.

Examples
4 6
2
10 1
9

*/

#include<bits/stdc++.h>
using namespace std;

int isSolve(int n, int m){
	if(m == 0) return 0;
	if(n == m) return 0;
	if(m < n) return n - m;
	int count = 0;
	if(m & 1){
		count = 1 + isSolve(n, m + 1);
	}
	else{
		count = 1 + isSolve(n, m / 2);
	}
	return count;

}

int main(){
	int n, m;
	cin >> n >> m;
	cout << isSolve(n, m) << endl;
}
