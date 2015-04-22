//Includes Elmendorf Boulder Seattle San Francisco JFK Las Vegas, LAX, Amsterdam, Denver.
//http://aviationweather.gov/adds/dataserver_current/httpparam?dataSource=metars&requestType=retrieve&format=csv
//&stationString=PAED KBOL KSEA KSFO KJFK KLAS KLAX EHAM ,KDEN&hoursBeforeNow=12

//Liam Hampton  Final Project.

#include <iostream>
#include <vector>
#include "METARs.h"
#include <fstream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

void import (string filename){
    ifstream infile("metar9Cities.txt");
    string ICOM;
    string Output;
    string messyZulu;
    string garbage;
    string wholeMtr;
    //first 6 lines are garbage.
    int Lcounter = 1;
    HashTable Airfield;
    if(infile.is_open()){
        while (getline(infile,Output)){
            istringstream iss(Output);
            if(Lcounter <=7){
                getline(iss, garbage);
                Lcounter++;
                }
            if(Lcounter > 7){
                int Ccount=1;
                float MetData[7];
                if (Ccount==2){
                    getline(iss, wholeMtr, ',');
                    Ccount++;
                }
                if (Ccount == 1){
                    getline(iss,ICOM, ',');
                    Ccount++;
                }
                if (Ccount == 3){
                    getline(iss, messyZulu, ',');
                    Ccount++;
                }
                if (Ccount >3 && Ccount<6){
                    getline(iss, garbage, ',');
                    Ccount++;
                }
                if (Ccount >=6 && Ccount<13){
                    string holder;
                    for (int i=0; i<=7; i++){
                        getline(iss, holder, ',');
                        MetData[i]=stof(holder);
                        Ccount++;
            /*Gonna need to add the nodes here,
            but have to do the math as well.*/


                    }
                }
                /*Sky category 16, Flight cat 17, 24hrhigh/lowT 21&22,
                24hr precip 26, snow 27, MSL 30 */
                else
                    Lcounter++;
            }
        }
    infile.close();
    cout<<Lcounter<<endl;
    }
}

int main (){
    //work in progress
    cout<< "What is the file extension"<< endl;
    string file;
    getline(cin, file);


    import(file);

    return 0;
}
