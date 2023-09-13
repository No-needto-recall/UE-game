// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"//UE核心编译环境的类型和函数文件
#include "GameFramework/Actor.h"//基类头文件
#include "MyActor_Test.generated.h"//反射头文件 自动创建


//为UObject提供一个UClass的引用，用于描述虚幻类的类型信息
//每个UClass保留一个，类默认对象(class default object)的对象CDO
//UCLASS和CDO为特定对象实例的恢复提供了数据支持，所以通常是只读。
//GetClass()返回UCLASS信息。
//UCLASS(BlueprintType)   ：表明这个类可以在蓝图中被实例化
//UFUNCTION(BlueprintCallable)  :加载函数前面
//UPROPERTY(BlueprintReadWrite)   :加上属性前面
UCLASS()
class BOSI_API AMyActor_Test : public AActor
{
	//必须放置在类的最前方
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	//构造器，构造函数
	AMyActor_Test();

	UPROPERTY(VisibleAnywhere,Category = "ActorComp")
	UStaticMeshComponent* staticMesh;

	UPROPERTY(EditInstanceOnly, Category = "ActorProperty")
	FVector v1;
	
	UPROPERTY(VisibleInstanceOnly,Replicated, Category = "ActorProperty")
	FVector v2;

	//UPROPERTY(EditReadOnly, Category = "ActorProperty")
	//FVector v2;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
