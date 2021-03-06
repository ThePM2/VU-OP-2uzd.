#ifndef STRUCTAI_H
#define STRUCTAI_H

#include <fstream>  // std::ifstream
#include <iostream>
#include <sstream>  // std::stringstream
#include <string>
#include <vector>

    struct mokinioInfo{
        std::string vardas;
        std::string pavarde;
        int kiekPaz;
        std::vector<int> pazymiai;
        double vidurkis = 0;
        double mediana;
        double galutinis;
        double galutinis2;
        int egzaminas;
    };

    std::vector<int> ilgiausiasPilnasVardas(std::vector<mokinioInfo> info);
    void atspauzdintiRez(std::vector<mokinioInfo> mokInfo);
    void suskaiciuotiPazymius(mokinioInfo *mokinys);
    bool palygintiPavardes(mokinioInfo mokinys1, mokinioInfo mokinys2);
    void isrikiuotiPagalPavarde(std::vector<mokinioInfo> &mokInfo);

#endif // STRUCTAI_H
