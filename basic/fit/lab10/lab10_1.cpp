//
//  main.cpp
//  lab10
//
//  Created by Ivan Romancev on 03.12.2020.
//

//Створити масив структур. Кожна структура складається з таких елементів: номер авіаційного рейсу, тип літака, дата відльоту, кількість вільних місць, вартість квитка. Реалізувати запити:
//скласти список номерів авіаційних рейсів, на які є вільні місця;
//вивести типи літаків і відповідні номери авіаційних рейсів на задану дату;
//упорядкувати масив за умови зростання вартості квитків по кожній даті.
//Результати запитів вивести у вигляді таблиць

#include <iostream>

const char plane_types[9] {'h', 't', 'p', 'l', 'm', 'j', 'r', 'n', 'w'};

struct Flight {
    int flight_number;
    char plane_type;
    
    unsigned int left_places;
    unsigned int cost;
    
    struct Date{
        int year;
        int month;
        int day;
    };
    Date date;
};

void fill_in(Flight &flight) {
    flight.flight_number = (rand()%20000);
    flight.plane_type = plane_types[(rand()%8)];
    flight.left_places = (rand()%2);
    flight.cost = 1000 + (rand()%1000);
    flight.date.year = 2000 + (rand()%20);
    flight.date.month = 1 + (rand()%11);
    flight.date.day = 1 + (rand()%27);
}


void displayMenu() {
    using std::cout;
    using std::endl;
    cout << "Menu: " << endl;
    cout << "1) Print out flights with free places" << endl;
    cout << "2) Print out flights on some date" << endl;
    cout << "3) Sort by cost" << endl;
    cout << "4) Print all flights" << endl;
}

void get_free_places(Flight flights[], int length) {
    std::cout << "NUM " << "LEFT PLACES" << std::endl;
    for (int i = 0; i < length; i++) {
        if (flights[i].left_places > 0) {
            std::cout << flights[i].flight_number << "      " << flights[i].left_places << std::endl;
        }
    }
}

void get_on_date(Flight flights[], char date[], int length) {
    std::cout << "PLANE TYPE " << "FLIGHT " << std::endl;
    char *year, *day, *month;
    day = date + strlen(date) - 2;
    year = date + strlen(date) - 10;
    month = date + strlen(date) - 5;
    
    for (int i = 0; i < length; i++) {
        if (std::atoi(year) == flights[i].date.year && std::atoi(month) == flights[i].date.month && std::atoi(day) == flights[i].date.day) {
            std::cout << flights[i].plane_type << " " << flights[i].flight_number << std::endl;
        }
    }
}

void print_out_flights(Flight flights[], int length) {
    std::cout << "FLIGHT " << "LEFT PLACES " << "COST " << "TYPE " << "TIME" << std::endl;
    for (int i = 0; i < length; i++) {
        std::cout << flights[i].flight_number << " " << flights[i].left_places << " " << flights[i].cost << " " << flights[i].plane_type << " " << flights[i].date.year << "." << flights[i].date.month << "." << flights[i].date.day << std::endl;
    }
}

void sort_by_cost_and_date(Flight flights[], int length) {
    bool swapped;
    for (int i = 0; i < length-1; i++) {
        swapped = false;
        for (int j = 0; j < length-i-1; j++) {
            if (flights[j].date.year > flights[j+1].date.year) {
                std::swap(flights[j], flights[j+1]);
                swapped = true;
            }
            else if (flights[j].date.year == flights[j+1].date.year && flights[j].date.month > flights[j+1].date.month) {
                std::swap(flights[j], flights[j+1]);
                swapped = true;
            }
            else if (flights[j].date.year == flights[j+1].date.year && flights[j].date.month == flights[j+1].date.month && flights[j].date.day > flights[j+1].date.day) {
                std::swap(flights[j], flights[j+1]);
                swapped = true;
            }
            else if (flights[j].date.year == flights[j+1].date.year && flights[j].date.month == flights[j+1].date.month && flights[j].date.day == flights[j+1].date.day) {
                if (flights[j].cost > flights[j+1].cost) {
                    std::swap(flights[j], flights[j+1]);
                    swapped = true;
                }
            }
        }
        if (!swapped) break;
    }

}

int main(int argc, const char * argv[]) {
    const int length = rand()%100;
    Flight flights[length];
    for (int i = 0; i < length; i++) {
        fill_in(flights[i]);
    }
    displayMenu();
    int option;
    while (true) {
        std::cin >> option;
        switch (option) {
            case 1:
                get_free_places(flights, length);
                break;
            case 2:
                char date[10];
                std::cin >> date;
                get_on_date(flights, date, length);
                break;
            case 3:
                sort_by_cost_and_date(flights, length);
                break;
            case 4:
                print_out_flights(flights, length);
                break;
            default:
                break;
        }
    }
}
