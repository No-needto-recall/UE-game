// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyUserWidget.h"
#include "HOME_UI_CPP.generated.h"

/**
 * 
 */
UCLASS()
class BOSI_API UHOME_UI_CPP : public UMyUserWidget
{
	GENERATED_BODY()

	virtual bool Initialize() override;
	virtual void NativeConstruct() override;

	UFUNCTION()
	void Button1Click();
	
public:
	UPROPERTY(meta = (BindWidget))
	class UButton* Button1;
};
