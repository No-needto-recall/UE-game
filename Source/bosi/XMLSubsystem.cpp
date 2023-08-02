// Fill out your copyright notice in the Description page of Project Settings.


#include "XMLSubsystem.h"
#include "XmlFile.h"

UMyPlayerConfigData* UXMLSubsystem::GetPlayerConfigData()
{
	return  GetConfigInfo<UMyPlayerConfigData>(FString("PlayerConfig.xml"));
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

