#include <iostream>
using namespace std;
#define FOR(i,a,b) for(int i=(a), _i=(b); i<_i; i++)
int main() {
	bool victor=true;
	string line;
	while(getline(cin,line)){
		FOR(i,0,line.length()){

			if(line[i] >= '2' && line[i]<='9'){
				cout<<(line[i]-1)-'0';
			}else{
				switch(line[i]){
					case '1':{
						cout<<"`";break;
					}
					case '-':{
						cout<<"0";break;
					}
					case '0':{ cout<<"9";break;}
					case ' ':{ cout<<" ";break;}
					case '=':{ cout<<"-";break;}
					case ']':{ cout<<"[";break;}
					case '[':{ cout<<"P";break;}
					case 'P':{ cout<<"O";break;}
					case 'O':{ cout<<"I";break;}
					case 'I':{ cout<<"U";break;}
					case 'U':{ cout<<"Y";break;}
					case 'Y':{ cout<<"T";break;}
					case 'T':{ cout<<"R";break;}
					case 'R':{ cout<<"E";break;}
					case 'E':{ cout<<"W";break;}
					case 'W':{ cout<<"Q";break;}
					case ';':{ cout<<"L";break;}
					case 'L':{ cout<<"K";break;}
					case 'K':{ cout<<"J";break;}
					case 'J':{ cout<<"H";break;}
					case 'H':{ cout<<"G";break;}
					case 'G':{ cout<<"F";break;}
					case 'F':{ cout<<"D";break;}
					case 'D':{ cout<<"S";break;}
					case 'S':{ cout<<"A";break;}
					case '/':{ cout<<".";break;}
					case '.':{ cout<<",";break;}
					case ',':{ cout<<"M";break;}
					case 'M':{ cout<<"N";break;}
					case 'N':{ cout<<"B";break;}
					case 'B':{ cout<<"V";break;}
					case 'V':{ cout<<"C";break;}
					case 'C':{ cout<<"X";break;}
					case 'X':{ cout<<"Z";break;}
					case '\\':{ cout<<"]";break;}
					case '\'':{ cout<<";";break;}
					default : { cout<<line[i];}
				}

			}
		}
		cout<<endl;
	}
	return 0;
}
