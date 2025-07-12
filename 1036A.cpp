#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for ( int i = 0; i < n; i++ ) {
        cin >> a[i];
    }
    vector<int> b = a;
    sort( b.begin(), b.end() );
    unordered_map<int,bool> mp;
    for ( int i = 0; i < n; i++ ) {
        if ( a[i] == b[i] ) mp[i] = true;
    }
    if ( mp.size() == n ) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    cout << n - mp.size() << endl;
    for ( int i = 0; i < n; i++ ) {
        if ( !mp[i] ) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

int main () {
    int t; cin >> t;
    while ( t-- ) {
        solve();
    }
    return 0;
}
