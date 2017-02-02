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

			void setnombre(carpeta * & L, string nombre, string rename){
				if(!vacio(L)){
					if(L->nombre == nombre){
						L->nombre=rename;
					}else
						setnombre(L->sig,nombre,rename);
				}

			}

			void setnombreA(archivo * & L, string nombre, string rename){
							if(!vacioA(L)){
								if(L->nombre == nombre){
									L->nombre=rename;
								}else
									setnombreA(L->sig,nombre,rename);
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
                    	cout <<"|--" << L->nombre <<endl;
                    }
                	 mostrarA(L->A);
                     mostrar(L->sig,tortura);
                }
             }
             void ordenar(carpeta * & L, archivo * & aux){
            	 if(!vacio(L)){
            		 if(!vacio(L->sig)){
            		 cout << L->nombre << L->sig->nombre << endl;
						 if (L->nombre >= L->sig->nombre){
								 string a;
								 a = L->nombre;
								 L->nombre = L->sig->nombre;
								 L->sig->nombre = a;
								aux = L->sig->A;
								L->sig->A = L->A;
								L->A = aux;
						 }
            		 }
            		 return ordenar(L->sig,aux);
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
             bool edit(carpeta * & L,string carp,string arc, string cont){
            	 	 if(!vacio(L)){
            	 		 if((L->nombre != carp)){
            	 			 return edit(L->sig,carp,arc,cont);
            	 		 }else{
            	 			 return editA(L->A,arc,cont);
            	 		 }

            	 	 }
             }

             bool editA(archivo *& J,string arc, string cont){
                         	 	 if(!vacioA(J)){
                         	 		 if(J->nombre != arc){
                         	 			 return editA(J->sig,arc,cont);
                         	 		 }else{
                         	 			 J->contenido = cont;
                         	 			 return true;
                         	 		 }
                         	 	 }
                          }

             void ver(carpeta * & L,string carp,string arc){
            	 if(!vacio(L)){
            	             	 		 if(L->nombre != carp){
            	             	 			 return ver(L->sig,carp,arc);
            	             	 		 }else{
            	             	 			 return verA(L->A,arc);
            	             	 	 }
                          }
             }
             void verA(archivo * & J,string arc){
                         	 if(!vacioA(J)){
                         	             	 		 if(J->nombre != arc){
                         	             	 			 return verA(J->sig,arc);
                         	             	 		 }else{
                         	             	 			 cout << J->nombre << ": " << J->contenido << endl;
                         	             	 		 }
                                       }
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
                                              cout <<" ---" << L->nombre << endl;
                                              mostrarA(L->sig);
                                         }
                                      }
                         string escritura(carpeta *L, string aux){
                        	 if(L != NULL){
                        		 aux = "\nD="+L->nombre + escrituraA(L->A);
                        		 return  aux + escritura(L->sig,"");
                        	 }
                        	 return "";
                         }
                         string escrituraA(archivo *Ar){
                               if(Ar != NULL){
                            	   return "\nA="+Ar->nombre+" *"+Ar->contenido+"*"+escrituraA(Ar->sig);
                               }
                               return "";
                         }

};
class menu{
	public :
	carpeta * Li, *SO;
	Disco l;
	queue<string> cola,colaAux,ayuda;
	string entrada;
	string unid;
	bool bandera,continuo,A,D;

	bool ban;

		menu(){
			unid="*";
			Li=NULL;
			ban=false;
			A=false;
			D=false;
			bandera=false;
			continuo=true;
			string zilo = "";
			ayuda = leerFile();

			if (!leerA() and unid=="*"){
				l.insertar(Li,"SO");
			}
			SO=Li;
			unid = SO->nombre;
			while(continuo){
				cout << unid<< " >" ;
				getline(cin,entrada);
					if(entrada != "salir"){
						cola = token(colaAux,entrada);
						zilo = mkdir(cola," ");
						if(zilo == "true"){
							escribirA();
						}else{
							if (zilo == "false"){
								if(entrada != "")
									cout <<"'" << entrada << "' " << "No es reconocido como un comando interno o externo."<< endl;
							}else{
						    	cout << zilo << endl;
						    }
						}
					}else
						continuo=false;
			}
		}

		bool leerA(){
			ifstream arcEntrada;
			arcEntrada.open("DDV.txt");
			queue<string> lineas;
			string linea;
			if(arcEntrada.fail()){
				cout << " El archivo no se lee correctamente." << endl;
			}
			while(getline(arcEntrada,linea)){
				lineas.push(linea);
			}
			arcEntrada.close();
			return llenarLista(lineas);
		}

		bool llenarLista(queue<string> line){
		//			condiciones para llenar la lista.
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
								l.edit(Li,aux,aux2,cont.front());
								A=false;
							}else if(D){
								D=false;
								l.insertar(Li,carp);
								unid ="";
								//l.ordenar(Li,Li->A);
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

		void escribirA(){
			ofstream arcSalida;
			arcSalida.open("DDV.txt");
							if(arcSalida.fail()){
									cout << " El archivo no se creo correctamente." << endl;
							}
							string salida;
							salida = l.escritura(SO,"");
							arcSalida << salida << endl;
							arcSalida.close();
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

		queue<string> leerFile(){
					ifstream arcEntrada ;
					string linea;
					queue<string> lineas;

					arcEntrada.open("comandos.txt");
					if(arcEntrada.fail())
						cout << "El archivo no se abrio correctamente."  << endl;

					while(getline(arcEntrada,linea)){
						lineas.push(linea);
					}
					arcEntrada.close();
					return lineas;
				}

		void recorrerCola(queue<string> lineas){
					if(!lineas.empty()){
								cout <<lineas.front() << endl;
								lineas.pop();
								recorrerCola(lineas);
					}
				}

		string mkdir( queue<string> in, string nodo){
			string nodo2=in.front();
			in.pop();
			if(nodo2 =="mostrar"){
					if(SO==Li){
						l.mostrar(SO,true);
					}else{
						l.mostrarA(Li->A);
					}
			return "true";}
			if(nodo2 =="ayuda"){
						recorrerCola(ayuda);
			return "true";}
			if(nodo2 =="mkdir"){
						if(!in.empty()){
							nodo=in.front();
							in.pop();
						}else	return "faltan argumentos en la instruccion.";
								if(!l.buscar(Li,nodo) and (SO == Li)){
										if(in.empty() and nodo != " " and nodo != ""){
											l.insertar(Li,nodo);
											return "true";
										}else return "No se inserto.";
								}else{
									if(l.buscar(Li,nodo))
										return "El elemento se encuentra repetido.";
									else
										return "No se puede insertar carpeta en este nivel. Pruebe con la instruccion 'cd raiz'";
								}
		}
			string entrada = "";
	if(((nodo2 =="cd") or (nodo2=="rm") or (nodo2=="del") or (nodo2=="mkar") or (nodo2 == "edit") or (nodo2=="ver"))) {
					nodo=in.front();
					in.pop();
		if(l.buscar(Li,nodo) and (SO==Li)){
			if(nodo2 == "cd"){
						if(in.empty()){
							Li=SO;
							l.ubicar(Li,nodo);
							unid=Li->nombre;
							return "true";
						}
			}
			if(nodo2 == "edit"){
				if(!in.empty()){
					if(l.buscarA(SO,nodo,in.front())){
						if(!in.empty()){
							do{
																					cout <<"Desea editar el archivo '"<<in.front()<<"'? Y/N"<< endl;
																					getline(cin,entrada);
																					if(entrada=="Y" or entrada=="y"){
																						break;
																					}else if(entrada=="N" or entrada=="n"){
																						return "Instruccion abortada.";
																					}
							}while(true);
							string e;
							cout << "_"<< endl;
							getline(cin,e);
							if(l.edit(Li,nodo,in.front(),e))
								return "true";
							else
								return "No se pudo editar el archivo '" + in.front() + "' en la carpeta '" + nodo + "'";

						}
					}else return "No existe el archivo '"+in.front()+"' en la carpeta '"+nodo+"'";
				}else return "Fantal argumento en la instruccion.";
			}
			if(nodo2 == "ver"){
							if(!in.empty()){
								if(l.buscarA(SO,nodo,in.front())){
									l.ver(Li,nodo,in.front());
									return "true";
								}else return "No existe el archivo '"+in.front()+"' en la carpeta '"+nodo+"'";
							}else
								return "Faltan argumentos en la instruccion.";
						}
			if(nodo2 =="rm"){
								if(!in.empty()){
												string ar = in.front();
												in.pop();

												if(!in.empty()){
													if(!l.buscarAr(Li->A,in.front())){
														string desti = in.front();
														in.pop();
														do{
															cout <<"Desea renombrar el archivo '"<<ar<<"'? Y/N"<< endl;
															getline(cin,entrada);
															if(entrada=="Y" or entrada=="y"){
																break;
															}else if(entrada=="N" or entrada=="n"){
																return "Instruccion abortada.";
															}
														}while(true);
														string aux = Li->nombre;
														*Li = l.ubicar(Li,nodo);
														l.setnombreA(Li->A,ar,in.front());
														Li = SO;
														return "true";
													}else{
														return "Ya existe un archivo con el nombre '"+in.front()+"'";
													}
												}else{
													if(!in.empty()){
														if (nodo != in.front()){
															return "no coincide la carpeta '" + in.front() + "'";
														}
													}else if(l.buscar(Li,nodo)){
															do{
																cout <<"Desea renombrar el carpeta '"<<ar<<"'? Y/N"<< endl;
																getline(cin,entrada);
																if(entrada=="Y" or entrada=="y"){
																	break;
																}else if(entrada=="N" or entrada=="n"){
																	return "Instruccion abortada.";
																}
															}while(true);
															l.setnombre(Li,nodo,ar);
															return "true";
													}else if(nodo == unid){
															unid=in.front();
													}else
														if (SO == Li){
																													cout << "La instruccion no se puede ejecutar en este nivel." << endl;
														}else
														return "true";

												}

								}else	return "Faltan argumentos en la instruccion.";
			}
			if(nodo2 =="del"){
						if(in.empty() and SO->nombre != nodo){
							do{
																					cout <<"Desea eliminar '"<<nodo<<"'? Y/N"<< endl;
																					getline(cin,entrada);
																					if(entrada=="Y" or entrada=="y"){
																						break;
																					}else if(entrada=="N" or entrada=="n"){
																						return "Instruccion abortada.";
																					}
							}while(true);
							l.eliminar(Li,nodo);	return "true";
						}else{
								if(SO->nombre == nodo){
									return "No se puede eliminar la carpeta raiz.";
								}
											if(l.buscarA(Li,nodo,in.front())){
												do{
																										cout <<"Desea eliminar '"<<in.front()<<"'? Y/N"<< endl;
																										getline(cin,entrada);
																										if(entrada=="Y" or entrada=="y"){
																											break;
																										}else if(entrada=="N" or entrada=="n"){
																											return "Instruccion abortada.";
																										}
												}while(true);
												if (l.eliminarA(Li,Li->A,nodo,in.front()))
													return "true";
												else
													return "No se pudo eliminar el archivo '" + in.front() + "' en la carpeta '" + nodo + "'";
											}else
												return "No se encontro el archivo '"+ in.front() + "' en la carpeta '" + nodo + "'";
						}
			}

			if(nodo2 =="mkar"){
						if(!in.empty()){
							l.archivar(Li,nodo,in.front());
							return "true";
						}else{
							return "Faltan argumentos en la instruccion.";
						}
			}

		}else{

			if(nodo2 == "cd"){
				if(nodo == ".."){
					if(in.empty()){
						l.primero(Li);
						unid=Li->nombre;
						return "true";
					}else{
						if(l.buscar(SO,in.front())){
							Li=SO;
							l.ubicar(Li,in.front());
							unid=Li->nombre;
							return "true";
						}else return "No se encontro la carpeta '" + in.front();
					}
				}
			}else if(nodo2 =="mkar"){
					l.archivar(Li,Li->nombre,nodo);
					return "true";
			}else if(nodo2 =="del"){

		    	if(l.buscarAr(Li->A,nodo) ){
		    		do{
		    																cout <<"Desea eliminar '"<<nodo<<"'? Y/N"<< endl;
		    																getline(cin,entrada);
		    																if(entrada=="Y" or entrada=="y"){
		    																	break;
		    																}else if(entrada=="N" or entrada=="n"){
		    																	return "Instruccion abortada.";
		    																}
		    															}while(true);
		    		if (l.eliminarAr(Li->A,nodo))	return "true";
		    		else return "No se pudo eliminar.";
		    	}else
		    		return "No se encontro el archivo '"+ nodo +"' en la carpeta '" + Li->nombre +"'";


		    }else if(nodo2 =="edit"){
		    	if(in.empty()){
		    		if(l.buscarAr(Li->A,nodo)){
		    			do{
		    																	cout <<"Desea editar el archivo '"<<nodo<<"'? Y/N"<< endl;
		    																	getline(cin,entrada);
		    																	if(entrada=="Y" or entrada=="y"){
		    																		break;
		    																	}else if(entrada=="N" or entrada=="n"){
		    																		return "Instruccion abortada.";
		    																	}
		    			}while(true);
		    								string e;
		    								cout << "_"<< endl;
		    								getline(cin,e);
		    								if (l.editA(Li->A,nodo,e)) return "true";
		    								else return "No se puedo editar el archivo '"+ nodo +"' en la carpeta '"+Li->nombre +"'";
		    		}
		    	}
		    }else if(nodo2 == "ver"){
		    	if(in.empty()){
		    		if(l.buscarAr(Li->A,nodo)){
		    			l.verA(Li->A,nodo);
		    			return "true";
		    		}
		    	}
		    }else if(nodo2 == "rm"){
		    	if(!in.empty() and l.buscarAr(Li->A,nodo)){
		    		do{
		    																cout <<"Desea renombrar el archivito '"<<nodo<<"'? Y/N"<< endl;
		    																getline(cin,entrada);
		    																if(entrada=="Y" or entrada=="y"){
		    																	break;
		    																}else if(entrada=="N" or entrada=="n"){
		    																	return "Instruccion abortada.";
		    																}
		    		}while(true);
		    		l.setnombreA(Li->A,nodo,in.front());
		    		return "true";
		    	}else if (!l.buscarAr(Li->A,nodo)){
		    		return "No se encontro en archivo '" + nodo + "' en la carpeta '" + Li->nombre+"'";
		    	} return "Faltan argumentos a la instruccion.";
		    }

		}
	}
	return "false";
		}

};
int main(){
		menu a= menu();
		return 0;
}

