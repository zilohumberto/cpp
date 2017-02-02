#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <cstring>
using namespace std;
#define FOR(i,a,b) for(int i=(a), _i=(b); i<_i;i++)
int main() {
	string str;
	while(cin>>str){
		int sec  = ( (str[0] - '0') * 10 + (str[1] - '0') ) * 60 * 60 * 100;
					sec += ( (str[2] - '0') * 10 + (str[3] - '0') ) * 60 * 100;
					sec += ( (str[4] - '0') * 10 + (str[5] - '0') ) * 100;
					sec += ( (str[6] - '0') * 10 + (str[7] - '0') );
		printf("%07d\n",(sec*125) / 108);

	}
	return 0;
}
/*La relacion entre los sistemas sexagecimales (tradicional) y el sistema decimal pueden ser expresadas como S/24 hors = C/10 horas, pero 24 tiene 24*60 minutos y 24*3600 segundos  asi mismo 10 horas tienen 10*100 minutos y 10*100*100 segundos*/
/*24*3600 secs = 86400 segundos= 1 dia tradicional
10*100*100 secs= 100000 segundos = 1 dia decimal
La relacion queda:
S/ 86400 segundos = C/100000
reduciendolo:
S/108= C/125 => Despejando C que es lo que nos interesa tienes C=125*S/108*/
