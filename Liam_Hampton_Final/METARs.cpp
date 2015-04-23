#include <iostream>
#include <vector>
#include "METARs.h"
#include <fstream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

AirHubs::AirHubs(){

}
AirHubs::~AirHubs(){
    //dtor
}


void AirHubs::insertAirfield(std::string in_IATA, std::string in_updateZ, float m[]){
    Airfield.IATA=in_IATA;
    Airfield->updateZ=in_updateZ;
    Airfield->temp=m[0];
    Airfield->dewPT=m[1];
    Airfield->windDir=m[2];
    Airfield->windSpd=m[3];
    Airfield->windGust=m[4];
    Airfield->vis=m[5];
    Airfield->altr=m[6];
    Airfield->next=NULL;
    cout<<"Airfield: "<<Airfield->IATA<<endl;
    cout<<"Last Updated: "<<Airfield->updateZ<<endl;
    cout<<"Temperature: "<< Airfield->temp<<endl;
}


/*
Airfield* findAirfield(std::string in_title, int *index);


void deleteAirfield(std::string in_title);


void updateAirfield(std::string in_title, float y);


void printInventory();
*/
