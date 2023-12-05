#include <bits/stdc++.h>
using namespace std;

bool ban_cmp(const string &id, const string &ban_id) {
    if (id.size() != ban_id.size())
        return false;
    int i = 0;
    while (i < id.size())
        if (ban_id[i] == '*' || id[i] == ban_id[i]) ++i;    
        else return false;
    return true;
}

void insert_answer(vector<set<string>> &answer_cases, set<string> &case1) {
    for (auto& answer_case : answer_cases) {
        if (answer_case == case1)
            return ;
    }
    answer_cases.push_back(case1);
}

void dfs(int depth, set<string> answer, vector<set<string>> &answer_cases, vector<vector<string>> &mapping_ids) {
    if (depth == mapping_ids.size()) {
        if (answer.size() == mapping_ids.size())
            insert_answer(answer_cases, answer);
        return;
    }
    for (string& s : mapping_ids[depth]) {
        set<string> tmp_answer = answer;
        tmp_answer.insert(s);
        dfs(depth + 1, tmp_answer, answer_cases, mapping_ids);
    }   
}

int solution(vector<string> user_ids, vector<string> banned_ids) {
    vector<vector<string>> mapping_ids; // 각 ban_id 당 가능한 user_id
    vector<set<string>> answer_cases; // 제재 아이디 목록 set
    
    // get mapping_ids
    for (string banned_id : banned_ids) {
        vector<string> _case;
        for (string user_id : user_ids) {
            if (ban_cmp(user_id, banned_id)) {
                _case.push_back(user_id);
            }
        }
        mapping_ids.push_back(_case);
    }
    // get answer_cases
    dfs(0, set<string>(), answer_cases, mapping_ids);
    return answer_cases.size();
}