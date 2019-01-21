#ifndef PCH_H
#define PCH_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <list>
#include <algorithm>

#include "ieee80211.h"

//print hex
u_int16_t printHex(u_int8_t * data, long unsigned int len);
//print binary
void printBins(u_int8_t *data, u_int64_t size);
#endif
