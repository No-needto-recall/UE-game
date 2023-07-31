// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_Manager_cpp.h"

#include "MyUserWidget.h"

// Sets default values
AUI_Manager_cpp::AUI_Manager_cpp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUI_Manager_cpp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUI_Manager_cpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUI_Manager_cpp::ShowWidgetWithType(TSubclassOf<UMyUserWidget> Type)
{
	const auto Search = MapForWidget.find(Type);
	if(Search != MapForWidget.end())
	{
		//这个需要展示的控件是新的，需要被创建然后添加。
		UMyUserWidget* NewWidget = CreateWidget<UMyUserWidget>
		(GetWorld(),Type);

		if(NewWidget != nullptr)
		{
			//增加键值对
			MapForWidget.emplace(Type,NewWidget);
			GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Red,TEXT("创建新的控件"));			
		}
		
	}
}

