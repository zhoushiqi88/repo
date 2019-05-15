#include<iostream>

using namespace std;

int A[105];
int B[105];

int find(const int* Vec, int begin, int key, int N) {
	int i;
	for (i = begin; Vec[i] < key && i < N; i++);
	return i;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	int ret = 2 * N;
	int a = 0, b = 0;
	while (a != N && b != N) {
		if (A[a] > B[b]) {
			ret--;
			b++;
		}
		else if (A[a] < B[b]) {
			ret--;
			a++;
		}
		else {
			int cur = find(A, a + 1, B[b], N);
			ret -= (cur - a);
			a = cur - 1;
			cur = find(B, b + 1, A[a], N);
			ret -= (cur - b);
			b = cur - 1;

		}
	}
	cout << ret << endl;
}
	