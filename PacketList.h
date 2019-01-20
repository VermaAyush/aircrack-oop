#pragma once

#include "pch.h"
#include "PacketType.h"

class PacketList
{
    public:
        PacketList();
        ~PacketList();

        std::list<WlanPacket> pktList;
        std::list<BeaconPacket> BeaconList;
        
};