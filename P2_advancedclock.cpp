#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <windows.h>

using namespace std;

int main() {
    // Use the system clock to get the current time_point
    auto now = chrono::system_clock::now();
    // Convert it to a time_t object, representing system time in seconds
    time_t now_c = chrono::system_clock::to_time_t(now);
    // Convert this time_t object to tm struct to access time components
    struct tm *parts = localtime(&now_c);

    int h = parts->tm_hour;  // hours since midnight (0-23)
    int m = parts->tm_min;   // minutes after the hour (0-59)
    int s = parts->tm_sec;   // seconds after the minute (0-60)

    const char* weekday[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    while(true) {
        // Instead of clearing the console, use '\r' to return the cursor to the beginning of the line
        cout << "\r"; // Return the cursor to the start of the line

        // Output the current time and weekday, flush to make sure it updates the display
        cout << (h < 10 ? "0" : "") << h << ":"
             << (m < 10 ? "0" : "") << m << ":"
             << (s < 10 ? "0" : "") << s << " "
             << weekday[parts->tm_wday] << flush;

        // Wait for a second
        this_thread::sleep_for(chrono::seconds(1));

        // Increment the time by one second
        s++;
        if (s > 59) {
            s = 0;
            m++;
        }
        if (m > 59) {
            m = 0;
            h++;
        }
        if (h > 23) {
            h = 0;
        }

        // Update the tm structure to reflect the day change if needed
        if (h == 0 && m == 0 && s == 0) {
            now = chrono::system_clock::now();
            now_c = chrono::system_clock::to_time_t(now);
            parts = localtime(&now_c);
        }
    }
    return 0;
}
