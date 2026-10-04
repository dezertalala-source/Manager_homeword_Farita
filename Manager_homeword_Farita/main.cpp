#include <iostream>
#include <windows.h>



//Название функций это дата ВЫДАЧИ домашнего задания

int _29_09_2026() {
    int choice_airplane = 0;

    int airplane_fuel_tank[2]{300, 1000};

    int weight_types[2][3]{
        {750, 1500, 2000},
        {1000, 2000, 3000}
    };

    int fuel[2][3] = {
        {1, 4, 7},
        {2, 4, 6}
    };

    int temp_tank = 100;


    while (true) {
        std::cout << "\nВыберите номер самолета\n[1] Обьем бака 300л\n[2] обьем бака 1000л\nВведите номер самолета 1-2: ";
        std::cin >> choice_airplane;
        if (choice_airplane == 1 || choice_airplane == 2) {
            std::cout << "\nВы выбрали самолет номер " << choice_airplane;
            break;
        }
        else {
            std::cout << "\nОшибка выбраного вами самолета не существует попробуйте еще раз\n\n";
        }
    }


    int a_b = 0;
    int b_c = 0;

    int weight = 0;

    int helper = 0;
    
    bool run = true;
    while (run) {
        std::cout << "\nВведите массу груза который в планируете перевозить: ";
        std::cin >> weight;
        for (int i = 0; i < 3; i++) {
            if (weight_types[choice_airplane - 1][i] >= weight) {
                std::cout << "Вес допустимый расход топлева будет " << fuel[choice_airplane - 1][i] << "л на 1 км";
                helper = i;
                run = false;
                break;
            }
                
            else {
                if (i == 2) {
                    std::cout << "Вес не допустимый!";
                }
            }
        }
    }

    std::cout << "\nВведите расстояние от точке А_В: ";
    std::cin >> a_b;

    std::cout << "\nВведите расстояние от точке B_C: ";
    std::cin >> b_c;

    int tank = 0;

    if (choice_airplane == 1) {
        tank = airplane_fuel_tank[0];
    }

    else {
        tank = airplane_fuel_tank[1] + temp_tank;
    }

    float result_a_b = tank - (fuel[choice_airplane - 1][helper] * a_b);
    if (result_a_b >= 0) {
        std::cout << "\nВы пролетели А-В все гуд";
        if (choice_airplane == 2) {
            if (tank <= 1000) {
                tank -= 100;
            }
        }

        float result_b_c = tank - (fuel[choice_airplane - 1][helper] * b_c);

        if (result_b_c >= 0) {
            std::cout << "\nВы пролетели B-C все гуд";
        }
        else {
            std::cout << "\nВы не пролетели B-C нехватило бензина\n\nПопробуйте еще раз!";
        }
    }
    else {
        std::cout << "\nВы не пролетели А-В нехватило бензина\n\nПопробуйте еще раз!";
    }
    


    return 0;
}




int _30_09_2026() {
    std::cout << "2";
    return 0;
}






int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int choice = 0;

    while (true) {
        std::cout << "\n\n\nФАРИТ короче чтобы посмореть нужное дз выбери дату выдачи домашнего задания (названия функций с дз это тоже дата выдачи)\n"
            << "[1] 29.09.2026\n"
            << "[2] 30.09.2026\n"
            << "[INPUT] Введи номер дз по дате выдачи для просмотра: ";
        std::cin >> choice;
        

        if (choice == 1) {
            _29_09_2026();
        }

        else if (choice == 2) {
            _30_09_2026();
        }
    }

    return 0;
}