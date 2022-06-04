#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Studentas.h"

using namespace std;

vector<int>tiesinePaieska(const vector<Studentas>& list, int keyword);
//int dvejetainePaieska(vector<Studentas>& list,int left, int right, int keyword);


int main() {

    vector<int>testList{25,45,55,65,56,55,54,52,89};
    vector<Studentas>studentai {
        Studentas("Robertas", 27, 1, 7.8),
        Studentas("Margarita", 33, 3, 8.8),
        Studentas("Rimante", 27, 2, 9.5),
        Studentas("Domantas", 29, 4, 6.7),
        Studentas("Pranas", 55, 1, 5.6),
        Studentas("Stasys", 36, 3, 10),
        Studentas("Mingaile", 22, 2, 9)
    };

    int stop = 1;

    while(stop != 0) {

        cout << "<--------------MENIU---------------->" << endl;
        cout << "1. Pagal raktini zodi (varda) Tiesine paieska." << endl;
        cout << "2. Pagal raktini zodi (varda) Dvejetaine paieska." << endl;
        cout << "0. Uzbaigti darba" << endl;
        cout << "<----------------------------------->" << endl;

        cout << "Pasirinkite opcija: ";
        cin >> stop;

        switch (stop) {

            case 1: {
                cout << "Nurodykite ko ieskote: ";
                int keyword;
                cin >> keyword;

                vector<int> foundResults = tiesinePaieska(studentai, keyword);

                cout << "-------------------Pagal raktini zodi TIESINE PAIESKA---------------------------" << endl;

                if(!foundResults.empty()) {
                    for(int it: foundResults) {
                        cout << "Sekmingai rastas studentas! Jo indeksas: " << it << ", vardas: " << studentai[it].getVardas() << endl;
                    }
                } else {
                    cout << "Deja nepavyko rasti studento siame kurse: " << keyword << endl;
                }
                cout << "----------------------------------------------------------------" << endl;
                break;
            }
//            case 2:{
//                cout << "Nurodykite ko ieskote: ";
//                int keyword;
//                cin >> keyword;
//
//                int index = dvejetainePaieska(studentai, 0, (int)studentai.size() - 1, keyword);
//
//                cout << "-------------------Pagal raktini zodi DVEJETAINE PAIESKA---------------------------" << endl;
//
//                if(index != -1) {
//                    cout << "Sekmingai rasta, pozicija: " << index << ", rastas: " << studentai[index].getVardas() << endl;
//                } else {
//                    cout << "Deja nepavyko rasti raktinio zodzio: " << keyword << endl;
//                }
//                cout << "----------------------------------------------------------------" << endl;
//                break;
//            }
            default:
                cout << "Nera tokio pasirinkimo" << endl;
                break;

        }
    }
    
    return 0;
}

//vector<int>testList{25,45,55,65,56,55,54,52,89};

vector<int>tiesinePaieska(const vector<Studentas>& list, int keyword){

    vector<int>tempList;

    for (int i = 0; i < list.size(); ++i) {

        if (keyword == list[i].getKursas()) {
            tempList.emplace_back(i);
        }
    }
    return tempList;
}

int dvejetainePaieska(vector<Studentas>& list,int left, int right, int keyword){

    sort(list.begin()->getKursas(), list.end()->getKursas()); // surusiavimas.

    // left = 0
    // right = 7
    // midElement = 0 + (8 - 0) / 2 = 4

    while(left <= right) {

        int midElement = left + (right - left) / 2;

        if(list[midElement].getKursas() == keyword) {
            return midElement;
        }

        if(list[midElement].getKursas() < keyword) {
            left = midElement + 1; // jeigu einam i desine
        } else {
            right = midElement - 1; // jeigu einam i kaire
        }

    }
    return -1;
}