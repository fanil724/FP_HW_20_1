#include <iostream>
#include <cstring>

using namespace std;

//задание 1

struct Student {
    char surname[20];
    char group[20];
    double grade[5]{0};
};

void Entering_grades(Student &student) {
    double osenka;
    for (int i = 0; i < 5; i++) {
        cout << "Entering grades" << i + 1 << ": ";
        cin >> osenka;
        student.grade[i] = osenka;
    }
}


double Average_rating(Student student) {
    double grade = 0;
    for (int j = 0; j < 5; j++) {
        grade += student.grade[j];
    }
    grade /= 5;
    return grade;
}

void Prints_Students(Student arr[], size_t size) {
    for (int i = 0; i < size; i++) {
        cout << "Family: " << arr[i].surname << "\n";
        cout << "Groupe: " << arr[i].group << "\n";
        cout << "Average rating: " << Average_rating(arr[i]) << "\n";
    }
    cout << endl;
}


Student Structure_filling(char *surnames, char *groupe) {
    Student stud;
    strncpy(stud.surname, surnames, (strlen(surnames) + 1));
    strncpy(stud.group, groupe, (strlen(groupe) + 1));
    Entering_grades(stud);
    return stud;
}

Student *Resize_an_array(Student arr[], size_t size, size_t &new_size) {
    Student *arr2 = new Student[new_size];
    for (int i = 0; i < new_size; i++) {
        arr2[i] = arr[i];
    }
    delete[] arr;
    return arr2;
}

Student *Honors_List(Student arr[], size_t size, size_t &new_size) {
    Student *arr2 = new Student[new_size];
    size_t count = 0;
    for (int i = 0; i < size; i++) {
        if ((Average_rating(arr[i])) >= 3.75) {
            arr2[count] = arr[i];
            count++;
        }
    }
    new_size = count;
    arr2 = Resize_an_array(arr2, size, count);
    return arr2;
}

Student *List_of_losers(Student arr[], size_t size, size_t &new_size) {
    Student *arr2 = new Student[new_size];
    size_t count = 0;
    for (int i = 0; i < size; i++) {
        if ((Average_rating(arr[i])) <= 2.5) {
            arr2[count] = arr[i];
            count++;
        }
    }
    new_size = count;
    arr2 = Resize_an_array(arr2, size, count);
    return arr2;
}

//задание 2


struct Man {
    char Family[20];
    char Name[10];
    int age;
    int day;
    int month;
    int year;
};

void Print(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        cout << str[i];
    }
    cout << " ";
}

void Print_Man(Man *man, size_t size) {
    for (int i = 0; i < size; i++) {
        cout << i << ": ";
        Print(man[i].Family);
        Print(man[i].Name);
        cout << " : " << man[i].age << " years old" << endl;
        cout << "Date of Birth: " << man[i].day << "." << man[i].month << "." << man[i].year << endl;
    }
    cout << "\n";
}

void Sort_by_Last_Name(Man man[], size_t size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(man[i].Family, man[j].Family) < 0) {
                swap(man[i], man[j]);
            }
        }
    }
}

void Sort_by_Name(Man man[], size_t size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(man[i].Name, man[j].Name) < 0) {
                swap(man[i], man[j]);
            }
        }
    }
}

void Print_Birthday_People(Man *m, size_t size, int month) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (m[i].month == month) {
            cout << m[i].Family << " " << m[i].Name << "-" << m[i].day << "." << m[i].month << "\n";
            count++;
        }
    }
    if (count == 0) {
        cout << "There are no birthdays this month";
    }
}

int Search_by_Last_Name(Man *m, size_t size, const char *family) {
    for (int i = 0; i < size; i++) {
        if ((strcmp(m[i].Family, family)) == 0) {
            return i;
        }
    }
    return -1;
}

int Search_by_Name(Man *m, size_t size, const char *name) {
    for (int i = 0; i < size; i++) {
        if ((strcmp(m[i].Name, name)) == 0) {
            return i;
        }
    }
    return -1;
}

Man *reolocate(Man *&man, size_t size, size_t new_size) {
    Man *m = new Man[new_size];
    for (int i = 0; (i < min(size, new_size)); i++) {
        m[i] = man[i];
    }
    delete[] man;
    man = m;
    return m;
}

Man Editing_a_Post(char *Family, char *Name,
                   int age, int day, int month, int year) {
    Man man;
    man.month = month;
    man.day = day;
    man.year = year;
    man.age = age;
    strncpy(man.Family, Family, strlen(Family) + 1);
    strncpy(man.Name, Name, strlen(Name) + 1);
    return man;
}

Man *adding_record_to_array(Man *m, size_t size, size_t &new_size, char *Family, char *Name,
                            int age, int day, int month, int year) {
    new_size = size + 1;
    Man *man = reolocate(m, size, new_size);
    man[new_size - 1] = Editing_a_Post(Family, Name, age, day, month, year);
    return man;
}

Man *removing_records_from_array(Man *m, size_t size, size_t &new_size, int index) {
    new_size = size - 1;
    if (index < size) {
        for (int i = index; i < size - 1; i++) {
            m[i] = m[i + 1];
        }
    }
    Man *man = reolocate(m, size, new_size);
    return man;
}


int main() {
//    size_t size = 5;
//    Student *students = new Student[size];
//    char surnam[20];
//    char groupes[20];
//    for (int i = 0; i < size; i++) {
//        cout << "Enter last name and group:";
//        cin >> surnam;
//        cin >> groupes;
//        students[i] = Structure_filling(surnam, groupes);
//    }
//    Prints_Students(students, size);
//    cout << endl;
//
//    size_t new_size = size;
//    Student *stud;
//    stud = Honors_List(students, size, new_size);
//    Prints_Students(stud, new_size);
//    cout << endl;
//
//    size_t newsize = size;
//    Student *studs;
//    studs = List_of_losers(students, size, newsize);
//    Prints_Students(studs, newsize);
//    cout << endl;

    size_t size = 10;
    size_t new_size, size2;
    Man *man=new Man[size]{0};
    for (int i = 0; i < size; i++) {
        man[i] = Editing_a_Post("petrov", "petr", 29, 24, 9, 1990);
        i++;
        man[i] = Editing_a_Post("sidorov", "ivan", 49, 31, 12, 1980);
    }
    Print_Man(man, size);
    cout << "\n";
    Man *M = adding_record_to_array(man, size, new_size, "bulkin", "sasha", 19, 4, 6, 2002);
    // Sort_by_Name(M,new_size);
    Print_Man(M, new_size);
    Print_Birthday_People(M, new_size, 12);
//    cout << "\n" << Search_by_Name(M, new_size, "sasha") << "\n";
    Man *Man = removing_records_from_array(M, new_size, size2, 8);
    Print_Man(Man, size2);
}
