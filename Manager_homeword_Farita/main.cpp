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













// тут все вспомогательные функции для _30_09_2026
bool leap_year_check(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}

int days_in_month(int month, int year) {
    if (month == 2) {
        if (leap_year_check(year)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

int days_from_start(int year, int month, int day) {
    int days = 0;

    for (int i = 1; i < year; i++) {
        if (leap_year_check(i)) {
            days += 366;
        }
        else {
            days += 365;
        }
    }

    for (int i = 1; i < month; i++) {
        days += days_in_month(i, year);
    }

    days += day;

    return days;
}



int sum(int arr[], int size) {
    int suma = 0;
    for (int i = 0; i < size; i++) {
        suma += arr[i];
    }
    return suma / size;
}


int check(int arr[], int size) {
    int plus = 0;
    int minus = 0;
    int zero = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            minus += 1;
        }
        else if (arr[i] == 0) {
            zero += 1;
        }
        else {
            plus += 1;
        }
    }

    std::cout << "\nотрицытельных чисел тут всего: " << minus << "\nнулей тут: " <<zero<< "\nположительных тут: "<< plus;
    return 0;
}


int _30_09_2026() {
    int choice = 0;

    while (true) {
        std::cout << "\n\n\n\nВыберите номер задания\n[1] Задание 1\n[2] Задание 2\n[3] Задание 3\nВведите вариант ответа: ";
        std::cin >> choice;

        if (choice == 1) {
            int year1 = 0;
            int month1 = 0;
            int day1 = 0;

            int year2 = 0;
            int month2 = 0;
            int day2 = 0;

            while (true) {
                std::cout << "\nВведите год первой даты: ";
                std::cin >> year1;

                if (year1 <= 0) {
                    std::cout << "\nНельзя вводить отрицательные и нулевые значения";
                }
                else {
                    break;
                }
            }

            while (true) {
                std::cout << "\nВведите месяц первой даты: ";
                std::cin >> month1;

                if (month1 < 1 || month1 > 12) {
                    std::cout << "\nМесяц должен быть от 1 до 12";
                }
                else {
                    break;
                }
            }

            while (true) {
                std::cout << "\nВведите день первой даты: ";
                std::cin >> day1;

                if (day1 < 1 || day1 > days_in_month(month1, year1)) {
                    std::cout << "\nТакого дня в этом месяце нет";
                }
                else {
                    break;
                }
            }

            while (true) {
                std::cout << "\nВведите год второй даты: ";
                std::cin >> year2;

                if (year2 <= 0) {
                    std::cout << "\nНельзя вводить отрицательные и нулевые значения";
                }
                else {
                    break;
                }
            }

            while (true) {
                std::cout << "\nВведите месяц второй даты: ";
                std::cin >> month2;

                if (month2 < 1 || month2 > 12) {
                    std::cout << "\nМесяц должен быть от 1 до 12";
                }
                else {
                    break;
                }
            }

            while (true) {
                std::cout << "\nВведите день второй даты: ";
                std::cin >> day2;

                if (day2 < 1 || day2 > days_in_month(month2, year2)) {
                    std::cout << "\nТакого дня в этом месяце нет";
                }
                else {
                    break;
                }
            }

            int date1 = days_from_start(year1, month1, day1);
            int date2 = days_from_start(year2, month2, day2);

            int result = date1 - date2;

            if (result < 0) {
                result = -result;
            }

            std::cout << "\nКоличество дней между датами: " << result;
            break;
        }
        else if (choice == 2) {
            const int size = 5;
            int arr[size]{ 1, 2, 3, 4, 5 };
            std::cout << "Все числа: ";
            for (int i = 0; i < size; i++) {
                std::cout << " " << arr[i];
            }
            std::cout << "\nсред арифм: " << sum(arr, size);
            break;
        }
        else if (choice == 3) {
            const int size = 5;
            int arr[size]{ -1, 2, 0, 4, -5 };
            std::cout << "Все числа: ";
            for (int i = 0; i < size; i++) {
                std::cout << " " << arr[i];
            }
            check(arr, size);
            break;
        }
        else {
            std::cout << "\n\nТакого варианта ответа нету\n";
        }
    }

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