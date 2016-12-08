#include <iostream>

using namespace std;

double sum(float a, float b){
    return a + b;
}

double sub(float a, float b){
    return a - b;
}

int main(){
    float a, b;
    cout << "Введите a и b " << endl;
    cin >> a >> b;
    cout << "Сумма " << sum(a, b) << endl;
    cout << "Разность " << sub(a, b);
    return 0;
}
