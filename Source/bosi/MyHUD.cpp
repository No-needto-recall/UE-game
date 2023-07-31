// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"

#include "MyUserWidget.h"
#include "Kismet/GameplayStatics.h"

void AMyHUD::BeginPlay() {
	Super::BeginPlay();

	UMyUserWidget* TmpWidget= CreateWidget<UMyUserWidget>
	(GetWorld(),_myClass1);
	if(TmpWidget != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Red,TEXT("创建了的TmpWidget不为空"));
		TmpWidget->AddToViewport();	
	}else
	{
		GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Red,TEXT("创建了的TmpWidget不为空"));
	}

	//获取玩家控制器
	APlayerController* MyPlayerController = Cast<APlayerController>
		(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (MyPlayerController != nullptr) {
		//显示鼠标
		MyPlayerController->bShowMouseCursor = true;
		//设置鼠标输入模式
		const FInputModeGameAndUI InputMode;
		MyPlayerController->SetInputMode(InputMode);
	}
}
