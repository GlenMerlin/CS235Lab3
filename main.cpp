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
    list<string> words;
    set<string> uniqueWords;
    string next_line; // Each data line
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
    file.open(fileName + "_set.txt", ios::out);
    for (auto it = uniqueWords.begin(); it != uniqueWords.end(); it++)
    {
        file << *it << endl;
    }
    file.close();
    file.open(fileName + "_vector.txt", ios::out);
    for (auto it = words.begin(); it != words.end(); it++)
    {
        file << *it << endl;
    }
    file.close();

    map<list<string>, vector<string>> wordsMap;
    list<string> state;
    int M = 3;
    for (int i = 0; i < M; i++)
    {
        state.push_back("");
    }

    for (list<string>::iterator it = words.begin(); it != words.end(); it++)
    {
        wordsMap[state].push_back(*it);
        state.push_back(*it);
        state.pop_front();
    }

    state.clear();
    for (int i = 0; i < M; i++)
    {
        state.push_back("");
    }
    for (int i = 0; i < 100; i++)
    {
        int ind = rand() % wordsMap[state].size();
        cout << wordsMap[state][ind] << " ";
        state.push_back(wordsMap[state][ind]);
        state.pop_front();
    }
    cout << endl;
    return 0;
}