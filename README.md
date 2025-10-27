## Trumpas aprašymas: ##
Programa skirta studentų duomenų tvarkymui: 
 -  *įvedimui rankiniu būdu,* 
 -  *generavimui,* 
 -  *nuskaitymui iš failų.* 
 -  *galimybė pasirinkti, kokį konteinerio tipą naudoti.*

Kodas skaičiuoja kiekvieno studento **vidurkį** ir **medianą**, rūšiuoja studentus pagal vartotojo pasirinktą kriterijų (**vardą, pavardę arba vidurkį**), padalija juos į dvi grupes – **vargsiukus** ir **galvočius** – ir išsaugo rezultatus į atskirus failus.

## Funkcijos: ##
 - **_ivesk()_** – įveda studentą rankiniu būdu.
 - **_generuokStudenta()_** – sugeneruoja atsitiktinį studentą.
 - **_iveskIsFailo()_** – perskaito vieną studentą iš failo.
 - **_skaitytiIsFailo()_** – perskaito visą failą su studentais.
 - **_skaiciuotiMediana()_** – skaičiuoja studento medianą.
 - **_SkaiciaiSuKableliu()_** – formatuoja skaičius su dviem dešimtainėmis.
 - **_rikiuotiIrSukurtGrupe()_** – rūšiuoja studentus pagal vartotojo pasirinktą kriterijų ir padalija į grupes (vargsiukai / galvociai).
 - **_spausdintiIFaila()_** – įrašo rezultatus į failą.
 - **_formatuoti()_** – pagalbinė funkcija lentelės spausdinimui.

## Testavimai: ##
### Konteinerio tipas – _vector_ ###
**1 000 įrašų failas:**
- Failo nuskaitymas, duomenų rūšiavimas, padalijimas į dvi grupes ir įrašymas į failus užtruko *~0.03 sekundės*.

**10 000 įrašų failas:**
- Failo nuskaitymas, duomenų rūšiavimas, padalijimas į dvi grupes ir įrašymas į failus užtruko *~0.06 sekundės*.

**100 000 įrašų failas:**
- Failo nuskaitymas užtruko *0.26 sekundės*,
- Duomenų rūšiavimas, padalijimas į dvi grupes (1 strategija) užtruko *0.18 sekundės*,
- Duomenų rūšiavimas, padalijimas į dvi grupes (2 strategija) užtruko * sekundės*,
- Duomenų rūšiavimas, padalijimas į dvi grupes (3 strategija) užtruko * sekundės*,
- Įrašymas į failus užtruko *0.08 sekundės*.

**1 000 000 įrašų failas:**
- Failo nuskaitymas užtruko *2.4 sekundės*,
- Duomenų rūšiavimas, padalijimas į dvi grupes (1 strategija) užtruko *2.16 sekundės*,
- Duomenų rūšiavimas, padalijimas į dvi grupes (2 strategija) užtruko * sekundės*,
- Duomenų rūšiavimas, padalijimas į dvi grupes (3 strategija) užtruko *1.96 sekundės*,
- Įrašymas į failus užtruko *0.7 sekundės*.

**10 000 000 įrašų failas:**
- Failo nuskaitymas užtruko *26.4 sekundės*,
- Duomenų rūšiavimas, padalijimas į dvi grupes (1 strategija) užtruko *28.7 sekundės*,
- Duomenų rūšiavimas, padalijimas į dvi grupes (2 strategija) užtruko * sekundės*,
- Duomenų rūšiavimas, padalijimas į dvi grupes (3 strategija) užtruko * sekundės*,
- Įrašymas į failus užtruko *7.9 sekundės*.

### Konteinerio tipas – _list_ ###
**1 000 įrašų failas:**
- Failo nuskaitymas, duomenų rūšiavimas, padalijimas į dvi grupes ir įrašymas į failus užtruko *~0.03 sekundės*.

**10 000 įrašų failas:**
- Failo nuskaitymas, duomenų rūšiavimas, padalijimas į dvi grupes ir įrašymas į failus užtruko *~0.07 sekundės*.

**100 000 įrašų failas:**
- Failo nuskaitymas užtruko *0.34 sekundės*,
- Duomenų rūšiavimas, padalijimas į dvi grupes (1 strategija) užtruko *0.2 sekundės*,
- Duomenų rūšiavimas, padalijimas į dvi grupes (2 strategija) užtruko * sekundės*,
- Duomenų rūšiavimas, padalijimas į dvi grupes (3 strategija) užtruko * sekundės*,
- Įrašymas į failus užtruko *0.07 sekundės*.

**1 000 000 įrašų failas:**
- Failo nuskaitymas užtruko *3.33 sekundės*,
- Duomenų rūšiavimas, padalijimas į dvi grupes (1 strategija) užtruko *2.23 sekundės*,
- Duomenų rūšiavimas, padalijimas į dvi grupes (2 strategija) užtruko * sekundės*,
- Duomenų rūšiavimas, padalijimas į dvi grupes (3 strategija) užtruko * sekundės*,
- Įrašymas į failus užtruko *0.7 sekundės*.

**10 000 000 įrašų failas:**
- Failo nuskaitymas užtruko *34.8 sekundės*,
- Duomenų rūšiavimas, padalijimas į dvi grupes (1 strategija) užtruko *161 sekundės*,
- Duomenų rūšiavimas, padalijimas į dvi grupes (2 strategija) užtruko * sekundės*,
- Duomenų rūšiavimas, padalijimas į dvi grupes (3 strategija) užtruko * sekundės*,
- Įrašymas į failus užtruko *12.5 sekundės*.
    
## Sistemos parametrai: ##

- **CPU:**  Intel Core i5-1135G7 - 4 branduoliai / 8 gijų, 2.4 GHz
- **RAM:**  8 GB
- **SSD:**  500 GB
