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
    cout<<"1. Import METAR data"<<endl;
    cout<<"2. Airports in data"<<endl;
    cout<<"3. Print all data for Airfield"<<endl;
    cout<<"4. Change database."<<endl;
    cout<<"5. Quit."<<endl;

}
AirHubs Import (AirHubs Airfield){
    ifstream infile("metar9Cities.txt");
    string IATA;
    string Output;
    string messyZulu;
    string garbage;
    string wholeMtr;
    //first 6 lines are garbage.
    if(infile.is_open()){
        for(int i = 0; i<6; i++){
            getline(infile, Output);
        }
        while (getline(infile,Output)){
            istringstream iss(Output);
            float MetData[7];
                getline(iss, wholeMtr, ',');
                cout<<"1: ";
                cout<<wholeMtr<<endl;
                getline(iss,IATA, ',');
                cout<<"2: "<<IATA<<endl;
                getline(iss, messyZulu, ',');
                cout<<"3: "<< messyZulu<<endl;
                for(int j=0; j<2; j++){
                    getline(iss, garbage, ',');
                    cout<<"garbage: "<<garbage<<endl;
                }
                string holder;
                cout<<"array"<<endl;
                for (int i=0; i<=6; i++){
                    getline(iss, holder, ',');
                    if (holder == ""){
                        holder = "0";
                    }
                    cout<<"thing "<<i<<": "<<holder<<endl;
                    MetData[i]=stof(holder);
                    }
                Airfield.insertAirfield(IATA, messyZulu, MetData);
            }
                /*Sky category 16, Flight cat 17, 24hrhigh/lowT 21&22,
                24hr precip 26, snow 27, MSL 30 */


    }
infile.close();
return Airfield;
}

int main (){
    //work in progress
    int choice;
    string file;
    menu();
    cin>>choice;
    AirHubs Airfield;
    while (choice!=7){
        if (choice==1){
            Airfield=Import(Airfield);
            menu();
            cin>>choice;
        }
        if (choice==2){
            Airfield.printAirfields();
            menu();
            cin>>choice;
        }
        if (choice==3){
            cout<<"What airfield would you like data for?"<<endl;
            string IATA;
            cin>> IATA;
            Airfield.printAirfield(IATA);
            menu();
            cin>>choice;
        }
    }
    return 0;
}
