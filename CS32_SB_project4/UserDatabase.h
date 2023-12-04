#ifndef USERDATABASE_INCLUDED
#define USERDATABASE_INCLUDED

#include <string>
#include <vector>

class User;

class UserDatabase
{
public:
    UserDatabase();
    bool load(const std::string& filename);
    User* get_user_from_email(const std::string& email) const;
    
private:
    std::vector<User*> m_users;   //?
    bool loadHelper(std::ifstream& source, std::vector<User*> a);
    bool flag;
    bool exist(std::string s, char x);
};




#endif // USERDATABASE_INCLUDED
