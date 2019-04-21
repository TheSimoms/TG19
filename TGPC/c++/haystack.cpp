#include <iostream>
#include <set>


using namespace std;


int main() {
    string input;
    string pattern;

    cin >> input;
    cin >> pattern;

    int inputLength = input.size();
    int patternLength = pattern.size();

    int matchPositions[inputLength] = {-1};
    string matches[inputLength] = {""};
    int matchIndex = 0;

    for (int pos = 0; pos <= inputLength - patternLength; pos++) {
        bool match = true;

        for (int patternPos = 0; patternPos < patternLength; patternPos++) {
            int checkPos = pos + patternPos;

            char c = pattern.at(patternPos);

            // No match
            if (c != input.at(checkPos) && c != '_') {
                match = false;

                break;
            }
        }

        if (match) {
            matchPositions[matchIndex] = pos;
            matches[matchIndex] = input.substr(pos, patternLength);

            matchIndex++;
        }
    }

    cout << '[';

    for (int i = 0; i < matchIndex; i++) {
        if (i > 0) {
            cout << ", ";
        }

        cout << matchPositions[i];
    }

    cout << ']' << endl;

    for (int i = 0; i < matchIndex; i++) {
        cout << matches[i] << endl;
    }

    return 0;
}
