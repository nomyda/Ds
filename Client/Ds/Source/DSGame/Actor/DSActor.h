#pragma once
#include "Attr/DSAttribute.h"
#include "Attr/DSSituation.h"

struct FDSActorTable;

class DSActor
{
public:
	DSActor(uint32 Guid, const FDSActorTable* pActorTable, const FVector& vPos, const float fAngle);
	uint32 Guid() const { return m_Guid; }
	const FDSActorTable* ActorTable() const { return m_pActorTable; }
	DSAttribute& Attribute() { return m_Attribute; }
	DSSituation& Situation() { return m_Situation; }

private:
	uint32 m_Guid;
	const FDSActorTable* m_pActorTable;
	DSAttribute m_Attribute;
	DSSituation m_Situation;
};