#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <fstream>  // std::ifstream
#include <iostream>
#include <sstream>  // std::stringstream
#include <string>
#include <vector>
#include <algorithm>  // std::sort

double roundSk(double value);
bool check_number(std::string str);
double findMedian(std::vector<int> &array);
int generuotiSveikaSkaiciu(int maziausia, int didziausia);
std::string toString(double value);

#endif // FUNKCIJOS_H
