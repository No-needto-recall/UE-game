// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <unordered_map>
#include "GameFramework/Actor.h"
#include "UI_Manager_cpp.generated.h"

class UMyUserWidget;

using std::unordered_map;

UCLASS()
class BOSI_API AUI_Manager_cpp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUI_Manager_cpp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//对外接口
	UFUNCTION(BlueprintCallable,Category = "UIManagerCPP")
	void ShowWidgetWithType(TSubclassOf<class UMyUserWidget> Type);
	
private:
	//注意保存是指针
	unordered_map<UClass*,UMyUserWidget*> MapForWidget;	
};
