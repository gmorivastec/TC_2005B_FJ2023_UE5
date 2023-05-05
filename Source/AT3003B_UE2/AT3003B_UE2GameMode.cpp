// Copyright Epic Games, Inc. All Rights Reserved.

#include "AT3003B_UE2GameMode.h"
#include "AT3003B_UE2Character.h"
#include "UObject/ConstructorHelpers.h"

AAT3003B_UE2GameMode::AAT3003B_UE2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
