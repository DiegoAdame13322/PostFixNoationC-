#include <iostream>
#include <string>
#include <vector>


using namespace std;

double string_to_double(const string& s) {
    return stod(s);
}

string Choice;          
vector<double> stack;  
bool endstack=false;
bool choices=false;

double peek() {
    if (stack.empty()) {
        cout<<"Cannot Peek in Empty Stack"<<endl;
      return 0;
    } else {
        return stack.back();
    }
}

double pop() {
    double topofstack = peek();
    stack.pop_back();
    return topofstack;
}
void emptystack()
{
  while (!stack.empty())
    {
      stack.pop_back();
    }
    choices=true;
}
void showstack()
{
  for (int x=0; x < stack.size(); x++)
    {
      cout << stack[x] << endl;
    }
  choices=true;
}
void Ending()
{
  if (stack.size() != 1)
  {
  cout << "Stack has been complete!" << endl;
  cout << "Remaining in Stack" << endl;
  showstack();
   }
  endstack=true;
}

void push(double x) {
    stack.push_back(x);
}

int main() {
  cout << "type end to end stack" << endl; 
  cout << "type show to show stack" << endl;
  cout << "type empty to show stack" << endl;
    while (cin >> Choice) {
      choices=false;
          if (Choice == "end")
          {
            Ending();
            break;
          }
         if (Choice == "show")
          {
           showstack();
          }
         if (Choice == "empty")
          {
           emptystack();
          }
            if (Choice == "+") {
                double b = pop();
                double a = pop();
                cout<<"popped "<<b<<" "<<a<<" +"<<endl;
                push(a + b);
                cout<<"pushed "<<a+b<<endl;
            } else if (Choice == "-") {
                double b = pop();
                double a = pop();
                cout<<"popped "<<b<<" "<<a<<" -"<<endl;
                push(a - b);
                cout<<"pushed "<<a-b<<endl;
            } else if (Choice == "*") {
                double b = pop();
                double a = pop();
                cout<<"popped "<<b<<" "<<a<<" *"<<endl;
                push(a * b);
                cout<<"pushed "<<a*b<<endl;
            } else if (Choice == "/") {
                double b = pop();
                double a = pop();
                cout<<"popped "<<b<<" "<<a<<" /"<<endl;
                push(a / b);
                cout<<"pushed "<<a/b<<endl;
            } else if (Choice == ".") {
                cout << "topofstack = " << peek() << "\n";
            } else if (choices==false){
                push(string_to_double(Choice));
                cout<<"pushed "<<string_to_double(Choice)<<endl;
            } 
          }
  if (endstack==true )
  {
    cout<<"The result of the operation is " <<peek();
  }
} 