#include "Funkcijos.h"
#include <vector>
#include <string>
#include <bits/stdc++.h>  // CPP program to find median
#include <sstream>
#include <random>

double roundSk(double value){
    double finalValue = (int)(value*100 + .5);
    return finalValue / 100;
}

bool check_number(std::string str) {
    for(int i = 0; i < str.length(); i++)
        if (isdigit(str[i])) return true;
  return false;
}

double findMedian(std::vector<int> &array) {
  sort(array.begin(), array.end());

  if (array.size() % 2 != 0)
    return (double)array[array.size() / 2];

  return (double)(array[(array.size() - 1) / 2] + array[array.size() / 2]) / 2.0;
}

int generuotiSveikaSkaiciu(int maziausia, int didziausia) {
  return maziausia + rand() % ((didziausia + 1) - maziausia);
}

std::string toString(double value){
    std::ostringstream strs;
    strs << value;

  return strs.str();
}
