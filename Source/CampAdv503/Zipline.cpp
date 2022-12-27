// Fill out your copyright notice in the Description page of Project Settings.


#include "Zipline.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Math/Vector.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "VRCharacter.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AZipline::AZipline()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ZiplineRoot = CreateDefaultSubobject<USceneComponent>(TEXT("ZiplineRoot"));
	SetRootComponent(ZiplineRoot);

	ZipStartPole = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ZipStartPole"));
	UI_ZipStart = CreateDefaultSubobject<UTextRenderComponent>(TEXT("UI_ZipStart"));
	UI_ZipStart->SetupAttachment(ZipStartPole);
	AttachStart = CreateDefaultSubobject<USceneComponent>(TEXT("AttachStart"));
	AttachStart->SetupAttachment(ZipStartPole);
	CollisionStart = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionStart"));
	CollisionStart->SetupAttachment(ZipStartPole);


	ZipEndPole = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ZipEndPole"));
	ZipEndPole->SetupAttachment(ZiplineRoot);
	UI_ZipEnd = CreateDefaultSubobject<UTextRenderComponent>(TEXT("UI_ZipEnd"));
	UI_ZipEnd->SetupAttachment(ZipEndPole);
	AttachEnd = CreateDefaultSubobject<USceneComponent>(TEXT("AttachEnd"));
	AttachEnd->SetupAttachment(ZipEndPole);
	CollisionEnd = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionEnd"));
	CollisionEnd->SetupAttachment(ZipEndPole);

}

// Called when the game starts or when spawned
void AZipline::BeginPlay()
{
	Super::BeginPlay();
	

}

// Called every frame
void AZipline::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void AZipline::PrepareZipline(bool bZiplineEnabled)
//{
//	VRPlayer = Cast<AVRCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
//
//	if (bZiplineEnabled && VRPlayer != nullptr)
//	{
//		VRPlayer->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);
//		UCapsuleComponent* PlayerCapsule = VRPlayer->GetCapsuleComponent();
//		FLatentActionInfo LatentInfo;
//		LatentInfo.CallbackTarget = this;
//		LatentInfo.ExecutionFunction = FName("MoveToTargetFinished");
//		LatentInfo.Linkage = 0;
//		LatentInfo.UUID = 0;
//
//
//		UKismetSystemLibrary::MoveComponentTo(
//			PlayerCapsule,
//			AttachStart->GetComponentLocation() + ZipHeightOffset,
//			PlayerCapsule->GetRelativeRotation(), 
//			true, 
//			true, 
//			ZipStartTiming, 
//			false, 
//			EMoveComponentAction::Move, 
//			LatentInfo
//		);
//
//		FLatentActionInfo LatentInfoEnd;
//		LatentInfoEnd.CallbackTarget = this;
//		LatentInfoEnd.ExecutionFunction = FName("MoveToTargetFinished1");
//		LatentInfoEnd.Linkage = 0;
//		LatentInfoEnd.UUID = 1;
//
//		float ZipDuration = ZipStartTiming + FVector::Distance(AttachStart->GetComponentLocation(), AttachEnd->GetComponentLocation());
//		UKismetSystemLibrary::MoveComponentTo(
//			PlayerCapsule,
//			AttachEnd->GetComponentLocation() + ZipHeightOffset,
//			PlayerCapsule->GetRelativeRotation(),
//			true,
//			true,
//			ZipDuration,
//			false,
//			EMoveComponentAction::Move,
//			LatentInfoEnd
//		);
//		VRPlayer->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Falling);
//
//		ZiplineEnabled = false;
//	}
//}

void AZipline::EnableZiplineOnOverlap(bool bCanZipline, FVector ZipStart, FVector ZipEnd)
{
	VRPlayer = Cast<AVRCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (VRPlayer != nullptr)
	{
		VRPlayer->EnableZipline(bCanZipline, this, ZipStart, ZipEnd);
	}
}

