// Fill out your copyright notice in the Description page of Project Settings.


#include "ChequeoColision.h"

// Sets default values for this component's properties
UChequeoColision::UChequeoColision()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UChequeoColision::BeginPlay()
{
	Super::BeginPlay();

	StaticMesh = Cast<UStaticMeshComponent>(GetOwner()->GetComponentByClass(UStaticMeshComponent::StaticClass()));
	
	// dar empuj�n
	StaticMesh->AddImpulse(Vectorcito);

	// suscribir métodos para escuchar el momento de colisión y de fin de colisión
	StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &UChequeoColision::OnOverlapBegin);
	StaticMesh->OnComponentEndOverlap.AddDynamic(this, &UChequeoColision::OnOverlapEnd);
}


// Called every frame
void UChequeoColision::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UChequeoColision::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) { 
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("OVERLAP BEGIN"));
}

void UChequeoColision::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("OVERLAP END"));
}
