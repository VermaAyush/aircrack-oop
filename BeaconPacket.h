#pragma once

#include "WlanPacket.h"

#pragma pack(push,1)
struct BEACON_FRAME {
    u_int8_t timestamp[8];
 	u_int8_t beacon_interval[2];
 	u_int8_t capability_information[2];
    u_int8_t element_id;
    u_int8_t length;
};

struct FIELD_HEADER{
    u_int8_t ID;
    u_int8_t size;
};
#pragma pack(pop)

class BeaconPacket : public WlanPacket
{

    int nextfield();
    void analyze();
    u_int8_t * bodyPtr;
    size_t bodyLen;
    struct FIELD_HEADER * fieldHdrPtr;
    public:

        BeaconPacket();
        BeaconPacket(RawData * packet);
        ~BeaconPacket();

        struct BEACON_FRAME * beaconHdr;

        u_int8_t BSSID[6];
        int pwr;
        int Beacons;
        int data;
        //int Channel; --> goto radiotap header
        int MB;
        char encrypt[5];
        char CIPHER[5];
        char AUTH[5];
        char ESSID[33];
       
        //void printAttr();
};