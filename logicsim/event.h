#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
    bool operator()(const Event *E1, const Event *E2)
    {
        return E1->time < E2->time;
    }
} EventLess;
	
#endif
