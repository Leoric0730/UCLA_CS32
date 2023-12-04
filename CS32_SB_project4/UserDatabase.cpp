#include "UserDatabase.h"
#include "User.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

UserDatabase::UserDatabase()
{
    flag = false;
}

bool UserDatabase::exist(std::string s, char x){
    for (int i = 0; i<s.size(); i++){
        if (s[i]==x) return true;
    }
    return false;
}

bool UserDatabase::load(const string& filename)
{
    if (!flag){                             //if hasn't been loaded, load and set flag to true.
        ifstream source(filename);
        loadHelper(source, m_users);
        flag = true;
        return true;
    }
    return false;
}

bool UserDatabase::loadHelper(std::ifstream& source, std::vector<User*> a)
{
    string line;
    string name;
    string email;
    vector<string> movieWatched;
    while(getline(source, line)){
        if (exist(line, ' ')) {name = line;}
        else if (exist(line, '@')) {email = line;}
        else if (isdigit(line[0])) {continue;}
        else if (line.empty()){ m_users.push_back(new User(name,email,movieWatched)); movieWatched.clear();}
        else
            movieWatched.push_back(line);
    }
    
    
    // function returned true when it's called.
    return true;
}

User* UserDatabase::get_user_from_email(const string& email) const
{
    
    for (auto p = m_users.begin(); p != m_users.end(); p++ ){
        if ((*p)->get_email() == email) {return *p;}
    }
    return nullptr;  // Replace this line with correct code.
}
