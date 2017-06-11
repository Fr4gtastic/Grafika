#ifndef __FORMFILE_H__
#define __FORMFILE_H__

#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::vector<double>> fromFile(std::fstream & path)
{
    //std::fstream dataFile(path, std::ios_base::in); //niepotrzebne wx to załatwia w dialogu

    // Wektor wektorów, przechowuj¹cy dane z pliku, sposób wype³nienia opisany ni¿ej
    std::vector<std::vector<double>> dataArray;
    // Zmienna pomocnicza u¿ywana w zapisywaniu danych
    int counter = 0;
    // Zmienna przechowuj¹ca przepisywane dane
    double a;

    while(path >> a)
    {
        // Zype³nianie wektorów danych na zasadzie: wektor 0: wartoœci x, wektor 1: wartoœci y, wektor 2: wartoœci z, wektor 3: wartoœci f(x, y, z)
        dataArray[counter % 4].push_back(a);
        counter++;
    }

    getchar();

    // Zwraca wektor wektorów dataArray, jeœli bêdzie trzeba (np. dataArray bêdzie polem jakiejœ klasy), mo¿na przerobiæ na void metodê klasy
    return dataArray;
}

#endif // __FORMFILE_H__

