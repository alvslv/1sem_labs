// var 3: 3. Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). 
// Найти столбец содержащий наименьший элемент матрицы и заменить 
// все отрицательные элементы этого столбца числом 0.
#include <iostream>
using namespace std;


int main() {
    unsigned n, m;
    cout << "n, m: ";
    cin >> n >> m;

    int matrix[n][m];
    int min = INT_MAX, min_column;

    cout << "sequence:\n";
    for (unsigned i = 0; i < n; i++)
        for (unsigned j = 0; j < m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                min_column = j;
            }
        }

    for (unsigned i = 0; i < n; i++) {
        if (matrix[i][min_column] < 0)
            matrix[i][min_column] = 0;
    }

    cout << "\nanswer:\n";
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < m; j++)
            cout << matrix[i][j] << ' ';

        cout << endl;
    }
}