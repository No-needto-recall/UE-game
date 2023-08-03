// Fill out your copyright notice in the Description page of Project Settings.


#include "XMLSubsystem.h"

UMyPlayerConfigData* UXMLSubsystem::GetPlayerConfigData()
{
	return  GetConfigInfo<UMyPlayerConfigData>(FString("PlayerConfig.xml"));
}

void UXMLSubsystem::TestJsonSave()
{
	const FString FilPath = FPaths::ProjectContentDir()/TEXT("Data.json");
	FString JSONStr;

	TSharedPtr<TJsonWriter<>> JsonWriter = TJsonWriterFactory<>::Create(&JSONStr);
	JsonWriter->WriteObjectStart();
	JsonWriter->WriteValue(TEXT("data1"),TEXT("1002"));
	JsonWriter->WriteValue(TEXT("data2"),TEXT("1004"));
	JsonWriter->WriteValue(TEXT("data3"),TEXT("1006"));
	JsonWriter->WriteObjectEnd();
	//关闭写入流
	JsonWriter->Close();
	FFileHelper::SaveStringToFile(JSONStr,*FilPath);
}

void UXMLSubsystem::TestJsonLoad()
{
	const FString FilPath = FPaths::ProjectContentDir()/TEXT("Data.json");
	// 读取文件内容
    	FString jsonString;
    	FFileHelper::LoadFileToString(jsonString, *FilPath);
    
    	// 创建一个JSON阅读器
    	TSharedRef<TJsonReader<>> jsonReader = TJsonReaderFactory<>::Create(jsonString);
    
    	// 用于保存反序列化后的JSON对象
    	TSharedPtr<FJsonObject> jsonObject;
    
    	// 反序列化
    	if (FJsonSerializer::Deserialize(jsonReader, jsonObject) && jsonObject.IsValid())
    	{
    		// 获取并打印字段的值
    		FString data1 = jsonObject->GetStringField(TEXT("data1"));
    		FString data2 = jsonObject->GetStringField(TEXT("data2"));
    		FString data3 = jsonObject->GetStringField(TEXT("data3"));
    
    		UE_LOG(LogTemp, Warning, TEXT("json msg:--> Data1: %s, Data2: %s, Data3: %s"), *data1, *data2, *data3);
    	}
	
}

#if 0 
void PrintNodeRecursive(FXmlNode* node,int depth)
{
	// Print the node tag and content with indentation based on depth
	FString indentation = FString::ChrN(depth, '\t');
	UE_LOG(LogTemp, Log, TEXT("%sNode: %s, Content: %s"), *indentation, *node->GetTag(), *node->GetContent());

	// Print all attributes
	for (auto& attr : node->GetAttributes())
	{
		UE_LOG(LogTemp, Log, TEXT("%sAttribute: %s, Value: %s"), *indentation, *attr.GetTag(), *attr.GetValue());
	}

	// Recursively print all child nodes
	for (auto* childNode : node->GetChildrenNodes())
	{
		PrintNodeRecursive(childNode, depth + 1);
	}	
}

void UXMLSubsystem::TestForLoadXML(const FString& ConfigFileName)
{
	FString Path = FPaths::ProjectContentDir()/TEXT("my/XML/")+ConfigFileName;
	FXmlFile XmlFile(Path);
	if(!XmlFile.IsValid())
	{
		UE_LOG(LogTemp,Error,TEXT("XML File error: %s"),
			*XmlFile.GetLastError());
		return;
	}

	FXmlNode* RootNode = XmlFile.GetRootNode();
	PrintNodeRecursive(RootNode,0);	
}
#endif

