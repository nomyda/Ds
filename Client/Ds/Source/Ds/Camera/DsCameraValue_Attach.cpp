#include "DsCameraValue_Attach.h"

FDsCameraValue_Attach::FDsCameraValue_Attach()
: m_Offset(FVector::ZeroVector)
, m_fZoom(0.0f)
, m_fYaw(0.0f)
, m_fPitch(0.0f)
, m_fRoll(0.0f)
, m_fInitVelocity(0.0f)
, m_fFinalVelocity(0.0f)
, m_fSec_To_FinalVelocity(0.0f)
, m_fBlendSec(1.0f)
{
}

FDsCameraValue_Attach::~FDsCameraValue_Attach()
{
}
