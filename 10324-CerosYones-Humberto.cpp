/*Solucion sustrayida de taysig*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
using namespace std;
#define N 1000000
#define LL long long
#define For(i, a, b) for( int i = (a); i < (b); i++ )
char ch [N + 5];
int a [N + 5];

int main (){

    int cases = 0;

    while ( gets (ch) ) {
    	//logitud del array
        int len = strlen (ch);
        //nada nada
        if ( len == 0 ) break;
        //tomo el primer valor de ch y lo asigno en a[0] dependiendo de que valor sea
        a [0] = ch [0] == '1' ? 1 : 0;
        //recorro len y voy incrementando a[i]
        for ( int i = 1; i < len; i++ )
            a [i] = ch [i] == '1' ? a [i - 1] + 1 : a [i - 1];

        //leo los casos
        int n; scanf ("%d", &n);
        printf ("Case %d:\n", ++cases);
        //itero
        while ( n-- ) {
            int p, q; scanf ("%d %d", &p, &q);
            //cambio de ser necesario
            if ( p > q ) swap (p, q);
            //WTF
            if ( ch [p] == '0' && ch [q] == '0' && a [q] - a [p] == 0 )
            	printf ("Yes\n");
            else if ( ch [p] == '1' && ch [q] == '1' && a [q] - a [p] == q - p )
            	printf ("Yes\n");
            else printf ("No\n");
        }

        getchar ();
    }
    return 0;
}
