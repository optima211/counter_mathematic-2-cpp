#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int n = 4;
    int k = 0;
    double C[4][4] = {{0,        0.28125,  -0.16667, 0.29167},
                      {-0.11024, 0,        0.29134,  0.33858},
                      {-0.36,    0.70667,  0,        -0.42667},
                      {0.24293,  -0.16949, 0.43503,  0}};
    double B[4] = {2.5833, -2.48819, -2.02667, 0.72881};
    double X[4], Xn[4];
    double eps = 0.0001;
    double d;

    for (int i = 0; i < n; i++) X[i] = 0;
    d = 1000;
    while (d >= eps) {
        for (int i = 0; i < n; i++) {
            Xn[i] = 0;
            for (int j = 0; j < n; j++) {
                Xn[i] = Xn[i] + C[i][j] * X[j];
            }
            Xn[i] = B[i] - Xn[i];
        }
        d = fabs(Xn[0] - X[0]);
        for (int j = 1; j < n; j++) {
            if (fabs(Xn[j] - X[j]) > d) d = fabs(Xn[j] - X[j]);
        }
        for (int j = 0; j < n; j++) X[j] = Xn[j];
        k = k + 1;

    }
    //setlocale(LC_ALL, "Russian");

    for (int i = 0; i < n; i++) {
        cout << "X-" << i + 1 << "= " << X[i] << endl;

    }
    cout << "Count iterate  =" << k << endl;

    system("pause");
    return 0;
}
