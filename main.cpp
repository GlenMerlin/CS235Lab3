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

    map<string, vector<string>> wordsMap;
    string last = "";
    for (list<string>::iterator it=words.begin(); it!=words.end(); it++) {
    wordsMap[last] = *it;
    last = *it;
    }  
}