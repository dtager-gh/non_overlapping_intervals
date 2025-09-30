#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;

    // Sort by the last number in the pair
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
        });

    int count = 1; // number of pairs kept
    int lastEnd = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= lastEnd) {
            // Non-overlapping
            count++;
            lastEnd = intervals[i][1];
        }
    }

    return intervals.size() - count; // subtract the kept pairs from the total number of pairs
};

int main() {

    
    vector<vector<int>> intervals1 = { {1,2},{2,3},{3,4},{1,3} };
    cout << eraseOverlapIntervals(intervals1) << endl; // Output: 1

    vector<vector<int>> intervals2 = { {1,2},{1,2},{1,2} };
    cout << eraseOverlapIntervals(intervals2) << endl; // Output: 2

    vector<vector<int>> intervals3 = { {1,2},{2,3} };
    cout << eraseOverlapIntervals(intervals3) << endl; // Output: 0

    return 0;
}
