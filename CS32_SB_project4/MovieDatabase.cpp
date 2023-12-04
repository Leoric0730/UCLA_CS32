#include "MovieDatabase.h"
#include "Movie.h"


#include <string>
#include <vector>
#include <fstream>

using namespace std;

MovieDatabase::MovieDatabase()
{
    flag = false;
}

bool MovieDatabase::load(const string& filename)
{
    if (!flag){                             //if hasn't been loaded, load and set flag to true.
        ifstream source(filename);
//        ifstream infile(filename);
//        int numOfLines = checkLineNum(source);
        loadHelper(source, tmm);
        flag = true;
        return true;
    }
    return false;
}

//int checkLineNum(std::ifstream& source){
//    string line;
//    int num = 0;
//    while(getline(source,line)){
//        num++;
//    }
//    return num;
//}

bool MovieDatabase::loadHelper(std::ifstream& source, TreeMultimap<std::string, Movie*>& a){
    string line;
    string ID;
    string title;
    string year;
    vector<string> directors;
    vector<string> actors;
    vector<string> genres;
    string rating;
    int j=1;
        while(getline(source, line)){
            if(j%8 == 1){ID = line; j++;}
            else if(j%8 == 2){title = line; j++;}
            else if(j%8 == 3){year = line; j++;}
            else if(j%8 == 4){
                while(!line.empty()){
                    size_t pos = line.find(',');
                    directors.push_back(line.substr(0,pos));
                    line.erase(line.begin(),line.begin()+pos+1);
                }
                j++;
            }
            else if(j%8 == 5){
                while(!line.empty()){
                    size_t pos = line.find(',');
                    actors.push_back(line.substr(0,pos));
                    line.erase(line.begin(),line.begin()+pos+1);
                }
                j++;
            }
            else if(j%8 == 6){
                while(!line.empty()){
                    size_t pos = line.find(',');
                    genres.push_back(line.substr(0,pos));
                    line.erase(line.begin(),line.begin()+pos+1);
                }
                j++;
            }
            else if(j%8 == 7){rating = line; j++;}
            else {
                Movie m(ID,title,year,directors, actors, genres, stof(rating));
                Movie* ptr = &m;
                a.insert(ptr->get_id(), ptr);
                directors.clear();
                actors.clear();
                genres.clear();
                j++;}
        }
    return true;
}

Movie* MovieDatabase::get_movie_from_id(const string& id) const
{
    TreeMultimap<std::string,Movie*>::Iterator it = tmm.find(id);
    return it.get_value();
    // Replace this line with correct code.
}

vector<Movie*> MovieDatabase::get_movies_with_director(const string& director) const
{
    vector <Movie*> v;
    TreeMultimap<std::string,Movie*>::Iterator it = tmm.find(director);
    return v;  // Replace this line with correct code.
}

vector<Movie*> MovieDatabase::get_movies_with_actor(const string& actor) const
{
    return vector<Movie*>();  // Replace this line with correct code.
}

vector<Movie*> MovieDatabase::get_movies_with_genre(const string& genre) const
{
    return vector<Movie*>();  // Replace this line with correct code.
}
