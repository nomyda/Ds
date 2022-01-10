#include "DSActor.h"

DSActor::DSActor(uint32 Guid, const FDSActorTable* pActorTable, const FVector& vPos, const float fAngle)
	: m_Guid(Guid)
	, m_pActorTable(pActorTable)
	, m_Situation(vPos, fAngle)
{

}