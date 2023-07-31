// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"

#include "MyGameInstanceSubsystemForUI.h"
#include "MyUserWidget.h"
#include "Kismet/GameplayStatics.h"

void AMyHUD::BeginPlay() {
	Super::BeginPlay();

	//创建一个控件
#if 0 
	UMyUserWidget* TmpWidget= CreateWidget<UMyUserWidget>
	(GetWorld(),MyClass1);
#endif
	GetWorld()->GetGameInstance()->GetSubsystem<UMyGameInstanceSubsystemForUI>()->ShowWidgetWithType(MyClass1);
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
