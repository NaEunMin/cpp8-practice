/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Printer{
    string model;
    string manufacturer;
    int printedCount;
    int availableCount;
    public:
    Printer(string model, string manufacturer, int availableCount){
        this-> model = model;
        this-> manufacturer = manufacturer;
        this-> availableCount = availableCount;
    }
    void print(int printedCount){//  pages 매의 용지를 사용한다.
        availableCount -= printedCount;
    } 
    bool PrinterTest(int printedCount){
        if(availableCount > printedCount)
        return true;
        else
        return false;
    }
    string getModel(){ return model; }
    string getManufacturer(){ return manufacturer; }
    int getAvailableCount(){ return availableCount; }
};

class InkJetPrinter : public Printer {
    int availableInk;
    public:
    InkJetPrinter(string model, string manufacturer, int availableCount, int availableInk) : Printer(model, manufacturer, availableCount){
        this-> availableInk = availableInk;
    }
    int getAvailableInk(){ return availableInk; }
    void printInkJet(int pages){
        availableInk-= pages;
        print(pages);
    }
    void ShowInkJetPrinter(){
        cout << "잉크젯 : " << getModel() << ", " << getManufacturer() << ",남은 종이 " << getAvailableCount() << "장, 남은 잉크 " << getAvailableInk() << endl; 
    }
};

class LaserPrinter : public Printer {
    int availableToner;
    public:
    LaserPrinter(string model, string manufacturer, int availableCount, int availableToner) : Printer(model, manufacturer, availableCount){
        this-> availableToner = availableToner;
    }
    int getAvailableToner(){ return availableToner; }
    void printLaser(int pages){
        availableToner -= pages;
        print(pages);
    }
    void ShowLaserPrinter(){
        cout << "레이저 : " << getModel() << ", " << getManufacturer() << ", 남은 종이" << getAvailableCount() << "장, 남은 토너" << getAvailableToner() << endl;
    }
};


int main()
{
    int PrinterNumber;
    int pages;
    char ch;
    cout << "현재 작동중인 2 대의 프린터는 아래와 같다." << endl;
    InkJetPrinter inkjetprinter("Officejet V40", "HP", 5, 10);
    LaserPrinter laserPrinter("SCX-6x45", "삼성전자", 3, 20);
    
    inkjetprinter.ShowInkJetPrinter();
    laserPrinter.ShowLaserPrinter();
    while(true){
    cout << endl;
    
    cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
    cin >> PrinterNumber >> pages;
    if(PrinterNumber==1){
        if(inkjetprinter.PrinterTest(pages)){
        inkjetprinter.printInkJet(pages);
        cout << "프린트하였습니다." << endl;
        inkjetprinter.ShowInkJetPrinter();
        laserPrinter.ShowLaserPrinter();
        }
        else{
        cout << "용지가 부족하여 프린트 할 수 없습니다." << endl;
        inkjetprinter.ShowInkJetPrinter();
        laserPrinter.ShowLaserPrinter();
        }
    }
    else if(PrinterNumber==2){
        if(laserPrinter.PrinterTest(pages)){
            laserPrinter.printLaser(pages);
            cout << "프린트하였습니다." << endl;
            inkjetprinter.ShowInkJetPrinter();
            laserPrinter.ShowLaserPrinter();
        }
        else{
        cout << "용지가 부족하여 프린트 할 수 없습니다." << endl;
        inkjetprinter.ShowInkJetPrinter();
        laserPrinter.ShowLaserPrinter();
        }
    }
    
    cout << "계속 프린트 하시겠습니까(y/n)>>";
    cin >> ch;
    
    if(ch=='n')
    break;
  }

    return 0;
}
