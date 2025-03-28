#include <cstdint>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void merge_halves(vector<int>& v, int left, int right) {
	int mid = (left + right) / 2;
	vector<int> aux;
	int i = left, j = mid + 1;

        while (i <= mid && j <= right) {
		if (v[i] <= v[j]) {
			aux.push_back(v[i]);
			i++;
		} else {
			aux.push_back(v[j]);
			j++;
		}
	}

        while (i <= mid) {
		aux.push_back(v[i]);
		i++;
	}

        while (j <= right) {
		aux.push_back(v[j]);
		j++;
	}

	for (int k = left; k <= right; k++) {
		v[k] = aux[k - left];
	}
}


void merge_sort(vector<int>& v, int left, int right) {
	if (left >= right)
        return;

	int mid = (left + right) / 2;

    merge_sort(v, left, mid);
	merge_sort(v, mid + 1, right);
	merge_halves(v, left, right);
}


int64_t SolveTask1(vector<int>& a, vector<int>& b, int n) {
    // Caut cele mai mari N numere si le pun pe toate intr o sg lista
    // Sortez vectorii A si B
    merge_sort(a, 0, n - 1);
    merge_sort(b, 0, n - 1);

    int ia, ib, ires;
    ia = ib = ires = n - 1;

    int64_t  res = 0;

    // Intercalez vectorii a.i. sa adun cele mai mari N numere
    while (ia >= 0 && ib >= 0 && ires >= 0) {
        if (a[ia] > b[ib]) {
            res += a[ia];
            ia --;
        } else {
            res += b[ib];
            ib --;
        }

        ires --;
    }

    return res;
}


bool comparePairsMin(const pair<int, int>& p1, const pair<int, int>& p2) {
    return min(p1.first, p1.second) > min(p2.first, p2.second);
}


bool comparePairsMax(const pair<int, int>& p1, const pair<int, int>& p2) {
    return max(p1.first, p1.second) < max(p2.first, p2.second);
}


int find_min(vector<pair<int, int>> aux, int s, int f, int x) {
    while (s <= f) {
        int m = (s + f) / 2;
        if (x <= max(aux[m].first, aux[m].second))
            f = m - 1;
        else
            s = m + 1;
    }
    return f - 1;
}


int64_t SolveTask2(vector<int>& a, vector<int>& b,
                    int n, int moves) {
    // Caut sa interschimb cele mai mari K elemente minime
    // cu cele mai mari K elemente maxime
    int64_t  res = 0;
    int ia, ib, ires;
    ia = ib = ires = n - 1;

    vector<pair<int, int>> aux_min;
    vector<pair<int, int>> aux_max;

    for (int i = 0; i < n; i ++) {
        aux_min.push_back(make_pair(a[i], b[i]));
        aux_max.push_back(make_pair(a[i], b[i]));
    }

    // sortez crescator dupa valoarea minima
    sort(aux_min.begin(), aux_min.end(), comparePairsMin);

    // sortez descrescator dupa valoarea maxima
    sort(aux_max.begin(), aux_max.end(), comparePairsMax);

    int i = 0;

    while (i < moves) {
        int first_min = aux_min[i].first;
        int second_min = aux_min[i].second;
        int first_max = aux_max[i].first;
        int second_max = aux_max[i].second;

        if (min(first_min, second_min) > max(first_max, second_max)) {
            if (first_min > second_min)
                swap(aux_min[i].second, aux_max[i].first);
            else
                swap(aux_min[i].first, aux_max[i].first);
        } else {
            break;
        }

        i ++;
    }

    for (int j = 0; j < n; j ++)
        res += max(aux_max[j].first, aux_max[j].second);

    return res;
}


vector<int> ReadVector(istream& is, int size) {
    vector<int> vec(size);
    for (auto& num : vec) {
        is >> num;
    }
    return vec;
}


int main() {
    ifstream fin("nostory.in");
    ofstream fout("nostory.out");

    int task;
    fin >> task;

    int n, moves;
    if (task == 1) {
        fin >> n;
    } else {
        fin >> n >> moves;
    }

    auto a = ReadVector(fin, n);
    auto b = ReadVector(fin, n);

    auto res = task == 1 ? SolveTask1(a, b, n) : SolveTask2(a, b, n, moves);
    fout << res << "\n";

    return 0;
}
