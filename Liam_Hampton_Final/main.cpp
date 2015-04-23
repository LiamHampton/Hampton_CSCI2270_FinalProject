//Includes Elmendorf Boulder Seattle San Francisco JFK Las Vegas, LAX, Amsterdam, Denver.
//http://aviationweather.gov/adds/dataserver_current/httpparam?dataSource=metars&requestType=retrieve&format=csv
//&stationString=PAED KBOL KSEA KSFO KJFK KLAS KLAX EHAM ,KDEN&hoursBeforeNow=12

//Liam Hampton  Final Project.

/* Get some more data out of the wholeMtr
    Fix messyZulu
    ICOM to City library
    hook the infile up to the Text Data Server for live data
    Add Lat-Long can be used for algorithm queries
    Different Libraries by default
        US 6 hour data
        More airfields, most recent METAR
        Historical data for one or two nodes.*/

/*  Easy Kills
    Create text menu
    When asked city give all data.
    When asked for city with greatest or least x, find  city. */


/*  Build nodes and link them
    Algorithm ideas:
    Graph with lat long values for distances between
    HashTables if just trying to organize many cities and many METARs
    Which order would you want to fly in order to always be landing at a higher or lower elevation.*/


#include <iostream>
#include <vector>
#include "METARs.h"
#include <fstream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

void menu(){
    cout<<"======Liam's Bad Use of Good Data======"<<endl;
    cout<<"1. Choose CSV METARs data."<<endl;
    cout<<"2. METAR for a specific airfield."<<endl;
    cout<<"3. Greatest/Least value."<<endl;
    cout<<"4. Change database."<<endl;

}

void import (string filename){
    ifstream infile("metar9Cities.txt");
    string IATA;
    string Output;
    string messyZulu;
    string garbage;
    string wholeMtr;
    AirHubs Airfield;
    //first 6 lines are garbage.
    int Lcounter = 1;
    if(infile.is_open()){
        while (getline(infile,Output)){
            istringstream iss(Output);
            if(Lcounter <=7){
                getline(iss, garbage);
                Lcounter++;
                }
            if(Lcounter >= 8){
                int Ccount=1;
                float MetData[7];
                if (Ccount==1){
                    getline(iss, wholeMtr, ',');
                    Ccount++;
                }
                if (Ccount == 2){
                    getline(iss,IATA, ',');
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
                        }
                    Airfield.insertAirfield(IATA, messyZulu, MetData);
                    Ccount++;
                }
                else
                    Lcounter++;
            }
                /*Sky category 16, Flight cat 17, 24hrhigh/lowT 21&22,
                24hr precip 26, snow 27, MSL 30 */

          }
    }
infile.close();
cout<<Lcounter<<endl;
}


int main (){
    //work in progress
    menu();
    cout<< "What is the file extension"<< endl;
    string file;
    getline(cin, file);

    import(file);

    return 0;
}
