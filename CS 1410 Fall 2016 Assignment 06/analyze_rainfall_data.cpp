/*This program reads the input text file of rainfall data and performs
 *specific computations to be shown in an output text file. 
 *Summary of changes:
 *Created a structure called Rainfall consisting of the month, year, and amount
 *Created three functions to simplify calculations and make main look neat.
 *Discussion:
 *I felt like structures made it easier and more organized in doing the program.
 *I definitely choose structures for this assignment because it's easier to keep track of one array than three arrays and the functionality is better.
 *
 *Author: Steen Sia, sia
 *Prog. Assignment 5a/6a
 *Last updated: October 19, 2016
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Rainfall
{
  string month;
  string year;
  double amount;
};

double total_average_rainfall(Rainfall rf_data[], int SIZE);
void monthly_rainfall(Rainfall rf_data[], int SIZE, int month_count[], double month_rainfall[], int MAX);
void sort_rainfall_data(Rainfall rf_data[], int SIZE);

int main()
{
  const int SIZE = 240;
  Rainfall rf_data[SIZE];
  string city;
  const int MAX = 12; 
  int month_count[MAX];
  double month_rainfall[MAX];
  double month_average[MAX];

  
  ifstream in_file;
  ofstream out_file;
  
  in_file.open("rainfall_data.txt");
  
  in_file >> city;

  //Reads the input data and stores under the structure
  for(int i = 0; i < SIZE; i++)
    {
      in_file >> rf_data[i].month;
      in_file >> rf_data[i].year;
      in_file >> rf_data[i].amount;
    }   
  
  monthly_rainfall(rf_data, SIZE, month_count, month_rainfall, MAX);
  
  for(int i = 0; i < MAX; i++)
    {
      month_average[i] = month_rainfall[i] / month_count[i];
    }    

  sort_rainfall_data(rf_data, SIZE);

  out_file.open("rainfall_results.txt");
  out_file << "Assignment 5" << endl << "CS 1410" << endl << "Steen Sia" << endl << city << endl << endl;
  out_file << "The overall average rainfall amount is: "  << fixed << setprecision(2) << total_average_rainfall(rf_data, SIZE) << endl;
  out_file << "The average rainfall amount for January is: " << fixed << setprecision(2) << month_average[0] << endl;
  out_file << "The average rainfall amount for February is: " << fixed << setprecision(2) << month_average[1] << endl;
  out_file << "The average rainfall amount for March is: " << fixed << setprecision(2) << month_average[2] << endl;
  out_file << "The average rainfall amount for April is: " << fixed << setprecision(2) << month_average[3] << endl;
  out_file << "The average rainfall amount for May is: " << fixed << setprecision(2) << month_average[4] << endl;
  out_file << "The average rainfall amount for June is: " << fixed << setprecision(2) << month_average[5] << endl;
  out_file << "The average rainfall amount for July is: " << fixed << setprecision(2) << month_average[6] << endl;
  out_file << "The average rainfall amount for August is: " << fixed << setprecision(2) << month_average[7] << endl;
  out_file << "The average rainfall amount for September is: " << fixed << setprecision(2) << month_average[8] << endl;
  out_file << "The average rainfall amount for October is: " << fixed << setprecision(2) << month_average[9] << endl; 
  out_file << "The average rainfall amount for November is: " << fixed << setprecision(2) << month_average[10] << endl;
  out_file << "The average rainfall amount for December is: " << fixed << setprecision(2) << month_average[11] << endl;
  out_file << "The rain amount (in inches) of the four wettest months are: " << fixed << setprecision(2) << rf_data[239].amount << " " << fixed << setprecision(2) << rf_data[238].amount << " " << fixed << setprecision(2) << rf_data[237].amount << " " << fixed << setprecision(2) << rf_data[236].amount << " " << endl;
  out_file << "The rain amount (in inches) of the four driest months are: " << fixed << setprecision(2) << rf_data[0].amount << " " << fixed << setprecision(2) << rf_data[1].amount << " " << fixed << setprecision(2) << rf_data[2].amount << " " << fixed << setprecision(2) << rf_data[3].amount << " " << endl;
  out_file << "The ten median months are: " << endl;	
  
  for(int i = 114; i < 124 ; i++)
    {	    
      out_file << rf_data[i].month << " " << rf_data[i].year << " "<< rf_data[i].amount << " " << endl;
    }
  
}
/*This function adds the corresponding rainfall amount to each month
 *and increments the month count to be computed for monthly rainfall average 
 *
 *Parameters: 
 *struct -- the rainfall data array collect in array
 *int -- size of the array
 *int -- array that updates the count of each month
 *double -- array that sums the rainfall amount for each month
 *int -- size of month arrays
 *
 *Return:
 *nothing
 */
void monthly_rainfall(Rainfall rf_data[], int SIZE, int month_count[], double month_rainfall[], int MAX){
  ifstream in_file;

  for(int i = 0; i < SIZE; i++)
    {
	in_file >> rf_data[i].month;
    if(rf_data[i].month == "January")
      {
	month_count[0] ++;
	month_rainfall[0] += rf_data[i].amount;
      }
    else if(rf_data[i].month == "February")
      {
	month_count[1] ++;
	month_rainfall[1] += rf_data[i].amount;
      }
    else if(rf_data[i].month == "March")
      {
	month_count[2] ++;
	month_rainfall[2] += rf_data[i].amount;
      }
    else if(rf_data[i].month == "April")
      {
	month_count[3] ++;
	month_rainfall[3] += rf_data[i].amount;
      }
    else if(rf_data[i].month == "May")
      {
	month_count[4] ++;
	month_rainfall[4] += rf_data[i].amount;
      }
    else if(rf_data[i].month == "June")
      {
	month_count[5] ++;
	month_rainfall[5] += rf_data[i].amount;
      }
    else if(rf_data[i].month == "July")
      {
	month_count[6] ++;
	month_rainfall[6] += rf_data[i].amount;
      }
    else if(rf_data[i].month == "August")
      {
	month_count[7] ++;
	month_rainfall[7] += rf_data[i].amount;
      }
    else if(rf_data[i].month == "September")
      {
	month_count[8] ++;
	month_rainfall[8] += rf_data[i].amount;
      }
    else if(rf_data[i].month == "October")
      {
	month_count[9] ++;
	month_rainfall[9] += rf_data[i].amount;
      }
    else if(rf_data[i].month == "November")
      {
	month_count[10] ++;
	month_rainfall[10] += rf_data[i].amount;
      }
    else
      {
	month_count[11] ++;
	month_rainfall[11] += rf_data[i].amount;
      }
    }
}
/* This function calculates the total average rainfall
 *
 *Parameters:
 *struct -- uses the rainfall data collected in array
 *int -- size of the array
 *Return:
 *double -- returns the average rainfall
 */
double total_average_rainfall(Rainfall rf_data[], int SIZE){
  ifstream in_file;
  double total_rainfall_average = 0;
  double rainfall_sum = 0;

  for(int i = 0; i < SIZE; i++)
    {
      in_file >> rf_data[i].amount;
      rainfall_sum += rf_data[i].amount;
    }
  total_rainfall_average = rainfall_sum / SIZE;
  return total_rainfall_average;
  
}
/*This function uses selection sort to arrange rainfall amount from least to greatest
 *
 *Parameters:
 *struct -- the rainfall data collected in an array
 *int -- the total size of the array
 *
 *Return:
 *nothing
 */
void sort_rainfall_data(Rainfall rf_data[], int SIZE){
  for(int i = 0; i < SIZE; i++){
    double temp = 0;
    string temp_two = "";
    string temp_three = ""; 

    for(int i = 0; i < SIZE; i++)
      {
	int min = i;
	for(int j = i+1; j < SIZE; j++)
	  {
	 if(rf_data[j].amount < rf_data[min].amount)
	   min = j;
	   }
	//uses selection sort to arrange rainfall amount from least to greatest
	temp = rf_data[i].amount;
        rf_data[i].amount = rf_data[min].amount;
	rf_data[min].amount = temp;
	
	//swaps the month and year together as the rainfall amount is sorted
       	temp_two = rf_data[i].month;
        rf_data[i].month = rf_data[min].month;
	rf_data[min].month = temp_two;
	
	temp_three = rf_data[i].year;
        rf_data[i].year = rf_data[min].year;
        rf_data[min].year = temp_three;
      }
  }
}
