#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void removeS(vector<int>& S, int x) {
    S.erase(remove(S.begin(), S.end(), x), S.end());
}

vector<vector<int>> pointsCover(vector<int>& S) {
    vector<vector<int>> rez;
    while (!S.empty()) {
        int Xm = *min_element(S.begin(), S.end());
        rez.push_back({ Xm, Xm + 1 });
        removeS(S, Xm);
        removeS(S, Xm + 1);
    }
    return rez;
}

int main() {
    vector<int> S = { 3, 4, 1, 3, 1, 2, 6, 8, 5 };
    vector<vector<int>> result = pointsCover(S);

    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}