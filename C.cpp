#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <map>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b); i<_i;i++)

int main() {
	string aux;
	while(cin>>aux){
		map<char,int> fre;
		FOR(i,0,aux.length()){
			fre[aux[i]]=0;
		}
		cout<<fre['a']->secund<<endl;
	}
	return 0;
}
/*#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
using namespace std;
#define FOR(i,a,b) for(int i=(a),_i=(b); i<_i;i++)

int main() {

	string line;
	while(getline(cin,line)){
		vector<int> A;
		vector<int> B;
		int l=line.length();
		FOR(i,0,l){
			if((line[i] != ' ') || (i==l-1)){
				A.push_back(line[i]-'0');
			}
		}
		line="";
		getline(cin,line);
		l=line.length();
		FOR(i,0,l){
			if((line[i] != ' ') || (i==l-1)){
				B.push_back(line[i]-'0');
			}
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		int al=A.size(), bl=B.size();

		int pa=0,pb=0;
        	FOR(i,0,bl){
        		FOR(j,i,al){
        			if(A[j]==B[i]){
        				pa++;
        				break;
        			}
        		}
        	}

        	FOR(i,0,al){
        		FOR(j,i,bl){
        			if(A[i]==B[j]){
        				pb++;
        				break;
        			}
        		}
        	}

        if((pa==pb)){
					cout<<"A and B are disjoint"<<endl;
		}else{
			if((al == bl) && (pa==pb) ){
				cout<<"A equals B"<<endl;
			}else
				if((pa==pb) && (bl < al)){
				cout<<"B is a proper subset of A"<<endl;
				}else
					if((pa==pb) && (al < bl)){
						cout<<"A is a proper subset of B"<<endl;
					}else
						cout<<"I'm confused!"<<endl;
		}
	}

	return 0;
}
*/
