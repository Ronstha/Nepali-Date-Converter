#include <stdio.h> //Standard input output library
#include <string.h> //String function like strlen(),strcpy()
#include <stdlib.h>//function atoi()=>convert string to int
struct date{
 int year;
 int month;
 int day;
 int weekday;
 char error[100];
}; //structure for date object
int bs[100][12]={{30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 29, 31},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 30, 30},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 30, 30},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},{31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},{31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 31, 32, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{30, 32, 31, 32, 31, 31, 29, 30, 30, 29, 29, 31},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 30, 30},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 30, 30},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},{31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 31, 32, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{30, 32, 31, 32, 31, 31, 29, 30, 29, 30, 29, 31},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 29, 31},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{31, 31, 31, 32, 31, 31, 29, 30, 30, 29, 30, 30},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 31},{31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 30, 29, 31},{31, 31, 31, 32, 31, 31, 30, 29, 30, 29, 30, 30},{31, 31, 32, 31, 31, 31, 30, 29, 30, 29, 30, 30},{31, 32, 31, 32, 31, 30, 30, 30, 29, 29, 30, 30},{31, 31, 32, 32, 31, 30, 30, 30, 29, 30, 30, 30},{30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 30, 30},{31, 31, 32, 31, 31, 30, 30, 30, 29, 30, 30, 30},{31, 31, 32, 31, 31, 30, 30, 30, 29, 30, 30, 30},{31, 31, 32, 31, 31, 30, 30, 30, 29, 30, 30, 30},{30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 30, 30},{31, 31, 32, 31, 31, 31, 30, 30, 29, 30, 30, 30},{30, 31, 32, 32, 30, 31, 30, 30, 29, 30, 30, 30},{30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 30, 30},{30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 30, 30},{30, 32, 31, 32, 31, 30, 30, 30, 29, 30, 30, 30}};
int ad[12]={31,28,31,30,31,30,31,31,30,31,30,31};
typedef struct date Date; //Data type Date
//slice data
int leapyear(int year){
    if(year%100==0 && year%400!=0) return 0;
    
    if(year%4==0) return 1;
    return 0;
}
int slice(char raw[],int start,int end ){
  
    int i;
    char a[10]={};
    for(i=0;i<end-start;i++){
        a[i]=raw[i+start];
    }
    a[i+1]='\0';
  
    return atoi(a);
    
} 
//Function to convert raw date to structured date
Date format(char raw[]){
    
    int i;
    Date formatted;
    strcpy(formatted.error,"");
    if(strlen(raw)!=10 || raw[4]!='-' || raw[7]!='-'){
        strcpy(formatted.error,"Invalid Format");
        return formatted;
    }
    formatted.year=slice(raw,0,4);
    formatted.month=slice(raw,5,7);
    formatted.day=slice(raw,8,10);
    return formatted;
 }

 Date Bs2Ad(char raw[]){
     int i;
    Date current=format(raw);
    Date convert;
    strcpy(convert.error,"");
    if(strlen(current.error)!=0){
         strcpy(convert.error,"INVALID DATE [YYYY-MM-DD]");
       return convert;
    }


    if(current.year<2000|| current.year>2090){
       strcpy(convert.error,"Year out of Range(2000-2090)");
       return convert;

    };
    if(current.month>12){
        strcpy(convert.error,"Invalid Month");
       return convert;

    };
    if(current.month>32){
        strcpy(convert.error,"Invalid Day");
       return convert;

    };

    int yearcount=2000,daycount=0,monthcount=1;
    while(yearcount!=current.year){
        for(i=0;i<12;i++){
            daycount+=bs[yearcount-2000][i];
        };
        yearcount+=1;
    }

    while(monthcount!=current.month){
        daycount+=bs[yearcount-2000][monthcount-1];
        monthcount+=1;
    }
    if(current.day>bs[yearcount-2000][monthcount-1]){
       strcpy(convert.error,"Entered Date Donot exist");
       return convert;
    }
    daycount+=current.day;
    convert.weekday=((daycount+2)%7)+1;
   
    daycount+=103;
    
    convert.year=1943;
    while ((leapyear(convert.year) && daycount>366)||(!leapyear(convert.year) && daycount>365)){
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
        if(daycount>ad[convert.month-1]){
            daycount-=ad[convert.month-1];
            convert.month+=1;

        }
        else{
            convert.day=daycount;
            break;
        }
    }
    return convert;
 }
 int sum(int a[]){
     int i,sum=0;
     for(i=0;i<12;i++){
         sum+=a[i];
     }
     return sum;
     
 }

Date Ad2Bs(char raw[]){
  int i;
  Date current=format(raw);
  Date convert;
    strcpy(convert.error,"");
    if(strlen(current.error)!=0){
         strcpy(convert.error,"INVALID DATE [YYYY-MM-DD]");
       return convert;
    }


    if(current.year<1944|| current.year>2034){
       strcpy(convert.error,"Year out of Range(1944-2034)");
       return convert;

    };
    if(current.month>12){
        strcpy(convert.error,"Invalid Month");
       return convert;

    };
    if(current.month>31){
        strcpy(convert.error,"Invalid Day");
       return convert;

    };

    int yearcount=1943,daycount=0,monthcount=1;
    while(yearcount!=current.year){
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

    while(monthcount!=current.month){
        daycount+=ad[monthcount-1];
        monthcount+=1;
    }
    if(current.day>ad[monthcount-1]){
       strcpy(convert.error,"Entered Date Donot exist");
       return convert;
    }
    daycount+=current.day;
    convert.weekday=((daycount+4)%7)+1;
   
    daycount-=103;
    
    convert.year=2000;
    while (daycount>sum(bs[convert.year-2000])){
        daycount-=sum(bs[convert.year-2000]);
   
        convert.year+=1;
    }    
    convert.month=1;
  
    while (daycount>0){
        if(daycount>bs[convert.year-2000][convert.month-1]){
            daycount-=bs[convert.year-2000][convert.month-1];
            convert.month+=1;

        }
        else{
            convert.day=daycount;
            break;
        }
    }
    return convert;
}
