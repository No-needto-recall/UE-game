// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstanceSubsystemForUI.h"
#include "MyUserWidget.h"

void UMyGameInstanceSubsystemForUI::ShowWidgetWithType(TSubclassOf<UMyUserWidget> Type)
{
	FString Tmp = Type->GetName() + "need show";
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, Tmp);
	UMyUserWidget** Search = MapForWidget.Find(Type);
	if (Search == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,TEXT("展示新的控件"));
		//这个需要展示的控件是新的，需要被创建然后添加。
		UMyUserWidget* NewWidget = CreateWidget<UMyUserWidget>
			(GetWorld(), Type);

		if (NewWidget != nullptr)
		{
			//增加键值对
			MapForWidget.Add(Type, NewWidget);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,TEXT("创建新的控件"));
			AddWidgetToView(NewWidget);
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,TEXT("展示已有的控件"));
		AddWidgetToView(*Search);
	}
}

void UMyGameInstanceSubsystemForUI::HideWidgetWithType(TSubclassOf<UMyUserWidget> Type)
{
	UMyUserWidget** Search = MapForWidget.Find(Type);
	if (Search != nullptr)
	{
		HideWidget(*Search);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("尝试隐藏widget为不在Map中"));
	}
}

bool UMyGameInstanceSubsystemForUI::SwitchWidgetShowOrHideWithType(TSubclassOf<UMyUserWidget> Type)
{
	auto Widget = GetUIWidgetWithType(Type);
	if (Widget)
	{
		if (Widget->Attribute.IsShowing)
		{
			HideWidget(Widget);
		}
		else
		{
			AddWidgetToView(Widget);
		}
		return Widget->Attribute.IsShowing;
	}
	else
	{
		ShowWidgetWithType(Type);
		UE_LOG(LogTemp, Warning, TEXT("SwitchWidget widget=nullptr"));
		return true;
	}
}

void UMyGameInstanceSubsystemForUI::AddWidgetToView(UMyUserWidget* Widget)
{
	if (Widget)
	{
		if (Widget->Attribute.IsHideOther)
		{
			HideAllWidget();
		}
		Widget->AddToViewport();
		Widget->Attribute.IsShowing = true;
		Widget->Onshow();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("尝试添加到视口的widget为nullptr"));
	}
}

UMyUserWidget* UMyGameInstanceSubsystemForUI::GetUIWidgetWithType(TSubclassOf<UMyUserWidget> Type)
{
	UMyUserWidget** Search = MapForWidget.Find(Type);
	if (Search != nullptr)
	{
		return *Search;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("尝试获取的widget为不在Map中"));
		return nullptr;
	}
}

void UMyGameInstanceSubsystemForUI::HideAllWidget()
{
	for (auto& widget : MapForWidget)
	{
		HideWidget(widget.Value);
	}
}

void UMyGameInstanceSubsystemForUI::HideWidget(UMyUserWidget* Widget)
{
	if (Widget)
	{
		//如果不是持久化UI
		if (!Widget->Attribute.IsPersistent)
		{
			//如果UI是showing状态，则从父项中移除
			if (Widget->Attribute.IsShowing)
			{
				Widget->RemoveFromViewport();
				Widget->Attribute.IsShowing = false;
				Widget->OnHide();
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("尝试隐藏的widget为nullptr"));
	}
}
