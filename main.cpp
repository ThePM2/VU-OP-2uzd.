#include <iostream>
#include <string>
#include <bits/stdc++.h>  // CPP program to find median
#include <sstream>
#include <random>
#include <vector>
#include <sstream>

#include "File.h"
#include "Funkcijos.h"
#include "Structai.h"

using namespace std;

vector<mokinioInfo> nuskaitytiDuomenys(){
    vector<mokinioInfo> mokiniai;
    string path = "kursiokai.txt";
    bool nuskaityti = false;
    if(arYraFailas(path)){
        cout << "Nuskaityti duomenys is failo 'kursiokai.txt' ar ivedinesite duomenys ranka?" <<endl;
        cout << "Galimi variantai: 'nuskaityti' (nuskaityti is failo 'kursiokai.txt' / 'ivesti' (ivesti duomenys ranka): " <<endl;
        string input = "";
        cin >> input;
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        while(input != "nuskaityti" && input != "ivesti"){
            cout << "Galimi variantai yra arba 'nuskaityti', arba 'ivesti', bandykite dar karta." << endl;
            cout << "Nuskaityti duomenys is failo 'kursiokai.txt' ar ivedinesite duomenys ranka?" << endl;
            cout << "Galimi variantai: ('nuskaityti' / 'ivesti'): " << endl;
            cin >> input;
            transform(input.begin(), input.end(), input.begin(), ::tolower);
        }
        if(input == "nuskaityti") nuskaityti = true;
    }
    if(nuskaityti){
        nuskaitytiDuomenysIsFailo(path,mokiniai);
    }else{
        int mokiniuSk;
        cout << "Iveskite skaiciu, nurodanti kieki mokiniu ties kuriais bus pildomi duomenys: ";
        cin >> mokiniuSk;
        while(cin.fail()) {
            cout << "Galima ivesti tik pilna skaiciu, bandykite dar karta." << endl << endl;
            cout << "Iveskite skaiciu, nurodanti kieki mokiniu ties kuriaiss bus pildomi duomenys: ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> mokiniuSk;
        }


        for(int i = 0; i < mokiniuSk; i++){
            mokinioInfo mokinys;
            cout << endl << "Iveskite " << i+1 << " mokinio Varda: ";
            cin >> mokinys.vardas;
            while(check_number(mokinys.vardas)){
                cout << "Vardas turi buti sudarytas is raidziu, bandykite dar karta." << endl << endl;
                cout << "Iveskite " << i+1 << " mokinio Varda: ";
                cin >> mokinys.vardas;
            }
            while(cin.fail()) {
                cout << "Vardas turi buti sudarytas is raidziu, bandykite dar karta." << endl << endl;
                cout << "Iveskite " << i+1 << " mokinio Varda: ";
                cin.clear();
                cin.ignore(256,'\n');
                cin >> mokinys.vardas;
            }
            cout << endl << "Iveskite " << i+1 << " mokinio Pavarde: ";
            cin >> mokinys.pavarde;
            while(check_number(mokinys.pavarde)){
                cout << "Pavarde turi buti sudaryta is raidziu, bandykite dar karta." << endl << endl;
                cout << "Iveskite " << i+1 << " mokinio Pavarde: ";
                cin >> mokinys.pavarde;
            }
            while(cin.fail()) {
                cout << "Pavarde turi buti sudaryta is raidziu, bandykite dar karta." << endl << endl;
                cout << "Iveskite " << i+1 << " mokinio Pavarde: ";
                cin.clear();
                cin.ignore(256,'\n');
                cin >> mokinys.pavarde;
            }
            bool pazSkZinomas = false;

            cout << "Ar pazymiu skaicius yra zinomas? (taip/ne): ";
            string input = "";
            cin >> input;
            transform(input.begin(), input.end(), input.begin(), ::tolower);
            while(input != "taip" && input != "ne"){
                cout << "Galimi variantai yra arba 'taip', arba 'ne', bandykite dar karta." << endl;
                cout << "Ar pazymiu skaicius yra zinomas? (taip/ne): ";
                cin >> input;
                transform(input.begin(), input.end(), input.begin(), ::tolower);
            }
            if(input == "taip") pazSkZinomas = true;
            double vidurkis = 0;
            bool generuoti = false;
            if(pazSkZinomas){
                cout << endl << "Iveskite [" << i+1 << "] mokinio pazymiu kieki: ";
                cin >> mokinys.kiekPaz;
                while(cin.fail()) {
                    cout << "Galima ivesti tik pilna kieki, bandykite dar karta." << endl << endl;
                    cout << "Iveskite [" << i+1 << "] mokinio pazymiu kieki: ";
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >> mokinys.kiekPaz;
                }
                for(int j = 0; j < mokinys.kiekPaz; j++){
                    cout << endl << "Iveskite [" << j+1 << "] pazymi: ";
                    int paz;
                    cin >> paz;
                    while(cin.fail()) {
                        cout << "Galima ivesti tik pilna skaiciu, bandykite dar karta." << endl << endl;
                        cout << "Iveskite [" << j+1 << "] pazymi: ";
                        cin.clear();
                        cin.ignore(256,'\n');
                        cin >> paz;
                    }
                    while(paz > 10 || paz < 1){
                        cout << "Galima ivesti tik skaicius ne mazesnius uz 1 ir ne didesnius uz 10 (1-10 intervale). Bandykite dar karta." << endl << endl;
                        cout << "Iveskite [" << j+1 << "] pazymi: ";
                        cin >> paz;
                        while(cin.fail()) {
                            cout << "Galima ivesti tik pilna skaiciu, bandykite dar karta." << endl << endl;
                            cout << "Iveskite [" << j+1 << "] pazymi: ";
                            cin.clear();
                            cin.ignore(256,'\n');
                            cin >> paz;
                        }
                    }
                    mokinys.pazymiai.push_back(paz);
                    vidurkis += paz;
                }
            }else{

                cout << "Sugeneruoti atsitiktinius pazymius bei egzamino bala? (Kitu atveju, reikes ivesti balus) (taip/ne): ";

                cin >> input;
                transform(input.begin(), input.end(), input.begin(), ::tolower);
                while(input != "taip" && input != "ne"){
                    cout << "Galimi variantai yra arba 'taip', arba 'ne', bandykite dar karta." << endl;
                    cout << "Sugeneruoti atsitiktinius pazymius bei egzamino bala? (Kitu atveju, reikes ivesti balus) (taip/ne): ";
                    cin >> input;
                    transform(input.begin(), input.end(), input.begin(), ::tolower);
                }
                if(input == "taip") generuoti = true;
                if(generuoti){
                    srand(time(NULL));
                    mokinys.kiekPaz = generuotiSveikaSkaiciu(0,10);
                    cout << "Sugeneruoti " << mokinys.kiekPaz << " atsitiktiniai pazymiai: [";
                    for(int j = 0; j < mokinys.kiekPaz; j++){
                        int paz = generuotiSveikaSkaiciu(1,10);
                        mokinys.pazymiai.push_back(paz);
                        if(j != mokinys.kiekPaz-1)
                        cout << mokinys.pazymiai[j] << ", ";
                        else cout << mokinys.pazymiai[j] << "]" << endl;
                        vidurkis+=paz;
                    }

                    mokinys.egzaminas = generuotiSveikaSkaiciu(1,10);
                    cout << "Sugeneruotas atstitiktinis egzamino balas: " << mokinys.egzaminas << endl;
                    mokinys.vidurkis = vidurkis / mokinys.kiekPaz;

                }else{
                    vidurkis = 0;
                    cout << endl;
                    while(true){
                        int paz;
                        cout << "Iveskite [" << i+1 << "] mokinio [" << mokinys.pazymiai.size()+1 << "] pazymi (Jei tai buvo paskutinis pazimys, iveskite '-1'): ";
                        cin >> paz;
                        while(cin.fail()) {
                            cout << "Galima ivesti tik pilna skaiciu, bandykite dar karta." << endl << endl;
                            cout << "Iveskite [" << i+1 << "] mokinio [" << mokinys.pazymiai.size()+1 << "] pazymi (Jei tai buvo paskutinis pazimys, iveskite '-1'): ";
                            cin.clear();
                            cin.ignore(256,'\n');
                            cin >> paz;
                        }
                        while(paz > 10 || (paz < 1 && paz != -1)){
                            cout << "Galima ivesti tik skaicius ne mazesnius uz 1 ir ne didesnius uz 10 (1-10 intervale). Bandykite dar karta." << endl << endl;
                            cout << "Iveskite [" << i+1 << "] mokinio [" << mokinys.pazymiai.size()+1 << "] pazymi (Jei tai buvo paskutinis pazimys, iveskite '-1'): ";
                            cin >> paz;
                            while(cin.fail()) {
                                cout << "Galima ivesti tik pilna skaiciu, bandykite dar karta." << endl << endl;
                                cout << "Iveskite [" << i+1 << "] mokinio [" << mokinys.pazymiai.size()+1 << "] pazymi (Jei tai buvo paskutinis pazimys, iveskite '-1'): ";
                                cin.clear();
                                cin.ignore(256,'\n');
                                cin >> paz;
                            }
                        }
                        mokinys.pazymiai.push_back(paz);
                        if(paz == -1)
                            break;
                        vidurkis += paz;
                    }
                    mokinys.kiekPaz = mokinys.pazymiai.size();
                }
            }
        mokinys.vidurkis = vidurkis / mokinys.kiekPaz;

        if(!generuoti){
            cout << endl << "Iveskite egzamino bala: ";
            cin >> mokinys.egzaminas;
            while(cin.fail()) {
                cout << "Galima ivesti tik pilna skaiciu, bandykite dar karta." << endl << endl;
                cout << "Iveskite egzamino bala: ";
                cin.clear();
                cin.ignore(256,'\n');
                cin >> mokinys.egzaminas;
            }
            while(mokinys.egzaminas > 10 || mokinys.egzaminas < 1){
                cout << "Galima ivesti tik skaicius ne mazesnius uz 1 ir ne didesnius uz 10 (1-10 intervale). Bandykite dar karta." << endl << endl;
                cout << "Iveskite egzamino bala: ";
                cin >> mokinys.egzaminas;
                while(cin.fail()) {
                    cout << "Galima ivesti tik pilna skaiciu, bandykite dar karta." << endl << endl;
                    cout << "Iveskite egzamino bala: ";
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >> mokinys.egzaminas;
                }
            }
        }

        mokiniai.push_back(mokinys);
    }
  }

  for(int i = 0; i < mokiniai.size(); i++){
    suskaiciuotiPazymius(&mokiniai[i]);
  }

return mokiniai;
}

int main(){
    vector<mokinioInfo> mokiniai = nuskaitytiDuomenys();
    atspauzdintiRez(mokiniai);


    return 0;
}
