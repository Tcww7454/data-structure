#include<iostream>
#include<stack>
using namespace std;
stack<int> s[3];//定义三个栈 

void move(int x, int y) {
	int temp = s[x].top();
	s[x].pop();
	s[y].push(temp);
	cout << x << "-->" << y << endl;
}

void hanoi(int A, int B, int C, int n)
{
	if (n == 1) { //边界条件 
		move(A, C);
		return;
	}
	hanoi(A, C, B, n - 1);
	move(A, C);
	hanoi(B, A, C, n - 1);
}

int main() {
	int n;
	cin >> n;
	for (int i = n; i >= 1; i--) {
		s[0].push(i);
	}
	hanoi(0, 1, 2, n);
	while (!s[2].empty())
	{
		cout << s[2].top() << " ";
		s[2].pop();
	}
	return 0;
}
