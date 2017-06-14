#pragma once
#include <iostream>
#include <fstream>
#include <vector>

void fromFile(std::ifstream & path, std::vector<std::vector<double>> & dataArray, std::ofstream & test1)
{
	

	// Wektor wektorów, przechowujący dane z pliku, sposób wypełnienia opisany niżej
	//std::vector<std::vector<double>> dataArray;
	dataArray.resize(4);
	// Zmienna pomocnicza używana w zapisywaniu danych
	int counter = 0;
	// Zmienna przechowująca przepisywane dane
	double a;

	while (dataFile >> a)
	{
		// Zypełnianie wektorów danych na zasadzie: wektor 0: wartości x, wektor 1: wartości y, wektor 2: wartości z, wektor 3: wartości f(x, y, z)
		dataArray[counter % 4].push_back(a);
		counter++;
	}

	getchar();

	// Zwraca wektor wektorów dataArray, jeśli będzie trzeba (np. dataArray będzie polem jakiejś klasy), można przerobić na void metodę klasy
	return dataArray;
}
