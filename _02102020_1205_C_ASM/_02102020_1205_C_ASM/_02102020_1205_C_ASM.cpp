﻿// _02102020_1205_C_ASM.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void Test_1()
{
    int x = 10;
    int y = 11;
    //<[Адрес в памяти;значение в пямяти]>
    std::cout << "<&x;x>=<"<< &x <<";"<< x <<">"<< std::endl;
    std::cout << "<&y;y>=<" << &y << ";" << y << ">" << std::endl;
    //Указатель, как он рабтает
    int* yy = &y;//Этот код эквивалентен следующей ассемблерной вставке
    __asm 
    {//Получение адреса переменной y
        //...=&y
        lea eax, [y]
        //int* yy = ...
        mov dword ptr[yy], eax
    }
    std::cout << "<&yy;yy>=<" << &yy << ";" << yy << ">" << std::endl;
    _asm
    {
        xor eax, eax
        xor ebx, ebx
        mov         eax, dword ptr[x]
        mov         ecx, dword ptr[yy]
        mov         ebx, dword ptr[ecx]
        mov          dword ptr[x], ebx
        mov          dword ptr[ecx], eax
    }
    std::cout << "<&x;x>=<" << &x << ";" << x << ">" << std::endl;
    std::cout << "<&y;y>=<" << &y << ";" << y << ">" << std::endl;
}
void Test_2()
{
    int x = 10;
    int y = 11;
    std::cout << "<&x;x>=<" << &x << ";" << x << ">" << std::endl;
    std::cout << "<&y;y>=<" << &y << ";" << y << ">" << std::endl;
    _asm
    {
        //Человеческая очистка
        xor eax, eax
        xor ebx, ebx
        //Получение значения x
        mov eax, x
        //Получение указателя
        lea ebx, [y]
        //Обмен значениями
        XCHG eax, [ebx]
        mov x, eax
        //
    }
    std::cout << "<&x;x>=<" << &x << ";" << x << ">" << std::endl;
    std::cout << "<&y;y>=<" << &y << ";" << y << ">" << std::endl;
}
int main()
{
    Test_2();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
