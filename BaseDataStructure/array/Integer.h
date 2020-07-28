//
// Created by Jesson on 2020/7/18.
//

#ifndef BASEDATASTRUCTURE_INTEGER_H
#define BASEDATASTRUCTURE_INTEGER_H


typedef struct Integer{
    int retainCount;
    int value;

}Integer;

Integer* newInteger(int value);
int getIntegerValue(Integer* ins);


#endif //BASEDATASTRUCTURE_INTEGER_H
