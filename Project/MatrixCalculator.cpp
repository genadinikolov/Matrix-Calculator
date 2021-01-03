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
    if(i == n - 1 ){cout << " " ;}
    else {
      cout << endl;
    }
  }
}

int SumMatrix(double arr[][MAX_SIZE] , double brr[][MAX_SIZE] , int n , int m ){
  double crr[MAX_SIZE][MAX_SIZE] = {0.0};
  cout << " Sum of the matrix is : "  << endl;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
        if ( j == 0){
                cout << "||";
        }
        cout <<setw(3) << arr[i][j];
        if( j == m -1 && i != n / 2){cout << "||  ";
        }
        if( i == n / 2 && j == m -1){
            cout << "|| + ||";
        }
        if(j == m - 1){
            for(int k = 0 ; k < m ; k++){
                if( k == 0 && i != n / 2){
                        cout << " ||";
                }
                cout <<setw(3) << brr[i][k];
                if( k == m - 1  && i != n / 2){
                        cout << "||  ";
                }
                if( i == n / 2 && k == m - 1){
                        cout << "|| =";
                }
                if( k == m - 1 ){
                    for(int t = 0 ; t < m ; t++){
                        if( t == 0){
                                cout << " ||";
                        }
                        cout << setw(3) << arr[i][t] + brr[i][t];
                        if(t == m - 1){
                                cout << "||";
                        }
                    }
                }
            }
        }
    }
    cout << endl;
  }
}

int Difference(double arr[][MAX_SIZE] , double brr[][MAX_SIZE] , int n , int m ){
    cout << " The difference of matrix is : "<<endl;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(j == 0){
                    cout << "||";
            }
            cout << setw(3) << arr[i][j];
            if( j == m - 1 && i != n / 2){
                    cout << "||  ";
            }
            if( j == m - 1 && i == n / 2){
                    cout << "|| - ||";
            }
            if(j == m - 1){
                for(int k = 0 ; k < m ; k++){
                    if( k == 0 && i != n / 2){
                            cout << " ||";
                    }
                    cout << setw(3) << brr[i][k];
                    if( k == m - 1 && i != n / 2 ){
                            cout << "||  ";
                    }
                    if(i == n / 2  && k == m  - 1){
                            cout <<"|| = ||";
                    }
                    if( k == m - 1){
                        for(int t = 0 ; t < m ; t++){
                            if(t == 0 && i != n / 2){
                                    cout << " ||";
                            }
                            cout << setw(3) << arr[i][t] - brr[i][t];
                            if(t == m - 1){
                                    cout <<"||";
                            }
                        }
                    }
                }
            }
        }
        cout << endl;
    }
}

int VariableMultiplication(double arr[][MAX_SIZE] , int n  , int m , double scalar){
   cout << " The multiplication with " << scalar << " is : "<< endl;
   for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if( j == 0 ){
                cout << "||";
            }
            cout <<setw(3) << arr[i][j];
            if( j == m - 1 && i == 0 ){
                cout <<"||" << " * " << "||" << scalar << "|| " << " = ";
            }
            if( j == m - 1 ){
                cout << "||";
                for(int k = 0 ; k < m ; k++){
                    if( k == 0 && i > 0){
                        cout <<"            ||";
                    }
                    cout << setw(3) << arr[i][k] * scalar;
                    if( k == m - 1){
                        cout << "||";
                    }
                }
            }
        }
        cout << endl;
   }
}

int MatrixMultiplication(double arr[][MAX_SIZE] , double brr[][MAX_SIZE] , int n , int m , int  k , int t  , double crr[][MAX_SIZE]){
    // n , m = arr;
    // k , t = brr;
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

int determinant( double arr[][MAX_SIZE] , int n ){
    double Det = 0.0;
    if(n == 1){
        return arr[0][0];
    }
   double result[MAX_SIZE][MAX_SIZE];
   int sign = 1;
   for(int k = 0 ; k < n ; k++){
     AdQuantity(arr , result , 0 , k , n);
     Det += sign * arr[0][k] * determinant(result , n - 1);
     sign = -sign;
   }
    return Det;
}

int Divide(double arr[][MAX_SIZE] , int n , int m , double scalar){
   cout << " The matrix after dividing is : " << endl;
   for(int i = 0 ; i < n ; i++){
     for(int j = 0 ; j < m ; j++){
        if( j == 0){
            cout << "||";
        }
        cout << setw(4) << arr[i][j];
        if( j == m - 1 && i == 0){
            cout << "|| / ||"<< scalar << "|| = ";
        }
        if( j == m - 1 ){
            cout << "||";
            for(int k = 0 ; k < m ; k++){
                if( k == 0 && i > 0){
                    cout << "           ||";
                }
                cout << setw(4) << arr[i][k] / scalar ;
                if( k == m - 1 ){
                    cout << "||";
                }
            }
        }
     }
     cout << endl;
   }
}

void TranspositionReverse(double arr[][MAX_SIZE] , int n){
cout << " Reverse matrix is : " << endl;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
         cout << arr[j][i] << " ";
    }
    cout << endl;
  }
}

void TranspositionMatrix(double arr[][MAX_SIZE] , int n , int m){
    cout << endl <<  " Transposition matrix is  : "<< endl;
    if(n < m ){
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(j == 0){
                    cout << "||";
                }
                cout << setw(3) << arr[j][i];
                if( j == n - 1){
                    cout << "||";
                }
            }
                cout << endl;
        }
    }

    else if( n == m){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if( j == 0){
                    cout << "||";
                }
                cout <<setw(3) << arr[j][i];
                if( j == n - 1){
                    cout << "||";
                }
            }
          cout << endl;
        }
    }
    else if( n > m){
        for(int j = 0 ; j < m ; j++){
            for(int i = 0 ; i < n ; i++){
                if( i == 0){
                    cout << "||";
                }
                cout << setw(3) << arr[i][j];
                if( i == n - 1){
                    cout << "||";
                }
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
            cout << rev[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n = 0 , m = 0 ;
    char input[MAX_SIZE] = "0";
    fstream file("mainfunc.txt");
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
             cout << " Input the rows of the matrix " << endl;
             cin >> n ;
             cout << " Input the cows of the matrix " << endl;
             cin >> m;
             cout << " Input the matrix : " << endl;
             Input(arr , n , m);
             cout << " Input the number for multiplication : " << endl;
             cin >> scalar;
             VariableMultiplication(arr , n , m , scalar);
       }
       if( My_strncmp(func , "2.MultiMatrix") == 1){
            cout << " Input the rows of first matrix : " << endl;
            cin >> n ;
            cout << " Input the cows of the first matrix " << endl;
            cin >> m;
            cout << " Input first matrix " << endl;
            Input(arr , n , m);
            cout << " Input rows of second matrix " << endl;
            cin >> n1 ;
            cout << " Input cows of second matrix " << endl;
            cin >> m1 ;
            if( m == n1){
                Input(brr , n1 , m1);
                MatrixMultiplication(arr , brr , n , m , n1 , m1 , result);
            }
       }
        if( My_strncmp(func , "3.Determinant") == 1){
            cout << " Input the rows = cows of the matrix : " << endl;
            cin >> n;
            cout << " Input the matrix : " << endl;
            Input(arr , n , n );
            cout <<"The determinant of the matrix is : " << endl << determinant(arr , n );
       }
       if( My_strncmp(func , "4.Dividing") == 1){
            cout << " Input the rows of the matrix : " << endl;
            cin >> n ;
            cout << " Input the cows of the matrix  : " << endl;
            cin >> m;
            cout << " Input the number for dividing : " << endl;
            cin >> scalar;
            cout << " Input the matrix : " << endl;
            Input( arr , n , m);
            Divide(arr , n , m , scalar);
       }
      if( My_strncmp( func , "5.ReverseMatrix") == 1){
            cout << " Input the rows = cows of the matrix : " << endl;
            cin >> n ;
            cout << " Input the matrix : " << endl;
            Input(arr , n , n );
            ReverseMatrix(arr , used , n);
            TranspositionReverse(used , n);
      }
      if(My_strncmp(func , "6.Transe") == 1){
            cout << " Input the rows of the matrix : " << endl;
            cin >> n ;
            cout << " Input the cows of the matrix : " << endl;
            cin >> m;
            cout << " Input the matrix : " << endl;
            Input(arr , n , m);
            cout << " Main matrix is : " << endl;
            Print(arr , n , m );
            TranspositionMatrix(arr , n , m);
      }
      if(My_strncmp(func , "7.SumMatrix") == 1){
        cout << " Input the rows of the matrixes : " << endl;
        cin >> n ;
        cout << " Input the cows of the matrixes : " << endl;
        cin >> m;
        cout << " Input first matrix : " << endl;
        Input(arr , n , m );
        cout << " Input second matrix : " << endl;
        Input(brr , n , m );
        SumMatrix(arr , brr , n , m );
      }
      if(My_strncmp(func , "8.DifferenceMatrix") == 1){
        cout << " Input the rows of the matrixes : " << endl;
        cin >> n ;
        cout << " Input the cows of the matrixes : " << endl;
        cin >> m;
        cout << " Input first matrix : " << endl;
        Input(arr , n , m);
        cout << " Input second matrix : " << endl;
        Input(brr , n , m);
        Difference(arr , brr , n , m );
      }
        }while(func != "0");
    file.close();
    }
    else{
        cout << " -1";
    }
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

3 3
21 13 -5 2 4 8 1 0 6

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

3
-1 1 0 1 -1 -3 1 0 1

*/
