/*!
 * 
 * Copyright (c) 2009 by Tiago Baptista. All rights reserved.
 *
 */

#ifndef ANTAGENT_H_
#define ANTAGENT_H_

#include "CSimObject.h"
#include "BBTypes.h"
#include <string>
#include "irrlicht.h"
#include "AntBrainConfig.h"

using namespace bitbang;
using namespace std;

class AntAgent : public CSimObject
{
public:
	static const int CLASSID = 1001;
	
	static int m_nAgentCount;
	
	AntAgent(irr::IrrlichtDevice* p_device, ofstream* logBrain);
	virtual ~AntAgent();
	
	void InitBase();
	void InitRandomBrain();
	void InitTestBrain();
    void InitCustomBrain();
	virtual bool Init();
	virtual void Die();
	virtual void Reproduce(bool b_is_forced);
	
	virtual void OnObjectUpdate();
	virtual void OnSelect();
	virtual void OnDeselect();
	
	void SetForced(){m_bForced = true;};
	void SetRandom(){m_bRandom = true;};
	void IncreaseGatheredEnergy(double d_energy){m_dGatheredEnergy += d_energy;};
	void SetEditions(int n_editions){m_nEditions = n_editions;};
	void SetParentID(int n_id){m_nParentID = n_id;};
    void SetCustomBrain(AntBrainConfig* customBrain) { m_CustomBrain = customBrain;};
    
	int GetNumberChildren(){return m_nChildren;};
	BBTime GetAge();
	double GetGatheredEnergy(){return m_dGatheredEnergy;};
    
    BBPoint GetRelativePositionToGridCell(BBPoint pCellCenter);

	int GetPheromoneLocation(int pPheromoneType);
    
    int GetBrainSize(){return m_nBrainSize;};
	
protected:
	virtual void LogDeath();
	
private:
	std::string GetInfoText();	
	
	int m_nMaxAge;
	int m_nChildren;
	double m_dGatheredEnergy;
	BBTime m_BirthDate;
	bool m_bForced;
	bool m_bRandom;
	BBTime m_dLastUpdate;
	std::vector<float> m_DeathLogFieldValues;
	int m_nBrainSize;
	int m_nEditions;
	int m_nParentID;
    ofstream* m_LogBrainStream;
    
    AntBrainConfig* m_CustomBrain;

	double m_nPheromonesPlaced;
    
	irr::gui::IGUIStaticText* m_pInfoBox;
};


#endif //ANTAGENT_H_