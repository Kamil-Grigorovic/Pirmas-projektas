#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <type_traits>

using namespace std;

template <typename T>
struct Studentas {
    using paz_type = T;
    string vard;
    string pav;
    T paz;
    int egzas;
    float rez;
    float mediana;
};

// Funkciju deklaracijos
template <typename T>
Studentas<T> ivesk();
template <typename T>
Studentas<T> iveskIsFailo(const string &line);
template <typename T>
float skaiciuotiMediana(const T &pazymiai);
template <typename T>
T skaitytiIsFailo(const string &failoPavadinimas);
template <typename T>
Studentas<T> generuokStudenta();
template <typename T>
void rikiuotiIrSukurtGrupe(const T &visiStudentai, T &vargsiukai, T &galvociai, const string &kriterijus);
template <typename T>
void rikiuotiIrSukurtGrupe_2(T &visiStudentai, T &vargsiukai, const string &kriterijus);
template <typename T>
void rikiuotiIrSukurtGrupe_3(T &visiStudentai, T &vargsiukai, const string &kriterijus);
template <typename T>
void spausdintiIFaila(const T &grupe, const string &failoVardas);
template <typename Container, typename Comparator>
void rikiuoti(Container &temp, Comparator comp);

string formatuoti(string s, int plotis);
string SkaiciaiSuKableliu(float value);