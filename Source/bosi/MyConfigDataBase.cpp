// Fill out your copyright notice in the Description page of Project Settings.


#include "MyConfigDataBase.h"


bool UMyPlayerConfigData::LoadDataWithXml(const FXmlNode* Node)
{
	if (!Node)
	{
		return false;
	}
	for (const FXmlNode* ChildNode : Node->GetChildrenNodes())
	{
		FString Tag = ChildNode->GetTag();
		if (Tag == TEXT("Player"))
		{
			UPlayerConfigdata* tmp = NewObject<UPlayerConfigdata>();
			for (const FXmlNode* Cnode : ChildNode->GetChildrenNodes())
			{
				Tag = Cnode->GetTag();
				if (Tag == TEXT("PlayerData"))
				{
					tmp->Name = Cnode->GetAttribute(TEXT("name"));
					tmp->Id = FCString::Atoi(*Cnode->GetAttribute(TEXT("id")));
				}
				if (Tag == TEXT("Hp"))
				{
					tmp->Hp = FCString::Atoi(*Cnode->GetContent());
				}
				if (Tag == TEXT("Mp"))
				{
					tmp->Mp = FCString::Atoi(*Cnode->GetContent());
				}
			}
			PlayerConfigDatas.Add(tmp);
		}
	}
	return true;
}
