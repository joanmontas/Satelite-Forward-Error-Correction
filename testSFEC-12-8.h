// Copyright Joan Montas
// All rights reserved.
// License under GNU General Public License v3.0

#ifndef TESTSFEC_12_8_H
#define TESTSFEC_12_8_H
#include <stdio.h>
#include <CUnit/Basic.h>
#include "SFEC.h"

void testBit12Mutations();
void testBit12Encode8BitsBit12DecodeToStructBit8();
void testBit12EncodeUnsignedCharArrayBit12DecodeToStructBit8();
void testBit12FixMutationArray();
void testBit12FixMutationUint8();
void testBit12Stringify();
void testBit12ToUint16();

#endif
