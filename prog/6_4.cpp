#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void actSelU(vector<vector<int>>& S)
{
    int N = S.size();
    vector<int> added(N, 0);
    vector<vector<int>> rez;

    sort(S.begin(), S.end(), [](const vector<int>& x, const vector<int>& y) {
        return x[0] < y[0];
        });

    for (int i = 0; i < N; ++i) {
        bool overlap = false;
        for (int r = S[i][0]; r <= S[i][1]; ++r) {
            if (added[r - S[i][0]]) {
                overlap = true;
                break;
            }
        }
        if (!overlap) {
            rez.push_back(S[i]);
            for (int r = S[i][0]; r <= S[i][1]; ++r) {
                added[r - S[i][0]] = 1;
            }
        }
    }

    for (int i = 0; i < rez.size(); ++i) {
        cout << "[" << rez[i][0] << ", " << rez[i][1] << "] ";
    }
}

int main()
{
    vector<vector<int>> activities = { {3, 8}, {1, 4}, {2, 5}, {5, 9}, {0, 6}, {8, 11}, {5, 7}, {8, 12}, {9, 14}, {12, 16} };

    actSelU(activities);

    return 0;
}