#include "DSFormula.h"

DSFormula_Operator::DSFormula_Operator(const EFormulaOperator eOperator, const int32 iScopeDepth)
	: m_eOperator(eOperator)
	, m_iScopeDepth(iScopeDepth)
{

}

EFormulaOperator DSFormula_Operator::Operator() const
{
	return m_eOperator;
}