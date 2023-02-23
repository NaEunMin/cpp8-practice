/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;


class Seat{;
    string name;
    public:
    Seat(){
        name = "---";
    }
    void showSeat(){
        cout << name << '\t';
    }
    void reservation(string name){
        this->name = name;
    }
    void cancle(string name){
        if(this->name == name)
        this->name = "---";
    }
};

class Schedule{
    Seat *seat;
    string time;
    public:
    Schedule(){
        seat = new Seat[8];
    }
    ~Schedule(){ delete [] seat; }
    void setTime(string time){
        this->time = time;
    }
    string getTime(){
        return time;
    }
    void show(){
        cout << time;
        for(int i=0; i<8; i++){
            seat[i].showSeat();
        }
    }
    
    void reservationSeat(int seatnumber, string name){
        seat[seatnumber-1].reservation(name);
    }
    void cancleSeat(int seatnumber, string name){
        seat[seatnumber-1].cancle(name);
    }
};

class Console{
    public:
    static int Menu(){
        cout << "예약:1, 취소:2, 보기:3, 끝내기:4>>";
        int MenuNumber;
        cin >> MenuNumber;
        return MenuNumber;
    }
    static int ShowTime(){
        cout << "07시:1, 12시:2, 17시:3>>";
        int TimeNumber;
        cin >> TimeNumber;
        return TimeNumber;
    }
    static int SeatNumber(){
        cout << endl;
        cout << "좌석 번호>>";
        int seatnumber;
        cin >> seatnumber;
        return seatnumber;
    }
    static string InputName(){
        cout << "이름 입력>>";
        string name;
        cin >> name;
        return name;
    }
};


class AirlineBook{
    Schedule *schedule;
    public:
    AirlineBook(){
        schedule = new Schedule[3];
        schedule[0].setTime("07시:");
        schedule[1].setTime("12시:");
        schedule[2].setTime("17시:");
    }
    ~AirlineBook(){ delete [] schedule;}
    void StartBook(){
       cout << "***** 한성항공에 오신것을 환영합니다 *****" << endl << endl << endl;
       while(true){
       int Menu = Console::Menu();
       if(Menu == 1){ //예약메뉴선택
           int showtime = Console::ShowTime(); //시간선택
           schedule[showtime-1].show(); //자리보여주기
           int seatnumber = Console::SeatNumber(); //자리번호선택
           string name = Console::InputName(); //자리주인이름입력
           cout << endl;
           schedule[showtime-1].reservationSeat(seatnumber, name); //예약
        }
        else if(Menu == 2){ //취소메뉴선택
            int showtime = Console::ShowTime(); //시간선택
            schedule[showtime-1].show(); //자리보여주기
            int seatnumber = Console::SeatNumber(); //자리번호선택
            string name = Console::InputName(); //자리주인이름입력
            cout << endl;
            schedule[showtime-1].cancleSeat(seatnumber, name);//취소
        }
        else if(Menu == 3){ //보기메뉴선택
            for(int i=0; i<3; i++){
                schedule[i].show();
                cout << endl;
            }
            cout << endl;
        }
        else if(Menu == 4){
            cout << "예약 시스템을 종료합니다.";
            return;
        }
       }
    }
};
    


int main()
{
    AirlineBook airlinebook;
    airlinebook.StartBook();

    return 0;
}
