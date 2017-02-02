//739 - uva
#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
#include <string>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b); i<_i;i++)

char build_mapa(char aux){
	if(aux=='B' || aux=='P' || aux=='F' || aux=='V'){
		return '1';
	}
	if(aux=='C' ||  aux=='S' || aux=='K' ||  aux=='G' || aux=='J' || aux=='Q' || aux=='X' || aux=='Z'){
		return '2';
	}
	if(aux=='D' || aux=='T'){
		return '3';
	}
	if(aux=='L'){
		return '4';
	}
	if(aux=='M' || aux=='N'){
		return '5';
	}
	if(aux=='R'){
		return '6';
	}
	return '0';
}
int main() {
	char name[23];

	char aux,a,in;
	printf ("         NAME                     SOUNDEX CODE\n");
	string space = "         ";
	int j;
	while(gets(name)){
		a = name[0];
		char out[23];
		out[0]=a;
		out[1]=out[2]=out[3]=aux='0';
		j=1;
		in = build_mapa(name[0]);
		bool flag=true;
		int l=(unsigned)strlen(name);
		FOR(i,1,l){
			aux = build_mapa(name[i]);
			if(i==1) name[i-1] = a;
			if(aux=='0') flag=false;
			if(flag==false){
				if(aux!='0'){
						out[j++]=aux;
				}else{
						flag=true;
				}
			}else{
				if(aux!='0' && ((aux)!=build_mapa(name[i-1]))){
					out[j++]=aux;
				}
			}
		}
		name[0]=a;
		printf ("%9s%s", " ", name);
		short h=(unsigned)strlen(name);
		FOR(i,0,25-h){
			printf(" ");
		}
		printf("%c%c%c%c",out[0],out[1],out[2],out[3]);
		printf("\n");
	}
	printf("                   END OF OUTPUT\n");
	return 0;
}
/**
 *Sample Input

LEE
KUHNE
EBELL
EBELSON
SCHAEFER
SCHAAK
Sample Output

         NAME                     SOUNDEX CODE
         LEE                      L000
         KUHNE                    K500
         EBELL                    E140
         EBELSON                  E142
         SCHAEFER                 S160
         SCHAAK                   S200
                   END OF OUTPUT
         |         |              |
         |         |              |__ Column 35
         |         |__ Column 20
         |__ Column 10
 * */

