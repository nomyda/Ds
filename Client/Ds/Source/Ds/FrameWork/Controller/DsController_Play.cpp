#include "DsController_Play.h"



/*[작업필요]
* [작업중]asdw로 카메라 이동하기
* 좌드래그로 선택 영역 안에 있는 캐릭터 선택하기
* 좌클릭으로 캐릭터 선택
* 좌클릭으로 선택한 명령이 있을때 처리
* 좌더블클릭으로 선택한 캐릭터와 동일한 타입의 여러 캐릭터 선택
* 시프트 + 좌드래그로 선택한 캐릭터에 추가
* 우클릭으로 이동 명령
*/
void ADsPlayerController_Play::BeginPlay()
{
}

void ADsPlayerController_Play::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (nullptr == InputComponent)
		return;

}

void ADsPlayerController_Play::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}
