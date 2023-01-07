#include <iostream>
#include <string.h>


using namespace std;

//задание 1

struct Student {
    char surname[20];
    int group;
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


Student Structure_filling(char *surnames, int groupe) {
    Student stud;
    *strncpy(stud.surname, surnames, (strlen(surnames)+1));
    stud.group=groupe;
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
    Student *arr2 = new Student[size];
    size_t count = 0;
    for (int i = 0; i, size; i++) {
        if (Average_rating(arr[i]) >= 3.75) {
            arr2[i] = arr[i];
            count++;
        }
    }
    new_size = count;
    arr2 = Resize_an_array(arr2, size, count);
    return arr2;
}

Student *List_of_losers(Student arr[], size_t size, size_t &new_size) {
    Student *arr2 = new Student[size];
    size_t count = 0;
    for (int i = 0; i, size; i++) {
        if (Average_rating(arr[i]) <= 2.5) {
            arr2[i] = arr[i];
            count++;
        }
    }
    new_size = count;
    arr2 = Resize_an_array(arr2, size, count);
    return arr2;
}

int main() {
    size_t size = 4;
    Student *students = new Student[size];
    char surnam[20];
    int groupes;
    for (int i = 0; i < size; i++) {
        cout << "Enter last name and group:";
        cin >> surnam;
        cin>> groupes;
        students[i] = Structure_filling(surnam, groupes);
    }
    Prints_Students(students, size);
    size_t new_size = 10;
    cout << "Enter new array size:";
    cin >> new_size;
   // Student *new_students = Resize_an_array(students, size, new_size);

    Student *stud=new Student[new_size];
    stud= Honors_List(students, size, new_size);
    Prints_Students(stud, new_size);


}
