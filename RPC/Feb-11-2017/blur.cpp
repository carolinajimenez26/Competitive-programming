#include <bits/stdc++.h>
using namespace std;

int** blur_f(int** M, int n, int m){
  int** newmatriz;

  newmatriz = (int**)malloc(n*sizeof(int*));//reservamos memoria

	for(int i=0;i<n;i++){
		newmatriz[i] = (int*)malloc(m*sizeof(int*));
	}

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      int suma = 0;
      for(int k = -1; k < 2; k++){
        for(int l = -1; l < 2; l++){
          suma+= M[(k+i+n)%n][(l+j+m)%m];
        }
      }
      newmatriz[i][j] = suma;
    }
  }
  return newmatriz;
}


int diff_f(int** M,int n,int m){
  map<int,int> mapa;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      mapa[M[i][j]]=1;
    }
  }

  return mapa.size();
}

int main(void){
  int filas,columnas,blur;
  cin >> columnas >> filas >> blur;

  int** M;
  M = (int**)malloc(filas*sizeof(int*));//reservamos memoria

	for(int i=0;i<filas;i++){
		M[i] = (int*)malloc(columnas*sizeof(int*));
	}

  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
        cin >> M[i][j];
    }
  }

  for(int i = 0; i < blur; i++){
    M = blur_f(M,filas,columnas);
  }

  int dif = diff_f(M,filas,columnas);

  cout << dif << endl;

  return 0;
}
