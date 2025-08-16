//push
//pop
//peek
//isEmpty   
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Stack {
    int size;
    int top;
    int *arr;
    public :
    Stack(int s){
         top = -1;
         size = s;
         arr = new int[s];
    }

    void push(int x){
        if(top == size-1){
            cout << "Stack Overflow" << endl;
        } else {
            top++;
            arr[top] = x;
        }
    }
    void pop(){
        if(top == -1){
            cout << "Stack Underflow" << endl;
        } else {
            cout<< "Popped element: " << arr[top] << endl;
            top--;
        }
    int peek(){
        if(top == -1){
            cout<<"Stack is empty"<<endl;
            return -1;
        } else {
            return arr[top];
        }
        }
    bool isEmpty(){
        if(top == -1){
            return true;
            else {
                return false;
            }
        }
    }    
    };       
       

    int main(){
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.pop();
    
return 0;
    }

