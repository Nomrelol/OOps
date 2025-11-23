#include <iostream>
using namespace std;

class employee{
    int emp_number;
    float income;
public:
    void set_data(){
        cout << "\nEnter employee number = ";
        cin >> emp_number;
        cout << "\nEnter employee compensation = ";
        cin >> income;
    }
    void show_data(){
        cout << "\nEmployee number is = " << emp_number;
        cout << "\nEmployee Compensation is = " << income;
    }
};
int main() {
    
    
    return 0;
}