#include "Dot11Mac.h"

Dot11Mac::Dot11Mac(){
    //printf("malloc - Dot11mac\n");
    //hdr = (struct ieee80211_frame *)malloc(sizeof(struct ieee80211_frame));
}

Dot11Mac::~Dot11Mac(){
    //printf("Free - Dot11mac\n");
    //free(hdr);
}

void Dot11Mac::printAttr(){
    /*
    u_int8_t	i_fc[2];
	u_int8_t	i_dur[2];
	u_int8_t	i_addr1[IEEE80211_ADDR_LEN];
	u_int8_t	i_addr2[IEEE80211_ADDR_LEN];
	u_int8_t	i_addr3[IEEE80211_ADDR_LEN];
	u_int8_t	i_seq[2];
    */

    printf("frame control : %02X %02X\n",hdr->i_fc[0],hdr->i_fc[1]);
    printf("addr1 : %02X:%02X:%02X-%02X:%02X:%02X\n",hdr->i_addr1[0],hdr->i_addr1[1],hdr->i_addr1[2],hdr->i_addr1[3],hdr->i_addr1[4],hdr->i_addr1[5]);
    printf("addr2 : %02X:%02X:%02X-%02X:%02X:%02X\n",hdr->i_addr2[0],hdr->i_addr2[1],hdr->i_addr2[2],hdr->i_addr2[3],hdr->i_addr2[4],hdr->i_addr2[5]);
    printf("addr3 : %02X:%02X:%02X-%02X:%02X:%02X\n",hdr->i_addr3[0],hdr->i_addr3[1],hdr->i_addr3[2],hdr->i_addr3[3],hdr->i_addr3[4],hdr->i_addr3[5]);
    
    
}