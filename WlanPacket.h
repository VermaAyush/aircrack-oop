#pragma once

#include "RawData.h"

#include "Radiotap.h"
#include "Dot11Mac.h"

class WlanPacket : public RawData
{
    public:
        Radiotap radiotap;
        Dot11Mac dot11mac;
        
        WlanPacket();
        WlanPacket(RawData * packet);
        ~WlanPacket();

        void printAttr();
};