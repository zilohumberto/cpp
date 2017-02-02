#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <string.h>
#include <queue>
#include <stack>
#include <cstdlib>
using namespace std;

//nodo del archivo
class archivo{
 public :
        string nombre,tipo,ext,contenido;
        archivo * sig, *ant ;

        archivo(){
         nombre = "";
         sig = NULL;
         ant= NULL;
        }

        archivo(string nombre){
         this->nombre = nombre;
         sig = NULL;
         ant = NULL;
        }

};
//contiene el nodo de carpeta
class carpeta{
 public :

        string nombre,tipo;
        carpeta * sig, *ant ;
        archivo *A;
        carpeta(){
        	A=NULL;
         nombre = "";
         sig = NULL;
         ant = NULL;

        }

        carpeta( string nombre){
        	A=NULL;
         this->nombre = nombre;
         sig = NULL;
         ant = NULL;

        }

};
//contiene todo los metodos de los nodos y las listas doblemente enlazadas
class Disco{
      public :
             //insertar como pila funciona al pelo
            bool vacio(carpeta *& L){
            	return (L==NULL);
            }
			void insertar(carpeta * & L,string nombre){
              if(vacio(L)){
                  L= new carpeta(nombre);
                  L->ant=NULL;
                  L->sig=NULL;
                }else{
                	carpeta * Aux = new carpeta( nombre);
                	carpeta *P=L;
                	while(P != NULL){
                		if(P->sig != NULL){
                			P=P->sig;
                		}else
                			break;
                	}
                      Aux->ant = P;
                      P->sig = Aux;
                }
            }

			bool buscar(carpeta * & L, string nombre){
				if(!vacio(L)){
					if(L->nombre == nombre){
						return true;
					}else{
						return buscar(L->sig,nombre);
					}
				}
				return false;
			}

			void eliminar(carpeta * & L, string nombre){
				if(!vacio(L) and buscar(L,nombre)){
						if(L->nombre == nombre ){
							if(!vacio(L->sig)){
									L= L->sig;
									L->ant = NULL;
							}else
								L=NULL;

						}else{
								while(L->sig->nombre != nombre )
									L=L->sig;

								if(!vacio(L->sig->sig)){
									L->sig->sig->ant = L;
									L->sig = L->sig->sig;
								}else
									L->sig=NULL;


								while(L->ant != NULL )
									L=L->ant;

						}

				}
			}

             void mostrar(carpeta *L, bool tortura){
                if(L != NULL){
                    if(tortura){
                    	tortura= false;
                    }else{
                    	cout <<"C/ " << L->nombre <<endl;
                    }
                	 mostrarA(L->A);
                     mostrar(L->sig,tortura);
                }
             }

//Metodos de archivo
             void archivar(carpeta * & L,string carp,string nombre){
                                     				if(!vacio(L)){
                                 if(L->nombre != carp){
                                	 archivar(L->sig,carp,nombre);
                                 }else{

                                     					if(L->A ==NULL){
                                     						archivo *Aux = new archivo(nombre);
                                     						L->A=Aux;
                                     					}else{
                                     						archivo * Aux = new archivo( nombre);
                                     						Aux->sig = L->A;
                                     						L->A->ant = Aux;
                                     						L->A = Aux;
                                     					}
                                 }	}
                                     			}



             bool vacioA(archivo * & L){
                        	 return (L==NULL);
                         }

                         bool buscarA(carpeta * & L, string carp,string nombre){
                         		if(!vacio(L)){
                         			if(L->nombre == carp){
                         						return buscarAr(L->A,nombre);
                         			}else{
                         						return buscarA(L->sig,carp,nombre);
                         			}
                         		}
                         				return false;
                         }

                         bool buscarAr(archivo * & A, string nombre){
                        	 if(!vacioA(A)){
                        		 if(A->nombre == nombre){
                        			 return true;
                        		 }else{
                        			 return buscarAr(A->sig,nombre);
                        		 }
                        	 }
                        	 return false;
                         }


                         carpeta primero(carpeta * & L){
                                if(!vacio(L)){
                                   while(L->ant != NULL){
                                	   L=L->ant;
                                   }
                                      return *L;
                                }
                         }


                         carpeta ubicar(carpeta * & L, string nombre){
                        	 if(!vacio(L)){
                        		 if(L->nombre==nombre){
                        		       return *L;
                                 }
                        		 while(L->sig != NULL){
                        	          if(L->nombre==nombre){
                        	        	  return *L;
                        	          }
                        	    	  L=L->sig;
                        	      }
                        	     if(L->nombre==nombre){
                        	                             			 return *L;
                        	     }
                        	 }
                         }

                         bool eliminarA(carpeta * & L, archivo * & A, string carp, string arc){
                        	 if(!vacio(L)){
                        		 if(L->nombre != carp){
                        			 return eliminarA(L->sig,L->sig->A,carp,arc);
                        		 }else{
                        			 	return eliminarAr(A,arc);
                        		 }

                        	 }
                         }
                         //elimina dentro de la carpeta situando en la misma
                         bool eliminarAr(archivo * & A, string nombre){
                         				if(!vacioA(A)){
                         						if(A->nombre != nombre ){
                         							return eliminarAr(A->sig,nombre);
                         						}else{
                         							if(vacioA(A->sig)){
                         								A=NULL;
                         								return true;
                         							}else{
                         									A=A->sig;
                         									return true;
                         							}

                         				}
                         			}
                         				return false;}

                         void mostrarA(archivo *L){
                                         if(L != NULL){
                                              cout <<"A " << L->nombre << endl;
                                              mostrarA(L->sig);
                                         }
                                      }


};
class menu{
	public :
	carpeta * Li, *SO;
	Disco l;
	queue<string> cola,colaAux;
	string unid,entrada;
	bool bandera,continuo,A,D;

	bool ban;

		menu(){
			Li=NULL;
			ban=false;
			A=false;
			D=false;
			bandera=false;
			continuo=true;
			string zilo = "";
			l.insertar(Li,"shell");
			SO=Li;
			unid = SO->nombre;

			while(continuo){
				cout << unid<< ">" ;
				getline(cin,entrada);
					if(entrada != "exit"){
						cola = token(colaAux,entrada);
						if(!persuechon(cola," ")){
							cout <<"No es reconocido como un comando interno o externo."<< endl;
						 }
					}else{ break;}
		}
		}

		bool llenarLista(queue<string> line){
					string aux,aux2;
					queue<string> cont;
					bool enviar=false;
					while(!line.empty()){
						string carp = line.front();
						line.pop();
						carp = recortarCarp(carp);
						if(carp != " " or carp != ""){
							enviar=true;
							if(A){
								cont = cortarConte(carp);
								l.archivar(Li,aux,cont.front());
								aux2=cont.front();
								cont.pop();
								cout << aux2 << endl;
								//cout << l.edit(Li,aux2,cont.front()) << endl;
								A=false;
							}else if(D){
								D=false;
								l.insertar(Li,carp);
								aux=carp;
							}
						}else{
							return enviar;
						}
					}
					return false;
				}
			 	queue<string> cortarConte(string ct){
			 		int i=0,len=ct.length();
			 		string aux,aux2;
			 		queue<string> cont;
			 		while(len >= i){
			 			if(ct[i] != ' '){
			 				aux += ct[i];
			 				if(ct[i] == '*'){
			 					i++;
			 					while(ct[i] != '*'){
			 						aux2 += ct[i];
			 						i++;
			 					}
			 					cont.push(aux2);
			 					aux2 = "";
			 				}
			 			}else{
			 				cont.push(aux);
			 				aux = "";
			 			}
			 			i++;
			 		}
			 		return cont;
			 	}

				string recortarCarp(string a){
							int i=0,len=a.length();
							char vacio=' ';
							string aux;
							while(2 >= i){
								if((a[i] == vacio) or (i == len)){
									return aux;
								}else{
									if (((a[i] != 'D') and (a[i] != 'A')) and ((a[i] != '=') and (a[i] != ' '))){
										len=len-1;
										while(len >= i){
											aux +=a[i];
											i++;
										}
									}else{
										if (a[i] == 'D'){
											D=true;
										}else if (a[i] == 'A'){
											A=true;
										}
									}
								}
								i++;
							}
							return aux;
				}



		queue<string> token(queue<string> cola, string comando){
			int i=0,len=comando.length();
						char vacio=' ', barra='/';
						string aux;
						while(len >= i){
							if((comando[i] == vacio) or (i == len) or(comando[i] == barra)){
								cola.push(aux);
								aux= "";
							}else{
								aux+=comando[i];
							}
							i++;
						}
						return cola;
		}


		void recorrerCola(queue<string> lineas){
					if(!lineas.empty()){
								cout <<lineas.front() << endl;
								lineas.pop();
								recorrerCola(lineas);
					}
				}

		bool persuechon( queue<string> in, string nodo){
			string nodo2=in.front();
			in.pop();
			if(nodo2 =="tree"){
					if(SO==Li){
						l.mostrar(SO,true);
					}else{
						l.mostrarA(Li->A);
					}
			return "true";}

			if(nodo2 =="mkdir"){
						if(!in.empty()){
							nodo=in.front();
							in.pop();
						}else	return false;
								if(!l.buscar(Li,nodo) and (SO == Li)){
										if(in.empty() and nodo != " " and nodo != ""){
											l.insertar(Li,nodo);
											return true;
										}else return false;
								}else{
									if(!l.buscar(Li,nodo))
										return false;
									else
										return false;
								}
		}
			string entrada = "";
	if((nodo2 =="cd") or (nodo2=="del") or (nodo2=="touch")) {
					nodo=in.front();
					in.pop();
		if(l.buscar(Li,nodo) and (SO==Li)){
			if(nodo2 == "cd"){
						if(in.empty()){
							Li=SO;
							l.ubicar(Li,nodo);
							unid=Li->nombre;
							return true;
						}
			}

			if(nodo2 =="del"){
						if(in.empty()){
							l.eliminar(Li,nodo);	return true;
						}else{
											if(l.buscarA(Li,nodo,in.front())){
												if (l.eliminarA(Li,Li->A,nodo,in.front()))
													return true;
												else
													return false;
											}else
												return false;
						}
			}

			if(nodo2 =="touch"){
						if(!in.empty()){
							l.archivar(Li,nodo,in.front());
							return true;
						}else{
							return false;
						}
			}

		}else{

			if(nodo2 == "cd"){
				if(nodo == ".."){
					if(in.empty()){
						l.primero(Li);
						unid=Li->nombre;
						return true;
					}else{
						if(l.buscar(SO,in.front())){
							Li=SO;
							l.ubicar(Li,in.front());
							unid=Li->nombre;
							return true;
						}else return false;
					}
				}
			}else if(nodo2 =="touch"){
					l.archivar(Li,Li->nombre,nodo);
					return true;
			}else if(nodo2 =="del"){

		    	if(l.buscarAr(Li->A,nodo)){
		    		if (l.eliminarAr(Li->A,nodo))	return true;
		    		else return false;
		    	}else return false;


		}
		}
	}
	return false;
		}

};
int main(){
		menu a= menu();
		return 0;
}

