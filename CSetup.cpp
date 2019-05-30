#include "stdafx.h"
#include "CSetup.h"
#include "file needed.h"

CSetup::CSetup( )
{

	pCombatControllerStarter = new CCombatController(1);
}
CSetup::~CSetup()
{
	delete(pCombatControllerStarter);
}
CCombatController* CSetup::GetCombatController()
{
	return  move(pCombatControllerStarter);
}