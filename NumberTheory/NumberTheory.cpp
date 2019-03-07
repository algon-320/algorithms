
const double EPS = 1e-8;
// mod (double)
double modulo(double x, double mod) {
	x -= floor(x / mod)*mod;
	if (x<EPS || x + EPS>mod)x = 0;
	return x;
}

// �ŏ��񕉏�](c/c++�͐�Βl�ŏ���])
int modulo(int x, int mod) {
	return (x%mod < 0) ? x % mod + abs(mod) : x % mod;
}

// (a*b) % mod 
long long modmul(long long a, long long b, long long mod) {
	long long x = 0, y = a % mod;
	while (b > 0) {
		if (b & 1)x = x + y % mod;
		y = y * 2 % mod;
		b >>= 1;
	}
	return x % mod;
}

// �I�[�o�[�t���[����\��������Ί|���Z��modmul()���g��
long long modpow(long long a, long long exponent, long long mod) {
	long long res = 1;
	while (exponent > 0) {
		if (exponent & 1)res = res * a % mod;
		a = a * a % mod;
		exponent >>= 1;
	}
	return res;
}

// �ݏ�, power
// �����ݏ� �J��Ԃ�����@
// power((Int)a, k) �̂悤�Ɏg������
// pow ���� pow(int,int) ���Փ˂���
template<typename Int>
Int power(Int a, unsigned long long k) {
	Int r = 1;
	while (k) {
		if (k & 1) r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}

// �K��, factorial
int factorial(int n) {
	int fact = 1;
	for (int i = 1; i <= n; i++)
		fact *= i;
	return fact;
}

// �f������iMiller-Rabin primality test�j2^24���x����
// millerRabinPrimalityTest(n, 5)
bool millerRabinPrimalityTest(long long x, int iteration) {
	if (x < 2)return false;
	if (x != 2 && x % 2 == 0)return false;
	long long s = x - 1;
	while (s % 2 == 0)s /= 2;
	for (int i = 0; i < iteration; i++) {
		long long a = rand() % (x - 1) + 1, temp = s;
		long long mod = modpow(a, temp, x);
		while (temp != x - 1 && mod != 1 && mod != x - 1) {
			mod = modmul(mod, mod, x);
			temp *= 2;
		}
		if (mod != x - 1 && temp % 2 == 0)return false;
	}
	return true;
}

//�f������
bool isPrime(int x) {
	if (x <= 1)return false;
	else if (x == 2)return true;
	if (x % 2 == 0)return false;
	for (int i = 3; i*i <= x; i += 2)
		if (x%i == 0)return false;
	return true;
}

// �G���g�X�e�l�X���
vector<char> eratos(int n) {
	vector<char> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i*i <= n; i++)
		if (is_prime[i]) {
			int j = i + i;
			while (j <= n) {
				is_prime[j] = false;
				j += i;
			}
		}
	return is_prime;
}
// n�ȉ��̑f��
vector<int> getPrimes(int n) {
	vector<char> is_prime = eratos(n);
	vector<int> primes;
	for (int i = 0; i < n + 1; i++)
		if (is_prime[i])
			primes.emplace_back(i);
	return primes;
}
// �f�������� ����
// ��x�ȉ��̑f���ɑ΂��Ċ���؂�邩���ׂ�
vector<int> primeFactorization(int x) {
	vector<int> primes = getPrimes(sqrt(x));
	vector<int> factors;
	for (auto &p : primes) {
		while (x%p == 0) {
			x /= p;
			factors.emplace_back(p);
		}
	}
	if (x != 1)factors.emplace_back(x);
	return factors;
}


//�I�C���[�̃ӊ֐��iEuler's totient function�j
//n�ƌ݂��ɑf�Ȑ�[1,n]�̌�
//http://mathtrain.jp/phi
int eulerTotient(int n) {
	int ret = n;
	for (int x = 2; x*x <= n; x++) {
		if (n%x)continue;
		ret -= ret / x;
		while (n%x == 0)
			n /= x;
	}
	if (n != 1)
		ret -= ret / n;
	return ret;
}

// �t�B�{�i�b�`����
auto fibonacci = [&](int n) {
	vector<int> v(n);
	v[0] = v[1] = 1;
	for (int i = 0; i < n - 2; i++)
		v[i + 2] += v[i + 1] + v[i];
	return v;
};

// powerarray.snnipet
vector<int> powerArray(int p, int n) {
	vector<int> power(n + 1); power[0] = 1;
	for (int i = 0; i < n; i++)
		power[i + 1] = power[i] * p;
	return power;
}

// �ׂ��Ȓ藝�E�\�z

// �R���b�c�̗\�z
// https://en.wikipedia.org/wiki/Collatz_conjecture
// n/2  if n = 0 (mod 2)
// 3n+1 if n = 1 (mod 2)
// n <= 10^6 ���ƍő� collatzConjecture(837799) = 524 ������S�T�����Ă����\�����I���
int collatzConjecture(int n) {
	if (n == 1)
		return 0;
	if (n % 2)
		return collatzConjecture(3 * n + 1) + 1;
	else
		return collatzConjecture(n / 2) + 1;
}

