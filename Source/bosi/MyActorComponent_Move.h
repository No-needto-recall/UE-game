// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "MyActorComponent_Move.generated.h"

/**
 * 
 */
UCLASS()
class BOSI_API UMyActorComponent_Move : public UPawnMovementComponent
{
	GENERATED_BODY()
public:

	//从ActorMovementComponent继承的
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)override;


};
