#include <iostream>
#include <vector>
#include "METARs.h"
#include <fstream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

AirHubs::AirHubs(){
    head=NULL;
    tail=NULL;
}
AirHubs::~AirHubs(){
    //dtor
}

void AirHubs::printAirfield(string in_IATA){
    Airfield *temp = head;
    while (temp->next != NULL){
        cout<<temp->IATA<<endl;
        if (temp->IATA == in_IATA){
            cout<<"IATA: "<< temp->IATA<<endl;
            cout<<"Update Date/Time: "<< temp->updateZ<<endl;
            cout<<"Temperature: "<< temp->temp<<" C"<<endl;
            cout<<"DewPoint: "<< temp->dewPT<<" C"<<endl;
            cout<<"Wind Direction: "<< temp->windDir<<" Degrees"<<endl;
            cout<<"Wind Speed: "<< temp->windSpd<<" KTS"<<endl;
            cout<<"Wind Gust: "<< temp->windGust<<" KTS"<<endl;
            cout<<"Visibility "<< temp->vis<<" Miles"<<endl;
            cout<<"Altimeter "<< temp->altr<<" in Hg"<<endl;
            break;
        }
        if (temp->next == NULL){
            cout<<"No airport found "<<endl;
            break;
        }
        else{
            temp = temp->next;
        }
    }
}


void AirHubs::printAirfields(){
    Airfield *temp = head;
    int i = 1;
    while (temp->next != NULL){
        cout<<i<<": "<<temp->IATA<<endl;
        temp = temp->next;
        i++;
    }
}
void AirHubs::insertAirfield(std::string in_IATA, std::string in_updateZ, float m[]){
    Airfield *temp=new Airfield(in_IATA, in_updateZ, m);
    Airfield *ptr = head;
    if(head == NULL){
        head = temp;
        tail = temp;
        head->next = tail ->next = NULL;
        head->prev = tail->prev= NULL;
    }
    else{
        while (ptr->next !=NULL){
            if (temp->IATA!=ptr->IATA){
                ptr = ptr->next;
            }
            else{
                break;
            }
        }
        while (temp->IATA == ptr->IATA){
            if (ptr->hist != NULL){
                ptr= ptr->hist;
            }
            if (ptr->hist == NULL){
                ptr->hist = temp;
                break;
            }
        }
        if (temp->IATA != ptr->IATA){
            ptr->next = temp;
            temp->prev = ptr;
            temp = tail;
        }
    }
}


//Airfield* findAirfield(std::string in_title, int *index);

/*

void deleteAirfield(std::string in_title);


void updateAirfield(std::string in_title, float y);


void printInventory();
*/
