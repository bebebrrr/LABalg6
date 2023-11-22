#include <iostream>
#include <vector>
using namespace std;

void deleteElements(vector<vector<int>>& T, const vector<int>& r) {
    for (int i = 0; i < T.size(); ) {
        if (T[i][1] == r[0]) {
            T.erase(T.begin() + i);
        }
        else {
            ++i;
        }
    }
}

int maximum(const vector<vector<int>>& T) {
    int maxNum = 0;
    for (const vector<int>& pair : T) {
        for (int num : pair) {
            if (num > maxNum) {
                maxNum = num;
            }
        }
    }
    return maxNum;
}

int countElements(const vector<vector<int>>& T, int num) {
    int count = 0;
    for (const vector<int>& pair : T) {
        if (pair[0] == num || pair[1] == num) {
            count++;
        }
    }
    return count;
}

vector<vector<int>> maxIndependentSet(vector<vector<int>>& T) {
    vector<vector<int>> rez;
    int a = maximum(T);
    while (!T.empty()) {
        vector<int> r;
        for (int i = a; i > 0; --i) {
            int t = countElements(T, i);
            if (t == 1) {
                r.push_back(i);
            }
        }
        deleteElements(T, r);
        rez.push_back(r);
    }
    return rez;
}

int main() {
    vector<vector<int>> T = { {1, 2}, {2, 3}, {1, 4}, {4, 5}, {1, 6}, {6, 7}, {7, 8}, {7, 9}, {7, 10}, {6, 11} };
    vector<vector<int>> result = maxIndependentSet(T);

    for (const vector<int>& r : result) {
        for (int num : r) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}