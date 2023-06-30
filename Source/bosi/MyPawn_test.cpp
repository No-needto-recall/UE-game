// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn_test.h"
#include "MyActorComponent_Move.h"//添加头文件
#include "Components/SphereComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h" //UE玩家类相关头文件

// Sets default values
AMyPawn_test::AMyPawn_test()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//根组件
	USphereComponent* sphereCmop = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = sphereCmop;
	
	//将静态网格体组件，附加到根组件下
	UStaticMeshComponent* SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mystatic"));
	SphereMesh->SetupAttachment(RootComponent);

	//StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		SphereAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	if (SphereAsset.Succeeded()) {
		SphereMesh->SetStaticMesh(SphereAsset.Object);
		SphereMesh->SetRelativeLocation(FVector(0.0f,0.0f,-40.0f));
		SphereMesh->SetWorldScale3D(FVector(1.0f));
	}

	//弹簧壁组件
	USpringArmComponent* springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArm"));
	springArm->SetupAttachment(RootComponent);
	springArm->TargetArmLength = 600.0f;
	springArm->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));
	
	//相机组件
	UCameraComponent* Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("PawnCamera"));
	//附加到弹簧臂组件下
	Camera->SetupAttachment(springArm,USpringArmComponent::SocketName);

	//成员变量：自动控制玩家
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	//添加移动组件
	movement = CreateDefaultSubobject<UMyActorComponent_Move>(TEXT("MovementCompont"));
	//更新设置
	movement->UpdatedComponent = RootComponent;

	// 设置Pawn使用控制器旋转yaw
	this->bUseControllerRotationYaw = true;
}

// Called when the game starts or when spawned
void AMyPawn_test::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn_test::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMyPawn_test::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//绑定轴映射事件
	PlayerInputComponent->BindAxis("front_and_back", this, &AMyPawn_test::front_and_back);
	PlayerInputComponent->BindAxis("left_and_right", this, &AMyPawn_test::left_and_right);
	PlayerInputComponent->BindAxis("turn", this, &AMyPawn_test::turn);
	//绑定操作映射事件
	PlayerInputComponent->BindAction("jump",IE_Pressed,this,&AMyPawn_test::jumpActive);
	PlayerInputComponent->BindAction("fire",IE_Pressed,this,&AMyPawn_test::fire);
}

void AMyPawn_test::front_and_back(float AxisVal) {
	
	if (movement && movement->UpdatedComponent == RootComponent) {
		//AddMovementInput(GetActorForwardVector()*AxisVal*800.f);
		movement->AddInputVector(GetActorForwardVector()*AxisVal);
	}
}

void AMyPawn_test::left_and_right(float AxisVal) {

	if (movement && movement->UpdatedComponent == RootComponent) {
		//AddMovementInput(GetActorRightVector() * AxisVal * 800.f);
		movement->AddInputVector(GetActorRightVector()*AxisVal);
	}
}

void AMyPawn_test::turn(float AxisVal) {

	if (movement && movement->UpdatedComponent == RootComponent) {
		// 创建一个Yaw旋转量
		FRotator DeltaRotation(0, AxisVal, 0);
		// 将鼠标移动值用作PlayerController的Yaw输入
		auto contrl = UGameplayStatics::GetPlayerController(this, 0);
		contrl->AddYawInput(AxisVal);
	}

}

void AMyPawn_test::jumpActive() {

}

void AMyPawn_test::fire() {

	if (FireEffect) {
		FVector Location = GetActorLocation(); // 将特效放在Pawn的位置
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), FireEffect, Location);
	}
}
