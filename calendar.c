#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
struct calendartop{
	char line[22];
	char line_sep[22];
	char line_no_day[3];
	char line_single_digit_day[2];
	char line_two_digit_day[1];
	};

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

void printcal(int* year,int* month){

	struct calendartop separators=
	{
		{"|Su|Mo|Tu|We|Th|Fr|Sa|"},
		{"+--+--+--+--+--+--+--+"},
		{"|  "},
		{"| "},
		{"|"}
	};
	int first_day=first_day_of_the_year(&year),
	    day_no=first_day,
	    week_no=1,
	    months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	months[1]=leap_year_check(months[1],&year);
	size_t separator_len[3]={
		strlen(separators.line)-strlen(separators.line_sep),
		strlen(separators.line_sep)-strlen(separators.line_no_day),
		strlen(separators.line_no_day)-strlen(separators.line_single_digit_day)
	    };

	for(size_t i=0;i!=*month-1;i++){
		first_day+=months[i];
		first_day%=7;
	}

	for(size_t i=0 ; i < separator_len[0]; i++){
		printf("%c",separators.line[i]);
		if(i==separator_len[0]-1){
			printf("\n");
		}
	}

	for(size_t i=0 ; i < separator_len[1]; i++){
		printf("%c",separators.line_sep[i]);
		if(i==separator_len[1]-1){
			printf("\n");
		}
	}

	switch(first_day){
		case 0:
			break;
		default:
		for(int i=0 ; i < first_day ; i++ )
		{
			for(size_t l=0 ; l < separator_len[2] ; l++ )
			{
			printf("%c", separators.line_no_day[l]);
			}
		}
	}

	for( int i=1; i<=months[*month-1] ; i++ )
	{

		switch(i)
		{
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
				printf("%c%c%d",
				separators.line_single_digit_day[0],
				separators.line_single_digit_day[1],
				i);
			break;

			default:
				printf("%c%d",
				separators.line_two_digit_day[0],
				i
				);
		}

		day_no=(i+first_day)%7;

		switch(day_no)
		{
			case 0:
				printf("%c\n",
				separators.line_no_day[0]);
				for(int l=0 ; l<separator_len[1] ; l++)
				{
				printf("%c",separators.line_sep[l]);
				}
				printf("\n");
				week_no++;
		}
	}

	if(day_no<7&&day_no!=0)
	{
		while(day_no++<7)
		{
		for(size_t l=0 ; l < separator_len[2] ; l++ )
		{
		printf("%c", separators.line_no_day[l]);
		}
		}
		printf("%c\n",separators.line_no_day[0]);
		for(int l=0 ; l<separator_len[1] ; l++)
		{
		printf("%c",separators.line_sep[l]);
		}
		printf("\n");

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
