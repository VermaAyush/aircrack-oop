#pragma once

#include "pch.h"

#pragma pack(push,1)

struct ieee80211_radiotap_header {
        u_int8_t        it_version;     /* set to 0 */
        u_int8_t        it_pad;
        u_int16_t       it_len;         /* entire length */
        u_int32_t       it_present;     /* fields present */
};

#pragma pack(pop)
class Radiotap{
    
    public:
        struct ieee80211_radiotap_header * hdr;
        //Body 알아서 추가
        Radiotap();
        ~Radiotap();

        void printAttr();
};