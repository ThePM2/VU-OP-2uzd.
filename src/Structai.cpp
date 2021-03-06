#include "Structai.h"
#include <string>
#include <vector>

#include "Funkcijos.h"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::transform;
using std::endl;

vector<int> ilgiausiasPilnasVardas(vector<mokinioInfo> info){
    vector<int> ilgiausias;
    ilgiausias.push_back(0); ilgiausias.push_back(0);

    for(int i = 0; i < info.size(); i++){
        if(info[i].vardas.length() > ilgiausias[0]) ilgiausias[0] = info[i].vardas.length();
        if(info[i].pavarde.length() > ilgiausias[1]) ilgiausias[1] = info[i].pavarde.length();

    }
return ilgiausias;
}

void atspauzdintiRez(vector<mokinioInfo> mokInfo){
    isrikiuotiPagalPavarde(mokInfo);
    int mokSkaicius = mokInfo.size();
    vector<int> ilgiai = ilgiausiasPilnasVardas(mokInfo);
    int pirmasTarpas = ilgiai[1] > string("Pavarde").length() ? ilgiai[1] + 5 : 12;
    int antrasTarpas = ilgiai[0] > string("Vardas").length() ? ilgiai[0] + 5 : 11;

    cout << "Pasirinkite galutinio balo skaiciavimo buda - su vidurkiu ar su mediana (Galimi ivedimai: 'vidurkis' / 'mediana' / 'abu'): ";
    string value = "";
    cin >> value;
    transform(value.begin(), value.end(), value.begin(), ::tolower);
    while(value != "mediana" && value != "vidurkis" && value != "abu"){
        cout << "Galimi variantai yra arba 'vidurkis', arba 'mediana', arba 'abu'. Bandykite dar karta." << endl;
        cout << "Pasirinkite galutinio balo skaiciavimo buda - su vidurkiu ar su mediana (Galimi ivedimai: 'vidurkis' / 'mediana' / 'abu'): ";
        cin >> value;
        transform(value.begin(), value.end(), value.begin(), ::tolower);
    }

    string pirmaEil = "Pavarde" + string(pirmasTarpas-7, ' ')
     + "Vardas" + string(antrasTarpas-6, ' ') + ((value == "abu") ? "Galutinis (Vid.) / Galutinis (Med.)" : value == "vidurkis" ? "Galutinis (Vid.)" : "Galutinis (Med.)");
    cout << endl << pirmaEil << endl << string(pirmaEil.length(), '-') << endl;
    for(int i = 0; i < mokSkaicius; i++){
        cout << mokInfo[i].pavarde << string(pirmasTarpas-mokInfo[i].pavarde.length(), ' ') << mokInfo[i].vardas << string(antrasTarpas-mokInfo[i].vardas.length(), ' ');
        if(value == "vidurkis" || value == "abu"){
            cout << toString(roundSk(mokInfo[i].galutinis));
            if(value == "abu"){
                string value = toString(roundSk(mokInfo[i].galutinis));
                //cout << endl << "Value: " << value << "   ,lenght: " << value.length() << endl;
                int kiekTarpu = ((value.length() == 3) ? 16 : value.length() == 2 ? 17 :18);
                cout << (string(kiekTarpu, ' '))<< mokInfo[i].galutinis2 << endl;
            } else cout << endl;
        }else cout << toString(roundSk(mokInfo[i].galutinis2)) << endl;
    }
}

void suskaiciuotiPazymius(mokinioInfo *mokinys){
    mokinys->galutinis =  mokinys->vidurkis >= 0 ? 0.4*mokinys->vidurkis + 0.6*mokinys->egzaminas : 0.6*mokinys->egzaminas;
    if(mokinys->kiekPaz > 1) mokinys->mediana = findMedian(mokinys->pazymiai);
    else if(mokinys->kiekPaz == 1)mokinys->mediana = mokinys->pazymiai[0];
    else mokinys->mediana = 0;
    mokinys->galutinis2 = 0.4*mokinys->mediana + 0.6*mokinys->egzaminas;
}

bool palygintiPavardes(mokinioInfo mokinys1, mokinioInfo mokinys2){
    return mokinys1.pavarde < mokinys2.pavarde;
}


void isrikiuotiPagalPavarde(vector<mokinioInfo> &mokInfo){
    sort(mokInfo.begin(), mokInfo.end(), palygintiPavardes);
}


