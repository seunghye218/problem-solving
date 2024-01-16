#include <string>
using namespace std;

string solution(string rsp) {
    for (char &c : rsp) {
        switch (c) {
            case '0' : c = '5'; break;
            case '2' : c = '0'; break;
            case '5' : c = '2'; break;
        }
    }
    return rsp;
}