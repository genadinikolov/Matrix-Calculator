#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std ;

// Constant for maximum elements in the matrix;
const int MAX_SIZE = 100;

// Function for comparing of two strings.
int My_strncmp(char str1[] , char str2[] ){

// variable for start index.
    int i = 0;

// Declaration of flag.
    bool compare = false;

// Loop for comparing.
    while( str1[i] != '\0' || str2[i] !='\0'){
         compare= false;

//Checking each index.
        if(str1[i] == str2[i]){

// converting flag to true if the indexes are equal.
            compare = true;
        }
// Increasing index if flag is true.
        if(compare == true){
            i++;
        }else {
        return  -1;
        }
    }
    if(compare == true ){
        return 1;
    }

}

// Function for input an array from double date type.
void MatrixInput(double matrix[][MAX_SIZE] , int rows , int cows){

// Loop for inputing an array.
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cows ; j++){

// Input the matrix.
            cin >> matrix[i][j];
        }
    }
}

// Function for printing from double  date type.
void MatrixPrint(double matrix[][MAX_SIZE] , int rows , int cows){

// Loop for printing the array.
  for(int i = 0 ; i < rows ; i++){
    for(int j = 0 ; j < cows ; j++){

// Designing the table.
            if( j == 0 ){

// Print '||' before first column.
                cout << "||";
            }

// Print the matrix.
            cout << setw(11) << matrix[i][j];

// Print '||' after the last column.
            if( j == cows - 1){
               cout << "||";
            }
    }

// Making a new line for printing as a matrix.
    cout << endl;
  }
}

// Function for input an array from integer date type.
void IntegerMatrixInput( int matrix[][MAX_SIZE] , int rows ){

// Loop for inputing an array.
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < rows ; j++){

// Input a quadrat matrix.
            cin >> matrix[i][j];
        }
    }
}

// Function for printing an array from integer date type.
void IntegerMatrixPrint( int matrix[][MAX_SIZE] , int rows ){

// Loop for printing the matrix.
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < rows ; j++){

// Print '||' before first column.
            if( j == 0 ){
                cout << "||";
            }

// Printing the array.
            cout << setw(10) << matrix[i][j];

// Print '||' after the last column.
            if( j == rows - 1){
               cout << "||";
            }
        }

// Make a new line for printing as a matrix.
        cout << endl;
    }
}

// Function for sum of two matrixs with equal sizes.
int SumMatrix(double FirstMatrix[][MAX_SIZE] , double SecondMatrix[][MAX_SIZE] , int rows , int cows ){

// Printing this statement.
  cout << " Sum of the matrix is : "  << endl;

// Loop for printing and sum of two matrix.
  for(int i = 0 ; i < rows ; i++){
    for(int j = 0 ; j < cows ; j++){

// Print '||' before first column of the first matrix.
        if ( j == 0){
                cout << "||";
        }

// Printing the elements from the first matrix.
        cout <<setw(5) << FirstMatrix[i][j];

// Print '||' after the last column of the first matrix and rows different form the middle.
        if( j == cows -1 && i != rows / 2){
                cout << "||  ";
        }

// Print '|| + ||' in the middle row and after the last column of the first matrix.
        if( i == rows / 2 && j == cows -1){
            cout << "|| + ||";
        }

// Starting a loop for second matrix.
        if(j == cows - 1){

// Loop for printing the second matrix.
            for(int k = 0 ; k < cows ; k++){

// Print '||' different from the middle row and before first elements.
                if( k == 0 && i != rows / 2){
                        cout << " ||";
                }

// Printing the elements from the second matrix.
                cout <<setw(5) << SecondMatrix[i][k];

// Print '||' in the rows different form the middle and after the last column.
                if( k == cows - 1  && i != rows / 2){
                        cout << "||  ";
                }

// Print '|| = ' in the middle row and after the last column of the second matrix.
                if( i == rows / 2 && k == cows - 1){
                        cout << "|| =";
                }

// Start printing the sum.
                if( k == cows - 1 ){

// Loop for printing the sum.
                    for(int t = 0 ; t < cows ; t++){

// Print '||' before the first column of the third matrix.
                        if( t == 0){
                                cout << " ||";
                        }

// Print the sum of two matrix.
                        cout << setw(5) << FirstMatrix[i][t] + SecondMatrix[i][t];

// Print '||' after the last column of the third matrix.
                        if(t == cows - 1){
                                cout << "||";
                        }
                    }
                }
            }
        }
    }

// Make a new line for printing as a matrix.
    cout << endl;
  }
}

// Function for difference of two matrix with equal sizes.
int Difference(double arr[][MAX_SIZE] , double brr[][MAX_SIZE] , int n , int m ){

// Print this statement.
    cout << " The difference of matrix is : "<<endl;

// Loop for printing the difference of two matrix.
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){

// Print '||' before the first column of the matrix.
            if(j == 0){
                    cout << "||";
            }

// Print the elements from the first matrix.
            cout << setw(5) << arr[i][j];

// Print '||' after the last column an rows different from the middle.
            if( j == m - 1 && i != n / 2){
                    cout << "||  ";
            }

// Print '|| - ||' after the last column and in the middle row.
            if( j == m - 1 && i == n / 2){
                    cout << "|| - ||";
            }

// Start printing second matrix.
            if(j == m - 1){

// Loop for printing the second matrix.
                for(int k = 0 ; k < m ; k++){

// Print '||' before the first column and the rows different from the middle.
                    if( k == 0 && i != n / 2){
                            cout << " ||";
                    }

// Print the elements from the second matrix.
                    cout << setw(5) << brr[i][k];

// Print '||' after the last column and rows different from the middle.
                    if( k == m - 1 && i != n / 2 ){
                            cout << "||  ";
                    }

// Print '||' after the last column and the middle row.
                    if(i == n / 2  && k == m  - 1){
                            cout <<"|| = ||";
                    }

// Start printing the difference.
                    if( k == m - 1){

// Loop for printing th e difference.
                        for(int t = 0 ; t < m ; t++){

// Print '||' before the first column and rows different from the middle.
                            if(t == 0 && i != n / 2){
                                    cout << " ||";
                            }

// Print elements from difference.
                            cout << setw(5) << arr[i][t] - brr[i][t];

// Print '||' after the last column of the third matrix.
                            if(t == m - 1){
                                    cout <<"||";
                            }
                        }
                    }
                }
            }
        }

// Make a new line for printing as a matrix.
        cout << endl;
    }
}

// Function for multiplication with scalar.
int MatrixScalarMultiplication(double matrix[][MAX_SIZE] , int rows , int cows , double scalar){

// Print this statement.
   cout << " The multiplication with " << scalar << " is : "<< endl;

// Loop for printing the matrix.
   for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cows ; j++){

// Print '||' before the first column .
            if( j == 0 ){
                cout << "||";
            }

// Print the elements form the matrix.
            cout <<setw(6) << matrix[i][j];

// Pint '|| * ||....' after the last column of the matrix and the start row.
            if( j == cows - 1 && i == 0 ){
                cout <<"||" << " * " << "|| " << scalar << " || " << " = ";
            }

// Print '||' after the last column of the matrix and rows different from the 0.
            if( j == cows - 1 ){
                cout << "||";

// Loop for printing the multiplication matrix.
                for(int k = 0 ; k < cows ; k++){

// Print '||' in the first column and rows after 0.
                    if( k == 0 && i > 0){
                        cout <<"              ||";
                    }

// Print the elements after multiplication.
                    cout << setw(8) << matrix[i][k] * scalar;

// Print '||' after the last column of the multiplicated matrix.
                    if( k == cows - 1){
                        cout << "||";
                    }
                }
            }
        }

// Make a new line for printing as a matrix.
        cout << endl;
   }
}


// Function for multiplication of two matrix.
int MatrixMultiplication(double FirstMatrix[][MAX_SIZE] , double SecondMatrix[][MAX_SIZE] , int frows , int fcows , int srows , int scows  , double result[][MAX_SIZE]){
// Parameters n , m are for the first matrix.
// Parameters  k , t re for the second matrix.

// Loops for multiplication of the matrix.
    for(int i = 0 ; i < frows ; i++){
       for(int s = 0 ; s < scows ; s++){

// Make the sum of elements equal to null each time.
            result[i][s] = 0.0;

// Loop for sum the elements and push them into third matrix..
            for(int j = 0 ; j < fcows ; j++){
                result[i][s] += FirstMatrix[i][j] * SecondMatrix[j][s];
            }
        }
    }

// Printing each matrix in new line.
     cout << " A = " << endl ;
     MatrixPrint(FirstMatrix , frows , fcows);
     cout << endl << " B = " << endl ;
     MatrixPrint(SecondMatrix , srows , scows);
     cout << " A * B = "  << endl;
     MatrixPrint(result , frows , scows );
}

// Function for make an adjustable quantities.
void AdjustableQuantity(int matrix[][MAX_SIZE] , int used[][MAX_SIZE] , int row , int cow , int matrixrows ){

// Variables for index of the new matrix.
    int indexi = 0 , indexj = 0 ;

// Loop for finding each adjustable quantities.
    for(int i = 0 ; i < matrixrows ; i++){
        for(int j = 0 ; j < matrixrows ; j++){

// Check if row and colw are different from the 0 and the last.
            if( i != row && j != cow){

// Take elements from the first matrix.
                used[indexi][indexj++] = matrix[i][j];

// Make e new row when we reach the last column of the matrix.
                if(indexj == matrixrows - 1){
                    indexj = 0 ;
                    indexi++;
                }
            }
        }
    }
}

// Recursive function for determinant of the quadrat matrix.
int determinant( int matrix[][MAX_SIZE] , int rows ){

// Declaration of the determinant.
    int Det ;

// Bottom of the recursion and return the first elements from the matrix.
    if(rows == 1){
        return matrix[0][0];
    }

// variables used for find the determinant
   int result[MAX_SIZE][MAX_SIZE] , sign = 1;

// Loop for finding the determinant.
   for(int k = 0 ; k < rows ; k++){

// Make an adjustable quantities frm 0 row and each column.
     AdjustableQuantity(matrix , result , 0 , k , rows);

// Sum of the determinant after adjustable quantity.
     Det += sign * matrix[0][k] * determinant(result , rows - 1);

// Swap the sign in front of the sum.
     sign = -sign;
   }

// return the determinant.
    return Det;
}

// Function for dividing matrix on number.
int ScalarDividing(double matrix[][MAX_SIZE] , int rows , int cows , double scalar){

// Print this statement.
   cout << " The matrix after dividing is : " << endl;

// Loop for printing the matrix.
   for(int i = 0 ; i < rows ; i++){
     for(int j = 0 ; j < cows ; j++){

// Print '||' before the first column of first matrix.
        if( j == 0){
            cout << "||";
        }

// Print the elements from the first matrix.
        cout << setw(5) << matrix[i][j];

// Print '||' after the last column of the first matrix .
        if( j == cows - 1 && i == 0){
            cout << "|| / || "<< scalar << " || = ";
        }

// Print '||' after the last column and rows different from the middle.
        if( j == cows - 1 ){
            cout << "||";

// Loop for printing the dividing matrix.
            for(int k = 0 ; k < cows ; k++){

// Print '||' before the first column of the matrix and rows different from 0.
                if( k == 0 && i > 0){
                    cout << "             ||";
                }

// Print elements after dividing.
                cout << setw(8) << matrix[i][k] / scalar ;

// Print '||' after the last column of the divided matrix.
                if( k == cows - 1 ){
                    cout << "||";
                }
            }
        }
     }

// Make a new line for printing as a matrix.
     cout << endl;
   }
}

// Function for transposition of matrix.
void TranspositionMatrix(double matrix[][MAX_SIZE] , int rows , int cows){

// Print this statement.
    cout << endl <<  " Transposition matrix is  : "<< endl;

// First when rows are smaller than cows.
    if(rows < cows ){

// Loop for transposition.
        for(int i = 0 ; i < cows ; i++){
            for(int j = 0 ; j < rows ; j++){

// Print '||' before the first column of the transposition matrix.
                if(j == 0){
                    cout << "||";
                }

// Print the elements of new matrix.
                cout << setw(5) << matrix[j][i];

// Print '||' after the last column of the transposition matrix.
                if( j == rows - 1){
                    cout << "||";
                }
            }

// Make a new line for printing as a matrix.
                cout << endl;
        }
    }

// when rows are equal to cows.
    else if( rows == cows){

// Loop for transposition the matrix.
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cows ; j++){

// Print '||' before the first column of the new matrix.
                if( j == 0){
                    cout << "||";
                }

// Print the elements from the new matrix.
                cout <<setw(5) << matrix[j][i];

// Print '||' after the last column of the matrix.
                if( j == rows - 1){
                    cout << "||";
                }
            }

// Make a new line for printing as a matrix.
          cout << endl;
        }
    }

// When rows are bigger than cows.
    else if( rows > cows){

// Loop for transposition the matrix.
        for(int j = 0 ; j < cows ; j++){
            for(int i = 0 ; i < rows ; i++){

// Print '||' before the first column of the new matrix.
                if( i == 0){
                    cout << "||";
                }

// Printing the elements of the new matrix.
                cout << setw(5) << matrix[i][j];

// Print '||' after the last column of the first matrix.
                if( i == rows - 1){
                    cout << "||";
                }
            }

// Make a new line for printing as a matrix.
            cout << endl;
        }
    }
}

// Function for adjustable qantity matrix.
void AdjustableQuantityMatrix(int matrix[][MAX_SIZE] , int result[][MAX_SIZE] , int rows){

// Check if we have matrix 1X1.
   if( rows == 1){
    result[0][0] == 1 ;
    return ;
   }

// Variables .
   int sign = 1 , used[MAX_SIZE][MAX_SIZE];

// Loop for finding the adjustable quantity matrix.
   for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < rows ; j++){

// First finding the adjustable quantity of each elements.
            AdjustableQuantity(matrix , used , i , j , rows);

// Swapping the sign despite the sum of rows and cows.
            if( (i + j) % 2 == 0 ){
                sign = 1;
            }else{
                sign = -1;
            }

// Make a matrix with adjustable quantity elements.
// Using the determinant for finding the elements.
            result[j][i] = ( sign )* ( determinant ( used , rows - 1 ) );
        }
   }
}

// Function for finding the reverse ( inverse ) of the matrix.
bool InverseMatrix(int matrix[][MAX_SIZE] , double inverse[][MAX_SIZE] , int rows ){

// Variable for determinant.
    int DetA = determinant(matrix , rows);

// Check is the determinant is equal to null.
    if( DetA == 0){
        cout << " The is no inverse matrix : " << endl;
        return false;
    }

// array used for adjustable quantity matrix.
    int used[MAX_SIZE][MAX_SIZE];

// Finding the adjustable quantity matrix.
    AdjustableQuantityMatrix( matrix , used, rows);

// Loop for finding the reverse matrix.
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < rows ; j++){

// Dividing adjustable quantity elements on determinant for
// reach the elements of the inverse matrix.
            inverse[i][j] = used[i][j] / double(DetA);
        }
    }

// Return true when the determinant is different from null( 0 ).
   return true;
}

// Main function.
int main(){

// Variables used for printing the text from the file and input the functions.
    char Text[MAX_SIZE] = "0" , OpenFile[MAX_SIZE] = "0";

// Arrays used in different functions.
    double FirstMatrix[MAX_SIZE][MAX_SIZE] , SecondMatrix[MAX_SIZE][MAX_SIZE] , ResultMatrix[MAX_SIZE][MAX_SIZE] ;

// Variables used in different functions.
// n , m - size of first matrix;
// n1 , m1 - size of the second matrix.
// scalar - number for multiplication or dividing.
    int qmatrix[MAX_SIZE][MAX_SIZE] , frows , fcows , srows , scows , scalar;

// Print this statement.
    cout << " Input 'main' or 'add' for open the files : " << endl;

// Loop for open the 'main' or 'additional' functions.
   do{

// Input the name of the file for its opening.
        cin >> OpenFile;
        if(My_strncmp(OpenFile , "main") == 1 || My_strncmp(OpenFile, "add") == 1){
            break;
        }
   }while(true);

// Enter here when we open main function file.
    if(My_strncmp(OpenFile , "main") == 1){

// Opening of the main function file.
             fstream file("main_functions.txt");

// Check if the file is open.
        if(file.is_open()){

// Declaration of char 'function'
            char func[MAX_SIZE] = "1";

// Printing the information of the file.
            while(file.getline(Text , 200 , '\n') ) {
                cout << Text ;
                cout << endl;
            }

// Loop for running the functions.
            do {

// Print the statement.
                cout << endl <<  " Input a number for run the function " <<endl;

// enter the function which you want to run , just input the number.
                cin >> func;

// stopping with 0 or -1.
               if(My_strncmp (func , "0") == 1  || My_strncmp ( func , "-1") == 1){
                    return -1;
                }

// Check if func is equal to 1.
               if(My_strncmp(func , "1") == 1){

// Input the size of the matrix..
                     cout << " Input the rows of the matrix " << endl;
                     cin >> frows ;
                     cout << " Input the cows of the matrix " << endl;
                     cin >> fcows;

// Input the matrix.
                     cout << " Input the matrix : " << endl;
                     MatrixInput(FirstMatrix , frows , fcows);

// Input the number ( scalar )for multiplication..
                     cout << " Input the number for multiplication : " << endl;
                     cin >> scalar;

// Printing the matrix after multiplication.
                     MatrixScalarMultiplication(FirstMatrix , frows , fcows , scalar);
               }

// Check if func is equal to 2.
               if( My_strncmp(func , "2") == 1){

// Input the size of the matrix.
                    cout << " Input the rows of first matrix : " << endl;
                    cin >> frows ;
                    cout << " Input the cows of the first matrix " << endl;
                    cin >> fcows;

// Input the matrix.
                    cout << " Input first matrix " << endl;
                    MatrixInput(FirstMatrix , frows , fcows);

// Input the size of the second matrix.
                    cout << " Input rows of second matrix " << endl;
                    cin >> srows ;
                    cout << " Input cows of second matrix " << endl;
                    cin >> scows ;

// Check if the cows from the first are equal to the rows of second matrix.
                    if( fcows == srows){

// Input the second matrix.
                        cout << " Input the second matrix : " << endl;
                        MatrixInput(SecondMatrix , srows , scows);

// Print the multiplication matrix..
                        MatrixMultiplication(FirstMatrix , SecondMatrix, frows , fcows , srows , scows , ResultMatrix);
                    }
               }

// Check if func is equal to 3.
               if( My_strncmp(func , "3") == 1){

// Input the size of the matrix.
                    cout << " Input only the rows (rows = cows) of the matrix : " << endl;
                    cin  >> frows ;

// Input the quadrat matrix.
                    cout << " Input the matrix : " << endl;
                    IntegerMatrixInput(qmatrix , frows);

// Printing the determinant.
                    cout << endl << "DET A = " << determinant(qmatrix , frows) << endl ;
               }

// Check if func is equal to 4.
               if( My_strncmp(func , "4") == 1){

// Input the size of the matrix.
                    cout << " Input the rows of the matrix : " << endl;
                    cin >> frows ;
                    cout << " Input the cows of the matrix  : " << endl;
                    cin >> fcows ;

// Input the matrix.
                    cout << " Input the matrix : " << endl;
                    MatrixInput( FirstMatrix , frows , fcows);

// Input the number ( scalar ) for dividing.
                    cout << " Input the number for dividing : " << endl;
                    cin >> scalar;

// Print the result after dividing.
                    ScalarDividing(FirstMatrix , frows , fcows, scalar);
               }

// Check if func is equal to 5.
               if( My_strncmp( func , "5") == 1){

// Input the size of the matrix.
                    cout << " Input only the rows (rows = cows) of the matrix : " << endl;
                    cin >> frows ;

// Input the matrix.
                    cout << " Input the matrix : " << endl;
                    IntegerMatrixInput(qmatrix, frows);

// Check if the result of function for reverse matrix is true.
                    if( InverseMatrix(qmatrix , ResultMatrix , frows) == true ) {

// Printing the first matrix.
                        cout << " Reverse matrix of  " << endl  ;
                        IntegerMatrixPrint(qmatrix , frows);
                        cout << " is : " << endl;

// Printing the reverse ( inverse ) matrix.
                        MatrixPrint(ResultMatrix , frows , frows);
                    }
                }

// Check if func is equal to 6.
                if(My_strncmp(func , "6") == 1){

// Input the size of the matrix.
                    cout << " Input the rows of the matrix : " << endl;
                    cin >> frows ;
                    cout << " Input the cows of the matrix : " << endl;
                    cin >> fcows;

// Input the matrix.
                    cout << " Input the matrix : " << endl;
                    MatrixInput(FirstMatrix , frows , fcows);

// Print inputed matrix.
                    cout << " Main matrix is : " << endl;
                    MatrixPrint(FirstMatrix , frows , fcows );

// Print the transposition matrix.
                    TranspositionMatrix(FirstMatrix , frows , fcows);
                }

// Do this while you enter '0' or '-1'.
            }while(true);

// Closing the file after finishing.
        file.close();
        }

// if file can not open.
        else{
            cout << " -1";
        }

// Check if you entered 'add' .
    }else if(My_strncmp(OpenFile , "add") == 1){

// Variable used for printing the text form the file.
        char ainput[MAX_SIZE] = "0";

// Opening the additional functions file.
        fstream afile("add_functions.txt");

// check is it open.
        if(afile.is_open()){

// Variables or input the functions.
            char afunc[MAX_SIZE] = "1";

// Printing the information from the file.
            while(afile.getline(ainput, 200 , '\n') ) {
                    cout << ainput ;
                    cout <<endl;
            }

// Loop for input the functions and run them.
            do{

// Print the statement.
                 cout << endl << " Input the number for run the functions : " << endl;

// Input the function you want to run.
                 cin  >> afunc;

// Break wit '0' and '-1'.
                 if( My_strncmp(afunc , "0" ) == 1 || My_strncmp( afunc , "-1") == 1){
                    return -1;
                 }

// Check is afunc is equal to 1.
                 if(My_strncmp(afunc , "1") == 1){

// Input the size of two matrix.
                    cout << " Input the rows of the matrixes : " << endl;
                    cin >> frows ;
                    cout << " Input the cows of the matrixes : " << endl;
                    cin >> fcows ;

// Input the first matrix.
                    cout << " Input first matrix : " << endl;
                    MatrixInput(FirstMatrix , frows , fcows );

// Input the second matrix.
                    cout << " Input second matrix : " << endl;
                    MatrixInput(SecondMatrix , frows , fcows );

// Print the result of sum.
                    SumMatrix(FirstMatrix , SecondMatrix , frows , fcows);
                }

// Check is afunc is equal to 2.
                if(My_strncmp(afunc , "2") == 1){

// Input the size of two matrix.
                    cout << " Input the rows of the matrix : " << endl;
                    cin >> frows ;
                    cout << " Input the cows of the matrix : " << endl;
                    cin >> fcows;

// Input the first matrix.
                    cout << " Input first matrix : " << endl;
                    MatrixInput(FirstMatrix , frows , fcows);

// Input the second matrix.
                    cout << " Input second matrix : " << endl;
                    MatrixInput(SecondMatrix , frows , fcows);

// Print the result of the difference.
                    Difference(FirstMatrix , SecondMatrix , frows , fcows);
                }

// Do this until entering 0 or -1.
            }while(true);

// Then closing the file.
            afile.close();

// If file cna not open.
        }else {
            cout << " -1 " << endl;
        }
    }
return 0 ;
}
