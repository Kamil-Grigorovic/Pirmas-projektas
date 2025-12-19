cd "C:\Users\kamil\OneDrive\Stalinis kompiuteris\cmake"
cmake -G "MinGW Makefiles" .
cmake --build .
if exist src\studentai1000.txt (
    copy src\studentai1000.txt studentai1000.txt
)
if exist src\studentai10000.txt (
    copy src\studentai10000.txt studentai10000.txt
)
if exist src\studentai100000.txt (
    copy src\studentai100000.txt studentai100000.txt
)
if exist src\studentai1000000.txt (
    copy src\studentai1000000.txt studentai1000000.txt
)
if exist src\studentai_10000.txt (
    copy src\studentai1000000.txt studentai1000000.txt
)
Pirmas_Projektas.exe
pause