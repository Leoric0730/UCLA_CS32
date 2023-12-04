
    void removeBad(list<Movie*>& li)
{
        auto itr = li.begin();
        while(itr != li.end()){
            if((*itr)->rating() < 50) { (*itr)->~Movie(); itr = li.erase(itr);}
        else
            itr ++;
        }
    }
