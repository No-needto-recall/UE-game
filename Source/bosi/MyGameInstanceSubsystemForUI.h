// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MyGameInstanceSubsystemForUI.generated.h"

/**
 * 
 */


UCLASS()
class BOSI_API UMyGameInstanceSubsystemForUI : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	//对外接口
	UFUNCTION(BlueprintCallable,Category = "UIManagerCPP")

	//根据类引用展示UI
	void ShowWidgetWithType(TSubclassOf<class UMyUserWidget> Type);
	//根据类引用隐藏UI
	void HideWidgetWithType(TSubclassOf<class UMyUserWidget> Type);
	//隐藏所有UI
	void HideAllWidget();
	//隐藏UI
	void HideWidget(UMyUserWidget* Widget);
	//添加UI到视口
	void AddWidgetToView(UMyUserWidget* Widget);

	//通过类引用获取UI
	UMyUserWidget* GetUIWidgetWithType(TSubclassOf<class UMyUserWidget> Type);
	
private:
	//注意保存是指针
	TMap<UClass*,UMyUserWidget*> MapForWidget;	
};
