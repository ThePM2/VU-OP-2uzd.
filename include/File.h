#ifndef FILE_H
#define FILE_H

#include <fstream>  // std::ifstream
#include <iostream>
#include <sstream>  // std::stringstream
#include <string>
#include <vector>
#include "Structai.h"

void nuskaitytiDuomenysIsFailo(std::string path, std::vector<mokinioInfo> &mokInfo);
bool arYraFailas(std::string path);

#endif // FILE_H
