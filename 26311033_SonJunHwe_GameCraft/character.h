#pragma once
#include "main.h"
#include "item.h"

class character
{
public:
	void Initialize();
	void Main();
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

private:
	int m_lv{};
	int m_maxHp{};
	int m_hp{};
	int m_str{};
	int m_dex{};
	int m_con{};
	int m_int{};
	int m_wis{};
	int m_chr{};
public:
	vector<void*> itemsP{};
};