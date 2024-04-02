// Copyright Joan Montas
// All rights reserved.
// License under GNU General Public License v3.0

#ifndef TESTSFEC_7_3_H
#define TESTSFEC_7_3_H

#include <stdio.h>
#include <CUnit/Basic.h>
#include "SFEC.h"

void testBit7Encode0000();
void testBit7Encode0001();
void testBit7Encode0010();
void testBit7Encode0011();
void testBit7Encode0100();
void testBit7Encode0101();
void testBit7Encode0110();
void testBit7Encode0111();
void testBit7Encode1000();
void testBit7Encode1001();
void testBit7Encode1010();
void testBit7Encode1011();
void testBit7Encode1100();
void testBit7Encode1101();
void testBit7Encode1110();
void testBit7Encode1111();
void testBit7RandomMutation();
void tesBit7ErrorLocation();
void testBit7DecodeToArray();
void testBit7FixMutation();
void testBit7ToUnsigned8();
void testBit7Stringify();
#endif
