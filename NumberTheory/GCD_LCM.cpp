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

// �t��
// xy mod m = 1 ���� y < m �ƂȂ� y �����߂�
// m �͑f���Ƃ���
long long modinv(long long x, long long m) {
	long long y, n;
	extgcd(x, m, y, n);
	return (y + m) % m;
}

int main() {
	long long a = 240, b = 46, c = 4;
	long long x, y;
	long long g = extgcd(a, b, x, y);
	dump(g);
	long long k = c / g;
	x *= k, y *= k;
	dump(x, y);

	dump(modinv(5, 7));

	return 0;
}