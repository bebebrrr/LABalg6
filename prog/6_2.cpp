#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> pointsCoverU(vector<int>& S) {
    vector<vector<int>> rez;
    int i = 0;
    int r = S[i] + 1;

    while (i < S.size()) {
        rez.push_back({ S[i], S[i] + 1 });
        i++;

        while (i < S.size() && S[i] <= r) {
            i++;
        }

        if (i < S.size()) {
            r = S[i] + 1;
        }
    }

    return rez;
}

int main() {
    vector<int> S = { 3, 4, 1, 3, 9, 2, 6, 8, 5 };
    sort(S.begin(), S.end());

    vector<vector<int>> result = pointsCoverU(S);

    for (const auto& interval : result) {
        cout << '[' << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}


