#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//struct {
//char line[5]={"|Su|Mo|Tu|We|Th|Fr|Sa|","+--+--+--+--+--+--+--+","|  ","| ","|"};
//}calendartop;

int leap_year_check(int febuary,int** year){
	if((**year%4==0&&**year%400==0&&**year%3200!=0)||(**year%4==0&&**year%100!=0))
		return febuary+1;
	return febuary;
}

int first_day_of_the_year(int** year){
	int x=(**year-1)/100;
	int y=(**year-1)%100;
	return (((29-(2*x)+y+(y/4)+(x/4))%7)+7)%7;
}

void printcal(int* year,int *month){
	char day[7][2]={"Su","Mo","Tu","We","Th","Fr","Sa"};
	int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	months[1]=leap_year_check(months[1],&year);
	int first_day=first_day_of_the_year(&year);
	for(int i=0;i!=*month-1;i++){
		first_day+=months[i];
		first_day%=7;
	}
	for(int i=0;i<7;i++){
		printf("|%c%c",day[i][0],day[i][1]);
		switch(i){
			case 6:
			printf("|\n");
		}
	}
	printf("+--+--+--+--+--+--+--+\n");
	switch(first_day){
		case 0:
			break;
		default:
			for(int i=0;i<first_day;i++){
				printf("|  ");
			}
	}

}

int main(int argc, char *argv[]){
	int year,month;
	printf("What year:");
	scanf("%d", &year);
	printf("What month:");
	scanf("%d", &month);
	printf("The year passed into is %d, and the month is %d. \n", year, month);
	printcal(&year,&month);
	return 0;
}
