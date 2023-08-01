// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyConfigDataBase.h"
#include "XmlFile.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "XMLSubsystem.generated.h"

using FXmlName = FString;


UCLASS()
class BOSI_API UXMLSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	//加载指定类型的配置文件
	template <typename T>
	T* LoadConfigFile(const FXmlName& ConfigFileName)
	{
		static_assert(TIsDerivedFrom<T, UMyConfigDataBase>::IsDerived,
			"T must be derived from UMyConfigDataBase");
		//解析XML文件
		FXmlFile ConfigFile(ConfigFileName);
		FXmlNode* RootNode = ConfigFile.GetRootNode();
		//...
		//创建一个新的UObject实例来缓存配置数据
		T* ConfigData = NewObject<T>();
		// 将解析后的数据赋值给这个实例
		if constexpr (TIsDerivedFrom<T, UMyConfigDataBase>::IsDerived) {
			ConfigData->LoadFromXML(RootNode);
			MapForConfigData.Add(ConfigFileName,ConfigData);
		}
		return ConfigData;
	}

	//获取指定类型的配置信息
	/*template<typename T>
	T* GetConfigInfo(const XmlName& ConfigKey)
	{
		
	}
	*/
	
private:
	TMap<FXmlName,UMyConfigDataBase> MapForConfigData;
};
