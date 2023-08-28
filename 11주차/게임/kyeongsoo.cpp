#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    long long x, y, z, ans;
    cin >> x >> y;
    z = (y * 100) / x;
    ans = -1;
    if(z >= 99){
        cout << ans << endl;
        exit(0);
    }
        
    long long start = 1, end = x;
    while (start <= end) {
        long long mid = (start + end)/2;
        if (((y + mid) * 100) / (x+mid) > z ) {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    cout << ans << endl;
}
