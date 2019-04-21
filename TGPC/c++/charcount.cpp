#include <iostream>
#include <set>


using namespace std;


int main() {
    set<int> input;

    int c = getchar();

    while (c != '\n') {
        input.insert(c);

        c = getchar();
    }

    int number_of_characters = input.size();

    cout << number_of_characters << endl;

    return 0;
}
