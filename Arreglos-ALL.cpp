#include <iostream>
#include <vector>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b);i<_i;i++)
#define SIZE 20
#define cout(a,b) cout <<a<<" "<<b<<endl;
const short l=5;
class lol{
	private:
		int po;
	public:
		lol(){};
		lol(int p){ po=p;};
		int getI(){ return po;};
};
//faltan los metodos de vector
//http://www.dreamincode.net/forums/topic/33631-c-vector-tutorial/
//vector documentation
//http://en.cppreference.com/w/cpp/container/vector

int main() {
	int ii=2;
	int alfa[ii];
	alfa[100]=2;
	alfa[5]=9;
	alfa[9]=6;
	cout<<alfa<<endl;
	short a[l]={1,2,3,4,5};
	FOR(i,1,l)
		cout<<a[i-1]+a[i]++<<endl;

	const short p =10;
	short ma[p][p];
	int h=0;
	FOR(i,0,p){
		FOR(j,0,p){
			ma[i][j]=h;
			h=(h+1)%10;
		}
	}
	/*Da error
		 * for(short b: a){
			//cout<<b<<endl;
		}
		*/
	FOR(i,0,p){
		FOR(j,0,p){
			cout<<ma[i][j];
		}
		cout<<endl;
	}
	short maD[2][2][2];
	short mi=0;
	FOR(i,0,2){
			FOR(j,0,2){
				mi=0;
				FOR(k,0,2){
					maD[i][j][k]=h;
					mi+=h;
					h=(h+1)%10;
				}
				//maD[i][j][0]=0;
			}
	}
	cout << "-"<<endl;
	FOR(i,0,2){
			FOR(j,0,2){
				short H=0;
				FOR(k,0,2){
						//cout<<"X Y Z "<<i<<j<<k<<" "<<maD[i][j][k]<<endl;
						H+=maD[i][j][k];
				}
				cout << "TOTAL XY "<<H<<endl;
			}

		}
	typedef int tipomatriz[l][l];
	tipomatriz M1;
	//esta es una matriz normal.
	//hola[0]=4

	lol *yy = new lol[3];
	yy[0] = lol(1);
	yy[1] = lol(3);
	yy[2] = lol(5);
	int obj1= yy->getI();
	int obj2= (yy+1)->getI();
	int obj3= (yy+2)->getI();
	//135
	cout << obj1<<obj2<<obj3<<endl;
	cout << SIZE-10 << endl;
	cout(2,3);
	return 0;
}
