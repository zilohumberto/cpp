#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <sstream>
#include <cmath>
#include <utility>
#include <numeric>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b); i<_i; i++)
using namespace std;
long long int C,Hr,Hb,Wr,Wb;

int main() {
	cin>>C>>Hr>>Hb>>Wr>>Wb;
	if(Wr<Wb){
		swap(Hr,Hb);
		swap(Wr,Wb);
	}
	//
	return 0;
}
