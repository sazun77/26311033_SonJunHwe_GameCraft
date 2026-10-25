#pragma once
#include "main.h"
#include "character.h"

class item
{
public:
	void Initialize();
	void main();
	void Delete();
private:
	void PhaseForeBattleStart();
	void PhaseBattleStart();

	void PhaseForeTurnStart();
	void PhaseTurnStart();

	void PhaseForeActionStart();
	void PhaseActionStart();

	void PhaseForeAttackStart();
	void PhaseAttackStart();
	void PhaseGetAttacked();
	void PhaseAttacked();
	void PhaseDead();
	void PhaseKilled();

	void PhaseAttackEnd();
	void PhaseTurnEnd();
	void PhaseBattleEnd();

public:
	void* m_ownerP{};
};

