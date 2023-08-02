// Fill out your copyright notice in the Description page of Project Settings.


#include "MyConfigDataBase.h"



bool UMyPlayerConfigData::LoadDataWithXml(const FXmlNode* Node)
{
	if(!Node)
	{
		return false;
	}
	for(const FXmlNode* ChildNode:Node->GetChildrenNodes())
	{
		FString Tag = ChildNode->GetTag();

		if(Tag == TEXT("PlayerData"))
		{
			this->Name = ChildNode->GetAttribute(TEXT("name"));
			this->Id = FCString::Atoi(*ChildNode->GetAttribute(TEXT("id")));
		}
		else if(Tag == TEXT("Hp"))
		{
			this->Hp = FCString::Atoi(*ChildNode->GetContent());
		}else if(Tag == TEXT("Mp"))
		{
			this->Mp = FCString::Atoi(*ChildNode->GetContent());
		}
	}
	return true;
}
