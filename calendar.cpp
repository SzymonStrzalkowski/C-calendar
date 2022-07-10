#include <iostream>
#include <iomanip>

    using namespace std;

//text structure of the calendar
struct {
string line[5]={"|Su|Mo|Tu|We|Th|Fr|Sa|","+--+--+--+--+--+--+--+","|  ","| ","|"};
}calendartop;

class cstruct {
    public:
        int year_sel,mnth_sel=0;
        //function to run the private funtion that builds the whole calendar
        void check_year(){
        printcal();
        }
    private:
        bool is_leap = false;
        int Monthsdays[12]={31,28,31,30,31,30,31,31,30,31,30,31};

        //this function checks the day of the year that the program starts at so its always for jan 1
        int yearstart(int z){
        int x=(z-1)/100;
        int y=(z-1)%100;
        return (((29-(2*x)+y+(y/4)+(x/4))%7)+7)%7;
        };

        //The program checks if the years is a leap year according to the rules of the gregorian calendar
        void leapyearcheck(){
            if (year_sel%4==0){
                is_leap = true;
                if(year_sel%100==0){
                    is_leap = false;
                    if (year_sel%400==0){
                        is_leap = true;
                        }}}
            else
                is_leap=false;

                //if the program finds the year is a leap year, it changes the amount of days to print to 29
                if(is_leap==true)
                    Monthsdays[1]=29;
                    //to make sure if we rerun the program without closing it, it tells the program to revert the change if the year is not a leap year
                else
                    Monthsdays[1]=28;
                };

        void printcal(){
            //here we create the top part of the callendar that tells us the day of the week
        cout<<calendartop.line[1]<<endl<<calendartop.line[0]<<endl<<calendartop.line[1]<<endl;
        leapyearcheck();
        
        //This function checks when a given month will start,
        //according to the month we selected,
        //so when we want to check out febuary of a given year
        //it will at 31 days from january and look for the day
        short int calpos=yearstart(year_sel);
        for(int i=0;i!=mnth_sel-1;i++){
            calpos+=Monthsdays[i];
            calpos= calpos%7;
            }
        //here we print out all the blank places for the beggining of the month
        if(calpos>0){
            int blanks=calpos;
            while (blanks>0){
                cout<<calendartop.line[2];
                blanks--;
            }}
            //this part checks if we have a calendar table of 5 weeks 
            //or 6 weeks to print out to fit a month
        int totalcels=calpos+Monthsdays[mnth_sel-1];
        if (totalcels>35)
            totalcels=42;
        if (totalcels<35)
            totalcels=35;
            //here we start creating the table by adding the days in order,
            //from 1 to 28 or 29 or 30 or 31
        int day=0;
        while(calpos<totalcels)
        {
            day++;
            //this line adds blank squares to the end of the month
            if(day>Monthsdays[mnth_sel-1])
                cout<<calendartop.line[2];
            else
            {
            if(day/10==0&&day<=Monthsdays[mnth_sel-1])
                cout<<calendartop.line[3]<<day;
            if(day/10!=0&&day<=Monthsdays[mnth_sel-1])
                cout<<calendartop.line[4]<<day;
            }
            //Those 2 lines move us to the next line
            if(calpos==6||calpos==13||calpos==20||calpos==27||calpos==34||calpos==41)
                cout<<calendartop.line[4]<<endl;
            calpos++;
        }
        //this line adds the footer to close up the calendar
            cout<<calendartop.line[1]<<endl;
};};

int main () {
    cstruct calendar;
    while(calendar.mnth_sel!=13){
    cout<<"Enter Year: ";
    cin>>calendar.year_sel;
    cout<<"Enter Month: ";
    cin>>calendar.mnth_sel;
    if (calendar.mnth_sel==13)
        return 0;
    calendar.check_year();
    cout<<"To close the program put 13 inside month selection"<<endl;
    }};
    //hope you enjoy it :)
