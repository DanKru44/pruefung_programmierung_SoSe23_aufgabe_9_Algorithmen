# Prüfung SoSe 2023 Aufgabe 9
In diesem Repo befindet sich die Bearbeitung des Programmierteils der Aufgabe 9 aus der Modulprüfung Programmierung im SoSe 2023.

Diese Programme beinhalten die Implementierten Algorithmen der Aufgabe 9.
In diesen sollen Oszilloskop Kurven ausgewertet werden.
Dies soll einmal die Bestimmung der Samplingrate für eine Oszilloskop Kurve mit bekannter Frequenz geschehen und in dem nächsten Fall die Frequenz bei bekannter Samplingrate. 

Das Programm main_1.c ist dafür die Datei 50Hz_sinus.csv zu verarbeiten und aus dieser dessen Messwerte die Samplingrate zu ermitteln.

Das Programm main_2.c verwendet hingegen die ermittelte Samplingrate um die Frequenz der Messreihe aus der Datei sinus_unknown.csv zu ermitteln.

## Kompilation 
Das Programm kann einfach mit einem beliebigen Compiler kompiliert werden. Ich habe dafür gcc verwendet.

Beispiel :
```
gcc main.c -o main.elf
```

## Ausführung 
Das Programm kann einfach mit dem Befehl zum Ausführen von Programmen gestartet werden. Bei der Ausführung muss allerdings die entsprechende .csv Datei mit übergeben werden die sich in diesem Repo befinden.

Beispiel für Ubuntu/WSL:
```
./main.elf 50Hz_sinus.csv
```
