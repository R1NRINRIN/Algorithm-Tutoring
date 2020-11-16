#include <iostream>   
#include <vector>

using namespace std;

struct Answer {
	int s1;
	int s2;
};

vector<int> merge_sort(vector<int> List) {
	int left = 0;
	int right = List.size() - 1;

	if (left == right)
		return List;

	int mid = (left + right) / 2;

	vector<int> temp1;
	for (int i = left; i <= mid; i++)
		temp1.push_back(List[i]);

	vector<int> temp2;
	for (int i = mid + 1; i <= right; i++)
		temp2.push_back(List[i]);

	vector<int> L1 = merge_sort(temp1);
	vector<int> L2 = merge_sort(temp2);

	vector<int> merged;
	int idx1 = 0;
	int idx2 = 0;
	while (idx1 + idx2 < L1.size() + L2.size() && idx1 != L1.size() && idx2 != L2.size()) {
		if (L1[idx1] <= L2[idx2])
			merged.push_back(L1[idx1++]);

		else
			merged.push_back(L2[idx2++]);
	}

	for (int i = idx1; i < L1.size(); i++)
		merged.push_back(L1[i]);

	for (int i = idx2; i < L2.size(); i++)
		merged.push_back(L2[i]);

	return merged;
}

Answer binary_search(vector<int> List, int S) {
	int first = 0;
	int last = List.size() - 1;
	int mid;
	vector<Answer> Answers;
	Answer ans;
	ans.s1 = 0;
	ans.s2 = 0;
	Answers.push_back(ans);
	int sum;

	for (int i = 0; i < List.size() - 2; i++) {   // 첫번째 원소 ~ 마지막에서 두번째 원소 (마지막 원소 제외)
		first = i + 1;
		last = List.size() - 1;

		while (first <= last) {   // 이진 탐색
			mid = first + ((last - first) / 2);
			sum = List[i] + List[mid];
			if (sum <= S) {
				if (Answers[0].s1 + Answers[0].s2 <= sum) {
					if (Answers[0].s1 + Answers[0].s2 < sum) {
						while (Answers.size() > 1)
							Answers.pop_back();
					}
					Answers[0].s1 = List[i];
					Answers[0].s2 = List[mid];
				}
				first = mid + 1;
			}
			else {
				last = mid - 1;
			}
		}
	}

	ans = Answers[0];

	if (Answers.size() > 1) {
		for (int i = 1; i < Answers.size(); i++) {
			if (ans.s1 * ans.s2 < Answers[i].s1 * Answers[i].s2)
				ans = Answers[i];
		}
	}
	return ans;
}



int main() {
	int n;
	vector<int> List;
	int S;


	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		List.push_back(temp);
	}
	cin >> S;

	vector<int> sorted = merge_sort(List);


	// vector<int> sorted = merge_sort(List);
	cout << "sorted = ";
	for (int i = 0; i < n; i++) {
		cout << sorted[i] << " ";
	}
	cout << "\n";


	Answer ans = binary_search(sorted, S);
	cout << ans.s1 << " " << ans.s2 << endl;

	return 0;
}
