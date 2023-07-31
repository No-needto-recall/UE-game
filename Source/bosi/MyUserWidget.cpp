// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/CanvasPanel.h"
#include "Components/Image.h"
#include "MyGameInstanceSubsystemForUI.h"

bool UMyUserWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}

	return true;
}

void UMyUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	UIManager = GetWorld()->GetGameInstance()->GetSubsystem<UMyGameInstanceSubsystemForUI>();
	if (UIManager == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,TEXT("UIManager为空"));
	}
}

void UMyUserWidget::Onshow()
{
	SynchronizationUI();
	FString tmp = this->GetName() + "OnShow";
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,
	                                 tmp);
}

void UMyUserWidget::OnHide()
{
}

void UMyUserWidget::OnDispose()
{
}

void UMyUserWidget::SynchronizationUI()
{
	//关联的UI
	for (auto& UI : AssociationUI)
	{
		auto RealUI = UIManager->GetUIWidgetWithType(UI);
		if (!(RealUI->Attribute.IsShowing))
		{
			UIManager->ShowWidgetWithType(UI);
		}
	}
	//互斥的UI
	for (auto& UI : MutualExclusionUI)
	{
		auto RealUI = UIManager->GetUIWidgetWithType(UI);
		if (RealUI->Attribute.IsShowing)
		{
			UIManager->HideWidgetWithType(UI);
		}
	}
}
