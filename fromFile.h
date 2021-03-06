#ifndef __FORMFILE_H__
#define __FORMFILE_H__

#include <iostream>
#include <fstream>
#include <vector>

void fromFile(std::ifstream & path, std::vector<std::vector<double> > & dataArray, std::ofstream & test1)
{
//////// Czysci vector jezeli byl wczesniej zapelniony i ustala ilosc w nim zawartych zmiennych
    for(int i=0; i<dataArray.size(); i++)dataArray[i].clear();
    dataArray.clear();
    dataArray.resize(4);
    
    int counter = 0;    // Zmienna pomocnicza uzywana w zapisywaniu danych    
     double a;           // Zmienna przechowujaca przepisywane dane

    test1 << " ... zaczal wpsiywac   "; // uzupelnia log wczytywania // tzra potem usunac
    
///// Uzupelnianie wektorow danych na zasadzie: 
///// wektor 0: wartosci x, wektor 1: wartosci y, wektor 2: wartosci z, wektor 3: wartosci f(x, y, z)
    while(!path.eof())
    {
        path >> a;
        test1 << a << " ";if(counter==3)test1<<std::endl;
       
        dataArray[counter].push_back(a);
        counter=(counter+1)%4;
    }
    getchar();
}

#endif // __FORMFILE_H__

