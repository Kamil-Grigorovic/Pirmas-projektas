## Trumpas aprašymas:
Programa skirta studentų duomenų tvarkymui:
 - *įvedimui rankiniu būdu*,
 - *generavimui*,
 - *nuskaitymui iš failų*.

Kodas skaičiuoja kiekvieno studento vidurkį ir medianą, rūšiuoja studentus pagal vartotojo pasirinktą kriterijų (vardą, pavardę arba vidurkį), padalija juos į dvi grupes – vargsiukus ir galvočius – ir išsaugo rezultatus į atskirus failus.

## Funkcijos:
- **_ivesk()_**  – įveda studentą rankiniu būdu.
- **_generuokStudenta()_** – sugeneruoja atsitiktinį studentą.
- **_iveskIsFailo()_** – perskaito vieną studentą iš failo.
- **_skaitytiIsFailo()_** – perskaito visą failą su studentais.
- **_skaiciuotiMediana()_** – skaičiuoja studento medianą.
- **_SkaiciaiSuKableliu()_** – formatuoja skaičius su dviem dešimtainėmis.
- **_rikiuotiIrSukurtGrupe()_** – rūšiuoja studentus pagal vartotojo pasirinktą kriterijų ir padalija į grupes (vargsiukai / galvociai).
- **_spausdintiIFaila()_** – įrašo rezultatus į failą.
- **_formatuoti()_** – pagalbinė funkcija lentelės spausdinimui.
## Testavimai:
**1 000 įrašų failas:**
- Failo nuskaitymas, duomenų rūšiavimas, padalijimas į dvi grupes ir įrašymas į failus užtruko ~0.05 sekundės.

**10 000 įrašų failas:**
- Failo nuskaitymas, duomenų rūšiavimas, padalijimas į dvi grupes ir įrašymas į failus užtruko ~0.1 sekundės.

**100 000 įrašų failas:**
- Failo nuskaitymas užtruko 0.25 sekundės,
- Duomenų rūšiavimas, padalijimas į dvi grupes užtruko 0.15 sekundės,
- Įrašymas į failus užtruko 0.08 sekundės.

**1 000 000 įrašų failas:**
- Failo nuskaitymas užtruko 2.4 sekundės,
- Duomenų rūšiavimas, padalijimas į dvi grupes užtruko 1.9 sekundės,
- Įrašymas į failus užtruko 1.1 sekundės.

**10 000 000 įrašų failas:**
- Failo nuskaitymas užtruko 25 sekundės,
- Duomenų rūšiavimas, padalijimas į dvi grupes užtruko 28.9 sekundės,
- Įrašymas į failus užtruko 8 sekundės.
