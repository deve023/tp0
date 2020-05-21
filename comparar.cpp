#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

int main(){
	fstream ifs, ifc;
	string line;
	int n,m;
	string origen= "origen.pgm";
	string destino="destino.pgm";

	ifs.open(origen.c_str(), ios::in);
	getline(ifs,line);
	cout<<line<<endl;

	ifc.open(destino.c_str(), ios::in);
	getline(ifc,line);
	cout<<line<<endl;


	while (ifs.good()&& ifc.good()){
		ifs>>n;
		ifc>>m;
		if( n!=m){	
			cerr<<"error"<<endl;
			return 1;
		}
	}


	cout<<"IGUALES"<<endl;
	
}