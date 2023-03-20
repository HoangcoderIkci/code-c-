#pragma once
#include "myLitst.h"
void enQueue(ref &Q, ref &T, int k);
bool isEmptyQ(ref Q);
ref deQueue(ref &Q, ref &T);
int deQueueGetKey(ref &Q, ref &T); 