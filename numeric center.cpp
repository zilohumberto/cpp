#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
long long int N, index=1, fsum=0, ssum=1,ans;
vector<int> sol;
void full(long long int t){
	long long int i=1, aux=1;
	sol.push_back(0);
	while(aux<t){
		sol.push_back(i+sol.back());
		aux=aux+i;
		i++;
	}
}
int main() {
	full(100000000000005);
	while(cin>>N){
		ans=0;
		index=3;
		fsum=0;
		ssum=1;
		do{
		            fsum=sol[index];
		            cout<<fsum<<endl;
		            for(int j=index+1;j<index*2;j++){
		                if(ssum==fsum){
		                	ans++;
		                	break;
		                }else{
		                        ssum=ssum+j;
		                }
		             }
		            index++;
		            fsum=0;ssum=1;
		}while(index<N+1);
		printf("%lld\n",ans);
	}
	return 0;
}


/*

class Ideone
{
    public static void main(String args[]){
        int n, index, fsum, ssum;
        n=204;
        index=1;
        fsum=0;
        ssum=1;
        do{
            for (int i=1;i<index;i++){
            	fsum=fsum+i;
            }
            for (int j=index+1;j<index*2;j++){
                if (ssum==fsum){
                    System.out.println(index+" es un centro numerico.");
                    break;
                    }else{
                        ssum=ssum+j;
                    }
             }
            index++;
            fsum=0;ssum=0;
        }while (index<n+1);
    }
}
 */
