// _02102020_1128_C_ASM.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
////////////////////////////////////////////////////////////////////////////////////
#include<windows.h>
#define __Set_Test if(true)//
#define __Set_Test if(false)
//#define __Set_Test if(true) - на случай тестирования на скорость
//#define __Set_Test if(false) - на случай отладки...
#define __Set_TimeTestX 100000000
#define __Set_TestTimeStart double TickStart = GetTickCount(); for(int i=0;i<__Set_TimeTestX;i++)
#define __Set_TestTimeStop double TickFinish = GetTickCount();std::cout << "_TimeTest=" << TickFinish-TickStart << std::endl;
////////////////////////////////////////////////////////////////////////////////////
/// <summary>Пример программы с асембленрной вставкой. Обмен значениями двух переменных через ASM вставку.</summary>
void Test_1()
{
    __Set_Test std::cout << "Test_1();" << std::endl;
    int x = 10;
    int y = 11;
    __Set_Test std::cout << "<x,y>=" << "<" << x << "," << y << ">" << std::endl;
    __Set_TestTimeStart
    __asm
    {
        //Обнуление регистра на пожарный случай
        xor eax, eax
        xor ebx, ebx
        //Команда пересылки данных. eax = x
        mov eax, dword ptr[x]
        mov ebx, dword ptr[y]
        //Команда пересылки данных. x=eax
        mov dword ptr[x], eax
        mov dword ptr[y], ebx
    }
    __Set_TestTimeStop
    __Set_Test std::cout << "<x,y>=" << "<" << x << "," << y << ">" << std::endl;
}
/// <summary>Пример программы с асембленрной вставкой. Обмен значениями двух переменных через ASM вставку.</summary>
void Test_2()
{
    __Set_Test std::cout << "Test_2();" << std::endl;
    int x = 10;
    int y = 11;
    __Set_Test std::cout << "<x,y>=" << "<" << x << "," << y << ">" << std::endl;
    __Set_TestTimeStart
    __asm
    {
        xor eax, eax
        xor ebx, ebx
        mov eax, dword ptr[x]
        mov ebx, dword ptr[y]
        //Обмен значениями регистров
        XCHG eax,ebx
        mov dword ptr[x], eax
        mov dword ptr[y], ebx
    }
    __Set_TestTimeStop
    __Set_Test
    std::cout << "<x,y>=" << "<" << x << "," << y << ">" << std::endl;
}
/// <summary>Модифицированный обмен значениями переменных через XCHG, в 3 строки</summary>
void Test_3()
{
    __Set_Test std::cout << "Test_3();" << std::endl;
    int x = 10;
    int y = 11;
    __Set_Test std::cout << "<x,y>=" << "<" << x << "," << y << ">" << std::endl;
    __Set_TestTimeStart
    __asm
    {
        xor ebx, ebx
        mov ebx, dword ptr[x]
        XCHG ebx, dword ptr[y]
        mov dword ptr[x], ebx
    }
    __Set_TestTimeStop
    __Set_Test std::cout << "<x,y>=" << "<" << x << "," << y << ">" << std::endl;
}
/// <summary>Короткий обмен значениями без приблуд...</summary>
void Test_4()
{
    __Set_Test std::cout << "Test_3();" << std::endl;
    int x = 10;
    int y = 11;
    __Set_Test std::cout << "<x,y>=" << "<" << x << "," << y << ">" << std::endl;
    __Set_TestTimeStart
    __asm
    {
        xor ebx, ebx
        mov ebx, x
        XCHG ebx, y
        mov x, ebx
    }
    __Set_TestTimeStop
    __Set_Test std::cout << "<x,y>=" << "<" << x << "," << y << ">" << std::endl;
}

int main()
{
    Test_1();
    Test_2();
    Test_3();
    Test_4();
    //Как видно из примера самый быстрый тест у первой ассемблерной встваки с приблудами от MASM
    Test_1();
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
