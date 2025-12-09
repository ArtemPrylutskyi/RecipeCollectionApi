#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    
    setlocale(LC_ALL, "");

   
    double A[3][3] = {
        { 4, -1,  2},
        {-2,  5,  5},
        {-1,  4,  6}
    };

    
    double b[3] = { 7, -3, 2 };

    
    vector<double> x = { 0, 0, 0 };
    vector<double> x_new = { 0, 0, 0 };

    double eps = 1e-6; 
    double error = 0;
    int max_iter = 100;
    int k = 0;

    cout << "Розв'язання СЛР методом простих ітерацій (Якобі):" << endl;
    cout << fixed << setprecision(6);
    cout << "Iter\t x1\t\t x2\t\t x3\t\t Error" << endl;

    for (k = 1; k <= max_iter; k++) {
        
        x_new[0] = (b[0] - (A[0][1] * x[1] + A[0][2] * x[2])) / A[0][0];
        x_new[1] = (b[1] - (A[1][0] * x[0] + A[1][2] * x[2])) / A[1][1];
        x_new[2] = (b[2] - (A[2][0] * x[0] + A[2][1] * x[1])) / A[2][2];

       
        error = 0;
        for (int i = 0; i < 3; i++) {
            double diff = fabs(x_new[i] - x[i]);
            if (diff > error) {
                error = diff;
            }
        }

      
        cout << k << "\t " << x_new[0] << "\t " << x_new[1] << "\t " << x_new[2] << "\t " << scientific << error << fixed << endl;

        
        x = x_new;

       
        if (error < eps) {
            break;
        }
    }

    cout << "-----------------------------------" << endl;
    if (error < eps) {
        cout << "Розв'язок знайдено:\n";
        cout << "x1 = " << x[0] << endl;
        cout << "x2 = " << x[1] << endl;
        cout << "x3 = " << x[2] << endl;
    }
    else {
        cout << "Метод не зійшовся (перевищено ліміт ітерацій)." << endl;
    }

    return 0;
}