#include "DsController_Play.h"



/*[�۾��ʿ�]
* [�۾���]asdw�� ī�޶� �̵��ϱ�
* �µ巡�׷� ���� ���� �ȿ� �ִ� ĳ���� �����ϱ�
* ��Ŭ������ ĳ���� ����
* ��Ŭ������ ������ ����� ������ ó��
* �´���Ŭ������ ������ ĳ���Ϳ� ������ Ÿ���� ���� ĳ���� ����
* ����Ʈ + �µ巡�׷� ������ ĳ���Ϳ� �߰�
* ��Ŭ������ �̵� ���
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
