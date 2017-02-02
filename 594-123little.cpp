#include <iostream>
#include<cstdio>
#include<bitset>
using namespace std;
#define SWAP(a,b) a= a^b, b=a^b, a=a^b
/*
long convert_endian(long x){
	//conviert ese digito en binario.
    bitset<32> b(x);
    long ret = 0;
    for (int j=0; j<32; j++) if (b[j]) ret |= 1<<(3-j/8)*8+(j%8);
    return ret;
}

int main(){
    long x;
    while(scanf("%ld", &x)==1) printf("%ld converts to %ld\n",
        x, convert_endian(x));
    return 0;
}*/
union{
        int i;
        char c[4];
}A,B;
int main(){
        while( scanf("%d",&A.i)==1 ){
                B.c[0]=A.c[3];
                B.c[1]=A.c[2];
                B.c[2]=A.c[1];
                B.c[3]=A.c[0];
                printf("%d converts to %d\n",A.i,B.i);
        }
        return 0;
}
/*
int main() {
    int o, reverse;
    while (scanf("%d", &o) == 1) {
        reverse = o;
        char * bits = (char*) &reverse;
        SWAP(bits[0], bits[3]), SWAP(bits[1], bits[2]);
        printf("%d converts to %d\n", o, reverse);
    }
    return 0;
}*/
