#include <iostream>

using namespace std;

int depth;

int calc(int a, int n, int m, int d){ 
	depth = d;
	if (n == 0) {
		return 1;
	}
	else if (n % 2 == 0) {
		return int(pow(calc(a, n / 2, m, d+1), 2)) % m;
	}
	else {
		return (a * calc(a, n - 1, m, d+1)) % m;
	}
}

int main(){
	int a;
	int n;
	int m;

	cin >> a;
	cin >> n;
	cin >> m;

	int ans = calc(a, n, m, 0);
	cout << depth << "\n" << ans << endl;

	return 0;
}
