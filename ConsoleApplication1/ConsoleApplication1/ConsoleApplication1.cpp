// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;
void show_bits(int a)
{
    int size = 4 * sizeof(int);
    int mask = 1 << size;
    for (int i = 0; i <= size; ++i)
    {
        std::cout << (a & mask ? 1 : 0);
        a <<= 1;
    } 
    cout << "\n";
}
int main()
{
    int i = 0b10101010101;
    cout << i << '\n';
    show_bits(i);
    __asm 
    {
        mov eax,dword ptr[i]
        rcr eax,1
        mov dword ptr[i], eax
    }
    show_bits(i);
    __asm
    {
        mov eax, dword ptr[i]
        rcl eax, 1
        mov dword ptr[i], eax
    }
    cout << "/////////////////////////\n";
    /////////////////////////
    show_bits(i);
    int a(0), b(0);
    ;
    __asm
    {
        xor eax, eax
        xor ebx, ebx
        mov eax, dword ptr[i]
        push eax
        pop ax
        pop bx
        mov bx, ax
        /*
        shr eax, 8
        */
        mov dword ptr[a], eax
        mov dword ptr[b], ebx
        
        /*
        popa ax
        //popa al
        //popa bh
        //popa bl
        //rcl eax, 1
        //mov dword ptr[i], eax
        */
    }
    cout << "a=";show_bits(a);
    cout << "b=";show_bits(b);
    cout << "Hello World!\n";
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
