#include <iostream>
#include <string.h>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
	string linea1;
	long long int n;
	int TC;
	cin >> TC;
	while(TC--){
		cin >> n;
		cin >> linea1 ;
		if(n>=linea1.size()|| n==0){
			cout << linea1<<endl;
		}else{
			int tamano=linea1.size()-n;
			stringstream res;
			res <<linea1[tamano];
			if(tamano==linea1.size()-1){
				res << linea1.substr(0,tamano);
			}else{
				//res<<linea1.substr(tamano,linea1.size());
				res<<linea1.substr(0,tamano);

			}
			cout << res.str() << endl;

		}
	}

	return 0;
}
