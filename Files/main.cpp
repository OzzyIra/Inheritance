#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
#include<time.h>
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE
#define READ_TO_FILE
void main()
{
    setlocale(LC_ALL, "Russian");
#ifdef WRITE_TO_FILE

    std::ofstream fout; //1)создаем поток:
    fout.open("File.txt", std::ios_base::app);//2)открываем поток, 
                                              //std::ios_base::app - дописать в конец файла
    fout << "HelloWorld" << endl;//3)пишем поток
    time_t now = time(NULL);
    fout << ctime(&now) << endl;
    fout.close();//4)закрываем поток


    system("notepad File.txt");//чтобы файл открывался вместе с консолью
#endif // WRITE_TO_FILE

#ifdef READ_TO_FILE
    //1)Создаем и открываем поток
    std::ifstream fin("File.txt");
    if (fin.is_open())
    {
        //читаем файл
        const int SIZE = 256;
        char buffer[SIZE]{};
        while (!fin.eof())//NOT EndOfFile
        {
           // fin >> buffer;
            fin.getline(buffer, SIZE);
            cout << buffer << endl;
        }
        fin.close();
    }
    else
    {
        std::cerr << "Error: file not found" << endl;
    }
#endif // READ_TO_FILE



}