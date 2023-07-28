// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "Kismet/GameplayStatics.h"

void AMyHUD::BeginPlay() {
	Super::BeginPlay();
	APlayerController* myPlayerController = Cast<APlayerController>
		(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (myPlayerController != nullptr) {
		myPlayerController->bShowMouseCursor = true;
	}
}
