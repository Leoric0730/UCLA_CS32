

#include "Set.h"
    #include <iostream>
    #include <cassert>

using namespace std;

    int main()
    {
        Set ss;
            ss.insert("dosa");
            assert(!ss.contains(""));
            ss.insert("tortilla");
            ss.insert("");
            ss.insert("focaccia");
            assert(ss.contains(""));
            ss.erase("dosa");
            assert(ss.size() == 3  &&  ss.contains("focaccia")  &&  ss.contains("tortilla")  &&
                        ss.contains(""));
            string v;
            assert(ss.get(1, v)  &&  v == "focaccia");
            assert(ss.get(0, v)  &&  v == "");
        cout <<"6" << endl;
}
