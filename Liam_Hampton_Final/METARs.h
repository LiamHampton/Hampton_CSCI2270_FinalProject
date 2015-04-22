#ifndef HASHTABLE_H
#define HASHTABLE_H

struct Airfield{
    std::string ICOP;
    std::string updateZ;
    float temp;
    float dewPT;
    float windDir;
    float windSpd;
    float windGust;
    float vis;
    float altr;

    Airfield *next;

    Airfield(){};

    Airfield(std::string in_ICOP, std::string in_updateZ, float m[])
    {
        ICOP = in_ICOP;
        updateZ = in_updateZ;
        temp=m[0];
        dewPT=m[2];
        windDir=m[3];
        windSpd=m[4];
        windGust=m[5];
        vis=m[6];
        altr=m[7];
    }

};

class HashTable
{
    public:
        HashTable();
        ~HashTable();
        void insertAirfield(std::string in_title);
        Airfield* findAirfield(std::string in_title, int *index);
        void deleteAirfield(std::string in_title);
        void updateAirfield(std::string in_title, float y);
        void printInventory();
    protected:
    private:
        Airfield *hashTable;
};

#endif // HASHTABLE_H

