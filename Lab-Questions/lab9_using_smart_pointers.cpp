#include<iostream>
#include<memory>
using namespace std;
//same question using smart pointer : std::unique_ptr
template<typename T>
class Matrix{
private:
    int n;
    unique_ptr<unique_ptr<T[]>[]> mat;
public:
/*
    this approach took raw pointer as a parameter
    Matrix(T **input, int order): n(order){
        //in this line we are creating an array of unique_ptr of size n 
        //similar to the way we do in DMA using raw pointers
        mat = make_unique<unique_ptr<T[]>[]>(n);    //mat is a smart pointer to an array of row pointers, each of which is a std::unique_ptr<T[]>
        for (int i = 0; i < n; ++i)
            mat[i] = make_unique<T[]>(n);       //har ek row mein elements assign kiye hain number of columns ke according
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                mat[i][j] = input[i][j];
    }
*/
    //this approach transfers the ownership of input to mat
    Matrix(std::unique_ptr<std::unique_ptr<T[]>[]> input, int order)
        : n(order), mat(std::move(input)) {}

    void print_matrix(){
        cout << "\nOriginal Matrix: \n";
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j)
                cout << mat[i][j] << ' ';
            cout << '\n';
        }
    }
    // void spiral_matrix(){
    void spiral_matrix() const {
        cout << "traversal in spiral order\n";
        int top = 0, 
            bottom = n - 1, 
            left = 0, 
            right = n - 1;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; ++i)
                cout << mat[top][i] << ' ';
            ++top;

            for (int i = top; i <= bottom; ++i)
                cout << mat[i][right] << ' ';
            --right;

            if (top <= bottom) {
                for (int i = right; i >= left; --i)
                    cout << mat[bottom][i] << ' ';
                --bottom;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; --i)
                    cout << mat[i][left] << ' ';
                ++left;
            }
        }
        cout <<'\n';
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
        auto arr = std::make_unique<std::unique_ptr<int[]>[]>(n);
        for (int i = 0; i < n; ++i)
            arr[i] = std::make_unique<int[]>(n);
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cout << "\nEnter element = ";
                cin >> arr[i][j];
            }
        }
        Matrix<int> m(std::move(arr), n);
        m.print_matrix();
        m.spiral_matrix();
    }
    else if (type == 'c' || type == 'C'){
        
        auto arr = make_unique<unique_ptr<char[]>[]>(n);
        for (int i = 0; i < n; ++i)
            arr[i] = std::make_unique<char[]>(n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cout << "\nEnter element = ";
                cin >> arr[i][j];
            }
        }
        Matrix<char> m(std::move(arr), n);
        m.print_matrix();
        m.spiral_matrix();
    }else{
        auto arr = make_unique<unique_ptr<float[]>[]>(n);
        for (int i = 0; i < n; ++i)
            arr[i] = std::make_unique<float[]>(n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cout << "\nEnter element = ";
                cin >> arr[i][j];
            }
        }
        Matrix<float> m(std::move(arr), n);
        m.print_matrix();
        m.spiral_matrix();
    }
    return 0;
}
