#include "DSFormula.h"

DSFormula_Value::DSFormula_Value(const FString& Value)
	: m_fValue(0.0f)
	, m_bExtract(false)
{
	if (Value.IsNumeric())
	{
		m_bExtract = true;
		m_fValue = FCString::Atof(*Value);
	}
	else
		m_ValueString = Value;
}