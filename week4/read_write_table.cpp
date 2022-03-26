#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream input("input.txt");
    //ofstream output("output.txt");
    int n, m, x;
    input >> n >> m;
    for (int i=0; i < n; ++i){
        for (int j=0; j < m - 1; ++j){
            input >> x;
            input.ignore(1);
            cout << setw(10) << x << " ";
        }
        input >> x;
        cout << setw(10) << x;
        if (i!=n-1){
            cout << endl;
        }

    }
}
