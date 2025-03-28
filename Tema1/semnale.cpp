#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

const int mod = 1000000007;

int type1(int x, int y) {
    // Compute the number of type 1 signals - nu am voie mai mult
	// de 2 biti de 1 consecutivi

	// matricea retine cate semnale pot avea folosind
	// i biti de 0 si j biti de 1
	vector <vector <int>> noSignals;
	noSignals.assign(x + 1, vector <int> (y + 1, 0));

	// consider ca exista 1 semnal 'gol' cu 0 biti 0 si 0 biti 1
	noSignals[0][0] = 1;

	// daca am doar 1 bit 0 sau doar 1 bit 1 pot avea doar 1 semnal
	noSignals[0][1] = noSignals[1][0] = 1;

	// cu i biti de 0 si 0 biti de 1 pot avea doar 1 semnal
	for (int i = 1; i <= x; i ++) {
        noSignals[i][0] = 1;
    }

	// cu j >= 2 biti de 1 si 0 biti de 0, nu pot avea niciun semnal
    for (int j = 2; j <= y; j ++) {
        noSignals[0][j] = 0;
    }

	for (int i = 1; i <= x; i ++) {
		for (int j = 1; j <= y; j ++) {
			// pot adauga 1 bit de 0 oricarui semnal cu i - 1 biti de 0
			// si j biti de 1 (adaug 0)
			noSignals[i][j] = noSignals[i - 1][j];

			// pot adauga un bit de 1 doar semnalelor cu i - 1 biti de 0
			// si j - 1 biti de 1 (adaug 01)
			noSignals[i][j] += noSignals[i - 1][j - 1];

			// retin valoarea % mod
			noSignals[i][j] %= mod;
		}
	}

	// rezultatul este numarul de semnale cu x biti de 0 si y biti de 1
	// adica noSignals[x][y]
	int res = noSignals[x][y];

    return res;
}

int type2(int x, int y) {
    // Compute the number of type 2 signals - nu am voie mai mult
	// de 3 biti de 1 consecutivi

	vector <vector <long long>> noSignals;
	noSignals.assign(x + 1, vector <long long> (y + 1, 0));

	// consider ca exista 1 semnal 'gol' cu 0 biti 0 si 0 biti 1
	noSignals[0][0] = 1;

	// daca am doar 1 bit de 0 sau doar 1 bit de 1 pot avea doar 1 semnal
	noSignals[0][1] = noSignals[1][0] = 1;

	// daca am doar 2 biti de 0 sau doar 2 biti de 1 pot avea doar 1 semnal
	noSignals[0][2] = noSignals[2][0] = 1;

	// cu i biti de 0 si 0 biti de 1 pot avea doar 1 semnal
	for (int i = 1; i <= x; i ++) {
        noSignals[i][0] = 1;
    }

	// cu j >= 3 biti de 1 si 0 biti de 0, nu pot avea niciun semnal
    for (int j = 3; j <= y; j ++) {
        noSignals[0][j] = 0;
    }

	for (int i = 1; i <= x; i ++) {
		for (int j = 1; j <= y; j ++) {
			// pot adauga 1 bit de 0 oricarui semnal cu i - 1 biti de 0
			// si j biti de 1 (adaug 0)
			noSignals[i][j] = noSignals[i - 1][j];

			// pot adauga 1 bit de 1 oricarui semnal cu i - 1 biti de 0
			// si j - 1 biti de 1 (adaug 01)
			noSignals[i][j] += noSignals[i - 1][j - 1];  // adaug 01


			// pot adauga 2 biti de 1 doar semnalelor cu i - 1 biti de 0
			// si j - 2 biti de 1 (adaug 011)
			if (j >= 2)
				noSignals[i][j] += noSignals[i - 1][j - 2];

			// retin valoarea % mod
			noSignals[i][j] %= mod;
		}
	}

	// rezultatul este numarul de semnale cu x biti de 0 si y biti de 1
	// adica noSignals[x][y]
	long long res = noSignals[x][y];

    return res;
}

int main() {
    freopen("semnale.in", "r", stdin);
	freopen("semnale.out", "w", stdout);

	int sig_type, x, y;

	cin >> sig_type >> x >> y;

    switch (sig_type) {
		case 1:
			cout << type1(x, y);;
			break;
		case 2:
			cout << type2(x, y);
			break;
		default:
			cout << "wrong task number" << endl;
	}

    return 0;
}
