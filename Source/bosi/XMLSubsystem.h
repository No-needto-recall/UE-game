// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyConfigDataBase.h"
#include "XmlFile.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "XMLSubsystem.generated.h"


UCLASS()
class BOSI_API UXMLSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	//加载指定类型的配置文件
	template <typename T>
	T* LoadConfigFile(const FString& ConfigFileName)
	{
		//断言
		static_assert(TIsDerivedFrom<T, UMyConfigDataBase>::IsDerived,
		              "T must be derived from UMyConfigDataBase");
		//解析XML文件
		const FString Path = FPaths::ProjectContentDir() / TEXT("my/XML/") + ConfigFileName;
		FXmlFile ConfigFile(Path);
		if (!ConfigFile.IsValid())
		{
			UE_LOG(LogTemp, Error, TEXT("XML File error: %s"),
			       *ConfigFile.GetLastError());
			return nullptr;
		}
		//获取根节点
		FXmlNode* RootNode = ConfigFile.GetRootNode();
		//创建一个新的UObject实例来缓存配置数据
		T* ConfigData = NewObject<T>();
		// 将解析后的数据赋值给这个实例
		if (ConfigData->LoadDataWithXml(RootNode))
		{
			MapForConfigData.Add(ConfigFileName, ConfigData);
			return ConfigData;
		}
		//如果加载失败，无法确定是因为文件无效还是解析错误而返回的nullptr
		return nullptr;
	}

	//获取指定类型的配置信息
	template <typename T>
	T* GetConfigInfo(const FString& ConfigKey)
	{
		//断言
		static_assert(TIsDerivedFrom<T, UMyConfigDataBase>::IsDerived,
		              "T must be derived from UMyConfigDataBase");
		UMyConfigDataBase** ConfigData = MapForConfigData.Find(ConfigKey);
		if (ConfigData)
		{
			return Cast<T>(*ConfigData);
		}
		else
		{
			return LoadConfigFile<T>(ConfigKey);
		}
	}


	//方便蓝图调取
	UFUNCTION(BlueprintCallable, Category = "XML")
	UMyPlayerConfigData* GetPlayerConfigData();

#if 0
	//测试函数	
	UFUNCTION(BlueprintCallable, Category = "XML")
	void TestForLoadXML(const FString& ConfigFileName);
#endif

private:
	UPROPERTY()
	TMap<FString, UMyConfigDataBase*> MapForConfigData;
};
