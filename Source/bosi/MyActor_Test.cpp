// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor_Test.h"
#include "Components/SphereComponent.h"  //组件头文件
#include "Kismet/GameplayStatics.h" //UE玩家类相关头文件
#include "Net/UnrealNetwork.h"

// Sets default values
AMyActor_Test::AMyActor_Test()
	:v1(9,9,9)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	USphereComponent* tmpSpComp = CreateDefaultSubobject<USphereComponent>(TEXT("root"));
	RootComponent = tmpSpComp;

	tmpSpComp->InitSphereRadius(45.f);
	tmpSpComp->SetCollisionProfileName(TEXT("Pawn"));

	//添加静态网格体资源
	UStaticMeshComponent* tmpSpMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mystatic"));
	tmpSpMesh->SetupAttachment(RootComponent);

	//StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		SphereAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	if (SphereAsset.Succeeded()) {
		tmpSpMesh->SetStaticMesh(SphereAsset.Object);
	}

}

// Called when the game starts or when spawned
void AMyActor_Test::BeginPlay()
{
	Super::BeginPlay();
	

}

// Called every frame
void AMyActor_Test::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor_Test::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AMyActor_Test,v2);	
}

