#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std ;

const int MAX_SIZE= 200;


int My_strncmp(char str1[] , char str2[] ){
    int i = 0 ;
    bool flag = false;
    while( str1[i] != '\0' || str2[i] !='\0'){
        flag = false;
        if(str1[i] == str2[i]){
            flag = true;
        }
        if(flag == true){
            i++;
        }else {
        return  -1;
        }
    }
    if(flag == true ){
        return 1;
    }

}

void Input(double arr[][MAX_SIZE] , int n , int m){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> arr[i][j];
        }
    }
}

void Print(double arr[][MAX_SIZE] , int n , int m){
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
}

int SumMatrix(double arr[][MAX_SIZE] , double brr[][MAX_SIZE] , int n , int m ){
  double crr[MAX_SIZE][MAX_SIZE] = {0.0};
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
        crr[i][j] = arr[i][j] + brr[i][j];
    }
  }
  cout << " Sum of the matrix is : "  << endl;
  Print(crr , n , m);

}

int Difference(double arr[][MAX_SIZE] , double brr[][MAX_SIZE] , int n , int m ){
    double crr[MAX_SIZE][MAX_SIZE] = {0.0};
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            crr[i][j] = arr[i][j] - brr[i][j];
        }
    }
    cout << " The difference of matrix is : "<<endl;
    Print(crr , n , m);
}

int VariableMultiplication(double arr[][MAX_SIZE] , int n  , int m , double  y){
   for(int i = 0 ; i < n ; i++){
     for( int j = 0 ; j < m ; j++){
        arr[i][j] *= y;
     }
   }
   cout << " The multiplication with " << y << " is  : " << endl ;
   Print (arr , n , m);
}

int MatrixMultiplication(double arr[][MAX_SIZE] , double brr[][MAX_SIZE] , int n , int m , int  k , int t  , double crr[][MAX_SIZE]){
    // n , m = matrix1;
    // k , t = matrix2;
    double j = 0.0;
    for(int i = 0 ; i < n ; i++){
       for(int s = 0 ; s < t ; s++){
            crr[i][s] = 0.0;
          for(int j = 0 ; j < m ; j++){
            crr[i][s] += arr[i][j] * brr[j][s];
          }
       }
     }
     cout << " Matrix multiplication is : "  << endl;
     Print(crr , n , t );
}

void AdQuantity(double arr[][MAX_SIZE] , double used[][MAX_SIZE] , int p , int q , int n ){
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

double determinant ( double arr[][MAX_SIZE] , int n ){
   double Det = 0.0;
    if(n == 1){
        return arr[0][0];
    }
   double result[MAX_SIZE][MAX_SIZE];
   int sign = 1;
   for(int  k = 0 ; k < n ; k++){
     AdQuantity(arr , result , 0 , k , n);
     Det += sign * arr[0][k] * determinant(result , n -1);
     sign = -sign;
   }
   return Det;
}

int Divide(double arr[][MAX_SIZE] , int n , int m , double scalar){
   for(int i = 0 ; i < n ; i++){
     for(int j = 0 ; j < m ; j++){
        arr[i][j] = arr[i][j] / scalar;
     }
   }
   cout << " The dividing is : " << endl;
   Print(arr , n , m );
}

void print(double arr[][MAX_SIZE] , int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << setw(15) << arr[i][j];
        }
        cout << endl;
    }
}

void TranspositionRevrse(double arr[][MAX_SIZE] , int n){
cout << " Reverse matrix is : " << endl;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
         cout << arr[j][i] << " ";
    }
    cout << endl;
  }
}

void TranspositionMatrix(double arr[][MAX_SIZE] , int n , int m){
    cout << " Transposition : "<< endl;
    if(n < m || n > m){
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

void Adjustable(double arr[][MAX_SIZE] , double adj[][MAX_SIZE] , int n){
   if( n == 1){
    adj[0][0] == 1 ;
    return ;
   }
   int sign = 1 ;
   double used[MAX_SIZE][MAX_SIZE];
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

bool ReverseMatrix(double arr[][MAX_SIZE]  , double rev[][MAX_SIZE] , int n ){
    cout << " the reverse matrix is : " << endl;
    double DetA = determinant( arr , n );
    if( DetA == 0){
        return false;
    }
    double adj[MAX_SIZE][MAX_SIZE];
    Adjustable( arr , adj , n);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            rev[i][j] = adj[i][j] / ( DetA );
        }
    }
}

int main(){
    int n = 0  , m = 0 ;
    char input[MAX_SIZE] = "0";
    fstream file("Matrix.txt");
    if(file.is_open()){
        char func[MAX_SIZE] = "0";
        while(file >> input){
         cout << input ;
         cout << endl;
        }
        do {
        double arr[MAX_SIZE][MAX_SIZE] , brr[MAX_SIZE][MAX_SIZE] , result[MAX_SIZE][MAX_SIZE];
        int n , m , n1 , m1 , scalar;
        double used[MAX_SIZE][MAX_SIZE] = {0.0};
       cout << endl <<  " Input the function which you want to see " <<endl;
       cin >> func;
       if(My_strncmp(func , "1.Multiplication") == 1){
         cout << " Input the size of the matrix : " << endl;
         cin >> n >> m;
         cout << " Input the matrix : " << endl;
         Input(arr , n , m);
         cout << " Input the number for multiplication : " << endl;
         cin >> scalar;
         VariableMultiplication(arr , n , m , scalar);
       }
       if( My_strncmp(func , "2.MultiMatrix") == 1){
        cout << " Input the size of first matrix : " << endl;
        cin >> n >> m;
        cout << " Input first matrix " << endl;
        Input(arr , n , m);
        cout << " Input size of second matrix " << endl;
        cin >> n1 >> m1;
        if( m == n1){
            Input(brr , n1 , m1);
            MatrixMultiplication(arr , brr , n , m , n1 , m1 , result);
        }
       }
        if( My_strncmp(func , "3.Determinant") == 1){
          cout << " Input the size of the matrix : " << endl;
          cin >> n >> m;
          cout << " Input the matrix : " << endl;
          Input(arr , n , m );
          if(n == m){
            cout <<"The determinant of the matrix is : " << determinant(arr , n );
          }
       }
       if( My_strncmp(func , "4.Dividing") == 1){
          cout << " Input the size of the matrix : " << endl;
          cin >> n >> m;
          cout << " Input the number for dividing : " << endl;
          cin >> scalar;
          cout << " Input the matrix : " << endl;
          Input( arr , n , m);
          Divide(arr , n , m , scalar);
       }
      if( My_strncmp( func , "5.ReverseMatrix") == 1){
        cout << " Input the size of the matrix : " << endl;
        cin >> n >> m;
        cout << " Input the matrix : " << endl;
        Input(arr , n , m);
        ReverseMatrix(arr , used , n);
        print(used , n);
      }
      if(My_strncmp(func , "6.Transe") == 1){
        cout << " Input the size of the matrix : " << endl;
        cin >> n >> m;
        cout << " Input the matrix : " << endl;
        Input(arr , n , m);
        Print(arr , n , m );
        TranspositionMatrix(arr , n , m);
      }
        }while(func != "0");

    file.close();
    }
    else{cout << " -1";}
   /*
    int brr[MAX_SIZE][MAX_SIZE] = {0} , k = 0  , t = 0;
    int result[MAX_SIZE][MAX_SIZE] = {0};
    cout << " Input the size of the first matrix : " << endl;
    cin >> n >> m ;
    cout << " Input first matrix : "<< endl;
    Input(arr , n , m);
    cout << " the size of the second matrix : " << endl;
    cin >> k >> t ;
    cout << " Input the second matrix : "<<endl;
    Input(brr , k ,t);
    if(n == k && m == t){
       Collect(arr , brr , n , m);
       Difference( arr , brr , n , m );
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
    IntegerTrans(arr , n , m );*/
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
