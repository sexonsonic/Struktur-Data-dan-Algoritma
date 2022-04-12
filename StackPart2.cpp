#include <iostream>

using namespace std;

const int ukuran = 4;
struct datastack{
    int top;
    int data[ukuran];
} stack;

void buatstack(){
    stack.top=-1;
}

int kosong(){
    if (stack.top == -1){

        return 1;
    }
    else {

        return 0;
    }
}

int penuh(){
    if (stack.top == ukuran - 1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int nilai)
{
    if(penuh() == 0){
        stack.top++;
        stack.data[stack.top] = nilai;
        cout << "data : " << stack.data[stack.top] << endl;
    }else{
 cout << "Stack sudah penuh gaes" << endl;
    }
}

int main(){
    buatstack();
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
}