

    void removeOdd(vector<int>& v)
{
        auto itr = v.begin();
        while (itr != v.end()){
            if (*itr %2 != 0) {itr = v.erase(itr);}
            else itr++;
        }
    }

