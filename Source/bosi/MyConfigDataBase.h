// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "XmlNode.h"
#include "UObject/NoExportTypes.h"
#include "MyConfigDataBase.generated.h"


//数据基类
UCLASS()
class BOSI_API UMyConfigDataBase : public UObject
{
	GENERATED_BODY()
	//设计一个纯虚函数，用于根据XML加载数据
	virtual bool LoadDataWithXml(const FXmlNode* Node)
	PURE_VIRTUAL(UMyConfigDataBase::LoadDataWithXml, return false;);
};

UCLASS()
class BOSI_API UPlayerConfigdata:public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlayerConfigData")
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlayerConfigData")
	int32 Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlayerConfigData")
	int32 Hp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlayerConfigData")
	int32 Mp;
};



//数据派生类
UCLASS(Blueprintable)
class BOSI_API UMyPlayerConfigData : public UMyConfigDataBase
{
	GENERATED_BODY()

public:
	//实现纯虚函数
	virtual bool LoadDataWithXml(const FXmlNode* Node) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlayerConfigData")
	TArray<UPlayerConfigdata*> PlayerConfigDatas;
	
};
