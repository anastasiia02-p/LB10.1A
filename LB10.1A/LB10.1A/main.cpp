#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

enum Speciality { ITIS, RE, KN, KI, PZ };
string speciality_str[] = { "����������� ", "��������������", "����'����� �����", "����'������ ��������", "��������� ������������" };

struct Students {
    string surname;
    int course;
    Speciality speciality;
    int grade_physics;
    int grade_math;
    int grade_info;
};

void Create(Students* S, const int N);
void count_physics_grades(Students* S, int N, int& count_5, int& count_4, int& count_3);
int count_students_with_high_grades(Students* S, int N);
void Print(Students* S, const int N);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "������ ������� ��������: "; cin >> N;

    Students* S = new Students[N];

    Create(S, N);
    Print(S, N);

    int count_5 = 0;
    int count_4 = 0;
    int count_3 = 0;

    count_physics_grades(S, N, count_5, count_4, count_3);

    cout << "ʳ������ ������ '5' � ������: " << count_5 << endl;
    cout << "ʳ������ ������ '4' � ������: " << count_4 << endl;
    cout << "ʳ������ ������ '3' � ������: " << count_3 << endl;

    int count_high_grades = count_students_with_high_grades(S, N);

    cout << "ʳ������ ��������, �� �������� ������ '4' ��� '5' � ������ �� ����������: " << count_high_grades << endl;

    delete[] S;
    return 0;
}

void Create(Students* S, const int N) {
    for (int i = 0; i < N; i++) {
        int speciality;
        cout << "����� ��������: " << i + 1 << endl;
        cin.get();
        cin.sync();
        cout << "�������: "; getline(cin, S[i].surname); cout << endl;
        cout << "����: "; cin >> S[i].course; cout << endl;
        cout << "������������(0 - �����������, 1 - ��������������, 2 - ����'����� �����, 3 - ����'������ ��������, 4 - ��������� ������������): ";
        cin >> speciality;
        S[i].speciality = (Speciality)speciality;
        cout << "������ � ������: "; cin >> S[i].grade_physics; cout << endl;
        cout << "������ � ����������: "; cin >> S[i].grade_math; cout << endl;
        cout << "������ � �����������: "; cin >> S[i].grade_info; cout << endl;
        cout << endl;
    }
}

void count_physics_grades(Students* S, int N, int& count_5, int& count_4, int& count_3) {
    count_5 = 0;
    count_4 = 0;
    count_3 = 0;

    for (int i = 0; i < N; i++) {
        if (S[i].grade_physics == 5) count_5++;
        else if (S[i].grade_physics == 4) count_4++;
        else if (S[i].grade_physics == 3) count_3++;
    }
}

int count_students_with_high_grades(Students* S, int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if ((S[i].grade_physics == 4 || S[i].grade_physics == 5) &&
            (S[i].grade_math == 4 || S[i].grade_math == 5)) {
            count++;
        }
    }
    return count;
}

void Print(Students* S, const int N) {
    cout << "=================================================================================================" << endl;
    cout << "|  �  |   �������   |  ����  |     ������������     |  Գ����  |  ����������  |  �����������  |" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++) {
        cout << "|" << setw(4) << left << i + 1 << " ";
        cout << "|" << setw(14) << left << S[i].surname;
        cout << "|" << setw(8) << left << S[i].course;
        cout << "|" << setw(23) << left << speciality_str[S[i].speciality];
        cout << "|" << setw(10) << left << S[i].grade_physics;
        cout << "|" << setw(14) << left << S[i].grade_math;
        cout << "|" << setw(15) << left << S[i].grade_info << "|" << endl;
    }
    cout << "=================================================================================================" << endl << endl;
}
