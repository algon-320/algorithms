#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

// Manacher's algorithm
// ����̍Œ��񕶂����߂�
// O(N)
// �߂�l: r[i]: s[i]�𒆐S�Ƃ���Œ��̉񕶂̔��a := (�S�� + 1) / 2
// �������̉񕶂����߂����ꍇ�̓_�~�[����������
vector<int> manacher(const string &s) {
	int n = s.size();
	vector<int> r(n);
	int i = 0, j = 0;
	while (i < n) {
		while (i - j >= 0 && i + j < n && s[i - j] == s[i + j]) ++j;
		r[i] = j;
		int k = 1;
		while (i - k >= 0 && i + k < n && k + r[i - k] < j) r[i + k] = r[i - k], ++k;
		i += k; j -= k;
	}
	return r;
}

// �_�~�[�����}��
// abc -> a$b$c
string insertDummyChar(const string &s, char dummy = '$') {
	int n = s.size();
	string ret(2 * n - 1, dummy);
	for (int i = 0; i < n; i++)
		ret[i * 2] = s[i];
	return ret;
}

// �������̍Œ��񕶂����߂�
// ret[i] := s[i] �� s[i+1] �̊Ԃ𒆐S�Ƃ���Œ��̉񕶂̔��a := �S�� / 2
vector<int> manacherEven(const string &s) {
	int n = s.size();
	vector<int> ret(n - 1);
	vector<int> m = manacher(insertDummyChar(s));
	for (int i = 0; i < n - 1; i++)
		ret[i] = m[i * 2 + 1] / 2;
	return ret;
}

int main() {
	string S = "aababcbabaab";

	dump(manacher(S));
	dump(manacherEven(S));
	return 0;
}