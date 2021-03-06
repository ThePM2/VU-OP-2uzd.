#include "File.h"
#include <fstream>

using std::string;
using std::cout;
using std::endl;
using std::istringstream;
using std::ifstream;

void nuskaitytiDuomenysIsFailo(string path, std::vector<mokinioInfo> &mokInfo){
  ifstream file;
  file.open(path);

  if(!file){
    cout << "Nepavyko atidaryti failo." << endl;
    exit(1);
  }

  string line;
  getline(file, line);
  while(getline(file, line)){
    mokinioInfo info;

    istringstream iss(line);
    iss >> info.pavarde >> info.vardas;

    int pazymis;
    while(iss >> pazymis){
        try{
          info.pazymiai.push_back(pazymis);
        }catch (std::exception& error) {
        cout << "Klaida nuskaitant faila 'kursiokai.txt': " << error.what() << endl;
        }
    }
    try{
    info.pazymiai.pop_back();
    info.egzaminas = pazymis;
    }catch (std::exception& error) {
        cout << "Klaida nuskaitant faila 'kursiokai.txt': " << error.what() << endl;
    }
    mokInfo.push_back(info);
  }

  file.close();
}

bool arYraFailas(string path) {
  ifstream file(path);
  return file.good();
}
