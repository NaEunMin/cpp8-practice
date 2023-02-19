/*****************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

******************************************************************************/

#include <iostream>

using namespace std;

class Circle{
    int radius;
    public:
    Circle(int radius=0) {
        this->radius = radius;
    }
    int getRadius(){
        return radius;
    }
    void setRadius(int radius){
        this->radius = radius;
    }
    double getArea(){
        return 3.14*radius*radius;
    }
};

class NamedCircle : public Circle{
    string name;
    public:
    NamedCircle(int radius=0, string name="") : Circle(radius){
        this->name = name;
    }
    void show(){
        cout << "반지름이 " << getRadius() << "인" << name;
    }
    void setName(string name){
        this->name = name;
    }
    string getName(){
        return name;
    }
};

int main()
{
    int radius;
    string name;
 NamedCircle pizza[5];
 cout << "5 개의 정수 반지름과 원의 이름을 입력하세요." << endl;
 for(int i=0; i<5; i++){
     cout << i+1 << ">>";
     cin >> radius >> name;
     cout << endl;
     pizza[i].setRadius(radius);
     pizza[i].setName(name);
     
 }
 
 string Max_AreaPizzaName;
 for(int i=0; i<4; i++){
     if(pizza[i].getArea()<pizza[i+1].getArea())
     Max_AreaPizzaName = pizza[i+1].getName();
     else
     Max_AreaPizzaName = pizza[i].getName();
 }
 cout << "가장 면적이 큰 피자는 " << Max_AreaPizzaName << "입니다.";

    return 0;
}
