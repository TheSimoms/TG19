#include <iostream>
#include <sstream>
#include <vector>


using namespace std;


#define MAX_SIZE 1000


// Shamelessly steal explode function from
// http://www.cplusplus.com/articles/2wA0RXSz/
const vector<string> explode(const string& s, const char& c) {
    string buff{""};
    vector<string> v;

    for(auto n:s) {
        if(n != c) buff+=n; else
        if(n == c && buff != "") { v.push_back(buff); buff = ""; }
    }

    if(buff != "") v.push_back(buff);

    return v;
}


int main() {
    string inventory_raw;
    string required_parts_raw;

    getline(cin, inventory_raw);
    getline(cin, required_parts_raw);

    vector<string> inventory{explode(inventory_raw, ' ')};
    vector<string> required_parts{explode(required_parts_raw, ' ')};

    int number_of_parts = inventory.size();
    int per_robot = 0, max_robots = 0, total_max_robots = 10000;

    for (int i = 0; i < number_of_parts; i++) {
        per_robot = stoi(required_parts[i]);

        if (per_robot == 0) {
            continue;
        }

        max_robots = stoi(inventory[i]) / per_robot;

        if (max_robots < total_max_robots) {
            total_max_robots = max_robots;
        }
    }

    cout << total_max_robots << endl;

    for (int i = 0; i < number_of_parts; i++) {
        if (i > 0) {
            cout << " ";
        }

        cout << stoi(inventory[i]) - stoi(required_parts[i]) * total_max_robots;
    }

    cout << endl;

    return 0;
}
