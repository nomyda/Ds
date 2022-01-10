#pragma once
#include "Table/DSBaseTable.h"
#include "DSCameraTable.generated.h"

UENUM()
enum class ECameraType : int16
{
	Default UMETA(DisplayName = "Default Camera"),
	Max,
};

USTRUCT()
struct FDSCameraSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere) float FieldOfView;
	UPROPERTY(EditAnywhere) bool bConstrainAspectRatio;
	UPROPERTY(EditAnywhere) float AspectRatio;
	UPROPERTY(EditAnywhere) float PostProcessBlendWeight;
};

USTRUCT()
struct FDSCameraTransform
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere) FRotator Rotation;		// ī�޶� ȸ��
	UPROPERTY(EditAnywhere) float Zoom;				// ī�޶� ��
	UPROPERTY(EditAnywhere) FVector Offset;			// ȸ��, �� ��ġ���� ������
};

USTRUCT()
struct FDSCameraViewTarget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere) TWeakObjectPtr<AActor> Target;	// ī�޶� ����ġ�� Ÿ�� ����
	UPROPERTY(EditAnywhere) FVector Location;				// ī�޶� ����ġ�� Ÿ�� ��ġ(Ÿ�� ���Ͱ� ���ٸ�)
	UPROPERTY(EditAnywhere) FName Socket;					// ī�޶� ����ġ�� Ÿ�� ������ ����
	UPROPERTY(EditAnywhere) FRotator Rotation;				// ī�޶� ����ġ�� Ÿ�� ȸ����
	UPROPERTY(EditAnywhere) FVector Offset;					// ī�޶� ����ġ�� Ÿ�� ������
};

USTRUCT()
struct FDSCameraTable : public FDSBaseTable
{
	GENERATED_BODY()

public:
	FDSCameraTable()
		: Super()
	{

	}

	UPROPERTY(EditAnywhere) FDSCameraSettings Settings;
	UPROPERTY(EditAnywhere) FDSCameraTransform Transform;
	UPROPERTY(EditAnywhere) FDSCameraViewTarget ViewTarget;
};	