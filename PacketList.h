#pragma once

#include "pch.h"
#include "PacketType.h"

class PacketList
{
    public:
        PacketList();
        ~PacketList();
        char channel[3];
        std::list<WlanPacket> pktList;
        std::list<BeaconPacket> BeaconList;
        
};