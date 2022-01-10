#include "DSFormula.h"

DSFormula_String::DSFormula_String(const FString& Formula)
{	
	Extract(Formula);
}

bool DSFormula_String::Extract(const FString& Formula)
{
	int32 iCurIndex = 0;
	int32 iPrevIndex = 0;
	int32 iCurScopeDepth = 0;
	TArray<FString> SplitString;
	const TCHAR OperatorChar[static_cast<int32>(EFormulaOperator::Max)] = { ' ', '(', '*', '/', '+', '-', ')' };
	for (; iCurIndex < Formula.Len(); ++iCurIndex)
	{
		const TCHAR CurChar = Formula[iCurIndex];
		for (int32 iOperatorIndex = 0; iOperatorIndex < static_cast<int32>(EFormulaOperator::Max); ++iOperatorIndex)
		{
			const TCHAR CurOperatorChar = OperatorChar[iOperatorIndex];
			const EFormulaOperator eCurOperator = static_cast<EFormulaOperator>(iOperatorIndex);
			if (CurChar == CurOperatorChar)
			{
				const int32 iLeftLen = iCurIndex - iPrevIndex;
				if (iLeftLen > 0)
				{
					const FString LeftValue = Formula.Mid(iPrevIndex, iLeftLen);
					SharedFormulaPtr kLeftFormulaValuePtr = SharedFormulaPtr(new DSFormula_Value(LeftValue));
					m_ArrSharedFormulaPtr.Push(kLeftFormulaValuePtr);
				}

				if (eCurOperator == EFormulaOperator::Scope_Begin)
					++iCurScopeDepth;

				if (eCurOperator != EFormulaOperator::None)
				{
					SharedFormulaPtr kFormulaOperatorPtr = SharedFormulaPtr(new DSFormula_Operator(eCurOperator, iCurScopeDepth));
					m_ArrSharedFormulaPtr.Push(kFormulaOperatorPtr);
				}

				if (eCurOperator == EFormulaOperator::Scope_End)
					--iCurScopeDepth;

				iPrevIndex = iCurIndex + 1;
				break;
			}
		}
	}

	const int32 iRightLen = iCurIndex - iPrevIndex;
	if (iRightLen > 0)
	{
		const FString RightValue = Formula.Mid(iPrevIndex, iRightLen);
		SharedFormulaPtr kRightFormulaValuePtr = SharedFormulaPtr(new DSFormula_Value(RightValue));
		m_ArrSharedFormulaPtr.Push(kRightFormulaValuePtr);
	}

	return m_ArrSharedFormulaPtr.Num() > 0;
}

float DSFormula_String::Calculation()
{
	if (m_ArrSharedFormulaPtr.Num() == 0)
		return 0.0f;

	for (int32 iCurIndex = 0; iCurIndex < m_ArrSharedFormulaPtr.Num(); ++iCurIndex)
	{
		SharedFormulaPtr& CurFormula = m_ArrSharedFormulaPtr[iCurIndex];
		if (CurFormula->Type() == EFormulaType::Value)
		{
			//m_ArrSharedValuePtr.Push(CurFormula);

			// ����ϴ� ���� : ������ ���϶�
			if ((iCurIndex + 1) == m_ArrSharedFormulaPtr.Num())
			{
				IntermediateCalculation();
			}
		}
		else if (CurFormula->Type() == EFormulaType::Operator)
		{
			DSFormulaBase* pCurBase = CurFormula.Get();
			DSFormula_Operator* pCurOperator = static_cast<DSFormula_Operator*>(pCurBase);
			bool bIntermediateCalc = false;
			if (pCurOperator->Operator() != EFormulaOperator::Scope_End)
			{
				// ����ȣ �߰� ���� : ��ȣ �ݱ⸸ �߰����� �ʴ´�
				//m_ArrSharedOperatorPtr.Push(pCurOperator);
			}

			// ����ϴ� ���� : 
			// => 1.��ȣ�� ������ 
			// => 2.�տ� ����ȣ�� �ϳ� �� ������
			//if (pCurOperator->Operator() != EFormulaOperator::Scope_End || m_ArrSharedOperatorPtr.Num() >= 2)
			{
				IntermediateCalculation();
			}
		}
	}

	return 0.0f;
}

bool DSFormula_String::IntermediateCalculation()
{
	// ����ϴ� ���� : 
	// => 1.��ȣ�� ������ 
	// => 2.�տ� ����ȣ�� �ϳ� �� ������
	return false;
}