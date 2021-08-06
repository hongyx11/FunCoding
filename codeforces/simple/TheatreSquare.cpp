#include <iostream> // includes cin to read from stdin and cout to write to stdout

//https://codeforces.com/problemset/problem/4/A

#define ulli unsigned long long int

ulli theatresquare(ulli m, ulli n, ulli a){
    ulli t1 = m / a + (m % a != 0);
    ulli t2 = n / a + (n % a != 0);
    return t1 * t2;
}

using namespace std; // since cin and cout are both in namespace std, this saves some text
int main() {
    ulli m, n, a;
    cin >> m >> n >> a; // read t. cin knows that t is an int, so it reads it as such.
    ulli ans = theatresquare(m, n, a);
    cout << ans << endl;
    return 0;
}

