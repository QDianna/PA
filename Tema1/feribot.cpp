#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("feribot.in");
ofstream fout("feribot.out");

unsigned long long findSumMid(unsigned long long *G, unsigned long long sumMin,
unsigned long long sumMax, int K, int N) {
    /*
        Algoritmul = un fel de cautare binara
        cea mai mica suma posibila este >= cel mai mare element din sir (sumMin)
        cea mai mare suma posibila este <= suma tututor elementelor din sir (sumMax)
        => caut suma minima cu care pot face toate cele K subsecvente
        undeva intre sumMin si sumMax (sumMin)
    */

    unsigned long long sumMid = 0;

    while (sumMin < sumMax) {
        sumMid = (sumMin + sumMax) / 2;

        unsigned long long sumSubsecventa = 0;
        int nrSubsecvente = K;
        int i = 0;

        // verific daca pot avea K feriboturi cu cost <= sumMid
        while (i < N) {
            if (G[i] + sumSubsecventa > sumMid) {
                nrSubsecvente--;
                sumSubsecventa = G[i];
            } else {
                sumSubsecventa += G[i];
            }

            i ++;
        }

        nrSubsecvente --;

        if (nrSubsecvente >= 0)
            sumMax = sumMid;
        else
            sumMin = sumMid + 1;
    }

    sumMid = (sumMax + sumMin) / 2;
    return sumMid;
}


int main() {
    int N, K;

    fin >> N >> K;

    unsigned long long G[N];
    unsigned long long sumMin = 0, sumMax = 0;

    fin >> G[0];
    sumMin = sumMax = G[0];

    // calculez sumMin = elementul maxim din vector
    // si sumMax = suma elementelor din vector
    for (int i = 1; i < N; i++) {
        fin >> G[i];

        if (sumMin < G[i])
            sumMin = G[i];

        sumMax += G[i];
    }

    fout << findSumMid(G, sumMin, sumMax, K, N);
}
