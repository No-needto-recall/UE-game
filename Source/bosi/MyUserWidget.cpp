// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/CanvasPanel.h"
#include "Components/Image.h"

bool UMyUserWidget::Initialize() {
	if (!Super::Initialize()) {
		return false;
	}
	if (button1) {
	}else
	{
		CreateWidget<>()
	}


	return true;
}

void UMyUserWidget::NativeConstruct() {

}
