#include <iostream>

const int NAME_LENGTH{ 10 };

class Student
{
private:
    char mName[NAME_LENGTH];
    int mNumber;
    int mScore;

public:
    void GetName(const char* name)
    {
        int i;
        for (i = 0; i < NAME_LENGTH && name[i] != '\0'; i++) {
            mName[i] = name[i];
        }
        mName[i] = '\0';
    }

    void GetInfo(int number, int score)
    {
        mNumber = number;
        mScore = score;
    }

    void Print() {
        std::cout <<  mScore<<" " << mName;
    }

    int GetScore() const {
        return mScore;
    }
};

int main()
{
    int StudentNumber;
    std::cout << "학생 수를 입력하세요: ";
    std::cin >> StudentNumber;

    Student* students = new Student[StudentNumber];

    for (int i = 0; i < StudentNumber; i++)
    {
        std::cout << "------------ " << std::endl;;

        std::cout << "이름: ";
        char name[NAME_LENGTH];
        std::cin >> name;
        students[i].GetName(name);

        std::cout << "번호: ";
        int number;
        std::cin >> number;

        std::cout << "점수: ";
        int score;
        std::cin >> score;

        students[i].GetInfo(number, score);
    }

    for (int i = 0; i < StudentNumber - 1; i++) {
        for (int j = 0; j < StudentNumber - i - 1; j++) {
            if (students[j].GetScore() < students[j + 1].GetScore()) {
                std::swap(students[j], students[j + 1]);
            }
        }
    }

    for (int i = 0; i < StudentNumber; ++i) {
        students[i].Print();
        std::cout << std::endl;
    }

    delete[] students;

}
/*
	class MyClass
{
private:
	int mYear;
	int mMonth;
	int mDay;
public:
	MyClass(int year, int month, int day) {
		mYear = year;
		mMonth = month;
		mDay = day;
	}
	void Print() const
	{
		std::cout << mYear << "년" << mMonth << "월" << mDay << "일" << std::endl;
	}

};


int main()
{
	const MyClass Today(2023, 7, 19);

	Today.Print();
}
*/