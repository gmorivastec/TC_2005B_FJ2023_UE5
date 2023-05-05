// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Cubito.generated.h"

UCLASS()
class AT3003B_UE2_API ACubito : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubito();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UStaticMeshComponent* StaticMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// m�todos para escuchar las colisiones 
	// este ser�a el an�logo a OnCollisionEnter 
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent * OverlappedComp, class AActor * OtherActor, class UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// este ser�a como el OnCollisionExit
	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere)
	FVector Vectorcito = FVector(2000, 0, 0);
};
