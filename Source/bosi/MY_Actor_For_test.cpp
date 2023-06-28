// Fill out your copyright notice in the Description page of Project Settings.


#include "MY_Actor_For_test.h"
#include "Components/SphereComponent.h"  //组件头文件
#include "Kismet/GameplayStatics.h" //UE玩家类相关头文件

// Sets default values
AMY_Actor_For_test::AMY_Actor_For_test()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USphereComponent* tmpSpComp = CreateDefaultSubobject<USphereComponent>(TEXT("root"));
	RootComponent = tmpSpComp;

	tmpSpComp->InitSphereRadius(45.f);
	tmpSpComp->SetCollisionProfileName(TEXT("Pawn"));

	// 设置初始摄像机为 CameraActorReference1
	PrimaryActorTick.bCanEverTick = true;
	bUseCamera1 = true;
}

// Called when the game starts or when spawned
void AMY_Actor_For_test::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (PlayerController != nullptr)
	{
		// 设置定时器，每隔三秒钟执行 SwitchCamera 函数
		GetWorld()->GetTimerManager().SetTimer(SwitchCameraTimerHandle, this, &AMY_Actor_For_test::SwitchCamera, 3.0f, true);
	}
	
}

void AMY_Actor_For_test::SwitchCamera()
{
	if (PlayerController != nullptr)
	{
		// 根据 bUseCamera1 的值来选择要切换到的摄像机
		ACameraActor* TargetCamera = bUseCamera1 ? this->_Camera_1: this->_Camera_2;

		if (TargetCamera != nullptr)
		{
			// 切换摄像机
			PlayerController->SetViewTargetWithBlend(TargetCamera, 0.5f);
		}

		// 切换 bUseCamera1 的值，这样下次调用 SwitchCamera 时会切换到另一个摄像机
		bUseCamera1 = !bUseCamera1;
	}
}

// Called every frame
void AMY_Actor_For_test::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

