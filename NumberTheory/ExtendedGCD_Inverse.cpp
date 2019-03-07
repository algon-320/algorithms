#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

// �g�����[�N���b�h�̌ݏ��@
// �ꎟ�s������� ax + by = gcd(a, b) �𖞂��� x, y �����߂�
// ax + by = k * gcd(a, b) �́A�܂� ax + by = gcd(a, b) �������A���� k �{����
// �߂�l: gcd(a, b)
long long extgcd(long long a, long long b, long long &x, long long &y) {
	long long g = a; x = 1; y = 0;
	if (b != 0) {
		g = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	return g;
}

//�t��
//xy%m=1, y<m �ƂȂ�y�����߂�
long long modinv(long long x, long long m) {
	long long s, t;
	extgcd(x, m, s, t);
	return (s + m) % m;
}

int main() {
	long long a = 240, b = 46, c = 4;
	long long x, y;
	long long g = extgcd(a, b, x, y);
	cout << "gcd(a, b) = " << g << endl;
	long long k = c / g;
	cout << "x = " << k * x << ", y = " << k * y << endl;
	return 0;
}