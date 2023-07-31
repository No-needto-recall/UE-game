// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class BOSI_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual bool Initialize()override;

	virtual void NativeConstruct()override;

public:
	UPROPERTY(Meta = (BindWidget))
	class UButton* button1;

	UPROPERTY(Meta = (BindWidget))
	class UTextBlock* TextBlock1;
};
