// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"


#include "Zipline.generated.h"

UCLASS()
class CAMPADV503_API AZipline : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AZipline();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class USceneComponent* ZiplineRoot;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class USceneComponent* AttachStart;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class USceneComponent* AttachEnd;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UStaticMeshComponent* ZipStartPole;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UStaticMeshComponent* ZipEndPole;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UTextRenderComponent* UI_ZipStart;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UTextRenderComponent* UI_ZipEnd;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UBoxComponent* CollisionStart;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UBoxComponent* CollisionEnd;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UFUNCTION(BlueprintCallable)
	//void PrepareZipline(bool bZiplineEnabled);
	UFUNCTION(BlueprintCallable)
	void EnableZiplineOnOverlap(bool bCanZipline, FVector ZipStart, FVector ZipEnd);

private:
	UPROPERTY()
	class AVRCharacter* VRPlayer;
	UPROPERTY()
	FVector ZipHeightOffset = FVector(0 , 0, -180);
	UPROPERTY()
	float ZipStartTiming = 0.4;
	UPROPERTY()
	bool ZiplineEnabled = false;
};
