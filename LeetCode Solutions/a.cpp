#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n ;
    cin >> n;
    while(n--){
        int t;
        cin >> t;
        for ( int i = 0; i < t; i++ ){
            cout << i << " " << t << " ";
        }
        cout << endl;
    }
    return 0;
}