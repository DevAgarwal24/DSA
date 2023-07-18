// https://www.codingninjas.com/studio/problems/minimise-max-distance_7541449

#include <iostream>
#include <vector>

using namespace std;

long double MinPossMaxDistanceBruteForce(vector<int>& arr, int k) {
    int n = arr.size();

    vector<int> howMany(n-1, 0);

    for (int gasStations = 1; gasStations <= k; gasStations++) {
        long double maxVal = -1; int maxInd = -1;

        for (int i = 0; i < n-1; i++) {
            long double diff = (long double)(arr[i+1] - arr[i]) / (long double)(howMany[i] + 1);
            if (diff > maxVal) {
                maxVal = diff;
                maxInd = i;
            }
        }

        howMany[maxInd]++;
    }

    long double maxDist = -1;

    for (int i = 0; i < n-1; i++) {
        long double dist = (long double)(arr[i+1] - arr[i]) / (long double)(howMany[i] + 1);
        if (dist > maxDist) {
            maxDist = dist;
        }
    }

    return maxDist;
}

int main()
{
    vector<int> v = {1, 13, 17, 23};

    cout << MinPossMaxDistanceBruteForce(v, 5) << endl;     // 3

    v.clear();
    v = {1, 2, 3, 4, 5};
    cout << MinPossMaxDistanceBruteForce(v, 4) << endl;     // 0.5

    return 0;
}