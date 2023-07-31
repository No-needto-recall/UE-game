// Fill out your copyright notice in the Description page of Project Settings.


#include "HOME_UI_CPP.h"

#include "Components/Button.h"

bool UHOME_UI_CPP::Initialize()
{
	return Super::Initialize();
}

void UHOME_UI_CPP::NativeConstruct()
{
	Super::NativeConstruct();

	if(Button1)
	{
		Button1->OnClicked.__Internal_AddDynamic(
			this,&UHOME_UI_CPP::Button1Click,FName("Button1Click"));
	}
}

void UHOME_UI_CPP::Button1Click()
{
	GEngine->AddOnScreenDebugMessage(
		-1,3.f,FColor::Red,TEXT("按钮点击"));
}
