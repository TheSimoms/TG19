#include <iostream>


using namespace std;


int main() {
    string input;

    cin >> input;

    int length = input.size();

    for (int i = 0; i < length; i++) {
        char c = tolower(input[i]);

        c += 3;

        if (c > 122) {
            c -= 26;
        }

        input[i] = c;
    }

    cout << input << endl;

    return 0;
}
