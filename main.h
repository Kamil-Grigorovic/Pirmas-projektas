#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;

struct Studentas {
    string vard;
    string pav;
    vector<int> paz;
    int egzas;
    float rez;
    float mediana;
};

// Funkciju deklaracijos
Studentas ivesk();
Studentas iveskIsFailo(const string &line);
float skaiciuotiMediana(vector<int> &pazymiai);
string formatuoti(string s, int plotis);
vector<Studentas> skaitytiIsFailo(const string &failoPavadinimas);
Studentas generuokStudenta();
void rikiuotiIrSukurtGrupe(const vector<Studentas> &visiStudentai, vector<Studentas> &vargsiukai, vector<Studentas> &galvociai, const string &kriterijus);
void spausdintiIFaila(const vector<Studentas> &grupe, const string &failoVardas);
string SkaiciaiSuKableliu(float value);
