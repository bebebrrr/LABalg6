#include <iostream>
#include <vector>
using namespace std;

void remove(vector<vector<int>>& S, int Lm, int Rm) {
    for (int i = 0; i < S.size(); ++i) {
         vector<int> t;
        for (int k = Lm; k < Rm; ++k) {
            t.push_back(k);
        }
        try {
            if (S[i][0] == t[0]) {
                S.erase(S.begin() + i);
            }
        }
        catch (...) {

        }
    }
}
vector<vector<int>> actSel(vector<vector<int>>& S) {
    vector<vector<int>> rez;
    int t = 0;

    while (S.size() != 0) {
        int min = 111;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i][1] < min) {
                min = S[i][1];
                t = S[i][0];
            }
            if (i == S.size() - 1) {
                rez.push_back({ t, min });
                remove(S, t, min);
            }
        }
    }
    return rez;
}
int main() {
    vector<vector<int>> S = { {1, 3}, {3, 4}, {5, 6}, {1, 5}, {3, 7}, {6, 8} };
    vector<vector<int>> result = actSel(S);

    for (const vector<int>& pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    return 0;
}