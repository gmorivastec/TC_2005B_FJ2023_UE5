// Fill out your copyright notice in the Description page of Project Settings.


#include "Plataforma.h"

// Sets default values
APlataforma::APlataforma()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
// como el start
void APlataforma::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("hola desde C++")); 
	
	
}

// Called every frame
// como el update
void APlataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// obtener ubicación programaticamente
	FVector ubicacionActual = GetActorLocation();
	

	//UE_LOG(LogTemp, Warning, TEXT("UBICACION: %s"), ubicacionActual);

	// verificar si salio de limite
	if (ubicacionActual.Y < limiteIzquierdo || ubicacionActual.Y > limiteDerecho) {
		// si salio cambiar direccion
		direccion *= -1;
	}

	// desplazar 
	ubicacionActual.Y += DeltaTime * velocidad * direccion;
	SetActorLocation(ubicacionActual);

}

