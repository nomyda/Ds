#pragma once

enum class EFormulaType : int32
{
	None,
	String,
	Operator,
	Value,
	Max,
};

enum class EFormulaOperator : int32
{
	None,
	Scope_Begin,
	Multiply,
	Division,
	Plus,
	Subtract,
	Scope_End,
	Max,
};


class DSFormulaBase
{
public:
	virtual ~DSFormulaBase() {}
	virtual EFormulaType Type() const = 0;
};


class DSFormula_Operator : public DSFormulaBase
{
public:
	DSFormula_Operator(const EFormulaOperator eOperator, const int32 iScopeDepth);
	EFormulaType Type() const override { return EFormulaType::Operator; }
	EFormulaOperator Operator() const;

private:
	const EFormulaOperator m_eOperator;
	const int32 m_iScopeDepth;
};


class DSFormula_Value : public DSFormulaBase
{
public:
	DSFormula_Value(const FString& Value);
	EFormulaType Type() const override { return EFormulaType::Value; }

private:
	FString m_ValueString;
	float m_fValue;
	bool m_bExtract;
};


class DSFormula_String : public DSFormulaBase
{
public:
	typedef TSharedPtr<DSFormulaBase> SharedFormulaPtr;

	DSFormula_String(const FString& Formula);
	EFormulaType Type() const override { return EFormulaType::String; }
	float Calculation();

private:
	bool Extract(const FString& Formula);
	bool IntermediateCalculation();

private:
	TArray<SharedFormulaPtr> m_ArrSharedFormulaPtr;
};