#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int O_n1(vector<int> Stock) {
	int cnt = 0;
	int start = 0;
	int end = 0;
	for (int i = 1; i < Stock.size(); i++) {
		if (Stock[i] > Stock[i - 1]) {
			end = i;
			if (cnt < end - start) {
				cnt = end - start;
			}
		}
		else {
			start = i;
			end = i;
		}
	}
	return cnt;
}

int O_n2(vector<int> Stock) {
	int cnt = 0;
	int start = 0;
	int end = 0;
	for (int i = 0; i < Stock.size(); i++) {
		start = i;
		end = i;
		for (int j = i + 1; j < Stock.size(); j++) {
			if (Stock[j] > Stock[j - 1]) {
				end = j;
				if (cnt < end - start) {
					cnt = end - start;
				}
			}
			else break;
		}
	}
	return cnt;
}

int O_n3(vector<int> Stock) {
	int cnt = 0;
	int start = 0;
	int end = 0;
	for (int i = 0; i < Stock.size(); i++) {
		start = i;
		end = i;
		for (int j = i + 1; j < Stock.size(); j++) {
			for (int k = i; k < j; k++) {
				if (Stock[k] < Stock[k + 1]) {
					end = k + 1;
					if (cnt < end - start) {
						cnt = end - start;
					}
				}
				else break;
			}
		}
	}
	return cnt;
}

int main() {
	int num;
	cin >> num;
	vector<int> Stock;
	for (int i = 0; i < num; i++) {
		int temp;
		cin >> temp;
		Stock.push_back(temp);
	}
	clock_t start, end;
	start = clock();
	int ans1 = O_n1(Stock);
	end = clock();
	cout << "ans1 = " << ans1 << ", 수행시간 : " << end - start << endl;
	start = clock();
	int ans2 = O_n2(Stock);
	end = clock();
	cout << "ans2 = " << ans2 << ", 수행시간 : " << end - start << endl;
	start = clock();
	int ans3 = O_n3(Stock);
	end = clock();
	cout << "ans3 = " << ans3 << ", 수행시간 : " << end - start << endl;
}