#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

void conversiones(int a,int b, int c){
	c = atof("2.2"); //conversion cadena to int o double
	int i=0;
	i = (int)(2.2);

	double d=2.2;
	d = atof("2.2");
	d = floor(d+2.75); // redondea al entero mas bajo, 4
	d = ceil(c+2.75); // redondea al entero mas alto, 4
	//faltaron
	//ran
	//sran
	//fmod
	cout << d << endl;

}
void funciones_cadenas(string a, string b, string c){

	//c = strcat(a,b); //Añade b en a
	//c = strcmp(a,b); //compara cadenas lexicograficamente
	//c = strcomp(a,b); //compara cadenas lexicograficamente sin importar mayusculas ni minusculas
	//c = strcpy(a,b); //copia la cadena b en a
	//int i = strlen(a); 	//retorna la longitud de a
}
void funciones_basicas(int a,int b, int c){
	c = min(a,b); //minimo entre a y b
	c = max(a,b); //maximo entre a y b
	c = fdim(a,b);//diferencias entera entre a y b (a-b)
	c = fma(a,b,2); //a*b+c

	cout << c << endl;
	//falta redondeo con precision
}
void macro(){
	/*Classification macro / functions
fpclassify
Classify floating-point value (macro/function )
isfinite
Is finite value (macro )
isinf
Is infinity (macro/function )
isnan
Is Not-A-Number (macro/function )
isnormal
Is normal (macro/function )
signbit
Sign bit (macro/function )

Comparison macro / functions
isgreater
Is greater (macro )
isgreaterequal
Is greater or equal (macro )
isless
Is less (macro )
islessequal
Is less or equal (macro )
islessgreater
Is less or greater (macro )
isunordered
Is unordered (macro )*/
}

void funciones_Math(int a, int b,int c){
	//funciones que utilizan la lib math.h
	c = abs(a); // valor absoluto de a, int
	double d;
	d = abs(a); // valor absoluto de a, double
	c = cos(a); //cos
	c = acos(a); //cos -1
	c = cosh(a);
	c = sin(a);  //seno
	c = asin(a); //seno -1
	c = sinh(a);
	c = tan(a); //tangente
	c = atan(a); //tan -1
	c = tanh(a);
	c = atan2(a,b); //tan -1, dos parametros
	c = exp(a); //elevar e a la potencia a
	c = log(a); //logaritmo narutal de a
	c = log10(a); //logaritmo base 10 de a
	c = pow(a,c); //potencia de a elevado a c
	c = sqrt(a); // raiz cuadrada de a

	cout << c << endl;
}
int main() {
	conversiones(4,5,0);
	return 0;
}
