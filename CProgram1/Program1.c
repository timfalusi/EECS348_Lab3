/*
 * Program1.c
 *
 *  Created on: Feb 8, 2023
 *      Author: o642f122
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float* file_reader(const char* name)
{
  FILE* input_file= fopen(name, "r");
  float* sales = (float*)malloc(sizeof(float)*12);
  int a = 0;
  for (a=0;a<12;a++){
    fscanf(input_file,"%f",&sales[a]);
  }
  fclose(input_file);
  return sales;
}


void read_sales(const char* months[], float* sales){
  int a = 0;
  printf("Monthly sales report for 2022\n");

  printf("Month\tSales\n");
  for(a=0;a<12;a++){
    printf("%-9s\t%8.2f\n",months[a],sales[a]);
  }
  return;
}

void sales_summary(float* sales, const char* months[])
{
  int a = 0;
  float max = 0;
  float min = sales[0];
  int placementofmax = 0;
  int placementofmin = 0;
  
 for (a=0;a<12;++a){
    if(max <= sales[a]){
      max = sales[a];
      placementofmax = a;
    }
  }
 for (a=0;a<12;++a){
      if (min >= sales[a]){
        min = sales[a];
        placementofmin = a;

      }
    }
  printf("minimum sales: %8.2f (%s)\n", min, months[placementofmin]);
  printf("maximum sales: %8.2f (%s)\n", max, months[placementofmax]);

  // average
  float total = 0;
  float average = 0; 
  for (a=0;a<12;a++){
    total += sales[a];
  }
  average = total/12;
  printf("Average Sales: %.2f\n", average);
}

void six_month(float* sales, const char* months[]){
  int a = 0;
  int b = 0;
  float sum = 0;
  float average = 0;
  printf("Six-Month Moving Average Report:\n");
  for (a = 0; a<7;++a){
    sum = 0;
    for (b=a;b<a+6;++b){
      sum += sales[b];
    }
    average = sum/6;
    printf("%-10s\t - \t%-10s\t%-12.2f\n",months[a],months[b-1],average);
  }

}
void sales_switch(float * i, float * j){
  float temp = *i;
  *i = *j; 
  *j = temp;
}
void month_switch(char **i, char **j){
  char* temp = *i;
  *i = *j;
  *j =  temp; 
}


void salessort(float* sales, const char* months[]){
  printf("Sales Report (Highest to Lowest)\n");
  printf("  Month\tSales\n");
  float* copysales = (float*)malloc(sizeof(float) * 12);
  
  for (int i=0;i<12;++i){
    copysales[i] = sales[i];
  }

  char *monthsorted[12];
  for (int i=0;i<12;++i){
    char* copymonths = (char*)malloc(sizeof(char) * sizeof(months[i]+1));
    strcpy(copymonths, months[i]);
    monthsorted[i] = copymonths;
  }

  for (int i=0;i<12;++i){
    for (int j=0;j<12;++j){
      if (copysales[i]>copysales[j]){
        sales_switch(&copysales[j], &copysales[i]);
        month_switch(&monthsorted[j], &monthsorted[i]); 
      }
    }
  }

  for (int i = 0; i<12;++i){
    printf("%-10s\t%-10.2f\n", monthsorted[i], copysales[i]);
  }
}

int main(){
  float* sales; 
  const char* months[12] = {"January","Feburary", "March", "April", "May", "June", "July", "August", "September","October", "November", "December"};  
  sales = file_reader("sales.txt");
  read_sales(months, sales);
  sales_summary(sales, months);
  six_month(sales,months);
  salessort(sales,months);

  return 0;
}