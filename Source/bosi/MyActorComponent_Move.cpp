// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorComponent_Move.h"

 void UMyActorComponent_Move::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction){
	 Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	 //pawn为空，没有更新组件，需要跳过循环
	 if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime)) {
		 return;
	}

	 //获取移动向量
	 //GetClampedToMaxSize()截断向量
	 FVector moveMent =  ConsumeInputVector().GetClampedToMaxSize(1.0f);
	 if (moveMent.IsNearlyZero()) {
		 return;
	 }
	 else {
		 //根据deltaTime修改
		 moveMent *= DeltaTime * 200.f;
	 }

	 //调用安全移动函数，消耗移动
	 FHitResult hit;
	 this->SafeMoveUpdatedComponent(moveMent,
		 UpdatedComponent->GetComponentRotation(),
		 true,hit);
}

