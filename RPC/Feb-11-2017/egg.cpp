#include <bits/stdc++.h>
using namespace std;


int main(void){

  int egg,pisos,piso,auxsafe=1;
  string estado;

  cin>>egg>>pisos;

  int auxbroken=pisos;

  for(int i=0; i<egg; i++){

    cin>>piso>>estado;
    if(estado == "SAFE"){
      if(piso>auxsafe) auxsafe=piso;
    }
    if(estado== "BROKEN"){
      if(piso<auxbroken) auxbroken=piso;
    }

  }

  if(auxsafe+1 != auxbroken){
    int aux=auxbroken - auxsafe - 1;
    auxbroken -= aux;
    auxsafe += aux;
  }
  cout<<auxbroken<<" "<<auxsafe<<endl;
  return 0;
}
