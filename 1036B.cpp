#include<iostream>
#include<vector>

using namespace std;

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n; cin >> n;
        vector<int> a(n);
        for ( int i = 0; i < n; i++ ) {
            cin >> a[i];
        }
        cout << min( 2*a[0] , a[0]+a[1] ) << endl;
    }
    return 0;
}
