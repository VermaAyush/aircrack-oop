#pragma once

#include "WlanPacket.h"

#pragma pack(push,1)

#pragma pack(pop)

class ProbePacket : public WlanPacket
{

    void analyze();

    public:

        ProbePacket();
        ProbePacket(RawData * packet);
        ~ProbePacket();

        //struct BEACON_FRAME * beaconHdr;

        u_int8_t BSSID[6];
        u_int8_t SSID[6];
       
        //void printAttr();
};