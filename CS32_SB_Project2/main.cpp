//
//  main.cpp
//  CS32_SB_Project2
//
//  Created by HaoYu Luo on 2023/1/31.
//

//#include "Set.h"
//        #include <iostream>
//        #include <cassert>
//        using namespace std;
//
//        void test()
//        {
//            Set uls;
//            assert(uls.insert(20));     // check if insert function can properly work.
//            assert(uls.insert(10));
//            assert(!uls.empty());       // check if empty function work correctly.
//            assert(uls.size() == 2);    // check the size function.
//            assert(uls.contains(10));   // check both cases of contains function
//            assert(!uls.contains(50));
//            ItemType x = 30;
//            assert(uls.get(0, x)  &&  x == 10);  // check if get function properly return value as desired
//            assert(uls.get(1, x)  &&  x == 20);
//            assert(!uls.get(4,x) && x == 20); // check if get function return false when pos is inappropriate
//                                              // and leave the x unchanged.
//            assert(uls.insert(30));
//            uls.dump();
//
//            Set uos;
//            assert(uos.insert(30));
//            assert(uos.insert(10));
//            assert(uos.insert(40));
//            assert(!uos.insert(10));
//            assert(!uos.erase(20));   //check if erase function return false when the argument is missing.
//            assert(uos.erase(10));
//            uos.dump();  // check if erase function correctly erase 10 from the list.
//
//            uos.swap(uls);
//            uos.dump();  // check if swap function correctly exchange elements of the two list.
//
//            Set result;
////            unite (uls,uos,result);
////            result.dump(); //check if unite functions as desired.
//            butNot (uls,uos,result);   // check if butNot fucntions as desired.
//            result.dump();
//        }
//
//        int main()
//        {
//            test();
//            cout << "Passed all tests" << endl;
//        }
