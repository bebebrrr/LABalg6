#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<double>> Knapsack(vector<vector<int>>& T, int W) {
    vector<vector<double>> rez;
    int curW = 0;
    sort(T.begin(), T.end(), [](const vector<int>& a, const vector<int>& b) {
        return static_cast<double>(a[1]) / a[0] > static_cast<double>(b[1]) / b[0];
        });

    int i = T.size() - 1;
    while (i >= 0) {
        curW += T[i][0];
        if (curW == W) {
            break;
        }
        if (curW > W) {
            int t = 0;
            for (int j = curW; j > W; --j) {
                ++t;
            }
            double coef = 1.0 / (T[i][0] - t);
            double w = T[i][0] * coef;
            double p = T[i][1] * coef;
            rez.push_back({ w, p });
        }
        else {
            rez.push_back({ static_cast<double>(T[i][0]), static_cast<double>(T[i][1]) });
        }
        --i;
    }
    return rez;
}

int main() {
    vector<vector<int>> T = { {2, 14}, {4, 20}, {3, 18}, {5, 30} };
    int W = 12;
   vector<vector<double>> result = Knapsack(T, W);

    for (const vector<double>& item : result) {
        for (double val : item) {
            cout << val << " ";
        }
       cout << endl;
    }

    return 0;
}