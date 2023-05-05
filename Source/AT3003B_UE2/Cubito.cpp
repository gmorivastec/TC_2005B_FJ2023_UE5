// Fill out your copyright notice in the Description page of Project Settings.


#include "Cubito.h"

// Sets default values
ACubito::ACubito()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
}

// Called when the game starts or when spawned
void ACubito::BeginPlay()
{
	Super::BeginPlay();
	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("EL CUBITO ESTA VIVO"));
	
	// 1er paso - obtener referencia al static mesh
	// (Que es como el rigid body)
	StaticMesh = Cast<UStaticMeshComponent>(GetComponentByClass(UStaticMeshComponent::StaticClass()));
	
	// dar empuj�n
	StaticMesh->AddImpulse(Vectorcito);

	// suscribir métodos para escuchar el momento de colisión y de fin de colisión
	StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &ACubito::OnOverlapBegin);
	StaticMesh->OnComponentEndOverlap.AddDynamic(this, &ACubito::OnOverlapEnd);
}

// Called every frame
void ACubito::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACubito::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) { 
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("OVERLAP BEGIN"));
	UE_LOG(LogTemp, Warning, TEXT("%s VS %s"), *GetName(), *OtherActor->GetName());

	// como destruir a un actor 
	Destroy();
}

void ACubito::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("OVERLAP END"));
}


