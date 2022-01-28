#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
#include <list>
using namespace std;

int main(int argc, char *argv[])
{
    vector<string> words;
    set <string> uniqueWords;
    string next_line;  // Each data line
    ifstream in(argv[1]);
    string fileName = argv[1];
    while (getline(in, next_line))
    {
        istringstream iss(next_line);
        string word;
        while (iss >> word)
        {
            string nopunct = "";
            for (auto &c : word)
            { // Remove Punctuation
                if (isalpha(c))
                {
                    nopunct += c;
                }
            }
            words.push_back(nopunct);
            uniqueWords.insert(nopunct);
        }
    }
    cout << "Number of words: " << words.size() << endl;
    cout << "Number of unique words: " << uniqueWords.size() << endl;
    ofstream file;
    file.open( fileName + "_set.txt", ios::out);
    for (set<string>::iterator it=uniqueWords.begin(); it!=uniqueWords.end(); it++){
        file << *it << endl;
    }
    file.close();
    file.open( fileName + "_vector.txt", ios::out);
    for (vector<string>::iterator it=words.begin(); it!=words.end(); it++){
        file << *it << endl;
    }
    file.close();

    map<string, vector<string>> wordsMap;
    string last = "";
    for (vector<string>::iterator it=words.begin(); it!=words.end(); it++) {
    wordsMap[last].push_back(*it);
    last = *it;
    }

    file.open( fileName + "_map.txt", ios::out);
    for (auto it=wordsMap.begin(); it!=wordsMap.end(); it++){
        for (int i = 0; i < it->second.size(); i++){
            file << i << ": ";
            file << it->first << ", " << it->second.at(i) << endl;
        }
    }
    file.close();

}