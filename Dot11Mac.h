#pragma once

#include "pch.h"

#include "ieee80211.h"




class Dot11Mac{

    public:
    struct ieee80211_frame * hdr;
    Dot11Mac();
    ~Dot11Mac();

    void printAttr();
};