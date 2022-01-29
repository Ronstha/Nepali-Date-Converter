#include <stdio.h> //Standard input output library
#include <string.h> //String function like strlen(),strcpy()
#include <stdlib.h>//function atoi()=>convert string to int
//structure for date object
struct date{
 int year;
 int month;
 int day;
 int weekday;
 char error[100];
 char Month[30];
 char Day[30];
};
typedef struct date Date; //Data type Date
//array for days in month (bs)
int bs[100][12]={{30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 29, 31},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 30, 30},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 30, 30},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},{31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},{31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 31, 32, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{30, 32, 31, 32, 31, 31, 29, 30, 30, 29, 29, 31},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 30, 30},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 30, 30},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},{31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 31, 32, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{30, 32, 31, 32, 31, 31, 29, 30, 29, 30, 29, 31},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 29, 31},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 30, 30},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},{31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 30},{31, 31, 32, 32, 31, 30, 30, 30, 29, 30, 30, 30},{30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 30, 30},{31, 31, 32, 31, 31, 30, 30, 30, 29, 30, 30, 30},{31, 31, 32, 31, 31, 30, 30, 30, 29, 30, 30, 30},{31, 31, 32, 31, 31, 30, 30, 30, 29, 30, 30, 30},{30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 30, 30},{31, 31, 32, 31, 31, 31, 30, 30, 29, 30, 30, 30},{30, 31, 32, 32, 30, 31, 30, 30, 29, 30, 30, 30},{30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 30, 30},{30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 30, 30},{30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 30, 30}};
int ad[12]={31,28,31,30,31,30,31,31,30,31,30,31};//array for days in month (ad)
char bsmonth[12][30]={"Baisakh","Jestha","Asar","Sharwan","Bhadra","Ashoj","Karthik","Mangsir","Paush","Magh","Falgun","Chaitra"};//array of monthname (bs)
char admonth[12][30]={"January","Februry","March","April","May","June","July","August","September","October","November","December"};//array of monthname (ad)
char weekdays[7][30]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};//array of weekdays
//check if year is leapyear
int leapyear(int year){
    if(year%100==0 && year%400!=0) return 0;
    
    if(year%4==0) return 1;
    return 0;
}
//slice string and convert to int
int slice(char raw[],int start,int end ){
  
    int i;
    char a[10]={};
    for(i=0;i<end-start;i++){
        a[i]=raw[i+start];
    }
    a[i+1]='\0';
  
    return atoi(a);
    
} 
//Function to convert raw date in string format[YYYY-MM-DD] to structured date
Date format(char raw[]){
    
    int i;
    Date formatted;
    strcpy(formatted.error,"");
    if(strlen(raw)!=10 || raw[4]!='-' || raw[7]!='-'){//format is invalid [YYYY-MM-DD]
        strcpy(formatted.error,"Invalid Format");
        return formatted;
    }
    formatted.year=slice(raw,0,4);
    formatted.month=slice(raw,5,7);
    formatted.day=slice(raw,8,10);
    return formatted;
 }

//function to convert Bs date to Ad
Date Bs2Ad(char raw[]){
     int i;
    Date current=format(raw);
    Date convert;
    strcpy(convert.error,"");
    if(strlen(current.error)!=0){//check for invalid format
         strcpy(convert.error,"INVALID DATE [YYYY-MM-DD]");
       return convert;
    }


    if(current.year<2000|| current.year>2090){ //check for available  range
       strcpy(convert.error,"Year out of Range(2000-2090)");
       return convert;

    };
    if(current.month>12){//check if month is greater than 12
        strcpy(convert.error,"Invalid Month");
       return convert;

    };
    if(current.day>32){//check if day is greater than 32
        strcpy(convert.error,"Invalid Day");
       return convert;

    };

    int yearcount=2000,daycount=0,monthcount=1;
    while(yearcount!=current.year){//count no of days from referance year[2000-01-01] to current year
        for(i=0;i<12;i++){
            daycount+=bs[yearcount-2000][i];
        };
        yearcount+=1;
    }

    while(monthcount!=current.month){//add no of days up to current month to the count
        daycount+=bs[yearcount-2000][monthcount-1];
        monthcount+=1;
    }
    if(current.day>bs[yearcount-2000][monthcount-1]){//check if current date exist
       strcpy(convert.error,"Entered Date Donot exist");
       return convert;
    }
    daycount+=current.day;//add day to the count
    convert.weekday=((daycount+2)%7)+1;//calaculate day of week
    strcpy(convert.Day,weekdays[convert.weekday-1]);//weekday name
   
    daycount+=103;//adjust day count for ad (ad date first day is 103 day ahead from refrence date first day)
    
    convert.year=1943;//referance date(1943-01-01 AD)
    while ((leapyear(convert.year) && daycount>366)||(!leapyear(convert.year) && daycount>365)){//add years and subtracting days in added years
        daycount-=365;
        if(leapyear(convert.year)){
   
            daycount-=1;
        }
        convert.year+=1;
    }    
    convert.month=1;
    ad[1]=28;
    if(leapyear(convert.year)){
        ad[1]=29;
    }
    while (daycount>0){
        if(daycount>ad[convert.month-1]){//increase month if remaining daycount is greater than day in month
            daycount-=ad[convert.month-1];//subtract days in month
            convert.month+=1;//increase month

        }
        else{
            convert.day=daycount;//day
            strcpy(convert.Month,admonth[convert.month-1]);//save month
            break;
        }
    }
    return convert;//return converted date
 }
 //function to calculate sum of array
 int sum(int a[]){
     int i,sum=0;
     for(i=0;i<12;i++){
         sum+=a[i];
     }
     return sum;
     
 }

//function to convert Bs date to Ad
Date Ad2Bs(char raw[]){
  int i;
  Date current=format(raw);
  Date convert;
    strcpy(convert.error,"");
    if(strlen(current.error)!=0){//check for invalid format
         strcpy(convert.error,"INVALID DATE [YYYY-MM-DD]");
       return convert;
    }


    if(current.year<1944|| current.year>2034){//check for available range
       strcpy(convert.error,"Year out of Range(1944-2034)");
       return convert;

    };
    if(current.month>12){//check if month is greater than 12
        strcpy(convert.error,"Invalid Month");
       return convert;

    };
    if(current.day>31){//check if day is greater than 31
        strcpy(convert.error,"Invalid Day");
       return convert;

    };

    int yearcount=1943,daycount=0,monthcount=1;
    while(yearcount!=current.year){//count no of days from referance year[2000-01-01] to current year
        daycount+=365;
        if(leapyear(yearcount)){
            daycount+=1;
        }
        yearcount+=1;
    }
      ad[1]=28;
    if(leapyear(yearcount)){
        ad[1]=29;
    }

    while(monthcount!=current.month){//add no of days up to current month to the count
        daycount+=ad[monthcount-1];
        monthcount+=1;
    }
    if(current.day>ad[monthcount-1]){//check if current date exist
       strcpy(convert.error,"Entered Date Donot exist");
       return convert;
    }
    daycount+=current.day;//add day to the count
    convert.weekday=((daycount+4)%7)+1;//calaculate day of week
    strcpy(convert.Day,weekdays[convert.weekday-1]);//weekday name
   
    daycount-=103;//adjust day count for bs (referance date first day is 103 day ahead from bs date first day)
    
    convert.year=2000;//referance date(2000-01-01 BS)
    while (daycount>sum(bs[convert.year-2000])){
        daycount-=sum(bs[convert.year-2000]);
   
        convert.year+=1;
    }    
    convert.month=1;
  
    while (daycount>0){
        if(daycount>bs[convert.year-2000][convert.month-1]){//increase month if remaining daycount is greater than day in month
            daycount-=bs[convert.year-2000][convert.month-1];//subtract days in month
            convert.month+=1;//increase month

        }
        else{
            strcpy(convert.Month,bsmonth[convert.month-1]);//save month
            convert.day=daycount;//day
            break;
        }
    }
    return convert;//return converted date
}
