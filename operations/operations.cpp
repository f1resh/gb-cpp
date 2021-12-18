#include <iostream>
#include <clocale>

int main()
{
    //Task 1
    {
        const int a = 4;
        const int b = 38;
        const int c = -465;
        const int d = 757;

        //static-cast
        float result1 = a * (b + (static_cast<float>(c) / d));
        std::cout << result1 << std::endl;

        //C-cast
        float result2 = a * (b + (float(c) / d));
        std::cout << result2 << std::endl;
    }

    //Task 2
    {
        setlocale(LC_ALL, "Russian");
        std::cout << "¬ведите целое число: ";
        int n;
        std::cin >> n;
        n = (n <= 21) ? 21 - n : (n - 21) * 2;
        std::cout << "–езультат: " << n << std::endl;
    }

    //Task 3
    {
        int aNumbers[3][3][3];// = { 5,12,3,4,5,6,7,8,9,10,11,12,13,99999,15,16,17,18,19,20,21,22,23,24,25,26,27 };
        auto pArray = &aNumbers[0][0][0];

        std::cout << aNumbers[1][1][1] << std::endl;
        std::cout << *(pArray+1*1+1*3+1*9) << std::endl;
    }

    //Task 4
    {
        extern int new_a, new_b, new_c, new_d;

        //static-cast
        float result1 = new_a * (new_b + (static_cast<float>(new_c) / new_d));
        std::cout << result1 << std::endl;

        //C-cast
        float result2 = new_a * (new_b + (float(new_c) / new_d));
        std::cout << result2 << std::endl;
    }
}

