//Implementacion de una matriz de dos dimensiones recursiva
//calcularemos su diagonales y la sumaremos con cada fila y tu total
//Practica
#include <iostream>
#include <cstdlib>
using namespace std;
#define SIZE 10
typedef int ddr[SIZE][SIZE];
ddr my;
int diagonal(int i, int j){
	if(i==(SIZE-1) || j>0){
		return my[i][j] + diagonal(++i,--j);
	}return 0;
}
int diagonal(int i){
	if(i==SIZE){
		return 0;
	}else
		return my[i][i] + diagonal(++i);
	return 0;
}
int total(int i,int j){
	if(i<SIZE){
		if(j<SIZE){
			return my[i][j] + total(i,++j);
		}else
			return total(++i,0);
	}
	return 0;
}
void llenarMatriz(int i,int j){
	if(i<(SIZE)){
		if(j<SIZE){
			my[i][j]=(i+j+(rand() % 10))%10;
			llenarMatriz(i,++j);
		}else{
			llenarMatriz(++i,0);
		}
	}else{
		return;
	}
}
void mostrar(){
	for(int i=0;i<SIZE;++i){
		for(int j=0;j<SIZE;++j){
			cout << my[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main() {
	llenarMatriz(0,0);
	mostrar();
	cout <<"Diagonal 1: "<<diagonal(0)<<endl;
	cout <<"Diagonal 2: "<<diagonal(0,(SIZE-1))<<endl;
	cout <<"Total : " <<diagonal(0) +diagonal(0,SIZE-1)+total(0,0)<<endl;
	return 0;
}
