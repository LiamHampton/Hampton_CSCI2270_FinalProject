#ifndef HASHTABLE_H
#define HASHTABLE_H

struct Airfield{
    std::string IATA;
    std::string updateZ;
    float m[];
    float temp;
    float dewPT;
    float windDir;
    float windSpd;
    float windGust;
    float vis;
    float altr;

    Airfield *next;

    Airfield(){};

    Airfield(std::string in_IATA, std::string in_updateZ, float m[])
    {
        IATA = in_IATA;
        updateZ = in_updateZ;
        temp=m[0];
        dewPT=m[1];
        windDir=m[2];
        windSpd=m[3];
        windGust=m[4];
        vis=m[5];
        altr=m[6];
    }

};

class AirHubs
{
    public:
        AirHubs();
        ~AirHubs();
        void insertAirfield(std::string in_IATA, std::string in_updateZ, float m[]);
        Airfield* findAirfield(std::string in_title, int *index);
        void deleteAirfield(std::string in_title);
        void updateAirfield(std::string in_title, float y);
        void printInventory();
    protected:
    private:
        Airfield *hashTable;
};

#endif // HASHTABLE_H

