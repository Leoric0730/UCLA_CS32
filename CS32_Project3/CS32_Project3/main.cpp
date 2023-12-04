#include <iostream>
#include <fstream>
#include <istream>
#include <cstring>
using namespace std;

const int MAXRESULTS   = 20;    // Max matches that can be found
const int MAXDICTWORDS = 30000; // Max words that can be read in

void loop (int i, int max, string prefix, string rest, const string dict[], const int& size, string results[], int& count);
void printPermutation(string prefix, string rest, const string dict[], const int& size, string results[], int& count);
int checkDick(string target, const string dict[], int size, string results[], string result_last[], int& count);
bool isduplicate(string target, string result[], int start, int max);
int lexiconBuilderhelper(istream &dictfile, string dict[], int num);
int lexiconBuilder(istream &dictfile, string dict[]);
int theJumbler(string word, const string dict[], int size, string results[]);
void divulgeSolutions(const string results[], int size);
int checkDict(string target, const string dict[], int size, string results[], string result_spec[], int& count);
int main()
{
    string results[MAXRESULTS];
    string dict[MAXDICTWORDS];
    ifstream dictfile;         // file containing the list of words
    int nwords;                // number of words read from dictionary
    string word;

    dictfile.open("/Users/haoyuluo/Desktop/CS32/CS32_Project3/wordsMax.txt");
    if (!dictfile) {
        cout << "File not found!" << endl;
        return (1);
    }
    nwords = lexiconBuilder(dictfile, dict);
    cout << nwords << endl;
    cout << "Please enter a string for an anagram: ";
    cin >> word;

    int numMatches = theJumbler(word, dict, nwords, results);
    assert(numMatches == 2 && (results[0] == "arrogant" ||
    results[0] == "tarragon"));
    if (!numMatches) {
        cout << "No matches found" << endl;
    }
    else {
        divulgeSolutions(results, numMatches);
    }

    return 0;
}

void printPermutation(string prefix, string rest, const string dict[], const int& size, string results[], int& count) {
    if (rest.size()==0) {cout << prefix << endl;
        count += checkDict(prefix, dict, size, results, &results[count], count);
    }
    else {
        loop(0,static_cast<int>(rest.size()), prefix, rest, dict, size, results, count);
    }
}

void loop (int i, int max, string prefix, string rest, const string dict[], const int& size, string results[], int& count) {
    if (i >= max) {return;}
    string prefix1 = prefix + rest[i];
    string rest1 = rest.substr(0,i)  + rest.substr(i+1);
    printPermutation(prefix1,rest1,dict,size,results,count);
    loop (i+1, max, prefix, rest, dict, size, results, count);
}
int checkDict(string target, const string dict[], int size, string results[], string result_last[], int& count) {
    if (count >= MAXRESULTS){return 0;}
    if (size==0) return 0;
    if (target == *dict) {                                              // helper function that find the number of target string in the dict
        if(isduplicate(target, results, 0, count))
        return 0;
        else
        {
        *result_last = target;
        return 1 + checkDict(target, dict + 1, size - 1, results, result_last + 1, count);
        }                                              // If the word is not duplicated, put it at the latest position on the
                                                     // array, if not return 0 as we won't put it on the string again.
        }
    else return checkDict(target,dict+1,size-1,results,result_last,count);
}

bool isduplicate(string target, string result[], int start, int max){   // helper function that check if some word has already
    if (start >= max) return false;                                     // existed in the result array
    if(target == *result) return true;
    else return isduplicate(target, result+1, start+1, max);
}

int lexiconBuilderhelper(istream &dictfile, string dict[], int num){
    if (num >= MAXDICTWORDS) {return 0;}
    string line;
    if (getline(dictfile,line)) {
        *dict = line;
        return 1 + lexiconBuilderhelper(dictfile, dict + 1, num+1);
    }
    return 0;
    }


int lexiconBuilder(istream &dictfile, string dict[]) {

    return lexiconBuilderhelper(dictfile, dict, 0);
    }


int theJumbler(string word, const string dict[], int size, string results[]) {
    //Examine each of the possible permutated words created, find if it's in the dict[] array.
    //If it is, add it to the results[] array and increment return count by one. If it's not do nothing.
    //Check if the macthed word is already in the array. If it has, don't add it agagin. Hasn't: add it.
    int count = 0;
    printPermutation("", word, dict, size, results, count);
    return count;
}

void divulgeSolutions(const string results[], int size){
    
    if(size <= 0) return;
    cout << "Matching word " << *results << endl;
    divulgeSolutions(results+1, size-1);
}
