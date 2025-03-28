#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

struct Sushi {
	// sushi price
	int price = 0;
	// sum of all the grades
	int gradesSum = 0;
};

int task1(int n, int m, int x, struct Sushi sushi[]) {
	int maxPrice = x * n;
	int i = 0;
	int res = 0;

	// asemanator pb rucsac, caut suma-note maxima
	vector <vector <int>> grades;
	grades.assign(m + 1, vector <int> (maxPrice + 1, 0));

	for (int i = 1; i <= m; i ++) {
		int p = sushi[i - 1].price;
		int s = sushi[i - 1].gradesSum;
		for (int j = 0; j <= maxPrice; j ++) {
			grades[i][j] = grades[i - 1][j];
			if (j >= p) {
				grades[i][j] = max(grades[i - 1][j],
				grades[i - 1][j - p] + s);
			}
		}
	}

	res = grades[m][maxPrice];
	return res;
}


int task2(int n, int m, int x, struct Sushi sushi[]) {
	// aplic acelasi algoritm,
	// duplicand platourile de sushi initiale
	struct Sushi doubleSushi[2 * m];

	for (int i = 0, j = m; i < m, j < 2 * m; i ++, j ++)
		doubleSushi[i] = doubleSushi[j] = sushi[i];

	int res = task1(n, 2 * m, x, doubleSushi);
	return res;
}

int task3(int n, int m, int x, struct Sushi sushi[]) {
	// modific algoritmul din task 2 astfel incat
	// sa tin cont atat de 'maxPrice' cat
	// si de nr maxim de platouri 'maxN'
	int maxPrice = n * x;
	int maxN = n;

	struct Sushi doubleSushi[2 * m];

	vector <vector <vector <int>>> grades;
	grades.assign(maxN + 1, vector <vector <int>>
				(2 * m + 1, vector <int> (maxPrice + 1, 0)));

	for (int i = 0, j = m; i < m, j < 2 * m; i ++, j ++) {
		doubleSushi[i] = sushi[i];
		doubleSushi[j] = sushi[i];
	}

	for (int i = 1; i <= 2 * m; i ++) {
		int p = doubleSushi[i - 1].price;
		int s = doubleSushi[i - 1].gradesSum;
		for (int j = 0; j <= maxPrice; j ++) {
			for (int k = 1; k <= maxN; k ++) {
				grades[k][i][j] = grades[k][i - 1][j];
				if (j >= p) {
					grades[k][i][j] = max(grades[k][i - 1][j],
					grades[k - 1][i - 1][j - p] + s);
				}
			}
		}
	}

	return grades[maxN][2 * m][maxPrice];
}

int main() {
	freopen("sushi.in", "r", stdin);
	freopen("sushi.out", "w", stdout);

	int task;  // task number

	int n;  // number of friends
	int m;  // number of sushi types
	int x;  // how much each of you is willing to spend

	cin >> task;
	cin >> n >> m >> x;

	struct Sushi sushi[m];

	// read price for each type of sushi
	for(int i = 0; i < m; i ++)
		cin >> sushi[i].price;

	// read grades and calculate gradesSum for each sushi type
	int grade = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			cin >> grade;
			sushi[j].gradesSum += grade;
		}
	}

	int ans = -1;

	switch(task) {
		case 1:
			ans = task1(n, m, x, sushi);
			break;
		case 2:
			ans = task2(n, m, x, sushi);
			break;
		case 3:
			ans = task3(n, m, x, sushi);
			break;
		default:
			cout << "wrong task number" << endl;
	}

	cout << ans << endl;

	return 0;
}
