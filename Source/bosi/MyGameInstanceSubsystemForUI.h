// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MyGameInstanceSubsystemForUI.generated.h"

/**
 * 
 */

//控件基类的前置声明
class UMyUserWidget;

UCLASS()
class BOSI_API UMyGameInstanceSubsystemForUI : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	//对外接口
	
	//根据类引用展示UI
	UFUNCTION(BlueprintCallable,Category = "UIManagerCPP")
	void ShowWidgetWithType(TSubclassOf<UMyUserWidget> Type);
	//根据类引用隐藏UI
	UFUNCTION(BlueprintCallable,Category = "UIManagerCPP")
	void HideWidgetWithType(TSubclassOf<UMyUserWidget> Type);
	//根据类引用切换UI状态
	UFUNCTION(BlueprintCallable,Category = "UIManagerCPP")
	bool SwitchWidgetShowOrHideWithType(TSubclassOf<UMyUserWidget> Type);
	//隐藏所有UI
	void HideAllWidget();
	//隐藏UI
	void HideWidget(UMyUserWidget* Widget);
	//添加UI到视口
	void AddWidgetToView(UMyUserWidget* Widget);

	//通过类引用获取UI
	UMyUserWidget* GetUIWidgetWithType(TSubclassOf<UMyUserWidget> Type);
	
private:
	//注意保存是指针
	TMap<UClass*,UMyUserWidget*> MapForWidget;	
};
