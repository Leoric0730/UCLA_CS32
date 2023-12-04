

    void removeOdd(list<int>& li)
    {
        auto itr = li.begin();
        while (itr != li.end()){
            if (*itr %2 != 0) {itr = li.erase(itr);}
            else itr++;
        }
    }
