#include <iostream>
#include <iomanip>
using namespace std;

const int PASS_MARK = 40;

void readMarks(int marks[], int n);
int findTotal(int marks[], int n);
double findAverage(int marks[], int n);
int findHighest(int marks[], int n);
int findLowest(int marks[], int n);
int countPassed(int marks[], int n);
void printReport(int marks[], int n);

void readMarks(int marks[], int n)
{
    for (int i = 0; i < n; i++)
    {
        do
        {
            cout << "Enter mark for student " << i + 1 << ": ";
            cin >> marks[i];

            if (marks[i] < 0 || marks[i] > 100)
            {
                cout << "Invalid mark! Enter between 0 and 100." << endl;
            }

        } while (marks[i] < 0 || marks[i] > 100);
    }
}
int findTotal(int marks[], int n)
{
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        total += marks[i];
    }

    return total;
}
double findAverage(int marks[], int n)
{
    int total = findTotal(marks, n);

    return static_cast<double>(total) / n;
}
int findHighest(int marks[], int n)
{
    int highest = marks[0];

    for (int i = 1; i < n; i++)
    {
        if (marks[i] > highest)
        {
            highest = marks[i];
        }
    }

    return highest;
}
int findLowest(int marks[], int n)
{
    int lowest = marks[0];

    for (int i = 1; i < n; i++)
    {
        if (marks[i] < lowest)
        {
            lowest = marks[i];
        }
    }

    return lowest;
}
int countPassed(int marks[], int n)
{
    int passed = 0;

    for (int i = 0; i < n; i++)
    {
        if (marks[i] >= PASS_MARK)
        {
            passed++;
        }
    }

    return passed;
}
void printReport(int marks[], int n)
{
    int total = findTotal(marks, n);
    int passed = countPassed(marks, n);
    int failed = n - passed;

    cout << "\n===== STUDENT MARKS REPORT =====\n";

    cout << "Number of students : " << n << endl;
    cout << "Total marks        : " << total << endl;

    cout << fixed << setprecision(2);

    cout << "Average marks      : " << findAverage(marks, n) << endl;
    cout << "Highest mark       : " << findHighest(marks, n) << endl;
    cout << "Lowest mark        : " << findLowest(marks, n) << endl;
    cout << "Students passed    : " << passed << endl;
    cout << "Students failed    : " << failed << endl;

    cout << "================================\n";
}
int main()
{
    int marks[100];
    int n;
    char choice;

    do
    {
        cout << "Enter number of students (1-100): ";
        cin >> n;

        while (n < 1 || n > 100)
        {
            cout << "Invalid count! Enter between 1 and 100: ";
            cin >> n;
        }

        readMarks(marks, n);

        printReport(marks, n);

        cout << "\nDo you want to analyse again? (yes/no): ";
        cin >> choice;

    } while (choice == 'yes' || choice == 'YES');

    cout << "\nThank you for using student analyser!\n";

    return 0;
}