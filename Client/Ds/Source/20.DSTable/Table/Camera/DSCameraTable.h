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
	UPROPERTY(EditAnywhere) FRotator Rotation;		// 카메라 회전
	UPROPERTY(EditAnywhere) float Zoom;				// 카메라 줌
	UPROPERTY(EditAnywhere) FVector Offset;			// 회전, 줌 위치에서 오프셋
};

USTRUCT()
struct FDSCameraViewTarget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere) TWeakObjectPtr<AActor> Target;	// 카메라가 어태치될 타겟 액터
	UPROPERTY(EditAnywhere) FVector Location;				// 카메라가 어태치될 타겟 위치(타겟 액터가 없다면)
	UPROPERTY(EditAnywhere) FName Socket;					// 카메라가 어태치될 타겟 액터의 소켓
	UPROPERTY(EditAnywhere) FRotator Rotation;				// 카메라가 어태치될 타겟 회전값
	UPROPERTY(EditAnywhere) FVector Offset;					// 카메라가 어태치될 타겟 오프셋
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