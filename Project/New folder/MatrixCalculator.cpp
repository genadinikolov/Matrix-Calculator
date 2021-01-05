#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std ;

const int MAX_SIZE= 254;

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

void IntInput( int arr[][MAX_SIZE] , int n) {
    for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> arr[i][j];
       }
    }
}

void IntPrint( int arr[][MAX_SIZE] , int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(j == 0){
                cout << "||";
            }
            cout << setw(10) << arr[i][j];
            if( j == n - 1){
                cout << "||";
            }
        }
        cout << endl;
    }
}

void FloatPrint(float arr[][MAX_SIZE] , int n , int m){
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
            if( j == 0 ){
                cout << "||";
            }
            cout << setw(11) << arr[i][j];
            if( j == m - 1){
               cout << "||";
            }
    }
    cout << endl;
  }
}

void Print(double arr[][MAX_SIZE] , int n , int m){
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
            if( j == 0 ){
                cout << "||";
            }
            cout << setw(10) << arr[i][j];
            if( j == m - 1){
               cout << "||";
            }
    }
    cout << endl;
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
        cout <<setw(5) << arr[i][j];
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
                cout <<setw(5) << brr[i][k];
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
                        cout << setw(5) << arr[i][t] + brr[i][t];
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
            cout << setw(5) << arr[i][j];
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
                    cout << setw(5) << brr[i][k];
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
                            cout << setw(5) << arr[i][t] - brr[i][t];
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
            cout <<setw(6) << arr[i][j];
            if( j == m - 1 && i == 0 ){
                cout <<"||" << " * " << "|| " << scalar << " || " << " = ";
            }
            if( j == m - 1 ){
                cout << "||";
                for(int k = 0 ; k < m ; k++){
                    if( k == 0 && i > 0){
                        cout <<"            ||";
                    }
                    cout << setw(8) << arr[i][k] * scalar;
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
     cout << " A = " << endl ;
     Print(arr , n , m);
     cout << endl << " B = " << endl ;
     Print(brr , k , t);
     cout << " A * B = "  << endl;
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


int determinant( int arr[][MAX_SIZE] , int n ){
    int Det ;
    if(n == 1){
        return arr[0][0];
    }
   int result[MAX_SIZE][MAX_SIZE];
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
        cout << setw(5) << arr[i][j];
        if( j == m - 1 && i == 0){
            cout << "|| / || "<< scalar << " || = ";
        }
        if( j == m - 1 ){
            cout << "||";
            for(int k = 0 ; k < m ; k++){
                if( k == 0 && i > 0){
                    cout << "           ||";
                }
                cout << setw(8) << arr[i][k] / scalar ;
                if( k == m - 1 ){
                    cout << "||";
                }
            }
        }
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
                cout << setw(5) << arr[j][i];
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
                cout <<setw(5) << arr[j][i];
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
                cout << setw(5) << arr[i][j];
                if( i == n - 1){
                    cout << "||";
                }
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
            adj[j][i] = ( sign )* ( determinant( used , n - 1 ) );
        }
   }
}

bool ReverseMatrix(int  arr[][MAX_SIZE]  , float rev[][MAX_SIZE] , int n ){
    int DetA = determinant(arr , n);
    if( DetA == 0){
        cout << " The is no inverse matrix : " << endl;
        return false;
    }
    int adj[MAX_SIZE][MAX_SIZE];
    Adjustable( arr , adj , n);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            rev[i][j] = adj[i][j] / float(DetA);
        }
    }
   return true;
}

int main(){
    char input[MAX_SIZE] = "0" , start[MAX_SIZE] = "0";
    double arr[MAX_SIZE][MAX_SIZE] , brr[MAX_SIZE][MAX_SIZE] , result[MAX_SIZE][MAX_SIZE];
    int quadratmatrix[MAX_SIZE][MAX_SIZE] , n , m , n1 , m1 , scalar;
    float used[MAX_SIZE][MAX_SIZE] = {0.0};
    cout << " Input 'main' or 'add' for open the files : " << endl;
   do{
        cin >> start;
        if(My_strncmp(start , "main") == 1 || My_strncmp(start , "add") == 1){
            break;
        }
   }while(true);
    if(My_strncmp(start , "main") == 1){
             fstream file("main_functions.txt");
        if(file.is_open()){
            char func[MAX_SIZE] = "1";
            while(file.getline(input , 200 , '\n') ) {
                cout << input ;
                cout << endl;
            }
            do {
                cout << endl <<  " Input a number for run the function " <<endl;
                cin >> func;
                if(My_strncmp (func , "0") == 1  || My_strncmp ( func , "-1") == 1){
                    return -1;
                }
               if(My_strncmp(func , "1") == 1){
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
               if( My_strncmp(func , "2") == 1){
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
                        cout << " Input the second matrix : " << endl;
                        Input(brr , n1 , m1);
                        MatrixMultiplication(arr , brr , n , m , n1 , m1 , result);
                    }
               }
                if( My_strncmp(func , "3") == 1){
                    cout << " Input only the rows (rows = cows) of the matrix : " << endl;
                    cin  >> n ;
                    cout << " Input the matrix : " << endl;
                    IntInput(quadratmatrix, n);
                    IntPrint(quadratmatrix , n );
                    cout << endl << "DET A = " << determinant(quadratmatrix , n ) << endl ;
               }
               if( My_strncmp(func , "4") == 1){
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
              if( My_strncmp( func , "5") == 1){
                    cout << " Input only the rows (rows = cows) of the matrix : " << endl;
                    cin >> n ;
                    cout << " Input the matrix : " << endl;
                    IntInput(quadratmatrix , n );
                    if( ReverseMatrix(quadratmatrix , used , n) == true ) {
                        cout << " Reverse matrix of  " << endl  ;
                        IntPrint(quadratmatrix , n);
                        cout << " is : " << endl;
                        FloatPrint(used , n , n);
                    }
              }
              if(My_strncmp(func , "6") == 1){
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

            }while(true);
        file.close();
        }
        else{
            cout << " -1";
        }
    }else if(My_strncmp(start , "add") == 1){
        char ainput[MAX_SIZE] = "0";
        fstream afile("add_functions.txt");
        if(afile.is_open()){
            char afunc[MAX_SIZE] = "1";
            while(afile.getline(ainput, 200 , '\n') ) {
                    cout << ainput ;
                    cout <<endl;
            }
            do{
                 cout << endl << " Input the number for run the functions : " << endl;
                 cin  >> afunc;
                 if( My_strncmp(afunc , "0" ) == 1 || My_strncmp( afunc , "-1") == 1){
                    return -1;
                 }
                 if(My_strncmp(afunc , "1") == 1){
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
              if(My_strncmp(afunc , "2") == 1){
                cout << " Input the rows of the matrix : " << endl;
                cin >> n ;
                cout << " Input the cows of the matrix : " << endl;
                cin >> m;
                cout << " Input first matrix : " << endl;
                Input(arr , n , m);
                cout << " Input second matrix : " << endl;
                Input(brr , n , m);
                Difference(arr , brr , n , m );
              }

            }while(true);
            afile.close();
        }else {
            cout << " -1 " << endl;
        }
    }
return 0 ;
}
