#include <iostream> 

using namespace std;


const int SIZE = 4; //global variable for matrix size

class Matrix{
    private:
        int data [SIZE][SIZE]; //2d array for matrix data

    public:

        //1. Read values from stdin into a matrix
        void readFromStdin(){
            for (int i = 0; i<SIZE; ++i){
                for (int j = 0; j < SIZE; ++j){
                    cin >> data[i][j];
                }
            }
        }

        //2. Display matrix
        void display() const{
            for (int i = 0; i<SIZE; ++i){
                for (int j = 0; j < SIZE; ++j){
                    cout<<data[i][j]<< " ";
                }
                cout<< endl;
            }
        }

        //3. add two matrices (op overloading +)
        Matrix operator+(const Matrix&other) const{
            Matrix result;
            
            for (int i = 0; i < SIZE; ++i){
                for (int j = 0; j<SIZE; ++j){
                    result.data[i][j] = data[i][j] + other.data[i][j];
                }
            }
            return result;
        }

        //4. multiply two matrices (op overloading for *)
        Matrix operator*(const Matrix &other) const{
            Matrix result;

            for (int i = 0; i<SIZE; ++i){
                for (int j = 0; j<SIZE; ++j){
                    result.data[i][j] = 0;

                    for (int k = 0; k<SIZE; ++k){
                        result.data[i][j] += data[i][k] * other.data[k][j];
                    }
                }
            }
            return result;
        }

        //5. compute the sum of matrix diagonal elements
        int sumOfDiagonals() const{
            int mainDiagonal = 0, secondaryDiagonal = 0;

            for (int i = 0; i <SIZE; ++i){
                mainDiagonal += data[i][i];
                secondaryDiagonal += data[i][SIZE - 1 - i];
            }
            return mainDiagonal + secondaryDiagonal;
        }

        //6. swap matrix rows
        void swapRows(int row1, int row2){
            if (row1 >= 0 && row1 < SIZE && row2 >= 0 && row2 < SIZE){
                for (int j = 0; j < SIZE; ++j){
                    swap(data[row1][j], data[row2][j]);
                }
            } else{
                cerr<<"Invalid row indices"<<endl;
            }
        }
};


int main(){
    //example use
    Matrix mat1;
    cout<<"Enter values for Matrix 1:"<< endl;
    mat1.readFromStdin();

    cout<<"Matrix1:"<<endl;
    mat1.display();

    Matrix mat2;
    cout<<"Enter values for Matrix 2:"<<endl;
    mat2.readFromStdin();

    cout<<"Matrix 2: \n"<<endl;
    mat2.display();


    //matrix addition
    Matrix sum = mat1 + mat2;
    cout<<"Sum of matrices:"<<endl;
    sum.display();

    //matrix multiplication
    Matrix product = mat1*mat2;
    cout<<"Product of matrices:"<<endl;
    product.display();

    //sum of diagonals
    cout<<"Sum of diagonals of Matrix 1:"<<mat1.sumOfDiagonals()<<endl;

    //Row swapping
    mat1.swapRows(0,2);
    cout<<"Matrix 1 after swapping rows:"<<endl;
    mat1.display();

    return 0;
}