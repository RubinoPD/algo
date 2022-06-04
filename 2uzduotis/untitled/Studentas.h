//
// Created by Robert Kaskur on 2022-06-04.
//

#ifndef UNTITLED_STUDENTAS_H
#define UNTITLED_STUDENTAS_H
#include <iostream>

using namespace std;

class Studentas {

private:
    string vardas;
    int amzius;
    int kursas;
    double vidurkis;

public:
    Studentas(const string &vardas, int amzius, int kursas, double vidurkis);

    const string &getVardas() const;

    int getAmzius() const;

    int getKursas() const;

    double getVidurkis() const;
};


#endif //UNTITLED_STUDENTAS_H
