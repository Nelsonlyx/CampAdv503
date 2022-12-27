// Copyright Epic Games, Inc. All Rights Reserved.

#include "CampAdv503GameMode.h"
#include "CampAdv503Character.h"
#include "UObject/ConstructorHelpers.h"

ACampAdv503GameMode::ACampAdv503GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
