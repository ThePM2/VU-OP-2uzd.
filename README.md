# VU-OP-2uzd.
# Pažymių galutinio įvertinimo skaičiuoklė

Programa yra skirta apskaičiuoti pažymių galutinį įvertinimą pasinaudojant pasirinkamai vidurkį arba medianą.

## Programos aprašymas

Paleidus programą, konsolėje yra klausiama ar nuskaityti duomenys iš failo "kursiokai.txt", ar įvesti duomenys ranka (Galimi pasirinkimai - 'nuskaityti' / 'ivesti'), jeigu failas neegzistuoja, šis klausimas yra praleidžiamas:
![NuskaitytFail](https://i.postimg.cc/mDPBwTsX/v31.png)

Pasirinkus nuskaityti duomenys iš failo, iš karto pereinama prie rezultato išvesties pasirinkimų (apie tai kiek veliau):
![NuskaitytFail2](https://i.postimg.cc/vZ0JSCXp/v32.png)

Pasirinkus suvesti duomenys ranka, toliau konsolėje yra prašoma vartotojo įvestį skaicių, nurodanti kiekį mokinių ties kuriais bus pildomi duomenys:

![Kiekis](https://i.postimg.cc/c4jP8j78/pirmas.png) 

Įvedus kiekį, prašoma įvestį pirmojo mokinio vardą:

![Vardas](https://i.postimg.cc/3RncrbJN/antras.png) 

Įvedus vardą, prašoma įvestį pirmojo mokinio pavardę:

![Pavardė](https://i.postimg.cc/xTWFdmYv/trecias.png) 

Įvedus pavardę, yra klausiama ar yra žinomas pažymių skaičius, duoti du pasirinkimai - taip arba ne:

![PažSkaičiusKl](https://i.postimg.cc/2ygTVppk/ketvirtas.png) 

Pasirinkus taip prašoma įvesti mokinio pažymių kiekį: 

![PažSkaičius](https://i.postimg.cc/bJhZY3V7/penktas.png) 

Įvedus pažymių kiekį, prašoma kiekvienam pažymiui įvesti po balą: 

![Balai](https://i.postimg.cc/ZKRCq9j5/sestas.png)

Suvedus visus balus, prašoma vartotojo įvesti mokinio egzamino balą:

![EgzBalas](https://i.postimg.cc/hv34mrMP/septintas.png) 

Įvedus egzamino balą, prasideda pakartotinis procesas ties antruoju mokiniu (nebent buvo pasirinkta kad iš viso bus aprašomas tik 1 mokinys):

![Sekantis](https://i.postimg.cc/g2KzqmgT/astuntas.png)

Jeigu pasirinkti pasirinkima ne ties klausimu ar yra žinomas pažymių skaičius, bus paklausta vartotojo ar atsitiktiniu būdu sugeneruoti pažymius bei egzamino balą vartotojui, priešingu atvėju reikės suvesti balus ranka. Pasirinkimai - taip arba ne:

![generavimoKl](https://i.postimg.cc/j2YmFJ5Q/9.png)

Pasirinkus taip - generuoti atsitiktina tvarka pažymius bei egzamino balą, vartotojui bus pranešta kiek pažymių buvo sugeneruota bei kokie jie, taip pat ir koks buvo sugeneruotas egzamino balas:

![sugeneruota](https://i.postimg.cc/YqpyL7m9/10.png)

Toliau būtų tesiama prie sekančio vartotojo, jeigu jis buvo nurodytas.

Pasirinkus ne - ties klausimu ar generuoti atsitiktina tvarka pažymius bei egzamino balą, vartotojui reikės įvesti pažymius ranka, tačiau galės sistemai pranešti, jog baigė įvedinėti pažymius parašes '-1':
![nezinomasKiekis](https://i.postimg.cc/jdFQqYHB/11.png)

Baigius pildyti pažymius ir parašius '-1', vartotojui yra pranešama jog reikia įvestį egzamino balą, po kurio, jeigu tai buvo paskutinis įvedamas mokinys pagal pirmoje eilutėje pranešta kiekį, bus paklausta vartotojo, kokią išvestį, kurį priklausoma galutiniam mokinio balo skaičiavimui jis nori matyti, ar susijusia su vidurkiu, su mediana, ar abi:

![rezKlausimas](https://i.postimg.cc/7LsT9gKd/12.png)

Pasirinkus 'abu', programa parodys galutinius rezultatus ir baigs savo darbą:

![rezKlausimas](https://i.postimg.cc/jS85YRyJ/13.png)

Pavyzdis:
![pavyzdis](https://i.postimg.cc/63CtqK4c/pabaiga.png)

## Programos įdiegimo instrukcija

Atsisiųskite naujausia programos versiją iš [Releases](https://github.com/ThePM2/VU-OP-2uzd./releases) aplanko ir ją importuokite į norima IDE (pavyzdžiui CodeBlocks),


## Programos releasai

* [v0.1](https://github.com/ThePM2/VU-OP-2uzd./releases/tag/0.1) Pradinė programos versija
* [v0.2](https://github.com/ThePM2/VU-OP-2uzd./releases/tag/0.2) Pradinė programos versija
Pridėta:
  *Galimybė nuskaityti duomenys iš failo "kursiokai.txt"
  *Pridėtas numatytas "kursiokai.txt" failas.
Pakeista:
  *Pataisytas galutinio balo skaičiavimas kai pažymių skaičius 0
  *Rezultatų išvedimas yra rūšiuojamas pagal pavardę abecėles tvarka
  *Ištrintas main_cArray.cpp failas.
  *main_Vector.cpp failas pervadintas į main.cpp failą
* [v0.3](https://github.com/ThePM2/VU-OP-2uzd./releases/tag/0.3) Pradinė programos versija
Pridėta:
  *Išimčių exceptions valdymas.
Pakeista:
  *Funkcijos, bei nauji duomenų tipai (struct’ūros) perkelti į antraštinius (angl. header (.h)) failus: File.h ; Funkcijos.h ; Structai.h
