#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std ;

const int MAX_SIZE= 200;

void Input(int arr[][MAX_SIZE] , int n , int m){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> arr[i][j];
        }
    }
}

void Print(int arr[][MAX_SIZE] , int n , int m){
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
            if( j == 0 ){
                cout << "||";
            }
            cout << setw(3) << arr[i][j];
            if( j == m - 1){
               cout << "||";
            }
    }
    cout << endl;
  }
  cout << endl;
}

int Collect(int arr[][MAX_SIZE] , int brr[][MAX_SIZE] , int n , int m ){
  int crr[MAX_SIZE][MAX_SIZE] = {0};
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
        crr[i][j] = arr[i][j] + brr[i][j];
    }
  }
  cout << " Collection of the matrix is : "  << endl;
  Print(crr , n , m);

}

int VariableMultiplication(int arr[][MAX_SIZE] , int n  , int m , int y){
   for(int i = 0 ; i < n ; i++){
     for( int j = 0 ; j < m ; j++){
        arr[i][j] *= y;
     }
   }
   cout << " The multiplication with Y is  : " << endl ;
   Print(arr , n , m);
}

int MatrixMultiplication(int arr[][MAX_SIZE] , int brr[][MAX_SIZE] , int n , int m , int  k , int t  , int crr[][MAX_SIZE]){
    // n , m = matrix1;
    // k , t = matrix2;
    int j = 0;
    for(int i = 0 ; i < n ; i++){
       for(int s = 0 ; s < t ; s++){
            crr[i][s] = 0;
          for(int j = 0 ; j < m ; j++){
            crr[i][s] += arr[i][j] * brr[j][s];
          }
       }
     }
     cout << " Matrix multiplication is : "  << endl;
     Print(crr , n , t );
}

void AdQuantity(int arr[][MAX_SIZE] , int used[][MAX_SIZE] , int p , int q , int n ){
    int indexi = 0 , indexj = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if( i != p && j != q){
                used[indexi][indexj++] = arr[i][j];
                if(indexj == n - 1){
                    indexj = 0 ;
                    indexi++;
                }
            }
        }
    }
}

int determinant ( int arr[][MAX_SIZE] , int n ){
   int Det = 0 ;
    if(n == 1){
        return arr[0][0];
    }
   int result[MAX_SIZE][MAX_SIZE];
   int sign = 1;
   for(int  k = 0 ; k < n ; k++){
     AdQuantity(arr , result , 0 , k , n);
     Det += sign * arr[0][k] * determinant(result , n -1);
     sign = -sign;
   }
   return Det;
}

int Divide(int arr[][MAX_SIZE] , int n , int m , int k){
   for(int i = 0 ; i < n ; i++){
     for(int j = 0 ; j < m ; j++){
        arr[i][j] = arr[i][j] / k;
     }
   }
   cout << " The dividing is : " << endl;
   Print(arr , n , m );
}

void print(float arr[][MAX_SIZE] , int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << setw(15) << arr[i][j];
        }
        cout << endl;
    }
}

void Transporation(float arr[][MAX_SIZE] , int n){
cout << " Transponsed matrix is : " << endl;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
         cout << arr[j][i] << " ";
    }
    cout << endl;
  }
}

void IntegerTrans(int arr[][MAX_SIZE] , int n , int m){
    cout << " Transporence: "<< endl;
    if(n < m){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                cout << arr[i][j] << " ";
            }
                cout << endl;
        }
    }
    else if( n > m){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if( n == m){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cout << arr[j][i] << " ";
            }
          cout << endl;
        }
    }

}

void Adjustable(int arr[][MAX_SIZE] , int adj[][MAX_SIZE] , int n){
   if( n == 1){
    adj[0][0] == 1 ;
    return ;
   }
   int sign = 1 ;
   int used[MAX_SIZE][MAX_SIZE];
   for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            AdQuantity(arr , used , i , j , n);
            if( (i + j) % 2 == 0 ){
                sign = 1;
            }else{
                sign = -1;
            }
            adj[i][j] = sign * determinant( used , n -1 );
        }
   }
}

bool ReverseMatrix(int arr[][MAX_SIZE]  , float rev[][MAX_SIZE] , int n ){
    cout << " the reverse matrix is : " << endl;
    int DetA = determinant( arr , n );
    if( DetA == 0){
        return false;
    }
    int adj[MAX_SIZE][MAX_SIZE];
    Adjustable( arr , adj , n);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            rev[i][j] = adj[i][j] / float( DetA );
        }
    }
}

int main(){
    int n = 0  , m = 0 ;
    int arr[MAX_SIZE][MAX_SIZE] ;
    int brr[MAX_SIZE][MAX_SIZE] = {0} , k = 0  , t = 0;
    int result[MAX_SIZE][MAX_SIZE] = {0};
   cout << " The sizes of the rows : " << endl;
    cin >> n ;
    cout << " The sizes of cows : " << endl;
    cin >> m ;
    Input(arr , n , m);
    cin >> k >> t ;
    Input(brr , k ,t);
    if(n == k && m == t){
       Collect(arr , brr , n , m);
    }
   VariableMultiplication(arr , n , m ,  2);
    Divide(arr , n , m , 2);
    if(m != k) return -1;
    MatrixMultiplication(arr , brr , n , m , k , t , result);
    if( n == m ){
        cout << determinant(arr , n );
    }
    float used[MAX_SIZE][MAX_SIZE] = {0.0};
    ReverseMatrix(arr , used , n );
    print(used , n);
    cout << endl;
    Transporation(used , n);
    cout << endl;
    IntegerTrans(arr , n , m );
return 0 ;
}
/*
3 3
1 3 5
12 0 8
4 11 31

3 1
1 2 3

1 3
1
2
3

4 4
1 0 2 -1
3 0 0 5
2 1 4 -3
1 0 5 0


3 3
-1 1 0
1 -1 -3
1 0 1

*/
