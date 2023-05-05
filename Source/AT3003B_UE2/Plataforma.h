// Fill out your copyright notice in the Description page of Project Settings.


// h - header 
// es donde se define el contrato de una clase
// el "qué hace" 
// (el "cómo lo hace" va en el cpp)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Plataforma.generated.h"

UCLASS()
class AT3003B_UE2_API APlataforma : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlataforma();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	int direccion = 1;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Limites de plataforma") float limiteIzquierdo = 0;

	UPROPERTY(EditAnywhere, Category = "Limites de plataforma")
	float limiteDerecho = 0;

	UPROPERTY(EditAnywhere, Category = "Limites de plataforma")
	float velocidad = 10;
};
