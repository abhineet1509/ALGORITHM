#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> findDuplicate(vector<string>& paths) {
    unordered_map<string, vector<string>> contentMap;
    
    for (string &path : paths) {
        stringstream ss(path);
        string dir;
        ss >> dir; // first token is directory
        string file;
        while (ss >> file) {
            size_t pos = file.find('(');
            string fileName = file.substr(0, pos);
            string fileContent = file.substr(pos + 1, file.size() - pos - 2);
            contentMap[fileContent].push_back(dir + "/" + fileName);
        }
    }

    vector<vector<string>> result;
    for (auto &[content, files] : contentMap) {
        if (files.size() > 1) result.push_back(files);
    }
    return result;
}

int main() {
    vector<string> paths = {
        "root/a 1.txt(abcd) 2.txt(efgh)",
        "root/c 3.txt(abcd)",
        "root/c/d 4.txt(efgh)",
        "root 4.txt(efgh)"
    };
    
    vector<vector<string>> duplicates = findDuplicate(paths);
    
    for (auto &group : duplicates) {
        for (string &file : group) cout << file << " ";
        cout << endl;
    }
    
    return 0;
}
