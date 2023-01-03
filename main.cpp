#include <iostream>

using namespace std;

//задание 1

struct Student {
    string surname;
    string group;
    int grade[5]{0};
};
void Entering_grades(Student student) {
    for (int i = 0; i < 5; i++) {
        cout << "Entering grades" << i + 1 << ": ";
        cin >> student.grade[i];
    }
}

double Average_rating(Student student) {
    double grade = 0;
    for (int j = 0; j < 5; j++) {
        grade += student.grade[j];
    }
    return (grade / 5);
}

void Prints_Students(Student arr[], size_t size) {
    for (int i = 0; i < size; i++) {
        cout << "Family: " << arr[i].surname << "\n";
        cout << "Groupe: " << arr[i].group << "\n";
        double grade = Average_rating(arr[i]);
        cout << "Average rating: " << grade << "\n";
    }
    cout << endl;
}



Student Structure_filling(string surnames, string groupe) {
    Student stud;
    stud.surname = surnames;
    stud.group = groupe;
    Entering_grades(stud);
    return stud;
}

Student *Resize_an_array(Student arr[], size_t size, size_t new_size) {
    Student *arr2 = new Student[new_size];
    for (int i = 0; i < new_size; i++) {
        arr2[i] = arr[i];
    }
    delete[] arr;
    return arr2;
}

Student *Honors_List(Student arr[], size_t size) {
    Student *arr2 = new Student[size];
    size_t count = 0;
    for (int i = 0; i, size; i++) {
        if (Average_rating(arr[i]) >= 3.75) {
            arr2[i] = arr[i];
            count++;
        }
    }
    arr2 = Resize_an_array(arr2, size, count);
    return arr2;
}

Student *List_of_losers(Student arr[], size_t size) {
    Student *arr2 = new Student[size];
    size_t count = 0;
    for (int i = 0; i, size; i++) {
        if (Average_rating(arr[i]) <= 2.5) {
            arr2[i] = arr[i];
            count++;
        }
    }
    arr2 = Resize_an_array(arr2, size, count);
    return arr2;
}

int main() {
    size_t size = 2;
    Student *students = new Student[size]{};
    for (int i = 0; i < size; i++) {
        students[i] = Structure_filling("wiugfiqwf", "ehlvwkh");
    }
    size_t new_size;
//    cout << "Enter new array size:";
//    cin >> new_size;
    // Student *new_students = Resize_an_array(students, size, new_size);
    Prints_Students(students, size);

}
