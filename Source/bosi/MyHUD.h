// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class BOSI_API AMyHUD : public AHUD
{
	GENERATED_BODY()
public:
	//重写beginPlay
	virtual void BeginPlay()override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "HUD CPP")
	FString _myTestString = "hello world";

	UPROPERTY(EditAnywhere,Category = "UserWidgetFromCpp")
	UClass* _myClass1;
};
