// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "AProjectItem.generated.h"

UCLASS()
class AAProjectItem : public AActor
{
	GENERATED_UCLASS_BODY()

public:
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Item)
		FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Item)
		int32 Value;

	UFUNCTION(BlueprintImplementableEvent, meta = (FriendlyName = "Item: Used"))
		virtual void Used();

	UFUNCTION(BlueprintImplementableEvent, meta = (FriendlyName = "Item: Dropped"))
		virtual void Dropped();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Item)
		TSubobjectPtr<class UStaticMeshComponent> Mesh;

	void PickedUp();
};
