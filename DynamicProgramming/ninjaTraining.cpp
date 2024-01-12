// https://www.codingninjas.com/studio/problems/ninja%E2%80%99s-training_3621003

#include <iostream>
#include <vector>
using namespace std;

// Memoization
// T.C = 
// S.C = 
#if 0
int solve(int day, int last, vector<vector<int>> &points, vector<vector<int>> &arr) {
    if (day == 0) {
        int maxi = 0;
        if (arr[0][last] != -1) return arr[0][last];
        for (int i = 0; i < 3; i++) {
            if (i != last) {
                maxi = max(maxi, points[0][i]);
            }
        }
        arr[0][last] = maxi;
        return maxi;
    }

    if (arr[day][last] != -1) return arr[day][last];

    int maxi = 0;
    for (int i = 0; i < 3; i++) {
        if (i != last) {
            int sum = 0;
            sum = points[day][i] + solve(day-1, i, points, arr);
            maxi = max(maxi, sum);
        }
    }

    arr[day][last] = maxi;
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    n = n - 1;
    vector<vector<int>> arr(n+1, vector<int>(4, -1));
    return solve(n, 3, points, arr);
}
#endif

// Tabulation
// T.C = 
// S.C = 
#if 0
int ninjaTraining(int n, vector<vector<int>> &points) {
    n = n - 1;
    vector<vector<int>> arr(n+1, vector<int>(4, 0));

    arr[0][0] = max(points[0][1], points[0][2]);
    arr[0][1] = max(points[0][0], points[0][2]);
    arr[0][2] = max(points[0][0], points[0][1]);
    arr[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day <= n; day++) {
        for (int last = 0; last < 4; last++) {
            int maxi = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int sum = points[day][task] + arr[day-1][task];
                    maxi = max(maxi, sum);
                }
            }
            arr[day][last] = maxi;
        }
    }

    return arr[n][3];
}
#endif

// Space Optimisation
// T.C = 
// S.C = 
int ninjaTraining(int n, vector<vector<int>> &points) {
    n = n - 1;
    vector<int> arr(4, 0);

    arr[0] = max(points[0][1], points[0][2]);
    arr[1] = max(points[0][0], points[0][2]);
    arr[2] = max(points[0][0], points[0][1]);
    arr[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day <= n; day++) {
        vector<int> tmp(4, 0);
        for (int last = 0; last < 4; last++) {
            tmp[last] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int sum = points[day][task] + arr[task];
                    tmp[last] = max(tmp[last], sum);
                }
            }
        }
        arr = tmp;
    }

    return arr[3];
}

int main()
{
    vector<vector<int>> v = {{10, 40, 70},
                             {20, 50, 80},
                             {30, 60, 90}};
                             
    cout << ninjaTraining(v.size(), v) << endl;     // 210

    vector<vector<int>> v1 = {{18, 11, 19},
                              {4, 13, 7},
                              {1, 8, 13}};

    cout << ninjaTraining(v1.size(), v1) << endl;   // 45

    return 0;
}