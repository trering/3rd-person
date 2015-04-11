// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "third_person.h"
#include "third_personGameMode.h"
#include "third_personCharacter.h"

Athird_personGameMode::Athird_personGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/MyCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
