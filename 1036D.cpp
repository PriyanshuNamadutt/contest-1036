#include<bits/stdc++.h>
using namespace std;

bool solve( vector<int> &a, int &n, int &k ) {
    if ( k == 1 ) return true;
    vector<int> b = a;
    sort( b.begin(), b.end() );
    int num = b[k-2];
    vector<int> ans;
    int cnt = 0;
    for ( int i = 0; i < n; i++ ) {
        if ( a[i] <= num ) ans.push_back( a[i] );
        else cnt++;
    }

    int i = 0, j = ans.size()-1;
    while ( i < j ) {
        if ( ans[i] == ans[j] ) {
            i++;
            j--;
        }
        else if ( ans[i] == num ) {
            cnt++;
            i++;
        }
        else if ( ans[j] == num ) {
            cnt++;
            j--;
        }
        else return false;
    }
    return (n-k+1) >= cnt;
}

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for ( int i = 0; i < n; i++ ) {
            cin >> a[i];
        }
        cout << ( solve( a, n, k) ? "YES" : "NO" ) << endl;
    }
    return 0;
}
