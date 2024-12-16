#include <iostream>
#include <ctime>
using namespace std;

int offsetHours = 0;
double answer = 0;
char x;

int main() {
    //problem 1

	//gets current time and prints
    time_t now = time(nullptr);
    cout << "Today is " << ctime(&now) << endl;
    
    //problem 2
    now = time(nullptr);
    tm* utcTime = gmtime(&now);
    //gets time offset
    cout << "Enter a time offset in hours from UTC (EST is -5): ";
    cin >> offsetHours;

    //converts to users time
    time_t adjustedTime = now + offsetHours * 3600;

    tm* timezone = gmtime(&adjustedTime);
    //prints out user’s time
    cout << "Adjusted time: " << asctime(timezone) << endl;

    //problem 3
    
    //once user enters test, time starts
    cout << "Welcome to the quiz! Answer the question as fast as you can! Press anything to Begin!";
    cin >> x;
    
    now = time(nullptr);
    //runs until user gets it right
    do {
        cout << "What is 17 / 4? >> ";
        cin >> answer;

        if (answer != 4.25) cout << "Incorrect!" << endl;
    } while (answer != 4.25);
    time_t end = time(nullptr);
    //prints start, end, and difference time
    cout << "\n\nStart time: " << asctime(gmtime(&now)) << "\nEnd time: " << asctime(gmtime(&end)) << "\nTime: " << difftime(end, now) << " seconds.";


    return 0;
}
