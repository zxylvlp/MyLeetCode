#include <vector>
#include <iostream>
using namespace std;
template<typename T>
void printVec(vector<T>& vec) {
    for (int j=0; j<vec.size(); j++) {
        cout << vec[j] << ' ';
    }
    cout << endl;
}

template<typename T>
void printMat(vector<vector<T>>& mat) {
    for (int i=0; i<mat.size(); i++) {
        printVec(mat[i]);
    }
}

