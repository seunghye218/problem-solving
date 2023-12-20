#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

struct dat {
    string act;
    string id;
    string name;
};

const static string ENTER_MESSAGE = "님이 들어왔습니다.";
const static string LEAVE_MESSAGE = "님이 나갔습니다.";

vector<string> solution(vector<string> records) {
    unordered_map<string, string> id_name;
    vector<dat> v_records;
    // parsing
    for (string &record : records) {
        istringstream iss(record.c_str());
        dat data;
        string tmp;
        iss >> data.act >> data.id >> data.name;
        v_records.push_back(data);
    }
    // get last name
    for (dat &record : v_records)
        if (record.act[0] == 'E' || record.act[0] == 'C')
            id_name[record.id] = record.name;
    // set message
    vector<string> answer;
    for (dat &record : v_records) {
        if (record.act[0] == 'E')
            answer.push_back(id_name[record.id] + ENTER_MESSAGE);
        if (record.act[0] == 'L')
            answer.push_back(id_name[record.id] + LEAVE_MESSAGE);     
    }
    return answer;
}