#ifndef RAND_H
#define RAND_H

#include "class.h"
#include "vector"
#include <string>
#include <random>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>

string randname();
void randphone(int* phone);
string randid();
void randinput(queue cq, queue sq);

#endif