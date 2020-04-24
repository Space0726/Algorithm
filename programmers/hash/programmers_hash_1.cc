#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> names;
    for (string& name: completion)
        if (names.find(name) != names.end())
            ++names[name];
        else
            names[name] = 1;
    for (string& name: participant)
        if (names.find(name) == names.end()) {
            return name;
        } else {
            if (!names[name]) return name;
            --names[name];
        }
    return "Input error";
}
