#include <iostream>
#include <string>
#include <fstream>
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;

int main() {
    int n;
    cout << "Iveskite studentu kieki: ";
    cin >> n;

    // Sukuriame failo pavadinimą
    string failoVardas = "studentai_" + std::to_string(n) + ".txt";
    ofstream fout(failoVardas);
    if (!fout.is_open()) {
        cout << "Nepavyko sukurti failo!" << endl;
        return 1;
    }

    // Atsitiktinių skaičių generatorius (1–10)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 10);

    // Antraštė
    fout << "Vardas Pavarde ";
    for (int i = 1; i <= 9; i++) fout << "ND" << i << " ";
    fout << "Egzaminas" << endl;

    // Studentų generavimas
    for (int i = 1; i <= n; i++) {
        string vardas = "Vardas" + std::to_string(i);
        string pavarde = "Pavarde" + std::to_string(i);

        fout << vardas << " " << pavarde << " ";

        // 9 namų darbų pažymiai (tikrai atsitiktiniai)
        for (int j = 1; j <= 9; j++) {
            fout << dist(gen) << " ";
        }

        // Egzamino pažymys
        fout << dist(gen) << endl;
    }

    fout.close();
    cout << "Failas '" << failoVardas << "' sugeneruotas sekmingai." << endl;

    return 0;
}

