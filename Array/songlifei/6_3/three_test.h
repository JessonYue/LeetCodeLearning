//
// Created by DF on 2020/6/3.
//

#ifndef LEETCODELEARNING_THREE_TEST_H
#define LEETCODELEARNING_THREE_TEST_H


class three_test {

    /**
     *
     */

    string haystack  = "Hello";
    string needle  = "o";


    if(needle.empty()){
        std::cout<<0<<endl;
        return 0;

    }

    for(int i = 0 ; i <haystack.length();i++){
        if(haystack.substr(i,needle.length())==needle){
            std::cout<< i << endl ;
        }
    }
    return 0 ;

};


#endif //LEETCODELEARNING_THREE_TEST_H
