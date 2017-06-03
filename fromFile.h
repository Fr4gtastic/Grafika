#pragma once
#include <iostream>
#include <fstream>

std::vector<std::vector<double>> fromFile(std::string path)
{
    std::fstream dataFile(path, std::ios_base::in);

    // Wektor wektor�w, przechowuj�cy dane z pliku, spos�b wype�nienia opisany ni�ej
    std::vector<std::vector<double>> dataArray;
    // Zmienna pomocnicza u�ywana w zapisywaniu danych
    int counter = 0;
    // Zmienna przechowuj�ca przepisywane dane
    double a;

    while(dataFile >> a)
    {
        // Zype�nianie wektor�w danych na zasadzie: wektor 0: warto�ci x, wektor 1: warto�ci y, wektor 2: warto�ci z, wektor 3: warto�ci f(x, y, z)
        dataArray[counter % 4].push_back(a);
        counter++;
    }

    getchar();

    // Zwraca wektor wektor�w dataArray, je�li b�dzie trzeba (np. dataArray b�dzie polem jakiej� klasy), mo�na przerobi� na void metod� klasy
    return dataArray;
}

