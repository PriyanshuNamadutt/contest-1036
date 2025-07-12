#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void print( vector<ll> &a ) {
    for ( int i = 0; i < a.size(); i++ ) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void solve( vector<ll> &a, vector<ll> &presum, ll &half,int &n ) {
    ll sum = 0;
    for ( int i = n-1; i > 0; i-- ) {
        sum += a[i];
        if ( sum == presum[i] ) {
            cout << 1 << endl;
            print(a);
            return;
        }
    }
    cout << 2 << endl;
    int idx = upper_bound( presum.begin(), presum.end(), half ) - presum.begin();
    ll tar = presum[idx] - half;
    vector<ll> b(n, 0);
    b[idx-1] = tar;
    a[idx-1] -= tar;
    for ( int i = 0; i < idx-1; i++ ) {
        b[i] = min( a[i], tar );
        tar -= min( a[i], tar );
        a[i] -= b[i];
    }
    print( b );
    print( a );
    return;
}
 
int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n; cin >> n;
        vector<ll> a(n);
        ll sum = 0;
        for ( int i = 0; i < n; i++ ) {
            cin >> a[i];
            sum += a[i];
        }
        bool check = false;
        ll half = sum / 2;
        vector<ll> presum( n+1, 0 );
        for ( int i = 0; i < n; i++ ) {
            if ( a[i] > half ) check = true;
            presum[i+1] = presum[i] + a[i]; 
        }

        if ( sum % 2 != 0 || check ) {
            cout << -1 << endl;
            continue;
        }

        solve( a, presum, half, n );
    }
    return 0;
}
