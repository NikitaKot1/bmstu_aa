#pragma once


#include "matr.h"

typedef struct {
    
    //time
    time_t start_generate;
    time_t end_generate;
    time_t start_mul;
    time_t end_mul;
    time_t start_write;
    time_t end_write;

    // data
    matr m1;
    matr m2;
} pipeTask;

typedef struct {
    vector<*pipeTask> queue;
} queue;

void Enqueue(*queue qu, pipeTask* t);
pipeTask* Dequeue(*queue qu);