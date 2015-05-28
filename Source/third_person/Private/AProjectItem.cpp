// Fill out your copyright notice in the Description page of Project Settings.

#include "third_person.h"
#include "AProjectItem.h"

AAProjectItem::AAProjectItem(const class FPostConstructInitializeProperties& PCIP)
: Super(PCIP)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void AAProjectItem::BeginPlay()
{
	Super::BeginPlay();
	Mesh->SetSimulatePhysics(true);
	Mesh->WakeRigidBody();
}

void AAProjectItem::PickedUp()
{
	if (Mesh)
	{
		Mesh->DestroyComponent(); // physical item has been picked up, destroy its visible component
	}
}

// Called every frame
void AAProjectItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

