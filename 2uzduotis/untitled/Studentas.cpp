//
// Created by Robert Kaskur on 2022-06-04.
//

#include "Studentas.h"

Studentas::Studentas(const string &vardas, int amzius, int kursas, double vidurkis) : vardas(vardas), amzius(amzius),
                                                                                      kursas(kursas),
                                                                                      vidurkis(vidurkis) {}

const string &Studentas::getVardas() const {
    return vardas;
}

int Studentas::getAmzius() const {
    return amzius;
}

int Studentas::getKursas() const {
    return kursas;
}

double Studentas::getVidurkis() const {
    return vidurkis;
}
