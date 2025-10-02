# Tema 1 – Programare Avansată (PA)

Acest proiect conține rezolvările pentru patru probleme algoritmice: **FERIBOT, NOSTORY, SUSHI, SEMNALE**.  
Am folosit tehnici precum **căutare binară, sortare, programare dinamică și optimizare greedy**.  

## Problema 1 – FERIBOT
Determinarea costului minim pentru un feribot folosind **căutare binară**.  

- Costul minim posibil = greutatea celei mai mari mașini (`sumMin`)  
- Costul maxim posibil = suma tuturor greutăților (`sumMax`)  
- Se caută binar în intervalul `[sumMin, sumMax]` pentru a găsi valoarea minimă posibilă a costului maxim, verificând dacă se pot încărca toate mașinile în `K` feriboturi.  

**Complexitate:** `O(n log n)`  

## Problema 2 – NOSTORY
### Task 1
- Se sortează cele două liste folosind **merge sort**.  
- Se selectează cele mai mari `N` numere din listele reunite, printr-o interclasare inversă.  

**Complexitate:** `O(n log n)`  

### Task 2
- Se construiesc 2 vectori de perechi:  
  - `aux_min` (sortat crescător după minimul perechii)  
  - `aux_max` (sortat descrescător după maximul perechii)  
- Se încearcă interschimbarea a cel mult `K` valori pentru maximizarea scorului.  

**Complexitate:** `O(n log n)`  

## Problema 3 – SUSHI
### Task 1
- Se folosește **programare dinamică** cu matrice `(m+1) x (n*x)` unde `i` = numărul de platouri, `j` = cost.  
- Se verifică pentru fiecare platou dacă se include sau nu în soluție.  

### Task 2
- Platourile pot fi duplicate → vector extins → se aplică același algoritm.  

### Task 3
- Matrice 3D:  
  - dimensiunea `i` = suma notelor,  
  - dimensiunea `j` = prețul,  
  - dimensiunea `k` = numărul de platouri.  

**Complexitate:** aproximativ `O(n^2)`  

## Problema 4 – SEMNALE
### Task 1
- Matrice `x` linii × `y` coloane, unde `(i,j)` = nr. semnale cu `i` zerouri și `j` unuuri.  
- Se adaugă `0` tuturor semnalelor anterioare, `1` doar semnalelor care se termină în `0`.  

### Task 2
- Similar cu Task 1, dar se poate adăuga și `11` la semnalele care se termină în `0`.  

**Complexitate:** `O(x*y)`  
