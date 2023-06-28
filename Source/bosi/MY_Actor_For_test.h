// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "Camera/CameraActor.h"  // ACameraActor 类型所在的头文件
#include "GameFramework/Character.h"
#include "MY_Actor_For_test.generated.h"

UCLASS()
class BOSI_API AMY_Actor_For_test : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMY_Actor_For_test();
	
	//用于存储相机的指针
	// 定义一个摄像机对象
	UPROPERTY(EditAnywhere, Category = "Components")
	ACameraActor* _Camera_1;
	UPROPERTY(EditAnywhere, Category = "Components")
	ACameraActor* _Camera_2;

	// 用于追踪下一次应该切换到哪个摄像机
	bool bUseCamera1;
	
	FTimerHandle SwitchCameraTimerHandle;
	//玩家控制器
	APlayerController* PlayerController;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void SwitchCamera();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
