
    void removeBad(vector<Movie*>& v)
{
        auto itr = v.begin();
        while(itr != v.end()){
            if((*itr)->rating() < 50) { (*itr)->~Movie(); itr = v.erase(itr);}
            else
                itr ++;
        }
    }
    
