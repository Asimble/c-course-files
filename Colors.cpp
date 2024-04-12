#include <iostream>

using namespace std;

int main() {
    // Regular colors
    cout << "\033[0;30m" << "Black\n";
    cout << "\033[0;31m" << "Red\n";
    cout << "\033[0;32m" << "Green\n";
    cout << "\033[0;33m" << "Yellow\n";
    cout << "\033[0;34m" << "Blue\n";
    cout << "\033[0;35m" << "Magenta\n";
    cout << "\033[0;36m" << "Cyan\n";
    cout << "\033[0;37m" << "White\n";

    // Bright (bold) colors
    cout << "\033[1;30m" << "Bright Black\n";
    cout << "\033[1;31m" << "Bright Red\n";
    cout << "\033[1;32m" << "Bright Green\n";
    cout << "\033[1;33m" << "Bright Yellow\n";
    cout << "\033[1;34m" << "Bright Blue\n";
    cout << "\033[1;35m" << "Bright Magenta\n";
    cout << "\033[1;36m" << "Bright Cyan\n";
    cout << "\033[1;37m" << "Bright White\n";

    // Reset color to default
    cout << "\033[0m" << "Back to default color\n";

    return 0;
}
