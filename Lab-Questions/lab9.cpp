#include<iostream>
using namespace std;

//create a template for a (square)matrix, order n
//perform spiral traversal with a function in the class
//17 November 2025
template<typename T>
class Matrix{
    private:
        int n;
        T **mat;
    public:
        Matrix(T **input, int order){
            n = order;
            mat = new T*[n];
            for(int i = 0; i < n; ++i)
                mat[i] = new T[n];
            
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    mat[i][j] = input[i][j];
        }
        ~Matrix(){
            for(int i = 0; i < n; ++i)
                delete[] mat[i];
            delete [] mat;
        }
        void print_matrix(){
            cout << "\nOriginal Matrix:\n";
            cout << "---------------------------\n";
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j)
                    cout << mat[i][j] << ' ';
                cout << '\n';
            }
            cout << "---------------------------\n";
        }
        void spiral_matrix(){
            cout << "traversal in spiral order\n";
            int top = 0,
                bottom = n - 1,
                left = 0,
                right = n - 1;
            while(left <= right && top <=bottom){
                //left to right travesal
                for(int i = left; i <=right; ++i)
                    cout << mat[top][i] << ' ';
                ++top;
                //top to bottom traversal
                for(int i = top; i <= bottom; ++i)
                    cout << mat[i][right] << ' ';
                --right;
                //right to left traverse
                //we traverse only when there are rows remaining 
                if (top <= bottom) {
                    for (int i = right; i >= left; --i)
                        cout << mat[bottom][i] << " ";
                    bottom--;
                }

                //bottom to top
                //we traverse only if there are columns remaining 
                if (left <= right) {
                    for (int i = bottom; i >= top; --i)
                        cout << mat[i][left] << " ";
                    left++;
                }
            }
            cout << "\n";
        }
};
int main(){
    char type;
    cout << "\n--------------------------------------------------------\n";
    cout << "Enter data type of the matrx elements\n";
    cout << "Enter i for integer, c for characters, f for float\n";
    cin  >> type;
    int n;
    cout << "Enter order of the matrix : ";
    cin >> n;
    cout << "\n--------------------------------------------------------\n";
    if(type == 'i' || type == 'I'){    
        int** arr = new int*[n];  
        for (int i = 0; i < n; ++i) {
            arr[i] = new int[n]; 
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cout << "\nEnter element = ";
                cin >> arr[i][j];
            }
        }
        Matrix<int> m(arr, n);
        m.print_matrix();
        m.spiral_matrix();

        for (int i = 0; i < n; ++i)
            delete[] arr[i];
        delete[] arr;
    }
    else if (type == 'c' || type == 'C'){
        char **arr = new char*[n];  
        for (int i = 0; i < n; ++i) {
            arr[i] = new char[n]; 
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cout << "\nEnter element = ";
                cin >> arr[i][j];
            }
        }
        Matrix<char> m(arr, n);
        m.print_matrix();
        m.spiral_matrix();

        for (int i = 0; i < n; ++i)
            delete[] arr[i];
        delete[] arr;
    }else{
        float **arr = new float*[n];  
        for (int i = 0; i < n; ++i) {
            arr[i] = new float[n]; 
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cout << "\nEnter element = ";
                cin >> arr[i][j];
            }
        }
        Matrix<float> m(arr, n);
        m.print_matrix();
        m.spiral_matrix();

        for (int i = 0; i < n; ++i)
            delete[] arr[i];
        delete[] arr;
    }
    return 0;
}
