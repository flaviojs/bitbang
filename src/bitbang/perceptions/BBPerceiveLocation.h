//
// Created by João Simões on 11/07/17.
//

#ifndef BULLET_TEST_BBPERCEIVELOCATION_H
#define BULLET_TEST_BBPERCEIVELOCATION_H

#include <BBPerceptionBoolean.h>
#include <BBPoint.h>

namespace bitbang
{

class BBWorldInterface;

class BBPerceiveLocation : public BBPerceptionBoolean
{
public:
    BBPerceiveLocation(std::string pPerceptionName, BBWorldInterface* pWorldInterface);
    virtual ~BBPerceiveLocation();

protected:
    BBPoint perceivedLocation;
    bool hasLocation;
    
    BBWorldInterface *worldInterface;
};

}


#endif //BULLET_TEST_BBPERCEIVELOCATION_H