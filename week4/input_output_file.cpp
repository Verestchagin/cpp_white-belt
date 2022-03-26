#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream input("input.txt");
    ofstream output("output.txt");
    string line;
    while (getline(input, line)){
        //cout << line << endl;
        output << line << endl;
    }
}
