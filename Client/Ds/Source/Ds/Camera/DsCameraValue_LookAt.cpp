#include "DsCameraValue_LookAt.h"

FDsCameraValue_LookAt::FDsCameraValue_LookAt()
: m_Offset(FVector::ZeroVector)
, m_fInitVelocity(0.0f)
, m_fFinalVelocity(0.0f)
, m_fSec_To_FinalVelocity(0.0f)
, m_fBlendSec(1.0f)
{
}

FDsCameraValue_LookAt::~FDsCameraValue_LookAt()
{
}
